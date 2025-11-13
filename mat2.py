# Experiment 8: AI-Based Adaptive Control (VS Code + Interactive)

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
from sklearn.neural_network import MLPRegressor

# 1. System Parameters

m = 1.0       # mass [kg]
c = 0.4       # damping [N·s/m]
k = 1.0       # stiffness [N/m]
dt = 0.01     # time-step [s]
T = 10.0      # total time [s]
t = np.arange(0, T, dt)

# 2. Nonlinear Dynamics

def nonlinear_dynamics(x, xdot, u):
    """ m*xddot + c*xdot + k*x + 0.5*x^3 = u """
    xddot = (u - c*xdot - k*x - 0.5*(x**3)) / m
    return xddot

# 3. Desired Trajectory (sinusoidal)

x_d      = np.sin(0.5 * t)
xdot_d   = 0.5 * np.cos(0.5 * t)
xddot_d  = -0.25 * np.sin(0.5 * t)

# 4. Figure Setup with Sliders

fig = plt.figure(figsize=(12, 8))
fig.suptitle("AI-Based Adaptive Control vs PID", fontsize=16)

# Main plot
ax = plt.subplot(2, 1, 1)
ax.set_title("Trajectory Tracking")
ax.set_ylabel("Position [m]")
ax.grid(True)

# Control effort plot
ax_u = plt.subplot(2, 1, 2)
ax_u.set_title("Control Input")
ax_u.set_xlabel("Time [s]")
ax_u.set_ylabel("u(t) [N]")
ax_u.grid(True)

plt.subplots_adjust(bottom=0.25)

# Slider axes
ax_Kp = plt.axes([0.15, 0.15, 0.65, 0.03])
ax_Ki = plt.axes([0.15, 0.11, 0.65, 0.03])
ax_Kd = plt.axes([0.15, 0.07, 0.65, 0.03])

# Sliders
s_Kp = Slider(ax_Kp, 'Kp', 0, 50, valinit=25, valstep=1)
s_Ki = Slider(ax_Ki, 'Ki', 0, 10, valinit=1, valstep=0.1)
s_Kd = Slider(ax_Kd, 'Kd', 0, 20, valinit=5, valstep=0.5)

# Text box for MSE
text_box = plt.text(0.02, 0.02, "", transform=fig.transFigure, fontsize=10,
                    bbox=dict(boxstyle="round", facecolor="wheat"))

# 5. Train Neural Network (once) on nominal PID data

print("Training Neural Network on nominal PID response...")

# Run nominal PID first to collect training data
Kp_nom, Ki_nom, Kd_nom = 25.0, 1.0, 5.0
x, xdot = 0.0, 0.0
x_pid_train = []
e_int = 0.0

for i in range(len(t)):
    e = x_d[i] - x
    e_int += e * dt
    e_dot = xdot_d[i] - xdot
    u = Kp_nom * e + Ki_nom * e_int + Kd_nom * e_dot
    xddot = nonlinear_dynamics(x, xdot, u)
    xdot += xddot * dt
    x += xdot * dt
    x_pid_train.append(x)

x_pid_train = np.array(x_pid_train)
X_train = np.vstack((x_pid_train, np.gradient(x_pid_train, dt))).T
y_train = 0.5 * (x_pid_train ** 3)

# Train NN
nn = MLPRegressor(hidden_layer_sizes=(10, 10),
                  activation='tanh',
                  solver='adam',
                  max_iter=5000,
                  learning_rate_init=0.01,
                  random_state=0,
                  warm_start=False)
nn.fit(X_train, y_train)
print("NN Training Complete!")

# 6. Update Function (called every time sliders change)

def update(val):
    Kp = s_Kp.val
    Ki = s_Ki.val
    Kd = s_Kd.val

    # --- Standard PID Simulation ---
    x, xdot = 0.0, 0.0
    x_pid = []
    u_pid = []
    e_int = 0.0

    for i in range(len(t)):
        e = x_d[i] - x
        e_int += e * dt
        e_dot = xdot_d[i] - xdot
        u = Kp * e + Ki * e_int + Kd * e_dot
        xddot = nonlinear_dynamics(x, xdot, u)
        xdot += xddot * dt
        x += xdot * dt
        x_pid.append(x)
        u_pid.append(u)

    x_pid = np.array(x_pid)
    u_pid = np.array(u_pid)

    # --- NN-Adaptive Simulation ---
    x, xdot = 0.0, 0.0
    x_nn = []
    u_nn = []
    e_int = 0.0

    for i in range(len(t)):
        e = x_d[i] - x
        e_int += e * dt
        e_dot = xdot_d[i] - xdot

        # NN estimates the nonlinear term f_nl(x) = 0.5*x^3
        fnl_hat = nn.predict(np.array([[x, xdot]]))[0]

        u = Kp * e + Ki * e_int + Kd * e_dot + fnl_hat
        xddot = nonlinear_dynamics(x, xdot, u)
        xdot += xddot * dt
        x += xdot * dt
        x_nn.append(x)
        u_nn.append(u)

    x_nn = np.array(x_nn)
    u_nn = np.array(u_nn)

    # --- Plotting ---
    ax.cla()
    ax_u.cla()

    ax.plot(t, x_d, 'k--', label='Desired', linewidth=2)
    ax.plot(t, x_pid, 'r', label='PID Only', linewidth=2)
    ax.plot(t, x_nn, 'b', label='NN-Adaptive', linewidth=2)
    ax.set_ylabel("Position [m]")
    ax.set_title("Trajectory Tracking")
    ax.grid(True)
    ax.legend()

    ax_u.plot(t, u_pid, 'r', label='PID Input')
    ax_u.plot(t, u_nn, 'b', label='NN-Adaptive Input')
    ax_u.set_xlabel("Time [s]")
    ax_u.set_ylabel("u(t) [N]")
    ax_u.set_title("Control Effort")
    ax_u.grid(True)
    ax_u.legend()

    # --- Performance Metrics ---
    def mse(a, b): return np.mean((a - b) ** 2)
    mse_pid = mse(x_d, x_pid)
    mse_nn = mse(x_d, x_nn)

    text_box.set_text(f"PID MSE: {mse_pid:.6f} | NN-Adaptive MSE: {mse_nn:.6f}\n"
                      f"Kp={Kp:.1f}, Ki={Ki:.1f}, Kd={Kd:.1f}")

    plt.draw()

# 7. Connect Sliders

s_Kp.on_changed(update)
s_Ki.on_changed(update)
s_Kd.on_changed(update)

# Initial plot
update(None)

plt.show()