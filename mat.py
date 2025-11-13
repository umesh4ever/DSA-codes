# Enhanced Interactive PID Control for Joint Positioning (VS Code Friendly)

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, CheckButtons
import control as ctrl

# 1. Plant Parameters (Single-Joint DC Motor Model)
J = 0.01    # kg*m^2
B = 0.1     # N*m*s/rad
K = 1.0     # motor gain

# Plant: G(s) = K / (J*s^2 + B*s)
G = ctrl.TransferFunction([K], [J, B, 0])

# 2. Initial PID Gains & Settings
Kp_init = 50.0
Ki_init = 100.0
Kd_init = 0.5
angle_deg_init = 90.0
disturbance_on_init = False

# 3. Create Figure and Axes
fig = plt.figure(figsize=(10, 10))
fig.suptitle("Interactive PID Joint Position Control", fontsize=16)

ax_pos = plt.subplot(3, 1, 1)
ax_err = plt.subplot(3, 1, 2)
ax_ctrl = plt.subplot(3, 1, 3)

plt.subplots_adjust(bottom=0.25, hspace=0.4)

# Slider axes
ax_Kp = plt.axes([0.15, 0.15, 0.65, 0.03])
ax_Ki = plt.axes([0.15, 0.11, 0.65, 0.03])
ax_Kd = plt.axes([0.15, 0.07, 0.65, 0.03])
ax_angle = plt.axes([0.15, 0.03, 0.65, 0.03])

# Checkbutton for disturbance
rax = plt.axes([0.02, 0.05, 0.12, 0.1])
check = CheckButtons(rax, ['Disturbance'], [disturbance_on_init])

# Sliders
s_Kp = Slider(ax_Kp, 'Kp', 10, 100, valinit=Kp_init, valstep=5)
s_Ki = Slider(ax_Ki, 'Ki', 0, 150, valinit=Ki_init, valstep=5)
s_Kd = Slider(ax_Kd, 'Kd', 0, 5, valinit=Kd_init, valstep=0.1)
s_angle = Slider(ax_angle, 'Angle (°)', 10, 180, valinit=angle_deg_init, valstep=10)

# 4. Simulation Function
def update(val):
    Kp = s_Kp.val
    Ki = s_Ki.val
    Kd = s_Kd.val
    angle_deg = s_angle.val
    disturbance_on = check.get_status()[0]

    theta_des = np.deg2rad(angle_deg)

    # PID Controller: C(s) = Kd*s + Kp + Ki/s
    C = ctrl.TransferFunction([Kd, Kp, Ki], [1, 0])

    # Closed-loop system
    T = ctrl.feedback(C * G, 1)

    # Time vector
    t = np.linspace(0, 2, 1000)
    dt = t[1] - t[0]

    # Input signal
    u = theta_des * np.ones_like(t)
    if disturbance_on:
        u += 0.1 * np.sin(10 * t)

    # Simulate
    t_out, y_out = ctrl.forced_response(T, T=t, U=u)

    # Compute error and control effort
    error = theta_des - y_out
    err_int = np.cumsum(error) * dt
    dydt = np.gradient(y_out, dt)
    control_signal = Kp * error + Ki * err_int - Kd * dydt

    # Clear and replot
    ax_pos.cla()
    ax_err.cla()
    ax_ctrl.cla()

    # Position
    ax_pos.plot(t_out, np.rad2deg(y_out), 'b', lw=2, label='θ(t)')
    ax_pos.axhline(angle_deg, color='r', linestyle='--', label='Desired')
    title = f"Target = {angle_deg:.1f}°"
    if disturbance_on:
        title += "  (with Disturbance)"
    ax_pos.set_title(title)
    ax_pos.set_ylabel("θ(t) [deg]")
    ax_pos.grid(True)
    ax_pos.legend()

    # Error
    ax_err.plot(t_out, np.rad2deg(error), color='orange', lw=2)
    ax_err.set_title("Tracking Error e(t)")
    ax_err.set_ylabel("Error [deg]")
    ax_err.grid(True)

    # Control effort
    ax_ctrl.plot(t_out, control_signal, color='purple', lw=2)
    ax_ctrl.set_title("Control Effort (Torque)")
    ax_ctrl.set_xlabel("Time [s]")
    ax_ctrl.set_ylabel("u(t) [Nm]")
    ax_ctrl.grid(True)

    # Performance metrics
    info = ctrl.step_info(T)
    metric_text = (f"RiseTime: {info['RiseTime']:.3f}s | "
                   f"SettlingTime: {info['SettlingTime']:.3f}s | "
                   f"Overshoot: {info['Overshoot']:.2f}%")
    fig.suptitle(f"Interactive PID Joint Position Control\n{metric_text}", fontsize=12)

    plt.draw()

# 5. Connect sliders and checkbox
s_Kp.on_changed(update)
s_Ki.on_changed(update)
s_Kd.on_changed(update)
s_angle.on_changed(update)
check.on_clicked(lambda event: update(None))

# Initial plot
update(None)

plt.show()