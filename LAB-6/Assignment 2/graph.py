import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(5, 100, 50)
o_n2 = n ** 2  # Addition, Zero Check, Symmetric Check, Transpose
o_n3 = n ** 3  # Multiplication, Determinant, Eigenvalues

plt.figure(figsize=(7, 5))
plt.plot(n, o_n2, label='O(n²): Addition, Transpose, Zero/Symmetric Check', color='green', linewidth=2)
plt.plot(n, o_n3, label='O(n³): Multiplication, Determinant, Eigenvalue', color='red', linewidth=2)
plt.title('Question 2: 2D Matrix Operations Scaling')
plt.xlabel('Matrix Dimension (n x n)')
plt.ylabel('Relative Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q2_graph.png', dpi=300)
print("q2_graph.png saved!")