import matplotlib.pyplot as plt
import numpy as np

n = np.array([10, 50, 100, 200, 500, 1000])
reversals_bound = n
cost_bound = n * (np.log2(n) ** 2)

plt.figure(figsize=(7, 5))
plt.plot(n, cost_bound, 'b-^', label='Total Reversal Cost O(n log² n)')
plt.plot(n, reversals_bound, 'm--d', label='Reversals Count O(n)')
plt.title('Question 4: Reversal Sorting Operations vs Cost Scaling')
plt.xlabel('Permutation Size (n)')
plt.ylabel('Cost / Operations')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q4_graph.png', dpi=300)
print("q4_graph.png saved!")