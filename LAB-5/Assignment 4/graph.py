import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(10, 10000, 100)
build_heap = n
sorting_phase = n * np.log2(n)
total_heapsort = build_heap + sorting_phase

plt.figure(figsize=(8, 5))
plt.plot(n, build_heap, label='Build Heap Phase O(N)', color='pink', linestyle='--')
plt.plot(n, sorting_phase, label='Extraction Phase O(N log N)', color='purple', linestyle=':')
plt.plot(n, total_heapsort, label='Total HeapSort Time Θ(N log N)', color='lightgreen', linewidth=2)

plt.xlabel('Array Size (N)')
plt.ylabel('Operations')
plt.title('HeapSort Complexity Phase Breakdown')
plt.legend()
plt.grid(True)
plt.savefig('heapsort_graph.png')
plt.show()