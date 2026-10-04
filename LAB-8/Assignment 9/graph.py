import matplotlib.pyplot as plt

def collatz_sequence(n):
    sequence = [n]

    while n != 1:
        if n % 2 == 0:
            n //= 2
        else:
            n = 3 * n + 1

        sequence.append(n)

    return sequence


# Same as analyzeSingle(27)
n = 27
sequence = collatz_sequence(n)

steps = list(range(len(sequence)))

# Display results
print("Initial value:", n)
print("Total Stopping Time:", len(sequence) - 1)
print("Peak Value:", max(sequence))

print("\nCollatz Sequence:")
print(" -> ".join(map(str, sequence)))


# ---------------- GRAPH ----------------

plt.figure(figsize=(12, 6))

plt.plot(
    steps,
    sequence,
    marker='o',
    markersize=3,
    linewidth=1.2
)

plt.title("Collatz Conjecture Trajectory for n = 27")
plt.xlabel("Step")
plt.ylabel("Value")

plt.grid(True, linestyle="--", alpha=0.5)

plt.tight_layout()

# Save PNG
plt.savefig("collatz_27_graph.png", dpi=300)

# Display graph
plt.show()