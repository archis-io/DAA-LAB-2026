import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 200, 100)
k3_bs = (n**2) * np.log2(n)
k3_brute = n**3

plt.figure(figsize=(8, 5))
plt.plot(n, k3_brute, label='Brute-force O(n^k)', color='red')
plt.plot(n, k3_bs, label='Nested Loops + BS O(n^(k-1) log n)', color='green')
plt.xlabel('Array Size (n)')
plt.ylabel('Operations')
plt.title('k-Sum Complexity comparison for k=3')
plt.legend()
plt.grid(True)
plt.savefig('k_sum_graph.png')
plt.show()