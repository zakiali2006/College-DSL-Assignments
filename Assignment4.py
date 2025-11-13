def selection_sort(arr):
    """
    Sorts an array of floating point numbers in ascending order using Selection Sort.
    """
    n = len(arr)
    # A copy is made to keep the original list intact.
    sorted_arr = arr[:]
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if sorted_arr[j] < sorted_arr[min_idx]:
                min_idx = j
        sorted_arr[i], sorted_arr[min_idx] = sorted_arr[min_idx], sorted_arr[i]
    return sorted_arr

def bubble_sort(arr):
    """
    Sorts an array of floating point numbers in ascending order using Bubble Sort.
    """
    n = len(arr)
    # A copy is made to keep the original list intact.
    sorted_arr = arr[:]
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if sorted_arr[j] > sorted_arr[j + 1]:
                sorted_arr[j], sorted_arr[j + 1] = sorted_arr[j + 1], sorted_arr[j]
                swapped = True
        if not swapped:
            break
    return sorted_arr

def display_top_five(arr):
    """
    Displays the top five scores from the array.
    Assumes the array is sorted in ascending order.
    """
    print("\nTop five scores:")
    if len(arr) >= 5:
        # Get the last 5 elements (the top scores) and reverse them for display
        top_scores = arr[-5:]
        print(top_scores[::-1])
    else:
        # If there are less than 5 scores, show all of them in descending order
        print(arr[::-1])

def main():
    """
    Main function to get student percentages and perform sorting.
    """
    percentages = []
    while True:
        try:
            num_students_str = input("Enter the number of students (or 'done' to finish input): ")
            if num_students_str.lower() == 'done':
                if not percentages:
                    print("No percentages entered. Exiting.")
                    return
                break
            
            num_students = int(num_students_str)
            for i in range(num_students):
                while True:
                    try:
                        perc = float(input(f"Enter percentage for student {i + 1}: "))
                        if 0 <= perc <= 100:
                            percentages.append(perc)
                            break
                        else:
                            print("Invalid percentage. Please enter a value between 0 and 100.")
                    except ValueError:
                        print("Invalid input. Please enter a number for the percentage.")
            break # Exit after getting percentages
        except ValueError:
            print("Invalid input. Please enter a valid number for the number of students.")

    while True:
        print("\nOriginal list of percentages:", percentages)
        print("\n--- Sorting Menu ---")
        print("1. Sort using Selection Sort")
        print("2. Sort using Bubble Sort")
        print("3. Exit")

        choice = input("Enter your choice (1-3): ")

        if choice == '1':
            print("\n--- Selection Sort ---")
            sorted_percentages = selection_sort(percentages)
            print("Percentages sorted in ascending order:", sorted_percentages)
            display_top_five(sorted_percentages)
        elif choice == '2':
            print("\n--- Bubble Sort ---")
            sorted_percentages = bubble_sort(percentages)
            print("Percentages sorted in ascending order:", sorted_percentages)
            display_top_five(sorted_percentages)
        elif choice == '3':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please enter 1, 2, or 3.")

if __name__ == "__main__":
    main()