import numpy as np
import matplotlib.pyplot as plt

n = np.linspace(1, 100, 100)
standard_ops = n**3
strassen_ops = n**2.81

plt.figure(figsize=(8, 5))
plt.plot(n, standard_ops, label='Standard Multiplication O(n^3)')
plt.plot(n, strassen_ops, label='Strassen Multiplication O(n^2.81)')

plt.xlabel('Matrix Dimension (n)')
plt.ylabel('Operations')
plt.title('Matrix Multiplication: Standard vs Strassen')
plt.legend()
plt.grid(True)
plt.savefig('strassen_graph.png')
plt.show()