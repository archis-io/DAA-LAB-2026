import matplotlib.pyplot as plt
import numpy as np

n = np.arange(10, 1000, 50)
operations = 2 * n  # 2 Linear sweeps

plt.figure(figsize=(6, 4))
plt.plot(n, operations, 'm-o', markersize=4, label='Linear Sweeps $O(n)$')
plt.title('Q5: Candy Distribution Scaling')
plt.xlabel('Number of Children (n)')
plt.ylabel('Array Operations')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q5_graph.png', dpi=300)