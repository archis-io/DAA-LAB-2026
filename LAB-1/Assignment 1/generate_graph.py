import numpy as np
import matplotlib.pyplot as plt

n = np.linspace(1, 100, 400)

plt.figure(figsize=(10, 6))
plt.plot(n, 1/n, label='1/n')
plt.plot(n, np.log2(n), label='log2(n)')
plt.plot(n, 12 * np.sqrt(n), label='12√n')
plt.plot(n, n**0.51, label='n^0.51')
plt.plot(n, 100*n, label='100n')
plt.plot(n, n * np.log2(n), label='n log2(n)')
plt.plot(n, n**2 - 324, label='n^2 - 324')

plt.yscale('log')
plt.xlabel('n')
plt.ylabel('f(n) (Log Scale)')
plt.title('Comparison of Function Growth Rates')
plt.legend()
plt.grid(True)
plt.savefig('order_of_growth.png')
plt.show()