import random
import matplotlib.pyplot as plt

# Function to generate random virtual addresses
def generate_virtual_address():
    return random.randint(0, address_space_size - 1)

# Function to check if a virtual address is valid based on the bounds register
def is_valid_address(address, bounds):
    return address < bounds

# Function to simulate the experiment for a given bounds register value
def simulate(bounds):
    valid_count = 0
    total_count = 10000  # Number of random addresses to generate for each simulation
    for _ in range(total_count):
        virtual_address = generate_virtual_address()
        if is_valid_address(virtual_address, bounds):
            valid_count += 1
    return valid_count / total_count

# Define the maximum size of the address space
address_space_size = 1000000  # Change this to the maximum size of your address space

# Generate data for different values of the bounds register
bounds_values = range(0, address_space_size, address_space_size // 20)  # Adjust the step size as needed
valid_fractions = [simulate(bounds) for bounds in bounds_values]

# Plot the graph
plt.plot(bounds_values, valid_fractions)
plt.xlabel('Bounds Register Value')
plt.ylabel('Fraction of Valid Addresses')
plt.title('Q5')
plt.grid(True)
plt.show()
