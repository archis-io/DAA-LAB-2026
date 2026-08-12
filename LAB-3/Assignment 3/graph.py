import numpy as np
import matplotlib.pyplot as plt

n = np.arange(2, 100, 2)
brute_force = 2 * n - 2
divide_conquer = (3 * n / 2) - 2

plt.figure(figsize=(8, 5))
plt.plot(n, brute_force, label='Standard Method (2n - 2)', linestyle='--')
plt.plot(n, divide_conquer, label='D&C Tournament (3n/2 - 2)', linewidth=2)

plt.xlabel('Array Size (n)')
plt.ylabel('Number of Comparisons')
plt.title('Max-Min Comparisons: Standard vs Divide & Conquer')
plt.legend()
plt.grid(True)
plt.savefig('max_min_comps.png')
plt.show()