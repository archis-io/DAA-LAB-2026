import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(100, 10000, 100)
avg_case = n * np.log2(n)
worst_case = n**2

plt.figure(figsize=(8, 5))
plt.plot(n, avg_case, label='Average Case O(N log N)', color='blue')
plt.plot(n, worst_case, label='Worst Case O(N^2)', color='red', linestyle='--')

plt.xlabel('Number of Elements (N)')
plt.ylabel('Time Complexity Benchmark')
plt.title('QuickSort Empirical Complexity')
plt.legend()
plt.grid(True)
plt.savefig('quicksort_graph.png')
plt.show()