import matplotlib.pyplot as plt

sizes = [100, 500, 1000, 5000]
comparisons = [4950, 124750, 499500, 12497500]

plt.figure(figsize=(8, 5))
plt.plot(sizes, comparisons, marker='o', color='red', label='Brute Force Comparisons O(n^2)')

plt.xlabel('Array Size (n)')
plt.ylabel('Comparisons')
plt.title('Element Uniqueness: Comparison Count vs Array Size')
plt.legend()
plt.grid(True)
plt.savefig('uniqueness_graph.png')
plt.show()