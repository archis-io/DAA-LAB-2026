import matplotlib.pyplot as plt
import numpy as np

floors = np.linspace(10, 100, 20)
dp_ops = 2 * (floors ** 2)

plt.figure(figsize=(6, 4))
plt.plot(floors, dp_ops, 'r-', label=r'DP Ops $O(E \cdot F^2)$ for E=2')
plt.title('Q2: Egg Dropping DP Scaling')
plt.xlabel('Floors (F)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q2_graph.png', dpi=300)