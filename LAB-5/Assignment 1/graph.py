import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 10000, 100)
sorting_approach = n * np.log2(n)
quickselect_avg = n
quickselect_worst = n**2

plt.figure(figsize=(8, 5))
plt.plot(n, sorting_approach, label='Sorting Approach O(N log N)', color='blue', linestyle='--')
plt.plot(n, quickselect_avg, label='QuickSelect Average Case O(N)', color='green', linewidth=2)
plt.plot(n, quickselect_worst, label='QuickSelect Worst Case O(N^2)', color='red', linestyle=':')

plt.xlabel('Array Size (N)')
plt.ylabel('Operations Count')
plt.title('Median Selection: Sorting vs QuickSelect')
plt.legend()
plt.grid(True)
plt.savefig('median_graph.png')
plt.show()