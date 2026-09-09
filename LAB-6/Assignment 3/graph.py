import matplotlib.pyplot as plt
import numpy as np

N = np.array([16, 32, 64, 128, 256, 512, 1024, 2048])
naive_ops = N ** 2
fft_ops = N * np.log2(N)

plt.figure(figsize=(7, 5))
plt.plot(N, naive_ops, 'r--o', label='Naive Convolution O(N²)')
plt.plot(N, fft_ops, 'g-s', label='Divide & Conquer FFT O(N log N)')
plt.title('Question 3: Vector Convolution Performance Comparison')
plt.xlabel('Vector Length (N)')
plt.ylabel('Operations Count')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('q3_graph.png', dpi=300)
print("q3_graph.png saved!")