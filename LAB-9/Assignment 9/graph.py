import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(5, 50, 20)
ops_naive = n**2
ops_optimal = n * np.log2(n)

plt.figure(figsize=(6, 4))
plt.plot(n, ops_naive, 'r-', label=r'Simulation $O(n^2)$')
plt.plot(n, ops_optimal, 'g--', label=r'Hu-Tucker Priority $O(n \log n)$')
plt.title('Q9: Hu-Tucker Algorithm Complexity')
plt.xlabel('Sequence Length (n)')
plt.ylabel('Operations')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q9_graph.png', dpi=300)