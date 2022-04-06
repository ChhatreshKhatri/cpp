#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;
    //constructor
    node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory for node freed with value "<<val<<endl;
    }
};
void insertathead(node* &head,node* &tail,int d){
    if(head==NULL){
        //empty list
        node* temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
    node* temp=new node(d);
    // temp->prev=NULL; alredy done in node class
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
void insertattail(node* &head,node* &tail,int d){
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{
    node* temp=new node(d);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
    }
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(node* head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertatposition(node* &head,node* &tail,int position,int d){
    //empty list
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
    if(position==1){
        insertathead(head,tail,d);
        return;
    }
    int cnt=1;
    node* temp=head;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
    }    

}
void deletion(int positon,node* &head,node* &tail){
    if(positon==1){
        node* temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<positon){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    tail=prev;
    }
}
int main()
{
    // node* node1=new node(5);
    // node* head=node1;
    // node* tail=node1;
    node* head=NULL;
    node* tail=NULL;
    
    print(head);
    // cout<<"length: " <<getlength(head)<<endl;

    insertathead(head,tail,4);
    print(head);
    // cout<<"length: " <<getlength(head)<<endl;
    insertathead(head,tail,3);
    print(head);

    insertattail(head,tail,6);
    print(head);
    insertattail(head,tail,7);
    print(head);

    insertatposition(head,tail,1,2);
    print(head);

    insertatposition(head,tail,6,8);
    print(head);

    insertatposition(head,tail,4,5);
    print(head);

    deletion(1,head,tail);
    print(head);

    deletion(3,head,tail);
    print(head);

    deletion(5,head,tail);
    print(head);
    cout<<"head= "<<head->data<<" tail= "<<tail->data<<endl;
    cout<<"length: " <<getlength(head)<<endl;

return 0;
}