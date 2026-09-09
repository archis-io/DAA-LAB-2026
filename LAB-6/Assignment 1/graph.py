import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 1000, 100)
o_n = n                      # Max, Mean, Median, Reverse, Partition
o_n_logn = n * np.log2(n)    # Mode, Remove Duplicates

plt.figure(figsize=(7, 5))
plt.plot(n, o_n, label='O(n): Max, Mean, Median, Reverse, Partition', color='blue', linewidth=2)
plt.plot(n, o_n_logn, label='O(n log n): Mode, Remove Duplicates', color='orange', linewidth=2)
plt.title('Question 1: 1D Array Operations Time Complexity')
plt.xlabel('Array Size (n)')
plt.ylabel('Relative Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q1_graph.png', dpi=300)
print("q1_graph.png saved!")