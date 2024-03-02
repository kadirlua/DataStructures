#include <iostream>

// Making a node struct containing any data and a pointer
// to next node
template <typename T>
struct Node { 
  T data;
  Node *next{};

  // Parameterised constructor with default argument
  Node(T val = T{}):
    data{ std::move(val) }
  {
  }

  // Parameterise constructor
  Node(T val, Node *tempNext):
    data{ std::move(val) },
    next{ tempNext }
  {
  }
};

template <typename T>
class LinkedList
{
  public:
    // default constructor. Initializing head pointer
    LinkedList() = default;

    // inserting elements (At start of the list)
    void insert(T&& val)
    {
      // make a new node
      Node<T>* newNode = new Node<T>(std::forward<T>(val));
      // If list is empty, make the new node, the head
      if (head == nullptr) {
        head = newNode;
      } else {
        // else, make the newNode the head and its next, the previous head
        newNode->next = head;
        head = newNode;
      }
    }

    // loop over the list. return true if element found
    bool search(T val)
    {
      Node<T>* temp = head;
      while (temp != nullptr) {
        if (temp->data == val) {
          return true;
        }
        temp = temp->next;
      }
      return false;
    }

    
    void remove(T val)
    {
      Node<T>* temp = head;
      // If the head is to be deleted
      if (temp != nullptr && temp->data == val) {
        head = temp->next;
        delete temp;
      } else {
        // Else loop over the list and search for the node to delete
        Node<T>* curr = head;
        while (temp != nullptr && temp->data != val) {
          // When node is found, delete the node and modify the pointers
          curr = temp;
          temp = temp->next;  
        }
        // If values is not found in the linked list
        if (temp == nullptr) {
           std::cout << "Value not found\n";
           return;
        }

        curr->next = temp->next;
        delete temp;
      }  
    }

    void display()
    {
      Node<T>* temp = head;
      while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
      }
      std::cout << "\r\n";
    }

private:
  // Head pointer
  Node<T>* head{};
};

int main() {
  LinkedList<int> l;
  // inserting elements
  l.insert(6);
  l.insert(9);
  l.insert(1);
  l.insert(3);
  l.insert(7);
  std::cout << "Current Linked List: ";
  l.display();

  std::cout << "Deleting 1: ";
  l.remove(1);
  l.display();

  std::cout << "Deleting 13: ";
  l.remove(13);

  std::cout << "Searching for 7: ";
  std::cout << l.search(7) << "\n";

  std::cout << "Searching for 13: ";
  std::cout << l.search(13) << "\n";
}