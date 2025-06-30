from queue import PriorityQueue

# Initial and goal states based on your input
start = [
    [2, 3, 0],
    [1, 8, 4],
    [7, 6, 5]
]

goal = [
    [1, 2, 3],
    [8, 0, 4],
    [7, 6, 5]
]

# Heuristic: number of misplaced tiles (excluding the blank)
def heuristic(state):
    misplaced = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != goal[i][j]:
                misplaced += 1
    return misplaced

# Find position of blank (0)
def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

# Get all possible moves
def get_moves(state):
    moves = []
    x, y = find_blank(state)
    directions = [(-1,0), (1,0), (0,-1), (0,1)]  # Up, Down, Left, Right

    for dx, dy in directions:
        nx, ny = x + dx, y + dy
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = [row[:] for row in state]
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            moves.append(new_state)
    return moves

# Convert state to string for visited set
def state_to_string(state):
    return ''.join(str(state[i][j]) for i in range(3) for j in range(3))

# A* search function
def a_star(start):
    visited = set()
    queue = PriorityQueue()
    h_start = heuristic(start)
    queue.put((h_start, 0, start, []))  # (f, g, state, path)

    while not queue.empty():
        f, g, current, path = queue.get()
        state_str = state_to_string(current)

        if current == goal:
            return path + [current]

        if state_str in visited:
            continue
        visited.add(state_str)

        for move in get_moves(current):
            g_new = g + 1  # Cost to move is always 1
            h_new = heuristic(move)
            f_new = g_new + h_new
            queue.put((f_new, g_new, move, path + [current]))

    return None

# Run the search
solution = a_star(start)

# Print the steps
if solution:
    print("Steps to reach goal:")
    for i, step in enumerate(solution):
        print(f"Step {i}:")
        for row in step:
            print(row)
        print("----")
    print("Total moves:", len(solution) - 1)
else:
    print("No solution found.")