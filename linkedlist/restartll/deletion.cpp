#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void printll(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertPos(Node*& head, int d, int pos) {
    Node* temp = head; // Point to head node
    int cnt = 1;
    while (cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }
    Node* nodeinsert = new Node(d);
    nodeinsert->next = temp->next;
    temp->next = nodeinsert;
}

int countNode(Node*& head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteNode(Node*& head, Node*& tail, int pos) {
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < pos) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL) {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    printll(head);

    insertTail(tail, 12);
    printll(head);

    insertTail(tail, 34);
    printll(head);

    insertPos(head, 45, 2);
    insertPos(head, 56, 3);
    printll(head);

    deleteNode(head, tail, 1);
    deleteNode(head, tail, 4);
    printll(head);

    if (head != NULL)
        cout << "Head value: " << head->data << endl;
    if (tail != NULL)
        cout << "Tail value: " << tail->data << endl;

    return 0;
}
