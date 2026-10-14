import matplotlib.pyplot as plt
import numpy as np

V_nodes = np.arange(10, 1000, 50)
E_edges = 3 * V_nodes
ops = (V_nodes + E_edges) * 4 # DSU inverse ackermann factor ~ 4

plt.figure(figsize=(6, 4))
plt.plot(V_nodes, ops, 'r-d', markersize=3, label=r'Reverse DSU $O((V + E) \cdot \alpha(V))$')
plt.title('Q4: Reverse DSU Time Complexity Scaling')
plt.xlabel('Number of Vertices (V)')
plt.ylabel('Operations Count')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('q4_graph.png', dpi=300)