#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        
        ListNode* head2=head;
        for(int i=0;i<n;i++)head2=head2->next;
        
        if(!head2)return head->next;
        
        ListNode* head3=head;
        while(head2->next){
            head2=head2->next;
            head3=head3->next;
        }
        head3->next=head3->next->next;
        return head;
    }
int main(){
    ListNode* head=new ListNode(10);
    head->next=new ListNode(20);
    head->next->next=new ListNode(30);
    head->next->next->next=new ListNode(40);
    head->next->next->next->next=new ListNode(50);
    ListNode* head2=head;
    while(head2){
        cout<<head2->val<<" ";
        head2=head2->next;
    }
    cout<<endl;
    head2=removeNthFromEnd(head,2);
    while(head2){
        cout<<head2->val<<" ";
        head2=head2->next;
    }

    return 0;
}