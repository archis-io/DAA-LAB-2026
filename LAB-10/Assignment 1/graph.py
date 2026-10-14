import matplotlib.pyplot as plt
import numpy as np

edges = np.arange(10, 500, 10)
# Ackermann alpha(V) ~ 4
alpha = 4
ops = edges * alpha

plt.figure(figsize=(6, 4))
plt.plot(edges, ops, 'b-o', markersize=3, label=r'DSU Query Time $O(E \cdot \alpha(V))$')
plt.title('Q1: Online Bipartiteness Query Scaling')
plt.xlabel('Number of Online Edges (E)')
plt.ylabel('Operations')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('q1_graph.png', dpi=300)