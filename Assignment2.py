def linear_search(arr, target):
    """
    Linear Search Algorithm
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Return index if found
    return -1  # Return -1 if not found

def sentinel_search(arr, target):
    """
    Sentinel Search Algorithm
    Time Complexity: O(n) but with fewer comparisons than linear search
    Space Complexity: O(1)
    """
    n = len(arr)
    if n == 0:
        return -1
    
    # Store the last element
    last = arr[n - 1]
    
    # Replace the last element with the target
    arr[n - 1] = target
    
    i = 0
    # Search for the target
    while arr[i] != target:
        i += 1
    
    # Restore the last element
    arr[n - 1] = last
    
    # Check if target was found
    if (i < n - 1) or (arr[n - 1] == target):
        return i
    else:
        return -1

def get_roll_numbers():
    """Get roll numbers from the user"""
    students = []
    print("Enter student roll numbers who attended training programs.")
    print("Enter -1 to stop entering roll numbers.")
    
    while True:
        try:
            roll = int(input("Enter roll number: "))
            if roll == -1:
                break
            elif roll < 0:
                print("Please enter a positive roll number!")
            elif roll in students:
                print(f"Roll number {roll} is already in the list!")
            else:
                students.append(roll)
                print(f"Roll number {roll} added successfully!")
        except ValueError:
            print("Please enter a valid integer roll number!")
    
    return students

def display_students(arr):
    """Display all student roll numbers"""
    if len(arr) == 0:
        print("No students have attended training programs yet.")
        return
    
    print("\nStudents who attended training programs:")
    for i, roll in enumerate(arr):
        print(f"  {i+1}. Roll Number: {roll}")

def search_student(students):
    """Search for a student using both algorithms"""
    if len(students) == 0:
        print("No students in the list. Please add some students first.")
        return
    
    try:
        target = int(input("Enter roll number to search: "))
        
        print("\n" + "="*50)
        print("SEARCH RESULTS:")
        print("="*50)
        
        # Linear Search
        print("\n1. LINEAR SEARCH:")
        result_linear = linear_search(students, target)
        if result_linear != -1:
            print(f"   Student with roll number {target} attended the training program!")
            print(f"   Found at position {result_linear + 1} in the list.")
        else:
            print(f"   Student with roll number {target} did NOT attend the training program.")
        
        # Sentinel Search
        print("\n2. SENTINEL SEARCH:")
        students_copy = students.copy()
        result_sentinel = sentinel_search(students_copy, target)
        if result_sentinel != -1:
            print(f"   ✓ Student with roll number {target} attended the training program!")
            print(f"   ✓ Found at position {result_sentinel + 1} in the list.")
        else:
            print(f"   ✗ Student with roll number {target} did NOT attend the training program.")
            
        # Comparison
        print("\n3. COMPARISON:")
        if result_linear == result_sentinel:
            print("   ✓ Both algorithms found the same result!")
        else:
            print("   ✗ Algorithms found different results (this shouldn't happen)")
            
    except ValueError:
        print("Please enter a valid integer roll number!")

def main():
    print("=== Student Training Program Attendance System ===")
    print("This program stores roll numbers of students who attended training programs")
    print("and provides search functionality using Linear and Sentinel search algorithms.\n")
    
    # Get roll numbers from user
    students = get_roll_numbers()
    
    if len(students) == 0:
        print("No students were added. Exiting program.")
        return
    
    # Display the entered roll numbers
    display_students(students)
    
    print(f"\nTotal students who attended: {len(students)}")
    
    # Menu for searching
    while True:
        print("\n" + "="*50)
        print("MENU:")
        print("1. Search for a student")
        print("2. Display all students")
        print("3. Exit")
        
        choice = input("\nEnter your choice (1-3): ")
        
        if choice == '1':
            search_student(students)
        elif choice == '2':
            display_students(students)
        elif choice == '3':
            print("Thank you for using the Student Training Program System!")
            break
        else:
            print("Invalid choice! Please enter 1, 2, or 3.")

if __name__ == "__main__":
    main()