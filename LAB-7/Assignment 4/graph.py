import matplotlib.pyplot as plt
import numpy as np

n = np.arange(1, 10)
moves = np.floor((2**(n + 1) - 1) / 3)

plt.figure(figsize=(6, 4))
plt.plot(n, moves, 'm-^', label=r'Moves: $\lfloor \frac{2^{n+1}-1}{3} \rfloor$')
plt.title('Q4: Security Switches Minimum Toggles')
plt.xlabel('Switches (n)')
plt.ylabel('Moves')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q4_graph.png', dpi=300)