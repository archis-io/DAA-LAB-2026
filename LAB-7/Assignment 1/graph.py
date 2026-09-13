import matplotlib.pyplot as plt
import numpy as np

n = np.arange(1, 20)
moves = (n * (n + 1)) // 6

plt.figure(figsize=(6, 4))
plt.plot(n, moves, 'bo-', label=r'Min Moves: $\lfloor \frac{n(n+1)}{6} \rfloor$')
plt.title('Q1: Coin-Triangle Inversion Scaling')
plt.xlabel('Triangle Height (n)')
plt.ylabel('Minimum Moves')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q1_graph.png', dpi=300)