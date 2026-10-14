import matplotlib.pyplot as plt
import numpy as np

V_vals = np.arange(10, 300, 10)
E_vals = 2 * V_vals
ops = E_vals * V_vals

plt.figure(figsize=(6, 4))
plt.plot(V_vals, ops, 'm-^', markersize=3, label=r'Query Complexity $O(E \cdot V)$')
plt.title('Q3: Max Weight Component Search Scaling')
plt.xlabel('Vertices Count (V)')
plt.ylabel('Operations')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('q3_graph.png', dpi=300)