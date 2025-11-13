#include <iostream> 
using namespace std; 
 
const int MAX = 100; 
 
class CircularQueue { 
private: 
    int jobs[MAX]; 
    int front, rear; 
 
public: 
    CircularQueue() { 
        front = -1; 
        rear = -1; 
    } 
 
    bool isEmpty() { 
        return (front == -1); 
    } 
 
    bool isFull() { 
        return ((rear + 1) % MAX == front); 
    } 
 
    void enqueue(int jobId) { 
        if (isFull()) { 
            cout << "Queue Full" << jobId << endl; 
            return; 
        } 
 
        if (isEmpty()) { 
            front = 0; 
        } 
 
        rear = (rear + 1) % MAX; 
        jobs[rear] = jobId; 
        cout << "Job " << jobId << " added" << endl; 
    } 
 
    void dequeue() { 
        if (isEmpty()) { 
            cout << "Queue Empty" << endl; 
            return; 
        } 
 
        int jobId = jobs[front]; 
 
        if (front == rear) { 
            front = -1; 
            rear = -1; 
        } else { 
            front = (front + 1) % MAX; 
        } 
 
        cout << "Job " << jobId << " processed and  removed" << endl; 
    } 
 
    void jobAtFront() { 
        if (isEmpty()) { 
            cout << "Queue Empty" << endl; 
            return; 
        } 
        cout << "Front job is: " << jobs[front] << endl; 
    } 
 
    int jobCount() { 
        if (isEmpty()) return 0; 
        if (rear >= front) 
            return rear - front + 1; 
        else 
            return MAX - (front - rear - 1); 
    } 
 
    void showJobs() { 
        if (isEmpty()) { 
            cout << "Queue Empty" << endl; 
            return; 
        } 
 
        cout << "Jobs in queue: "; 
        int i = front; 
        while (true) { 
            cout << jobs[i] << " "; 
            if (i == rear) break; 
            i = (i + 1) % MAX; 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    CircularQueue Q; 
    int choice, jobId; 
 
    do { 
        cout << "\nPrinter Job Queue Menu" << endl; 
        cout << "1. Add Job\n"; 
        cout << "2. Process Job\n"; 
        cout << "3. Show Front Job\n"; 
        cout << "4. Show All Jobs\n"; 
        cout << "5. Check if Queue Empty\n"; 
        cout << "6. Check if Queue Full\n"; 
        cout << "7. Print Job Count\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter your choice: "; 
 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter job ID to add: "; cin >> jobId; 
    Q.enqueue(jobId); break; 
        case 2: Q.dequeue(); break; 
        case 3: Q.jobAtFront(); break; 
            break; 
        case 4: 
            Q.showJobs(); 
            break; 
        case 5: 
            cout << (Q.isEmpty() ? "Queue is empty." :  
"Queue is not empty.") << endl; 
            break; 
        case 6: 
            cout << (Q.isFull() ? "Queue is full." : 
 "Queue is not full.") << endl; 
            break; 
        case 7: cout << "Number of jobs in queue: " <<  
Q.jobCount() << endl; break; 
        case 8: 
            cout << "Exiting..." << endl; 
            break; 
        default: 
            cout << "Invalid choice" << endl; 
        } 
    } while (choice != 8); 
    return 0; 
} 
 
