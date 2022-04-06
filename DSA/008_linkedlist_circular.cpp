#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory freed for node with value "<<value<<endl;
    }
};
void insertnode(node* &tail,int element,int d){
    //assuming that the element is in the list
    //if empty
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        //non empty list
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        //element found->curr is representing element wala node
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(node* &tail){
    node* temp=tail;
    //cant print single node with this logic so print it first then loop it or use do while here
    // cout<<tail->data<<" ";
    // while(tail!=temp){
    //     cout<<tail->data<<" ";
    //     tail=tail->next;
    // }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
void deletenode(node* &tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        //non-empty and assuming value is in the linked list
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;//prev kp aage bdhaya curr tk
            curr=curr->next;//curr ko ek aage badhaya
        }
        prev->next=curr->next;
        //to handle single node deletion in CLL
        if(curr==prev){
            tail=NULL;
        }
        //to handle 1st node deletion
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}
int main()
{
    node* tail=NULL;
    //insert 3 after 5
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,4);
    print(tail);
    // insertnode(tail,4,7);
    // print(tail);
    // insertnode(tail,4,5);
    // print(tail);
    // deletenode(tail,3);
    // print(tail);
    // deletenode(tail,7);
    // print(tail);
    deletenode(tail,3);
    print(tail);

return 0;
}