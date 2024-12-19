#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};
void  insertHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void printll(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;//move  to next node
    }
    cout<<endl;
}
void insertTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertPos(Node* &head,int d,int pos){
    Node* temp=head;//piont to head node
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    Node* nodeinsert=new Node(d);
    nodeinsert->next=temp->next;
    temp->next=nodeinsert;
}
int main()
{
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    Node* head=node1;
    Node* tail=node1;
    printll(head);
    insertTail(tail,12);
    printll(head);
    insertTail(tail,34);
    printll(head);
    insertPos(head,45,2);
    insertPos(head,56,3);
    printll(head);

    return 0;
}
