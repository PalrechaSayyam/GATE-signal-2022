import matplotlib.pyplot as plt
import numpy as np

# Read data points from the file
t_values = []
y_values = []
with open('data_points.txt', 'r') as file:
    for line in file:
        t, y = map(float, line.strip().split())
        t_values.append(t)
        y_values.append(y)

# Plot the graph
plt.plot(t_values, y_values, marker='o')
plt.xlabel('Time')
plt.ylabel('y(t)')
plt.xticks(np.arange(1,11,1))
plt.grid(True)
plt.savefig("graph.png")
