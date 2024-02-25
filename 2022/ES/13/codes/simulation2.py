import numpy as np
import matplotlib.pyplot as plt

# Define the Laplace function
def laplace_function(s, a):
    return s / (s**2 + a**2)

# Generate s values
s_values = np.linspace(-10, 10, 400)

# Define values for 'a'
a_values = [1, 2, 3]

# Plotting
plt.figure(figsize=(8, 6))

# Plot for each value of 'a'
for i, a in enumerate(a_values):
    laplace_values = laplace_function(s_values, a)
    plt.plot(s_values, laplace_values, label=f'a={a}', linewidth=2)

plt.title('Laplace Function Plot')
plt.xlabel('Re(s)')
plt.ylabel('Im(s)')
plt.grid(True)
plt.legend()
plt.show()

