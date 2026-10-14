import matplotlib.pyplot as plt
import numpy as np

N_elements = np.arange(10, 1000, 20)
M_swaps = 2 * N_elements
ops = N_elements * np.log2(N_elements) + M_swaps * 4

plt.figure(figsize=(6, 4))
plt.plot(N_elements, ops, 'c-o', markersize=3, label=r'Complexity $O(N \log N + M \cdot \alpha(N))$')
plt.title('Q5: Smallest Permutation Sorting Scaling')
plt.xlabel('Permutation Size (N)')
plt.ylabel('Operations')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('q5_graph.png', dpi=300)