import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 10000, 100)
counting_sort = n
comparison_sort = n * np.log2(n)

plt.figure(figsize=(8, 5))
plt.plot(n, counting_sort, label='Stable Counting Sort O(n)', color='green')
plt.plot(n, comparison_sort, label='Comparison Sort O(n log n)', linestyle='--')
plt.xlabel('Number of Items (n)')
plt.ylabel('Operations')
plt.title('Color Sorting: O(n) Stable Bucket Sort vs Comparison Sort')
plt.legend()
plt.grid(True)
plt.savefig('color_sort_graph.png')
plt.show()