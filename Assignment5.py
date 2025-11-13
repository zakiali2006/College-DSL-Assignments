def quicksort(arr):
    """
    Sorts an array of floating point numbers in ascending order using Quick Sort.
    """
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

def display_top_five(arr):
    """
    Displays the top five scores from the array.
    Assumes the array is sorted in ascending order.
    """
    print("\nTop five scores:")
    if len(arr) >= 5:
        # Get the last 5 elements (the top scores) and reverse them for display
        top_scores = arr[-5:]
        for i, score in enumerate(top_scores[::-1], 1):
            print(f"{i}. {score}%")
    else:
        # If there are less than 5 scores, show all of them in descending order
        for i, score in enumerate(arr[::-1], 1):
            print(f"{i}. {score}%")

def main():
    """
    Main function to get student percentages and perform sorting.
    """
    percentages = []
    
    print("Assignment 5: Student Percentage Management using Quick Sort")
    print("This program stores first year student percentages and sorts them using Quick Sort.")
    
    # Get student percentages
    while True:
        try:
            num_students = int(input("\nEnter the number of students: "))
            if num_students <= 0:
                print("Please enter a positive number of students.")
                continue
            break
        except ValueError:
            print("Invalid input. Please enter a valid number.")
    
    print(f"\nEnter percentages for {num_students} students:")
    for i in range(num_students):
        while True:
            try:
                perc = float(input(f"Student {i + 1}: "))
                if 0 <= perc <= 100:
                    percentages.append(perc)
                    break
                else:
                    print("Invalid percentage. Please enter a value between 0 and 100.")
            except ValueError:
                print("Invalid input. Please enter a number for the percentage.")
    
    print(f"\nOriginal list of percentages: {percentages}")
    
    # Menu for sorting
    while True:
        print("\n" + "="*40)
        print("           SORTING MENU")
        print("="*40)
        print("1. Sort using Quick Sort")
        print("2. Display Top Five Scores")
        print("3. Exit")
        
        choice = input("\nEnter your choice (1-3): ")
        
        if choice == '1':
            print("\n--- Quick Sort ---")
            sorted_percentages = quicksort(percentages)
            print("Percentages sorted in ascending order:", sorted_percentages)
            display_top_five(sorted_percentages)
            
        elif choice == '2':
            if not percentages:
                print("No percentages to display.")
            else:
                sorted_percentages = quicksort(percentages)
                display_top_five(sorted_percentages)
                
        elif choice == '3':
            print("Exiting program. Goodbye!")
            break
            
        else:
            print("Invalid choice. Please enter 1, 2, or 3.")

if __name__ == "__main__":
    main()