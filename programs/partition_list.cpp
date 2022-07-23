#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/partition-list/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode *temp)
{
    while (temp != NULL)
    {
        cout << temp->val;
        temp = temp->next;
    }
    cout << endl;
}
ListNode* partition(ListNode* head, int x) {
        ListNode *leftP=new ListNode();   //will contain all values less than x
        ListNode *rightP=new ListNode();  //will contain all values more than x
        ListNode *newHead=leftP;    //to start with leftP
        ListNode *startRight=rightP;//to track start of rightP
        while(head!=NULL){
            if(head->val<x){
                leftP->next=head;
                leftP=leftP->next;
            }
            else{
                rightP->next=head;
                rightP=rightP->next;
            }
            head=head->next;
        }
        leftP->next=startRight->next;// startRight has nothing, its next points to the start of new LL
        rightP->next=NULL;
        
        return newHead->next;//newHead is at NULL, start from its next;
    }

void linkedList(ListNode *head, vector<int> v)
{
    ListNode *tempHead = head;
    for (int i = 0; i < v.size(); i++)
    {
        ListNode *temp = new ListNode(v[i]);
        tempHead->next = temp;
        tempHead = tempHead->next;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    vector<int> v = {1, 4, 3, 2, 5, 2};
    linkedList(head, v);
    print(head);
    ListNode *newHead=partition(head,3);
    print(newHead);
    

    return 0;
}