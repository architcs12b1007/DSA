#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // ~Node(){
    //     int value=this->data;

    //     // memory free
    //     if(this->next!=NULL){
    //         delete next;
    //         this->next=NULL;
    //     }
    //     cout<<"Memory is free for node with data "<<value<<endl;
    // }
};

void insertAtHead(Node* &head, int data){ // so that copy of head is not created & passed it by reference.
    
    Node* temp=new Node(data);
    temp->next=head;
    head=temp; // head changes its pointing location, so needs to pass by reference 
    return;

}


void insertAtTail(Node* &tail, int data){

    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        return;
    }
    Node* newNode=new Node(data);

    tail->next=newNode;
    tail=newNode;
    return;

}

// pos refers to postion:
void insertAtPosition(Node* &head,Node* &tail, int data, int pos){
    if(pos==1){
        insertAtHead(head,data);
        return;
    }

    Node *curr=head;
    int count=1;
    while(count < pos-1){
        count++;
        curr=curr->next;
    }
    
    if(curr->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    
    Node* temp=new Node(data);
    temp->next=curr->next;
    curr->next=temp;
    return;

}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

// can also delte node on the basis of value instead of position
// Assuming pos is always below or equal to the length of Linked Lists
void deleteNode(Node* &head, int pos){
    // delete first node
    if(pos==1){
        Node* temp=head;
        if(head->next){
            head=head->next;
        }
        else{
            head=NULL;
        }
       // temp->next=NULL;
        delete temp;
        return;
    }
    // delete middle or last node
    int count=1;
    Node* temp=head; // can also do by taking prev=NULL, curr=head & then do while loop
    while(count<pos-1){
        temp=temp->next;   
        count++; 
    }
    Node* curr=temp->next; 
    temp->next=curr->next;

   // curr->next=NULL;
    delete curr;
}
int main(){

    Node* newNode=new Node(100);
    Node* head=newNode;
    Node* tail=newNode;
    

    // insertAtHead(head,10);
    // insertAtHead(head,20);
    // insertAtHead(head,30);
    // insertAtHead(head,40);
    // insertAtHead(head,50);

    insertAtTail(tail,101);
    insertAtTail(tail,201);
    insertAtTail(tail,301);
    insertAtTail(tail,401);
    insertAtTail(tail,501);

    

    insertAtPosition(head,tail,100,3);
    insertAtPosition(head,tail,200,1);
    insertAtPosition(head,tail,300,9);


    print(head);

    deleteNode(head,3);
    print(head);

    deleteNode(head,1);
    print(head);

    return 0;
}

// Linked List: Linear Data structure that is a collection of nodes (Node contain data & address of next node)

// Why Linked Lists?

// array size is fixed, cannot change at run time
// vector<int> a[5], if more size needed, new more storage allocates and values copy from original vector (dynamic array), so it is not a optimal case

//Advantages: Dynamic DS that grows/shrinks at runtime, so no memory wastage.
// Insertion & deletion is easy, no need to shift entire data to maintain order unlike arrays.

// Types: 1)Singly LL 2)Doubly LL 3) Circular LL