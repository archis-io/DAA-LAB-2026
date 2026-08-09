import numpy as np
import matplotlib.pyplot as plt

tosses = [100, 1000, 10000, 100000, 1000000]
fair_prob = [0.5200, 0.4910, 0.5023, 0.5008, 0.5001]
biased_prob = [0.6800, 0.7080, 0.6974, 0.7005, 0.7001]

plt.figure(figsize=(8, 5))
plt.plot(tosses, fair_prob, marker='o', label='Fair Coin (p=0.5)')
plt.plot(tosses, biased_prob, marker='s', label='Biased Coin (p=0.7)')
plt.axhline(y=0.5, color='r', linestyle='--', alpha=0.6)
plt.axhline(y=0.7, color='g', linestyle='--', alpha=0.6)

plt.xscale('log')
plt.xlabel('Number of Tosses (Log Scale)')
plt.ylabel('Probability of Heads')
plt.title('Fair vs Biased Coin Toss Simulation')
plt.legend()
plt.grid(True)
plt.savefig('coin_toss.png')
plt.show()