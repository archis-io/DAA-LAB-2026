import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 5000, 100)
full_sort = n * np.log2(n)
quick_select = n

plt.figure(figsize=(8, 5))
plt.plot(n, full_sort, label='Full Array Sorting O(N log N)', color='orange', linestyle='--')
plt.plot(n, quick_select, label='QuickSelect Order Statistic O(N)', color='darkcyan', linewidth=2)

plt.xlabel('List Size (N)')
plt.ylabel('Operations')
plt.title('K-th Smallest Element Selection Performance')
plt.legend()
plt.grid(True)
plt.savefig('kth_smallest_graph.png')
plt.show()