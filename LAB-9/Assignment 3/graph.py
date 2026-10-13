import heapq
import matplotlib.pyplot as plt
import numpy as np


# Exact Greedy Max-Heap Algorithm for Refuel Stops
def min_refuel_stops(target, start_fuel, stations):
    max_heap = []
    curr_fuel = start_fuel
    stops = 0
    i = 0
    n = len(stations)

    while curr_fuel < target:
        # Add all reachable stations to max-heap
        while i < n and stations[i][0] <= curr_fuel:
            heapq.heappush(max_heap, -stations[i][1])  # max-heap via negative
            i += 1

        if not max_heap:
            return -1  # Target unreachable

        # Pick the station with maximum fuel available so far
        curr_fuel += -heapq.heappop(max_heap)
        stops += 1

    return stops


# Setup actual highway simulation with 30 gas stations
np.random.seed(42)
num_stations = 30
station_dists = sorted(np.random.randint(15, 480, size=num_stations))
station_fuels = np.random.randint(15, 45, size=num_stations)
stations = list(zip(station_dists, station_fuels))

# Test for Target Distances D from 50 to 500 km
target_distances = np.arange(50, 510, 10)
stops_needed = []
valid_targets = []

for D in target_distances:
    stops = min_refuel_stops(target=D, start_fuel=20, stations=stations)
    if stops != -1:
        valid_targets.append(D)
        stops_needed.append(stops)

# Plot actual step graph
plt.figure(figsize=(7, 4.5))
plt.step(
    valid_targets,
    stops_needed,
    where="post",
    color="crimson",
    linewidth=2,
    label="Min Refuel Stops (Greedy Simulation)",
)
plt.scatter(
    valid_targets,
    stops_needed,
    color="darkred",
    s=20,
    zorder=3,
    label="Stop Decision Points",
)

plt.title(
    "Q3: Minimum Refuel Stops vs Target Distance (Max-Heap Greedy)", fontsize=11
)
plt.xlabel("Target Distance (D)", fontsize=10)
plt.ylabel("Min Refueling Stops Required", fontsize=10)
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend()
plt.tight_layout()
plt.savefig("q3_graph.png", dpi=300)
print("Q3 real graph generated and saved as q3_graph.png!")