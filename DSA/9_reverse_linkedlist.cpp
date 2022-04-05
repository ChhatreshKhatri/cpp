#include<bits/stdc++.h>
using namespace std;
template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
//iterative approach-1
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
//recrsive approach-2
void reverse1(LinkedListNode<int>* &head,LinkedListNode<int>* curr,LinkedListNode<int>* prev){
    //base case
    if(curr==NULL){
        head=prev;
        return;
    }
    LinkedListNode<int>* forward=curr->next;
    reverse1(head,forward,curr);
    curr->next=prev;


}
//approach 3 (recursive) chhota code
LinkedListNode<int>* reverse2(LinkedListNode<int>* head){
    //base case
    if(head==NULL||head->next==NULL){
        return head;
        }
    LinkedListNode<int>* chhotahead=reverse2(head->next);//pehla node chhod ke baaki nodes ki list is chhoti linked list and uska chhotahead reverse ke baad
    head->next->next=head;//second node ka next point karega pehli node ko
    head->next=NULL;//pehli node point karegi NULL ko reverse ke baad
    return chhotahead;
}
int main()
{
    LinkedListNode<int>* head=NULL;
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    reverse1(head,curr,prev);
    // return head;

return 0;
}