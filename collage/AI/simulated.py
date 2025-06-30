import random
import math

def evaluate_solution(solution):
    """Counts the number of satisfied clauses for a given (a, b, c, d) assignment."""
    a, b, c, d = solution
    clauses = [
        (not a or d),  # (¬a ∨ d)
        (c or b),      # (c ∨ b)
        (not c or not d),  # (¬c ∨ ¬d)
        (not d or not b),  # (¬d ∨ ¬b)
        (not a or not d)   # (¬a ∨ ¬d)
    ]
    return sum(clauses)  # Count satisfied clauses

# Simulated Annealing Parameters
temperature = 500  # Start with a high temperature
cooling_rate = 50  # Reduce temperature in each iteration
min_temperature = 1  # Stop when temperature is too low

# Initial solution (random assignment of a, b, c, d)
current_solution = [1,1,1,1]
current_fitness = evaluate_solution(current_solution)
variable_indices = [0, 1, 2, 3]  # Indices representing a, b, c, d
iteration = 0

# Simulated Annealing Loop
while temperature > min_temperature:
    iteration += 1

    # Generate a new solution by flipping a random variable
    new_solution = current_solution[:]
    var_to_flip = random.choice(variable_indices)
    new_solution[var_to_flip] = 1 - new_solution[var_to_flip]  # Flip 0 to 1 or 1 to 0

    # Evaluate new solution
    new_fitness = evaluate_solution(new_solution)

    # Decide whether to accept the new solution
    if new_fitness > current_fitness:
        accept = True  # Always accept a better solution
    else:
        # Compute acceptance probability
        prob = math.exp((new_fitness - current_fitness) / temperature)
        accept = prob > 0.5

    # Update solution if accepted
    if accept:
        current_solution = new_solution
        current_fitness = new_fitness

    # Cool down temperature
    temperature -= cooling_rate

# Print final results
print("Best Assignment (a, b, c, d):", current_solution)
print("Max Clauses Satisfied:", current_fitness)
print("Total Iterations:", iteration)
