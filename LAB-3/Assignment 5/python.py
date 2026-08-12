import numpy as np
import matplotlib.pyplot as plt

n = np.linspace(1, 100, 100)
standard_ops = n**3
fast_dc_ops = n**2

plt.figure(figsize=(8, 5))
plt.plot(n, standard_ops, label='Standard Block Method O(n^3)')
plt.plot(n, fast_dc_ops, label='Fast D&C (Algebraic) O(n^2)', color='green')

plt.xlabel('Matrix Dimension (n)')
plt.ylabel('Operations Count')
plt.title('Special Pattern Matrix Multiplication')
plt.legend()
plt.grid(True)
plt.savefig('special_matrix.png')
plt.show()