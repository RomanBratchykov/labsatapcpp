#include <iostream>

// Node structure
struct Node {
    int mark;
    Node* next;  
} *head = nullptr, *tail = nullptr;

void addFirst(int x){
    Node* newNode = new Node();
    newNode->mark = x;
    newNode->next = nullptr;
    head = newNode;
    tail = newNode;
} 
void addAtStart(int x){
        Node* newNode = new Node();
        newNode->mark = x;
        newNode->next = head;
        head = newNode;
}

void insertAtEnd(int x){
    Node* newNode = new Node();
    newNode->mark = x;
    newNode->next = nullptr;
    tail->next = newNode;
    tail = newNode;
}
void fillLinkedList(int size){
        addFirst(rand() % 100);

        for (int i = 0; i < size - 1; i++){
            insertAtEnd(rand() % 100);
        }
}

void insertAfterValue(int value, int x){
    Node* temp = head;
    while (temp != nullptr && temp->mark != value){
        temp = temp->next;
    }
    if (temp != nullptr){
        Node* newNode = new Node();
        newNode->mark = x;
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail){
            tail = newNode;
        }
    }
    else {
        std::cout << "Value not found\n";
    }
}
void showLinkedList(int size)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->mark << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}
void deleteAtEnd(){
    if (head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}
int main(){
    srand(time(0));
    // addFirst(1);
    // addAtStart(5);
    // addAtStart(10);
    // addAtStart(15);
    int n = 0, insert, value;
    std::cout << "Enter size of linked list: ";
    std::cin >> n;
    fillLinkedList(n);
    showLinkedList(n);
    deleteAtEnd();
    showLinkedList(n);
    return 0;
}