#include <iostream>
#include <string>

using namespace std;

// Node Class
class Node {
public:
  string data;
  Node *next;

  Node(string value) {
    data = value;
    next = nullptr;
  }
};

// HospitalQueue Class
class HospitalQueue {
private:
  Node *front;
  Node *back;

public:
  HospitalQueue() {
    front = nullptr;
    back = nullptr;
  }

  // Boolean function to check if the queue is empty
  bool isEmpty() { return front == nullptr; }

  // Function to add a patient to the queue
  void enqueue(string value) {
    Node *AddedNode = new Node(value);
    if (isEmpty()) {
      front = back = AddedNode;
    } else {
      back->next = AddedNode;
      back = AddedNode;
    }
    cout << "Next In Line: Added " << value << endl;
  }

  // Function to remove a patient from the back of the queue
  void dequeue() {
    if (isEmpty()) {
      cout << "No Patients In Line..." << endl;
    } else {
      Node *temp = front;
      front = front->next;
      cout << "Removed Patient: " << temp->data << endl;
      delete temp;
      if (front == nullptr) {
        back = nullptr;
      }
    }
  }

  // Function to display the patient at the front of the queue
  string peek() {
    if (!isEmpty()) {
      return front->data;
    } else {
      cout << "No Patients In Line..." << endl;
      return "";
    }
  }

  // Function to display all patients in the queue
  void display() {
    if (isEmpty()) {
      cout << "No Patients In Line..." << endl;
      return;
    }
    cout << "Current Patients:" << endl;
    Node *temp = front;
    while (temp != nullptr) {
      cout << temp->data << endl;
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  HospitalQueue patientQueue;
  char choice;
  char actionChoice;
  string patientName;
  string queueActions[] = {"Add New Patient", "Check Status", "Display Queue",
                           "Remove Latest Patient",
                           "Exit"}; // Array of queue actions

  cout << "\n*-=-*-=-*-=-*-=-*-=-*-=-*" << endl;
  cout << "|    HOSPITAL QUEUE!    |" << endl;
  cout << "*-=-*-=-*-=-*-=-*-=-*-=-*" << endl;

  cout << endl;
  patientQueue.enqueue("Walter White");
  patientQueue.enqueue("Jesse Pinkman");
  patientQueue.enqueue("Mike Ehrmantraut");

  cout << endl;
  patientQueue.display();

  // Main loop for demonstrating the example queue of the program
  for (int i = 0; i < 3; i++) {
    cout << "Currently Serving: " << patientQueue.peek() << endl;
    cout << endl;
    patientQueue.dequeue();
    cout << endl;
    patientQueue.display();
  }

  cout << "\n*=-*-=-*-=-*-=-*-=-*-=*" << endl;
  cout << "|    MODIFY QUEUE?    |" << endl;
  cout << "*=-*-=-*-=-*-=-*-=-*-=*" << endl;

  // Loop to allow the user to modify the queue
  do {
    cout << "\n'Y' to modify queue, 'N' to exit: ";
    cin >> choice;
    choice = toupper(choice);
    if (choice != 'Y' && choice != 'N') {
      cout << "\nError! Input not recognized. Try again." << endl;
    }
  } while (choice != 'Y' && choice != 'N');

  if (choice == 'N') {
    cout << "\nThank you for using the program!" << endl;
  } else {
    cout << endl;
    int actionCounter = 1;
    for (const string &action : queueActions) {
      cout << actionCounter << ". " << action << endl;
      actionCounter++;
    }
    do {
      do {
        cout << "\nChoice: ";
        cin >> actionChoice;
        if (actionChoice < '1' || actionChoice > '5') {
          cout << "\nError! Action not recognized. Try again." << endl;
        }
      } while (actionChoice < '1' || actionChoice > '5');

      // Switch statement to handle the user's choice
      switch (actionChoice) {
      case '1':
        cout << "\nEnter Patient Name: ";
        getline(cin >> ws, patientName);
        cout << endl;
        patientQueue.enqueue(patientName);
        break;
      case '2':
        cout << endl;
        cout << "Currently Serving: " << patientQueue.peek() << endl;
        break;
      case '3':
        cout << endl;
        patientQueue.display();
        break;
      case '4':
        cout << endl;
        patientQueue.dequeue();
        break;
      case '5':
        cout << "\nThank you for using the program!" << endl;
        break;
      default:
        cout << "\nThank you for using the program!" << endl;
        break;
      }
    } while (actionChoice != '5');
  }

  return 0;
}

/*

Program Description:
- Overall, automated systems heavily utilize queues in the real world to keep
track of various things, especially customers in business-related matters.
- This program emulates a very basic interpretation of a hospital queue used for
keeping patients in line.
- There are 5 main functions included in the class "HospitalQueue," which
represents the inner workings of how the queue operates via the C++ stack. These
functions are: enqueue, dequeue, peek, display, and isEmpty.
- Enqueue adds a new patient to the front of the stack list.
- Dequeue removes the patient at the back of the list (because they're the first
to go in order once they've been checked out).
- Peek checks the current status of the queue and the current patient.
- Display displays the current patients in the queue.
- isEmpty checks if the queue is empty, which determines if the program will
take action or not.
- Only names (as strings) are available in the current program when it comes to
inputting values.
- Finally, the do-whiles and for loops automate certain processes that involve
functions or act as contingencies for any user misinput.

*/
