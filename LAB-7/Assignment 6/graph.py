import matplotlib.pyplot as plt
import numpy as np

m = np.linspace(10, 1000, 50)
ops = m * np.log2(m)

plt.figure(figsize=(6, 4))
plt.plot(m, ops, color='orange', label=r'Sweep-Line $O(M \log M)$')
plt.title('Q6: Sweep-Line Algorithm Complexity')
plt.xlabel('Scientists Count (M)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q6_graph.png', dpi=300)