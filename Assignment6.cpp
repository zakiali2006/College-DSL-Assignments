#include <iostream>
#include <string>

// The Node structure represents a single member in the club.
struct Node {
    int prn;
    std::string name;
    Node* next;

    // Constructor for easy initialization
    Node(int p, std::string n) : prn(p), name(n), next(nullptr) {}
};

// The PinnacleClub class manages the entire linked list of members.
class PinnacleClub {
private:
    Node* head; // Points to the first member (President)

public:
    // Constructor: Initializes an empty club
    PinnacleClub() : head(nullptr) {}

    // Destructor: Cleans up memory by deleting all nodes
    ~PinnacleClub() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // --- 1. Add and Delete Members ---

    // Adds a member at the beginning (as the new President)
    void addPresident(int prn, const std::string& name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
        std::cout << "✅ New President added successfully." << std::endl;
    }

    // Adds a member at the end (as the new Secretary)
    void addSecretary(int prn, const std::string& name) {
        Node* newNode = new Node(prn, name);
        if (head == nullptr) {
            head = newNode; // If list is empty, this is the first member
            std::cout << "✅ First member (President/Secretary) added successfully." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        std::cout << "✅ New Secretary added successfully." << std::endl;
    }
    
    // Deletes a member by their PRN
    void deleteMember(int prn) {
        if (head == nullptr) {
            std::cout << "❌ Club is empty. Cannot delete." << std::endl;
            return;
        }

        // Case 1: Deleting the President
        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "✅ President has been deleted." << std::endl;
            return;
        }

        // Case 2: Deleting a general member or the Secretary
        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr && current->prn != prn) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "❌ Member with PRN " << prn << " not found." << std::endl;
            return;
        }

        prev->next = current->next;
        delete current;
        std::cout << "✅ Member with PRN " << prn << " has been deleted." << std::endl;
    }

    // --- 2. Compute Total Members ---

    int computeTotal() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // --- 3. Display Members ---

    void displayMembers() const {
        if (head == nullptr) {
            std::cout << "The club has no members." << std::endl;
            return;
        }

        std::cout << "\n--- Pinnacle Club Roster ---\n";
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "PRN: " << temp->prn << ", Name: " << temp->name;
            if (temp == head) {
                std::cout << " (President)";
            }
            if (temp->next == nullptr) {
                std::cout << " (Secretary)";
            }
            std::cout << std::endl;
            temp = temp->next;
        }
        std::cout << "---------------------------\n";
    }

    // --- 4. Concatenate Two Lists ---

    void concatenate(PinnacleClub& otherClub) {
        if (otherClub.head == nullptr) {
            std::cout << "ℹ️ The other list is empty, nothing to concatenate." << std::endl;
            return;
        }

        if (head == nullptr) {
            head = otherClub.head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = otherClub.head;
        }

        // Crucial step: Prevent the other list's destructor from deleting the nodes
        otherClub.head = nullptr;
        std::cout << "✅ Lists concatenated successfully." << std::endl;
    }
};

// Main function to drive the program
int main() {
    PinnacleClub divA, divB;
    int choice, prn;
    std::string name;

    // Pre-populate with some data for easier testing
    divA.addPresident(101, "Alice");
    divA.addSecretary(102, "Bob");
    divB.addPresident(201, "Charlie");
    divB.addSecretary(202, "Diana");

    do {
        std::cout << "\n========= Pinnacle Club Menu =========\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Delete Member\n";
        std::cout << "3. Display Members\n";
        std::cout << "4. Compute Total Members\n";
        std::cout << "5. Concatenate Division B to Division A\n";
        std::cout << "0. Exit\n";
        std::cout << "====================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int divChoice;
        if (choice >= 1 && choice <= 4) {
            std::cout << "Select Division (1 for A, 2 for B): ";
            std::cin >> divChoice;
        }

        switch (choice) {
            case 1: {
                int roleChoice;
                std::cout << "Enter PRN: ";
                std::cin >> prn;
                std::cout << "Enter Name: ";
                std::cin.ignore(); // To consume the newline character left by cin
                std::getline(std::cin, name);
                
                std::cout << "Select Role (1 for President, 2 for Secretary): ";
                std::cin >> roleChoice;

                PinnacleClub& targetDiv = (divChoice == 1) ? divA : divB;
                if (roleChoice == 1) {
                    targetDiv.addPresident(prn, name);
                } else {
                    targetDiv.addSecretary(prn, name);
                }
                break;
            }
            case 2: {
                std::cout << "Enter PRN to delete: ";
                std::cin >> prn;
                if (divChoice == 1) divA.deleteMember(prn);
                else divB.deleteMember(prn);
                break;
            }
            case 3: {
                if (divChoice == 1) {
                    std::cout << "\n--- Division A ---";
                    divA.displayMembers();
                } else {
                    std::cout << "\n--- Division B ---";
                    divB.displayMembers();
                }
                break;
            }
            case 4: {
                int total = (divChoice == 1) ? divA.computeTotal() : divB.computeTotal();
                std::cout << "Total members in Division " << ((divChoice == 1) ? "A" : "B") << ": " << total << std::endl;
                break;
            }
            case 5: {
                divA.concatenate(divB);
                std::cout << "Division A now contains all members. Division B is empty." << std::endl;
                break;
            }
            case 0: {
                std::cout << "Exiting program. Goodbye! 👋\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}