import matplotlib.pyplot as plt

k_vals = [4, 8, 16, 32]
m1_ops = [9000, 35000, 135000, 527000]
m2_ops = [4000, 12000, 32000, 80000]

plt.figure(figsize=(7, 4.5))
plt.plot(k_vals, m1_ops, label="Method 1: Sequential O(n * k^2)", color='red', marker='o')
plt.plot(k_vals, m2_ops, label="Method 2: Pairwise O(n * k log k)", color='green', marker='s')
plt.title("Q3: Merging k Sorted Arrays Order of Growth")
plt.xlabel("Number of Arrays (k)")
plt.ylabel("Comparisons")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("Order_of_growth.png")