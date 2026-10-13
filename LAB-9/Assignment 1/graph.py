import matplotlib.pyplot as plt
import numpy as np

capacities = np.linspace(10, 200, 20)
n_items = 50
ops = n_items * np.log2(n_items) + capacities

plt.figure(figsize=(6, 4))
plt.plot(capacities, [n_items * np.log2(n_items)] * len(capacities), 'r--', label='Sorting Cost $O(n \\log n)$')
plt.title('Q1: Deterioration Knapsack Schedule Scaling')
plt.xlabel('Knapsack Capacity (W)')
plt.ylabel('Operations')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q1_graph.png', dpi=300)