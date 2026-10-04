import matplotlib.pyplot as plt
import numpy as np

V = np.arange(1, 50)
# Sample coin set {1, 2, 5}
dp = np.zeros(50)
dp[0] = 1
for coin in [1, 2, 5]:
    for j in range(coin, 50):
        dp[j] += dp[j - coin]

plt.figure(figsize=(6, 4))
plt.plot(V, dp[1:], 'g-o', label='Combinations Count')
plt.title('Q2: Coin Change Combinations Growth')
plt.xlabel('Target Amount (V)')
plt.ylabel('Number of Ways')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q2_graph.png', dpi=300)