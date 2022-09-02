#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
node*reverseLinkedList(node *head) 
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
void print(node* ans){
    if(ans==NULL)return;
     while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }

}

int main(){
    node* head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    node* ans=head;
    print(ans);
    cout<<endl;
    ans=reverseLinkedList(head);
    print(ans);

    return 0;
}