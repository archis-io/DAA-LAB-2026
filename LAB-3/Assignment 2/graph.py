import numpy as np
import matplotlib.pyplot as plt

n = np.linspace(2, 100, 100)
# Linear weighing (worst case checking pairs)
linear_weighs = n / 2  
# D&C weighing
dc_weighs = np.log2(n) 

plt.figure(figsize=(8, 5))
plt.plot(n, linear_weighs, label='Linear Weighing O(n)', linestyle='--')
plt.plot(n, dc_weighs, label='Divide & Conquer O(log n)', color='purple', linewidth=2)

plt.xlabel('Number of Coins (n)')
plt.ylabel('Number of Weighings')
plt.title('Defective Coin: Linear vs Divide & Conquer')
plt.legend()
plt.grid(True)
plt.savefig('defective_coin.png')
plt.show()