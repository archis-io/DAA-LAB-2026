import numpy as np
import matplotlib.pyplot as plt

n = np.linspace(10, 1000, 100)
# Selection sort always takes n(n-1)/2 comparisons
comparisons = (n * (n - 1)) / 2

plt.figure(figsize=(8, 5))
plt.plot(n, comparisons, label='Comparisons (Best & Worst Case) O(n^2)', color='red')

plt.xlabel('Array Size (n)')
plt.ylabel('Number of Comparisons')
plt.title('Selection Sort Complexity')
plt.legend()
plt.grid(True)
plt.savefig('selection_sort.png')
plt.show()