import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(5, 50, 20)
ops = n**3

plt.figure(figsize=(6, 4))
plt.plot(n, ops, 'g--', label=r'OBST Complexity $O(n^3)$')
plt.title('Q8: Optimal BST Operations Growth')
plt.xlabel('Number of Keys (n)')
plt.ylabel('Operations')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q8_graph.png', dpi=300)