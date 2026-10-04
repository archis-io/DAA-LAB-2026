import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 200, 30)
ops_dp = n**2
ops_patience = n * np.log2(n)

plt.figure(figsize=(6, 4))
plt.plot(n, ops_dp, 'm-', label=r'DP Approach $O(n^2)$')
plt.plot(n, ops_patience, 'c--', label=r'Binary Search $O(n \log n)$')
plt.title('Q4: LIS Time Complexity Comparison')
plt.xlabel('Array Size (n)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q4_graph.png', dpi=300)