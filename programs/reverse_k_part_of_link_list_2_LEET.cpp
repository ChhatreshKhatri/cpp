#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/reverse-linked-list-ii/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void reverseLL(ListNode *head1, ListNode *head2)
{
    ListNode *prev = NULL, *curr = head1;
    ListNode *forward = NULL;
    while (curr != head2)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    curr->next = prev;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right)
    {
        return head;
    }
    ListNode *head1 = NULL, *head2 = NULL;
    ListNode *nextP = NULL, *prevP = NULL;
    ListNode *tempHead = head;
    int i=1;
    prevP=NULL;
    while (tempHead != NULL)
    {
        if(i==left-1)   prevP=tempHead;
        if (i==left)    head1 = tempHead;
        if (i==right)
        {
            head2 = tempHead;
            nextP = tempHead->next;
            break;
        }
        tempHead=tempHead->next;
        i++;
    }

    reverseLL(head1, head2);
    head1->next = nextP;
    if(prevP)prevP->next = head2;
    
    if(left==1) head=head2;

    return head;
}
void print(ListNode *temp)
{
    while (temp != NULL)
    {
        cout << temp->val;
        temp = temp->next;
    }
    cout << endl;
}
void linkedList(ListNode *head,vector<int> v){
    ListNode *tempHead=head;
    for(int i=0;i<v.size();i++){
        ListNode *temp=new ListNode(v[i]);
        tempHead->next=temp;
        tempHead=tempHead->next;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    vector<int> v={2,3,4,5,6};
    linkedList(head,v);
    print(head);
    ListNode *last = head->next->next->next->next->next;
    ListNode *ans=reverseBetween(head,1,6);
    print(ans);

    return 0;
}