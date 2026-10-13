import matplotlib.pyplot as plt
import numpy as np

symbols_count = np.arange(5, 100, 5)
fixed_bits = symbols_count * np.ceil(np.log2(symbols_count))
huffman_bits = symbols_count * (np.log2(symbols_count) * 0.65) # Compression ratio simulation

plt.figure(figsize=(6, 4))
plt.plot(symbols_count, fixed_bits, 'r--', label='Fixed-Length Encoding Bits')
plt.plot(symbols_count, huffman_bits, 'g-o', label='Huffman Compressed Bits')
plt.title('Q2: Huffman Coding Compression vs Symbol Count')
plt.xlabel('Alphabet Size (n)')
plt.ylabel('Total Bits Required')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('q2_graph.png', dpi=300)