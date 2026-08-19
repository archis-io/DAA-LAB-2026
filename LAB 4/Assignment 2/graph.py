import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 10000, 100)
brute_force = n**2
sorting_bs = n * np.log2(n)

plt.figure(figsize=(8, 5))
plt.plot(n, brute_force, label='Brute-force Search O(n^2)', color='red')
plt.plot(n, sorting_bs, label='Sort + Binary Search O(n log n)', color='blue')
plt.xlabel('Set Size (n)')
plt.ylabel('Operations Count')
plt.title('Two-Set Sum Complexity')
plt.legend()
plt.grid(True)
plt.savefig('two_set_sum_graph.png')
plt.show()