# Assignment 4: Binary and Fibonacci Search

def binary_search(arr, target):
    """
    Performs an iterative Binary Search on a sorted array.

    Args:
        arr (list): A sorted list of numbers.
        target (int): The number to search for.

    Returns:
        int: The index of the target if found, otherwise -1.
    """
    low = 0
    high = len(arr) - 1
    
    print("\n--- Performing Binary Search ---")
    while low <= high:
        mid = (low + high) // 2
        print(f"Checking middle element at index {mid}: {arr[mid]}")

        if arr[mid] == target:
            print(f"Target {target} found!")
            return mid  # Target found
        elif arr[mid] < target:
            print(f"{arr[mid]} < {target}. Searching in the right half.")
            low = mid + 1  # Search in the right half
        else:
            print(f"{arr[mid]} > {target}. Searching in the left half.")
            high = mid - 1  # Search in the left half
            
    print(f"Target {target} not found in the list.")
    return -1  # Target not found

def fibonacci_search(arr, target):
    """
    Performs Fibonacci Search on a sorted array.

    Args:
        arr (list): A sorted list of numbers.
        target (int): The number to search for.

    Returns:
        int: The index of the target if found, otherwise -1.
    """
    n = len(arr)
    if n == 0:
        return -1

    # Initialize Fibonacci numbers
    fib_m_2 = 0  # (m-2)'th Fibonacci No.
    fib_m_1 = 1  # (m-1)'th Fibonacci No.
    fib_m = fib_m_1 + fib_m_2  # m'th Fibonacci

    # Find the smallest Fibonacci number greater than or equal to n
    while fib_m < n:
        fib_m_2 = fib_m_1
        fib_m_1 = fib_m
        fib_m = fib_m_1 + fib_m_2

    offset = -1
    
    print("\n--- Performing Fibonacci Search ---")
    # While there are elements to be inspected.
    # Note that we compare arr[i] with target. When fib_m becomes 1,
    # fib_m_2 becomes 0.
    while fib_m > 1:
        # Check if fib_m_2 is a valid location
        i = min(offset + fib_m_2, n - 1)
        print(f"Comparing with element at index {i}: {arr[i]}")

        # If target is greater than the value at index i,
        # cut the subarray from offset to i
        if arr[i] < target:
            print(f"{arr[i]} < {target}. Dropping the lower part of the array.")
            fib_m = fib_m_1
            fib_m_1 = fib_m_2
            fib_m_2 = fib_m - fib_m_1
            offset = i

        # If target is less than the value at index i,
        # cut the subarray after i+1
        elif arr[i] > target:
            print(f"{arr[i]} > {target}. Dropping the upper part of the array.")
            fib_m = fib_m_2
            fib_m_1 = fib_m_1 - fib_m_2
            fib_m_2 = fib_m - fib_m_1
            
        # Element found
        else:
            print(f"Target {target} found!")
            return i

    # Compare the last element with target
    if fib_m_1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    print(f"Target {target} not found in the list.")
    return -1 # Element not found

def get_roll_numbers():
    """Gets and validates a list of roll numbers from the user."""
    while True:
        try:
            user_input = input("Enter roll numbers of students who attended (space-separated): ")
            rolls = [int(num) for num in user_input.split()]
            if not rolls:
                print("Error: Please enter at least one roll number.")
                continue
            # IMPORTANT: The list must be sorted for these search algorithms
            rolls.sort()
            return rolls
        except ValueError:
            print("Invalid input. Please enter only integer roll numbers separated by spaces.")

def main():
    """Main function to run the program."""
    print("Assignment 4: Searching for Student Roll Numbers")
    
    attendee_rolls = get_roll_numbers()
    print("\nSorted list of attendees:", attendee_rolls)

    while True:
        try:
            roll_to_search = int(input("\nEnter the roll number to search for: "))
            break
        except ValueError:
            print("Invalid input. Please enter a valid integer roll number.")
            
    while True:
        print("\n" + "="*30)
        print("        SEARCH MENU")
        print("="*30)
        print("1. Search using Binary Search")
        print("2. Search using Fibonacci Search")
        print("3. Search for a different Roll Number")
        print("4. Exit")
        
        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            result_index = binary_search(attendee_rolls, roll_to_search)
            if result_index != -1:
                print(f"\nResult: Roll number {roll_to_search} attended the program. (Found at index {result_index})")
            else:
                print(f"\nResult: Roll number {roll_to_search} did NOT attend the program.")
        
        elif choice == '2':
            result_index = fibonacci_search(attendee_rolls, roll_to_search)
            if result_index != -1:
                print(f"\nResult: Roll number {roll_to_search} attended the program. (Found at index {result_index})")
            else:
                print(f"\nResult: Roll number {roll_to_search} did NOT attend the program.")
        
        elif choice == '3':
            while True:
                try:
                    roll_to_search = int(input("\nEnter the new roll number to search for: "))
                    break
                except ValueError:
                    print("Invalid input. Please enter a valid integer roll number.")

        elif choice == '4':
            print("Exiting program. Goodbye!")
            break
            
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")

# Run the main program
if __name__ == "__main__":
    main()