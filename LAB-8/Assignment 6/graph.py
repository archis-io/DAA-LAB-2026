import matplotlib.pyplot as plt
import numpy as np

# String lengths scaling from 5 to 100 (assuming m = n)
lengths = np.arange(5, 105, 5)
operations = lengths * lengths

plt.figure(figsize=(7, 4.5))
plt.plot(lengths, operations, 'b-o', linewidth=2, markersize=5, label=r'DP Operations $O(m \times n)$')
plt.title('Q6: Edit Distance - Operations vs String Length', fontsize=12)
plt.xlabel('String Length (m = n)', fontsize=10)
plt.ylabel('Matrix Operations (m * n)', fontsize=10)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig('q6_graph.png', dpi=300)
print("Q6 graph saved successfully as q6_graph.png")