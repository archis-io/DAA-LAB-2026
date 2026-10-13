import matplotlib.pyplot as plt
import numpy as np

k_vals = np.arange(10, 100, 2)
approx_ratio = (9 * k_vals + 2) / (4 * k_vals + 4)

plt.figure(figsize=(6, 4))
plt.plot(k_vals, approx_ratio, 'r-o', markersize=3, label=r'Lower Bound Ratio $\frac{9k+2}{4k+4}$')
plt.axhline(y=2.0, color='b', linestyle='--', label='Original 2-Approximation Claim')
plt.axhline(y=2.25, color='g', linestyle=':', label='Asymptotic Limit (9/4 = 2.25)')
plt.title('Q10: Disproving Greedy Superstring Conjecture')
plt.xlabel('Even String Length (k)')
plt.ylabel('Approximation Ratio')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q10_graph.png', dpi=300)