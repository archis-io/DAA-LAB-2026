import matplotlib.pyplot as plt

n = [1000, 5000, 10000, 50000]
ops_2way = [8705, 55198, 120448, 718392]
ops_3way = [10928, 68420, 147810, 871204]

plt.figure(figsize=(7, 4.5))
plt.plot(n, ops_2way, label="Standard 2-Way Merge Sort O(n log n)", color='blue', marker='o')
plt.plot(n, ops_3way, label="Modified 3-Way Merge Sort O(n log n)", color='orange', marker='^')
plt.title("Q2: 2-Way vs 3-Way Merge Sort Order of Growth")
plt.xlabel("Array Size (N)")
plt.ylabel("Comparisons")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("Order_of_growth.png")