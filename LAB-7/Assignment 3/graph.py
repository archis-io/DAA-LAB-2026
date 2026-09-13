

import matplotlib.pyplot as plt
import numpy as np

n = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
reves_moves = np.array([1, 3, 5, 9, 13, 17, 25, 33, 41, 49])
hanoi_moves = 2**n - 1

plt.figure(figsize=(6, 4))
plt.plot(n, reves_moves, 'g-s', label="Reve's Puzzle (4 Pegs)")
plt.plot(n, hanoi_moves, 'r--o', label="Standard Hanoi (3 Pegs)")
plt.title("Q3: Reve's Puzzle vs Standard Hanoi Moves")
plt.xlabel('Disks (n)')
plt.ylabel('Moves')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q3_graph.png', dpi=300)