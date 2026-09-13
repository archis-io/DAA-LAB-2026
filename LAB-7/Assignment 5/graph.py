import matplotlib.pyplot as plt
import numpy as np

n = np.arange(3, 20)
shots = 2 * (n - 2)

plt.figure(figsize=(6, 4))
plt.plot(n, shots, 'c-d', label=r'Shots Bound: $2(n-2)$')
plt.title('Q5: Moving Target Search Complexity')
plt.xlabel('Hiding Spots (n)')
plt.ylabel('Shots Required')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q5_graph.png', dpi=300)