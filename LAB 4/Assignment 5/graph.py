import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 5000, 100)
ops = n * np.log2(n)

plt.figure(figsize=(8, 5))
plt.plot(n, ops, label='Sorting + Merging O(n log n)', color='brown')
plt.xlabel('Number of Intervals (n)')
plt.ylabel('Operations')
plt.title('Merge Intervals Complexity')
plt.legend()
plt.grid(True)
plt.savefig('merge_intervals_graph.png')
plt.show()