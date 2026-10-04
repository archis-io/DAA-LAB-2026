import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 300, 30)
ops = (n * (n - 1)) / 2

plt.figure(figsize=(6, 4))
plt.plot(n, ops, color='orange', label=r'MSIS Ops $O(n^2)$')
plt.title('Q5: MSIS Dynamic Programming Scaling')
plt.xlabel('Array Length (n)')
plt.ylabel('Comparisons')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q5_graph.png', dpi=300)