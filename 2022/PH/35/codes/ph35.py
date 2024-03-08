import matplotlib.pyplot as plt

# Read data from ph35.dat
data = []
with open("ph35.dat", "r") as file:
    for line in file:
        # Skip comment lines
        if not line.startswith("#"):
            values = line.split()
            data.append((float(values[0]), float(values[1])))

# Separate the data into two lists
omega_range, response = zip(*data)

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(omega_range, response, label='Spectrometer Response', color='blue')

plt.xlabel('Plasma Frequency (rad/s)')
plt.ylabel('Spectrometer Response')
plt.grid(True)
plt.legend()
plt.show()

