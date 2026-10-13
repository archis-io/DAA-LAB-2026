import matplotlib.pyplot as plt
import numpy as np

N = np.linspace(10, 500, 25)
ops = N * np.log2(26) # Fixed alphabet size = 26

plt.figure(figsize=(6, 4))
plt.plot(N, ops, 'b-o', markersize=4, label=r'Complexity $O(N \log A)$')
plt.title('Q6: Reorganize String Operations vs Length')
plt.xlabel('String Length (N)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q6_graph.png', dpi=300)