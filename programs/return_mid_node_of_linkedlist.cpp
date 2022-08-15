#include <bits/stdc++.h>
using namespace std;
//1->2->3->4
//3->4
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)return NULL;
        ListNode* fp=head;
        ListNode* sp=head;
        int count=0;
        while(fp!=NULL && fp->next!=NULL){
            sp=sp->next;
            fp=fp->next->next;
        }
        return sp;
    }
int main()
{
    ListNode*head=new ListNode(10);
    head->next=new ListNode(20);
    head->next->next=new ListNode(30);
    head->next->next->next=new ListNode(40);
    ListNode* ans=middleNode(head);
    while(ans!=NULL){
        cout<<ans->val;
        ans=ans->next;
    }
    return 0;
}