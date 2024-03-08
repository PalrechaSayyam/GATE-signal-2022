import matplotlib.pyplot as plt
import numpy as np

# Define the range of K values
K_values = np.linspace(-10, 10, 1000)

# Calculate the stability condition
stability_condition = (6 * K_values**2) + (24 * K_values) + 2

# Plot the stability region
plt.plot(K_values, stability_condition, label='6K^2 + 24K + 2')
plt.axhline(y=0, color='black', linestyle='--', label='Stability boundary')
plt.xlabel('K')
plt.ylabel('Stability Condition')
plt.title('Stability Region Plot')
plt.legend()
plt.grid(True)
plt.show()
