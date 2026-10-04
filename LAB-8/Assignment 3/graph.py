import matplotlib.pyplot as plt
import numpy as np

m = np.linspace(10, 200, 30)
ops = m * m  # Assuming m = n

plt.figure(figsize=(6, 4))
plt.plot(m, ops, 'r-', label=r'DP Complexity $O(m \cdot n)$')
plt.title('Q3: Longest Common Subsequence DP Scaling')
plt.xlabel('String Length (m = n)')
plt.ylabel('Matrix Operations')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q3_graph.png', dpi=300)