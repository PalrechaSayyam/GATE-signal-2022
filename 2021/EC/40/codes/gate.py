import numpy as np
import matplotlib.pyplot as plt

n = np.arange(-10, 10)

y = 2 * (1/2) ** (n + 1) * (n >= -1) - (1/2) ** n * (n >= 0) - (1/2) ** (n - 2) * (n >= 2)

plt.stem(n, y, use_line_collection=True)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Graph of y[n] vs n')
plt.grid(True)

plt.savefig('../figs/y(n) vs n.png')


