import numpy as np
import matplotlib.pyplot as plt

# Read data from file, skipping the first row
data = np.loadtxt("data.dat", skiprows=1)

# Extracting t and y(t) values
t_values = data[:, 0]
y_values = data[:, 1]

# Plotting
plt.plot(t_values, y_values, label='$y(t)$')
plt.axhline(y=1/3, color='r', linestyle='--', label='Horizontal Line at $y=1/3$')
plt.xlabel('$t$')
plt.ylabel('$y(t)$')
plt.grid(True)

# Show legend
plt.legend()

plt.savefig('plot.png')
plt.show()

