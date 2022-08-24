#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL, *cur = head, *next;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    int count = 1;
    ListNode *slow = head;
    ListNode *fast = head;
    // slow and fast pointer to get to mid O(n/2)
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            count++; // count here to handle even and odd
        }
        slow = slow->next;
    }
    ListNode *midHead = slow;
    // get midhead after reverse TC->O(n/2)
    midHead = reverseLL(midHead);
    // cout<<count<<endl;
    // check if palindrome from start and mid O(n/2)
    for (int i = 1; i < count; i++)
    {
        // cout<<"head "<<head->val<<" midhead "<<midHead->val<<endl;
        if (head->val != midHead->val)
            return false;
        else
        {
            head = head->next;
            midHead = midHead->next;
        }
    }
    return true;
}

// simple
bool isPalindrome2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head, *fast = head, *next = nullptr, *prev = nullptr;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    if (fast == NULL)
        ;
    else
        slow = slow->next;

    while (slow)
    {
        cout << slow->val << " " << prev->val << endl;
        if (slow->val != prev->val)
            return false;
        else
        {
            slow = slow->next;
            prev = prev->next;
        }
    }

    return true;
}
int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(10);
    // head->next->next->next->next->next = new ListNode(10);
    // ListNode* temp=head;
    // temp=reverseLL(temp);
    // while(temp!=NULL){
    //     cout<<temp->val<<" ";
    //     temp=temp->next;
    // }cout<<endl;
    ListNode *head2 = head;
    cout << isPalindrome(head2);
    return 0;
}