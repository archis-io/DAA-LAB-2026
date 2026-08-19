import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 5000, 100)
ops = 2 * n * np.log2(2 * n)

plt.figure(figsize=(8, 5))
plt.plot(n, ops, label='Sweep Line O(n log n)', color='teal')
plt.xlabel('Number of Intervals (n)')
plt.ylabel('Operations')
plt.title('Point in Max Intervals Complexity')
plt.legend()
plt.grid(True)
plt.savefig('max_point_graph.png')
plt.show()