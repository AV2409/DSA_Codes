import numpy as np
from collections import deque

class Puzzle:
    def __init__(self, initial_state, goal_state):
        self.current_state = initial_state
        self.goal_state = goal_state
        self.empty_index = self.get_empty_index()

    def get_empty_index(self):
        return self.current_state.index(0)

    def display(self):
        for i in range(0, 9, 3):
            print(self.current_state[i], self.current_state[i+1], self.current_state[i+2])
        print("\n--------\n")

    def move_up(self):
        if self.empty_index >= 3:
            self.current_state[self.empty_index], self.current_state[self.empty_index - 3] = \
                self.current_state[self.empty_index - 3], self.current_state[self.empty_index]
            self.empty_index -= 3
            return True
        return False

    def move_down(self):
        if self.empty_index <= 5:
            self.current_state[self.empty_index], self.current_state[self.empty_index + 3] = \
                self.current_state[self.empty_index + 3], self.current_state[self.empty_index]
            self.empty_index += 3
            return True
        return False

    def move_left(self):
        if self.empty_index % 3 != 0:
            self.current_state[self.empty_index], self.current_state[self.empty_index - 1] = \
                self.current_state[self.empty_index - 1], self.current_state[self.empty_index]
            self.empty_index -= 1
            return True
        return False

    def move_right(self):
        if self.empty_index % 3 != 2:
            self.current_state[self.empty_index], self.current_state[self.empty_index + 1] = \
                self.current_state[self.empty_index + 1], self.current_state[self.empty_index]
            self.empty_index += 1
            return True
        return False

    def is_goal_state(self):
        return self.current_state == self.goal_state

def bfs_solve(start, goal):
    queue = deque([(start, [])])
    visited = set()
    while queue:
        state, path = queue.popleft()
        state_tuple = tuple(state)
        if state_tuple in visited:
            continue
        visited.add(state_tuple)
        path.append(state)
        if state == goal:
            return path
        puzzle = Puzzle(state, goal)
        for move_func in [puzzle.move_up, puzzle.move_down, puzzle.move_left, puzzle.move_right]:
            new_state = state[:]
            puzzle.current_state = new_state
            puzzle.empty_index = puzzle.get_empty_index()
            if move_func():
                queue.append((puzzle.current_state[:], path.copy()))
    return None

initial_state = [2, 8, 1, 0, 4, 3, 7, 6, 5]
goal_state = [1, 2, 3, 8, 0, 4, 7, 6, 5]

path=bfs_solve(initial_state, goal_state)
if bfs_solve(initial_state, goal_state):
    print(path)
    print("Solution found!")
else:
    print("No solution found.")