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
Node* reverse1(Node* head) {        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
}
Node* addfunc(Node* first,Node* second){
    int carry=0;
    Node* ansHead=NULL;
    while(first!=NULL&&second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
        // cout<<"digit "<<digit<<endl;
        // Node* temp=new Node(digit);
        //create node of digit and insert in ans LL
        insertAtHead(ansHead,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;
        insertAtHead(ansHead,digit);
        carry=sum/10;
        first=first->next;
    }
    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;
        insertAtHead(ansHead,digit);
        carry=sum/10;
        second=second->next;
    }
    //end me agar caary bach gyi usko handle karo ab
    while(carry!=0){       
        int digit=carry;
        insertAtHead(ansHead,digit);
        carry=digit/10;
    }
    // ansHead=reverse1(ansHead); insertattail me karna padega
    return ansHead;
}
//upar wali ramayan ko sudharo while loops handle karo ache se
Node* addfunc2(Node* first,Node* second){
    int carry=0;
    Node* ansHead=NULL;
    while(first!=NULL||second!=NULL||carry!=0){
        int val1=0;
        if(first!=NULL)
            val1=first->data;
        
        int val2=0;
        if(second!=NULL)
            val2=second->data;
        int sum=carry+val1+val2;
        // cout<<"sum = "<<sum<<endl;
        int digit=sum%10;
        //create node of digit and insert in ans LL
        insertAtHead(ansHead,digit);
        carry=sum/10;
        if(first!=NULL)        first=first->next;
        if(second!=NULL)       second=second->next;
    }
    //insertattail me  reverse  karna padega
    // ansHead=reverse1(ansHead);
    return ansHead;
}
Node* addTwoList(Node* first,Node* second){
    first=reverse1(first);
    second=reverse1(second);
    Node* ans=addfunc(first,second);
    return ans;
}
Node* addTwoList2(Node* first1,Node* second1){
    first1=reverse1(first1);    
    second1=reverse1(second1);    
    Node* ans=addfunc2(first1,second1);
    return ans;
}
int main()
{
    Node* head=NULL;
    insertAtHead(head,9);insertAtHead(head,9);insertAtHead(head,9);insertAtHead(head,9);
    print(head);
    Node* head2=NULL;
    insertAtHead(head2,9);insertAtHead(head2,9);insertAtHead(head2,2);insertAtHead(head2,9);
    print(head2);
    Node* temp=addTwoList(head,head2);
    print(temp);
    Node* hd1=NULL;
    insertAtHead(hd1,9);insertAtHead(hd1,9);insertAtHead(hd1,9);insertAtHead(hd1,9);
    print(hd1);
    Node* hd2=NULL;
    insertAtHead(hd2,9);insertAtHead(hd2,9);insertAtHead(hd2,2);insertAtHead(hd2,9);
    print(hd2);
    temp=addTwoList2(hd1,hd2);
    print(temp);
return 0;
}