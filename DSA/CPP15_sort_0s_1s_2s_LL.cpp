#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    // ~Node(){
    //     this->next=NULL;
    // }
};
Node* sortList(Node *head)
{
    int ZeroCount=0;
    int OneCount=0;
    int TwoCount=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0)ZeroCount++;
        else if(temp->data==1)OneCount++;
        else if(temp->data==2)TwoCount++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(ZeroCount!=0){
            temp->data=0;
            ZeroCount--;
        }
        else if(OneCount!=0){
            temp->data=1;
            OneCount--;
        }
        else if(TwoCount!=0){
            temp->data=2;
            TwoCount--;
        }
        temp=temp->next;
    }
    
    return head;

}
void insertAtHead(Node* &head,int d){
    if(head==NULL){Node* temp=new Node(d);}
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
    
}
void print(Node* head){
    if(head==NULL) return;
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
void insertAtTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}
Node* sortList2(Node* &head){
    Node* zeroHead=new Node(-1);Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);Node* twoTail=twoHead;
    Node* curr=head;
    //separate list of 0s 1s 2s
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertAtTail(zeroTail,curr);
        }
        else if(value==1){
            insertAtTail(oneTail,curr);
        }
        else if(value==2){
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }
    //merge these 3 list
    if(oneHead->next!=NULL){zeroTail->next=oneHead->next;}//1s is not empty
    else{zeroTail->next=twoHead->next;}//1s is empty
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zeroHead->next;
    delete oneHead;
    delete zeroHead;
    delete twoHead;
    // cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next->data<<" "<<head->next->next->next->next->data<<" "<<head->next->next->next->next->next->data<<" "<<head->next->next->next->next->next->next->data<<endl;
    return head;
}
int main()
{
    Node* node1=new Node(2);
    Node* head=node1;
    insertAtHead(head,0);insertAtHead(head,0);insertAtHead(head,1);insertAtHead(head,0);insertAtHead(head,1);insertAtHead(head,2);
    print(head);
    // sortList(head);
    sortList2(head);
    print(head);

return 0;
}