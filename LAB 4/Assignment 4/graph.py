import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 5000, 100)
sweep_line = 2 * n * np.log2(2 * n)

plt.figure(figsize=(8, 5))
plt.plot(n, sweep_line, label='Sweep-Line Event Sorting O(n log n)', color='orange')
plt.xlabel('Number of Guests (n)')
plt.ylabel('Operations')
plt.title('Party Max People Problem Complexity')
plt.legend()
plt.grid(True)
plt.savefig('party_graph.png')
plt.show()