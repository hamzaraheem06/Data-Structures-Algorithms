graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': ['A', 'I'],
    'F': ['J'],
    'G': [],
    'H': [],
    'I': ['C'],
    'J': []
}

goal = 'J'
limit = 4
expanded_nodes = 0
avoided_nodes = 0

def heuristic_alpha_distance(node, goal):
    if not node or not goal:
        return 0
    return abs(ord(goal[0]) - ord(node[0]))

def dls_with_heuristic(graph, node, goal, limit, path, expansions_counter=None):
    if node == goal:
        return path
    if limit == 0:
        return None
    if expansions_counter is not None:
        expansions_counter[0] += 1
    for nbr in graph.get(node, []):
        est_depth = len(path)  # current path length (nodes)
        # heuristic interpreted as minimal remaining edges required
        if est_depth + heuristic_alpha_distance(nbr, goal) <= limit:
            res = dls_with_heuristic(graph, nbr, goal, limit - 1, path + [nbr], expansions_counter)
            if res:
                return res
    return None

def ids_with_heuristic(graph, start, goal, max_depth):
    per_iter_stats = []
    for depth in range(max_depth + 1):
        expansions_counter = [0]
        path = dls_with_heuristic(graph, start, goal, depth, [start], expansions_counter)
        per_iter_stats.append({
            'depth_limit': depth,
            'expansions': expansions_counter[0],
            'found': bool(path),
            'path': path
        })
        if path:
            return path, depth, per_iter_stats
    return None, None, per_iter_stats


# Task 4: IDS with heuristic filtering and comparison to plain IDS
print("--- Task 4: IDS with Heuristic Filtering ---")
max_depth_task4 = 6
# Heuristic IDS stats
path_hids, depth_hids, hids_stats = ids_with_heuristic(graph, 'A', goal, max_depth_task4)

print("\nHeuristic-IDS per-iteration expansions:")
for p in hids_stats:
    print(f" depth={p['depth_limit']}: expansions={p['expansions']}  found={p['found']}")

    if path_hids:
        print(f"\nHeuristic-IDS found goal {goal} at depth {depth_hids} with path: {path_hids}")
    else:
        print(f"\nHeuristic-IDS did NOT find goal {goal} up to depth {max_depth_task4}")

