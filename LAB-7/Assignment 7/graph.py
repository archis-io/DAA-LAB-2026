import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(5, 50, 20)
ops = n ** 3

plt.figure(figsize=(6, 4))
plt.plot(n, ops, 'k--', label=r'MCM DP Complexity $O(n^3)$')
plt.title('Q7: Matrix Chain Multiplication Complexity')
plt.xlabel('Number of Matrices (n)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q7_graph.png', dpi=300)