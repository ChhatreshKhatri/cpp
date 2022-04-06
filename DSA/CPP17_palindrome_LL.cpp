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
bool checkPalindrome(vector<int> arr){
    int s=0;int n=arr.size();int e=n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
        return false;
        }
        s++;e--;
    }
        return true;
}
bool isPalindrome(Node* head){
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    // cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    return checkPalindrome(arr);
}
Node* getMid(Node* head ) {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
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
bool isPalindrome2(Node *head)
    {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        Node* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse1(temp);
        
        //step3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse1(temp);
        
        return true;
    }
int main()
{
    Node* head=NULL;
    insertAtHead(head,1);insertAtHead(head,2);insertAtHead(head,1);insertAtHead(head,2);
    // insertAtHead(head,1);
    print(head);
    if(isPalindrome(head)!=false)cout<<"palindrome"<<endl;
    else{cout<<"not palindrome"<<endl;}
    // print(head);
    // bool temp=isPalindrome2(head);
    // cout<<temp<<endl;
    if(isPalindrome2(head)!=false)cout<<"palindrome"<<endl;
    else{cout<<"not palindrome"<<endl;}


return 0;
}