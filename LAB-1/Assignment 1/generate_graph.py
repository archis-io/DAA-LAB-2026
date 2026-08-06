import matplotlib.pyplot as plt
import numpy as np

n = np.array([1000, 5000, 10000, 50000, 100000])
linear_ops = n
binary_ops = np.log2(n)

plt.figure(figsize=(7, 4.5))
plt.plot(n, linear_ops, label="Unsorted Array: Linear Search O(n)", color='crimson', marker='o')
plt.plot(n, binary_ops, label="Sorted Array: Binary Search O(log n)", color='teal', marker='s')
plt.title("Q1: Order of Growth - Dictionary Operations")
plt.xlabel("Input Size (N)")
plt.ylabel("Key Comparisons")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("Order_of_growth.png")