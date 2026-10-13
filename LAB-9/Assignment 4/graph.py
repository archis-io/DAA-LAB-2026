import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 500, 30)
greedy_cost = n * np.log2(n)
arbitrary_cost = n**2 / 2

plt.figure(figsize=(6, 4))
plt.plot(n, greedy_cost, 'g-', label=r'Greedy Min-Heap $O(n \log n)$')
plt.plot(n, arbitrary_cost, 'r--', label=r'Arbitrary Join $O(n^2)$')
plt.title('Q4: Connect Sticks Cost Comparison')
plt.xlabel('Number of Sticks (n)')
plt.ylabel('Total Cumulative Cost')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q4_graph.png', dpi=300)