import numpy as np
import matplotlib.pyplot as plt

# Load the data generated by C code
data = np.loadtxt('data.txt')

# Generate the signal values for n = -3 to 4
n_values = np.arange(-3, 5)

# Plot the signal
plt.stem(n_values, data, markerfmt='^', basefmt='k')
plt.xlabel('n')
plt.ylabel('h[n]')
plt.grid(True)
plt.savefig('fig1.png')

