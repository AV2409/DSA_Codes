# Define the graph as a dictionary with AND/OR branches
graph = {
    'A': [['B', 'C'], ['D']],
    'B': [['G'], ['H']],
    'C': [],
    'D': [['E', 'F']],
    'E': [],
    'F': [],
    'G': [],
    'H': []
}

# Heuristic values for each node
heuristic = {
    'B': 6,
    'C': 12,
    'D': 10,
    'E': 4,
    'F': 4,
    'G': 5,
    'H': 7
}

# Edge cost (uniform for all edges in this case)
edge_cost = 1

# To store the solution path
solution = {}

# AO* algorithm function
def ao_star(node):
    if not graph[node]:
        return 0  # Leaf node, actual cost is 0
    
    min_cost = float('inf')
    best_path = None
    
    for branch in graph[node]:
        branch_cost = 0
        for child in branch:
            # Add edge cost and recursive cost for each child
            child_cost = edge_cost + ao_star(child)
            branch_cost += child_cost
        
        # For AND nodes, we need to consider heuristic values
        if branch_cost < min_cost:
            min_cost = branch_cost
            best_path = branch
    
    solution[node] = best_path
    return min_cost

# Function to print the solution path
def print_solution(node):
    if node not in solution:
        print(node)
        return
    print(f"{node} -> {solution[node]}")
    for child in solution[node]:
        print_solution(child)

# Function to evaluate a node with heuristics
def ao_star_with_heuristic(node):
    if not graph[node]:
        return 0  # Leaf node, actual cost is 0
    
    min_cost = float('inf')
    best_path = None
    
    for branch in graph[node]:
        branch_cost = 0
        for child in branch:
            # For non-leaf nodes, include heuristic
            if child in heuristic:
                child_cost = edge_cost + min(ao_star_with_heuristic(child), heuristic[child])
            else:
                child_cost = edge_cost + ao_star_with_heuristic(child)
            branch_cost += child_cost
        
        if branch_cost < min_cost:
            min_cost = branch_cost
            best_path = branch
    
    solution[node] = best_path
    return min_cost

# Run the AO* algorithm with heuristics
print("Running AO* algorithm with heuristics...")
ao_star_with_heuristic('A')

# Print the solution
print("\nSolution Path:")
print_solution('A')

# Calculate and print the actual cost of the solution
def calculate_actual_cost(node):
    if node not in solution:
        return 0
    
    cost = 0
    for child in solution[node]:
        # Add edge cost
        cost += edge_cost
        # Add recursive cost
        cost += calculate_actual_cost(child)
    
    return cost

total_cost = calculate_actual_cost('A')
print(f"\nTotal cost of the solution: {total_cost}")