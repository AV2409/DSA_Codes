class Puzzle:
    def __init__(self, initial_state, goal_state):
        self.current_state = initial_state
        self.goal_state = goal_state
        self.empty_index = self.get_empty_index()

    def get_empty_index(self):
        """Find the index of the empty tile (0)."""
        return self.current_state.index(0)

    def display(self):
        """Prints the current puzzle state in a 3×3 grid."""
        for i in range(0, 9, 3):
            print(self.current_state[i], self.current_state[i+1], self.current_state[i+2])
        print("\n--------\n")

    def move_up(self):
        """Move the empty space up (swap with the tile above)."""
        if self.empty_index >= 3:  # Can move up only if not in the top row
            self.current_state[self.empty_index], self.current_state[self.empty_index - 3] = \
                self.current_state[self.empty_index - 3], self.current_state[self.empty_index]
            self.empty_index -= 3  # Move empty space up
            return True
        else:
            print("Invalid Move: Cannot move up")
            return False

    def move_down(self):
        """Move the empty space down (swap with the tile below)."""
        if self.empty_index <= 5:  # Can move down only if not in the bottom row
            self.current_state[self.empty_index], self.current_state[self.empty_index + 3] = \
                self.current_state[self.empty_index + 3], self.current_state[self.empty_index]
            self.empty_index += 3  # Move empty space down
            return True
        else:
            print("Invalid Move: Cannot move down")
            return False

    def move_left(self):
        """Move the empty space left (swap with the tile on the left)."""
        if self.empty_index % 3 != 0:  # Can move left only if not in the first column
            self.current_state[self.empty_index], self.current_state[self.empty_index - 1] = \
                self.current_state[self.empty_index - 1], self.current_state[self.empty_index]
            self.empty_index -= 1  # Move empty space left
            return True
        else:
            print("Invalid Move: Cannot move left")
            return False

    def move_right(self):
        """Move the empty space right (swap with the tile on the right)."""
        if self.empty_index % 3 != 2:  # Can move right only if not in the last column
            self.current_state[self.empty_index], self.current_state[self.empty_index + 1] = \
                self.current_state[self.empty_index + 1], self.current_state[self.empty_index]
            self.empty_index += 1  # Move empty space right
            return True
        else:
            print("Invalid Move: Cannot move right")
            return False

    def is_goal_state(self):
        """Check if the current state is the goal state."""
        if self.current_state == self.goal_state:
            print("🎉 Goal State Reached! 🎉")
            return True
        return False


# Example usage
initial_state = [2, 8, 1, 0, 4, 3, 7, 6, 5]
goal_state = [1, 2, 3, 8, 0, 4, 7, 6, 5]

p = Puzzle(initial_state, goal_state)
p.display()

# Apply moves
p.move_left()  # Valid move
p.display()

p.move_up()  # Valid move
p.display()

p.move_right()  # Valid move
p.display()

# Check goal state
if p.is_goal_state():
    print("✅ Puzzle Solved!")
else:
    print("❌ Not yet solved.")
