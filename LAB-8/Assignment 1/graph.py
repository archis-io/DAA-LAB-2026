import matplotlib.pyplot as plt
import numpy as np

V = np.linspace(1, 500, 50)
n = 5  # Number of coin denominations
ops = n * V

plt.figure(figsize=(6, 4))
plt.plot(V, ops, 'b-', label=r'DP Complexity $O(n \cdot V)$')
plt.title('Q1: Minimum Coin Change DP Operations')
plt.xlabel('Target Amount (V)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q1_graph.png', dpi=300)