import numpy as np
import matplotlib.pyplot as plt

disks = np.arange(1, 16)
moves = 2**disks - 1

plt.figure(figsize=(8, 5))
plt.plot(disks, moves, marker='o', color='purple', label='Simulated Moves = 2^n - 1')

plt.yscale('log')
plt.xlabel('Number of Disks (n)')
plt.ylabel('Total Moves (Log Scale)')
plt.title('Towers of Hanoi: Disk Count vs Total Moves')
plt.legend()
plt.grid(True)
plt.savefig('toh_graph.png')
plt.show()