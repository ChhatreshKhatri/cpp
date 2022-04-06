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
Node* solve(Node* first,Node* second){
    //if only one element in the LLs
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;
    while(next1!=NULL&&curr2!=NULL){
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
            //second ki node ko beech me insert karao first LL me
            curr1->next=curr2;
            next2=curr2->next;//to not to loose the second LL
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }
        else{
            // curr1 and next1 ko aage badhao,go ahead in first list
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){//agar first ke aage list null hai toh second ko point karado
                curr1->next=curr2;
                return first;
            }            
        }
    }
    return first;
}
Node* sortTwoLists(Node* first, Node* second)
{
    if(first==NULL)return second;
    if(second==NULL)return first;
    if(first->data<=second->data){//pehla element jiska bada usko bhejo pehle
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
//     return first;
}
int main()
{
    Node* head=NULL;
    insertAtHead(head,10);insertAtHead(head,8);insertAtHead(head,4);insertAtHead(head,3);insertAtHead(head,1);insertAtHead(head,0);
    print(head);
    Node* head2=NULL;
    insertAtHead(head2,9);insertAtHead(head2,7);insertAtHead(head2,6);insertAtHead(head2,5);insertAtHead(head2,2);
    print(head2);
    
    print(sortTwoLists(head,head2));
return 0;
}