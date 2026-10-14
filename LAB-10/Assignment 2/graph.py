import matplotlib.pyplot as plt
import numpy as np

k_ops = np.arange(10, 500, 10)
grid_size = 100 * 100
ops = 4 * k_ops * 4 # 4 neighbors * inverse ackermann

plt.figure(figsize=(6, 4))
plt.plot(k_ops, ops, 'g-s', markersize=3, label=r'DSU Grid Operations $O(k \cdot \alpha(R \cdot C))$')
plt.title('Q2: Dynamic Islands II Time Complexity')
plt.xlabel('Land Additions (k)')
plt.ylabel('Operations')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('q2_graph.png', dpi=300)