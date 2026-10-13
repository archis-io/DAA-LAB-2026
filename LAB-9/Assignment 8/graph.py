import matplotlib.pyplot as plt
import numpy as np

n = np.arange(5, 100, 5)
ops = 2 * n * np.log2(n) + n # Sorting + Two-pointer sweep

plt.figure(figsize=(6, 4))
plt.plot(n, ops, 'k-o', markersize=4, label=r'Sweep Complexity $O(n \log n)$')
plt.title('Q8: Meeting Rooms Operations vs Intervals')
plt.xlabel('Number of Meetings (n)')
plt.ylabel('Operations')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q8_graph.png', dpi=300)