#include <iostream> 
#include <string> 
using namespace std; 
const int MAX = 10; 
 
class JobQueue { 
private: 
    string jobs[MAX]; 
    int front, rear; 
 
public: 
    JobQueue() { 
        front = -1; 
        rear = -1; 
    } 
 
    bool isFull() { 
        return rear == MAX - 1; 
    } 
 
    bool isEmpty() { 
        return (front == -1 || front > rear); 
    } 
 
    void enqueue(const string &jobName) { 
        if (isFull()) { 
            cout << "Queue is full. Cannot add new job.\n"; 
            return; 
        } 
 
        if (front == -1) 
            front = 0; 
 
        rear++; 
        jobs[rear] = jobName; 
        cout << "Job \"" << jobName << "\" added to the queue.\n"; 
    } 
 
    void dequeue() { 
        if (isEmpty()) { 
            cout << "Queue is empty. No job to process.\n"; 
            return; 
        } 
 
        cout << "Processing job: " << jobs[front] << endl; 
        front++; 
 
        if (front > rear) { 
            front = rear = -1; 
        } 
    } 
 
    void display() { 
        if (isEmpty()) { 
            cout << "The job queue is empty.\n"; 
            return; 
        } 
 
        cout << "Current jobs in the queue:\n"; 
        for (int i = front; i <= rear; i++) { 
            cout << "- " << jobs[i] << endl; 
        } 
    } 
}; 
 
int main() { 
    JobQueue jq; 
    int choice; 
    string jobName; 
 
    cout << "\n--- Job Queue Menu ---\n"; 
    cout << "1. Add Job (Enqueue)\n"; 
    cout << "2. Delete Job (Dequeue)\n"; 
    cout << "3. Display Queue\n"; 
    cout << "4. Exit\n"; 
 
    while (true) { 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter job name: "; 
            cin.ignore(); 
            getline(cin, jobName); 
            jq.enqueue(jobName); 
            break; 
 
        case 2: 
            jq.dequeue(); 
            break; 
 
        case 3: 
            jq.display(); 
            break; 
 
        case 4: 
            cout << "Exiting program.\n"; 
            return 0; 
 
        default: 
            cout << "Invalid choice. Please try again.\n"; 
        } 
    } 
} 
