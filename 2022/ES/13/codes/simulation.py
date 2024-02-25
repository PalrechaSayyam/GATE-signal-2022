import numpy as np
import matplotlib.pyplot as plt

# Load data from data1.txt
data1 = np.loadtxt('data1.txt', delimiter=',')
x_values, sin_values = data1[:, 0], data1[:, 1]

# Load data from data2.txt
data2 = np.loadtxt('data2.txt', delimiter=',')
s_values, laplace_values = data2[:, 0], data2[:, 1]

# Plotting
plt.figure(figsize=(8, 6))

# Plot sin(x)
plt.plot(x_values, sin_values, label='sin(x)', linewidth=2)

# Plot Laplace of sin(x)
plt.plot(s_values, laplace_values, linestyle='--', label='Laplace of sin(x)', linewidth=2)

plt.title('sin(ax) and Laplace of sin(ax)')
plt.xlabel('x or Re(s)')
plt.ylabel('')
plt.grid(True)
plt.legend()
plt.show()

