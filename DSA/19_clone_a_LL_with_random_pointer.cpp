#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* arb;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->arb=NULL;
    }
};
void insertAtHead(Node* &head,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        return;
    }
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node* head){
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &head,Node* &tail,int d){
    Node* newNode=new Node(d);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
Node* copyList(Node* head){//approach 2 
    //create a clone list
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    //step 2 create a map and set arb
    unordered_map<Node*,Node*> oldtoNewNode;
    Node* orgNode=head;
    Node* cloneNode=cloneHead;
    while(orgNode!=NULL&&cloneNode!=NULL){
        oldtoNewNode[orgNode]=cloneNode;
        orgNode=orgNode->next;
        cloneNode=cloneNode->next;
    }
    orgNode=head;cloneNode=cloneHead;
    while(orgNode!=NULL){
        cloneNode->arb=oldtoNewNode[orgNode->arb];
        orgNode=orgNode->next;
        cloneNode=cloneNode->next;
    }
    return cloneHead;
}
Node* approach3(Node* head){
    //step 1- create a clone list  //tc O(n) sc-O(1)
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    //step 2- cloneNodes add in between originalNodes //tc O(n) sc-O(1)
    Node* originalNode=head;
    Node* cloneNode=cloneHead;
    while(originalNode!=NULL&&cloneNode!=NULL){
        Node* next=originalNode->next;
        originalNode->next=cloneNode;
        originalNode=next;

        next=cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=next;
    }
    //step 3- random pointer copy karo clone me //tc O(n) sc-O(1)
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            // if(temp->arb!=NULL){
            //     temp->next->arb=temp->arb->next;//arb is random(arbitrary)
            // }
            // else{
            //     temp->next=temp->arb;
            // }
            //above code in ternary operator
            temp->next->arb=temp->arb?temp->arb->next:temp->arb;
        }
        temp=temp->next->next;
    }
    //step 4- revert changes from step 2 //tc O(n) sc-O(1)
    originalNode=head;
    cloneNode=cloneHead;
    while(originalNode!=NULL&&cloneNode!=NULL){
        originalNode->next=cloneNode->next;
        originalNode=originalNode->next;
        //niche wala 2 aage badha hai toh ho skta hai null point karde usko handle karo if condn se
        if(originalNode!=NULL)
            cloneNode->next=originalNode->next;

        cloneNode=cloneNode->next;
    }
    //return clone head
    return cloneHead;
}
int main()
{
    

return 0;
}