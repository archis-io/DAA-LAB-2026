import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 200, 20)
max_val = 1000
ops = n * np.log2(n) * np.log2(max_val)

plt.figure(figsize=(6, 4))
plt.plot(n, ops, 'r-o', markersize=4, label=r'Heap Operations $O(n \log n \log M)$')
plt.title('Q7: Minimizing Deviation Complexity')
plt.xlabel('Array Size (n)')
plt.ylabel('Heap Operations')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q7_graph.png', dpi=300)