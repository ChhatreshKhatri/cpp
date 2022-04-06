#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    ~node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};
//insertion at head
void insertathead(node* &head,int d){
    //new node creation at front
    node* temp=new node(d);
    temp->next=head;
    head=temp;

}
//insertion at tail
void insertattail(node* &tail,int d){
    //new node creation at end
    node* temp=new node(d);
    tail->next=temp;
    // tail=tail->next; or
    tail=temp;
}
//insert at mid/position
void insertatposition(node* &tail,node* &head,int position,int d){
    //to insert at 1st position
    if(position==1){
        insertathead(head,d);
        return;        
    }
    //to insert at tail   -> cant use it here to handle last position insertion
    // if(len==position-1){
    //     insertattail(tail,d);
    //     return;
    // }

    //point to the position to insert new node
     node* temp=head;
     int cnt=1;
     while(cnt<position-1){
         temp=temp->next;
         cnt++;
     }
     //to handle the case to add at tail
     if(temp->next==NULL){
         insertattail(tail,d);
         return;
     }
     //creating a node for d
     node* nodetoinsert=new node(d);
     nodetoinsert->next=temp->next;
     temp->next=nodetoinsert;
} 
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//delete node 
void deletenode(int position,node* &head,node* &tail){
        //deletiong first or start node
    if(position==1){
        node* temp=head;
        head=head->next;
        //remove next of thenode to be removed
        temp->next=NULL;
        //memory free for start node
        delete temp;
    }
    else{
        //deleting any middle or last node
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        //to handle tail for the last node
        if(curr->next==NULL){
            tail->next=prev->next;
            tail=prev;
        }
    }
}
int main()
{
    //new node created
 node* node1=new node(5);
//  cout<<node1->data<<endl;
//  cout<<node1->next<<endl;
 //head pointer to new node
    node* head=node1;
    node* tail=node1;
    print(head);

    insertathead(head,0);
    print(head);

    insertattail(tail,15);
    print(head);

    insertattail(tail,20);
    print(head);

    insertatposition(tail,head,3,10); 
    print(head);

    //insert at head from insertatposition 
    insertatposition(tail,head,1,-5);
    print(head);

    //insert at tail from insertatposition funtion
    insertatposition(tail,head,7,30);
    print(head);
    cout<<endl;

    deletenode(1,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deletenode(4,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deletenode(5,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deletenode(4,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
return 0;
}