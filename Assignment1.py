def get_marks():
    marks = []
    n = int(input("Enter the number of students: "))
    print("Enter marks for each student (use -1 for absent students):")
    for i in range(n):
        mark = int(input("Student " + str(i+1) + ": "))
        marks.append(mark)
    return marks
def average_score(marks):
    total = 0
    count = 0
    for mark in marks:
        if mark != -1:
            total += mark
            count += 1
    if count == 0:
        return 0
    return total / count
def highest_lowest_score(marks):
    highest = -1
    lowest = 101  # assuming marks out of 100
    for mark in marks:
        if mark != -1:
            if mark > highest:
                highest = mark
            if mark < lowest:
                lowest = mark
    if highest == -1:
        return None, None
    return highest, lowest
def count_absent_students(marks):
    count = 0
    for mark in marks:
        if mark == -1:
            count += 1
    return count
def mark_with_highest_frequency(marks):
    frequency = {}
    for mark in marks:
        if mark != -1:
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1
    max_freq = 0
    most_frequent_mark = None
    for mark in frequency:
        if frequency[mark] > max_freq:
            max_freq = frequency[mark]
            most_frequent_mark = mark
    return most_frequent_mark, max_freq




# Main program
marks = get_marks()

print("\nResults:")
print("1. Average score of class:", average_score(marks))

high, low = highest_lowest_score(marks)
if high is None:
    print("2. No students were present.")
else:
    print("2. Highest score:", high)
    print("   Lowest score:", low)

print("3. Number of absent students:", count_absent_students(marks))

freq_mark, freq_count = mark_with_highest_frequency(marks)
print(f"4. Mark with highest frequency: {freq_mark} (appeared {freq_count} times)")

