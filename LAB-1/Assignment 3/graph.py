import matplotlib.pyplot as plt

sizes = [100, 200, 500, 1000]
optimized = [4782, 19210, 121405, 492110]
standard = [4950, 19900, 124750, 499500]

plt.figure(figsize=(8, 5))
plt.plot(sizes, optimized, marker='o', label='Optimized (Early Exit)')
plt.plot(sizes, standard, marker='s', label='Standard ((n-1) Passes)')

plt.xlabel('Array Size (n)')
plt.ylabel('Number of Comparisons')
plt.title('Bubble Sort Performance: Optimized vs Standard')
plt.legend()
plt.grid(True)
plt.savefig('bubble_sort.png')
plt.show()