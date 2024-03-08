import numpy as np
import matplotlib.pyplot as plt

# Read data from output_data.txt
data = {'t': [], 'V_out': []}
with open('output_data.txt', 'r') as file:
    next(file)  # Skip the header
    for line in file:
        t, V_out = map(float, line.split())
        data['t'].append(t)
        data['V_out'].append(V_out)

# Generate sinusoidal increasing plot from t=0 to t=0.5
t_sin = np.arange(0, 0.5, 0.01)
V_out_sin =  0.4 * np.sin(np.pi * t_sin)

# Plot V_out versus t
plt.plot(data['t'], data['V_out'])
plt.plot(t_sin, V_out_sin, 'r--')  # Plot sinusoidal increasing
plt.xlabel('t')
plt.ylabel('V_out')
plt.title('V_out vs t')
plt.grid(True)
plt.savefig('typo.png')
plt.show()
