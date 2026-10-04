import matplotlib.pyplot as plt

# Prices for lengths 1 to 10 (index 0 is dummy)
price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
n_max = len(price) - 1

rev = [0] * (n_max + 1)

for i in range(1, n_max + 1):
    max_v = -1
    for j in range(1, i + 1):
        max_v = max(max_v, price[j] + rev[i - j])
    rev[i] = max_v

n_values = list(range(1, n_max + 1))

plt.figure(figsize=(6, 4))
plt.plot(n_values, rev[1:], "k-o", label="Max Revenue")
plt.title("Q7: Rod Cutting Maximum Revenue vs Length")
plt.xlabel("Rod Length (n)")
plt.ylabel("Maximum Revenue")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("q7_graph.png", dpi=300)
print("Graph saved successfully as q7_graph.png!")