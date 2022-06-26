/*
Merge K Sorted Lists



Merge k sorted linked lists and return it as one sorted list.



Example :

1 -> 10 -> 20 
4 -> 11 -> 13 
3 -> 8 -> 9 
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20


Input format:

The first line contains the integer k, the number of linked lists.

The next k lines contains the inputs for k linked lists.



Output format:

Print the elements of the merged lists in a single line, separated by space.



Sample input:

3

1 10 20

4 11 13

3 8 9

Sample Output:

1 3 4 8 9 10 11 13 20

Explanation:

On merging the three lists and sorting, the result is [1, 3, 4, 8, 9, 10, 11, 13, 20].
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
 };

struct compare 
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

 
ListNode *mergeKLists(vector<ListNode*> A) {
    
    if(A.size() == 0)
        return NULL;
    if(A.size() == 1)
        return A[0];

    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    for(int i = 0; i < A.size(); i++)
    {
        pq.push(A[i]);
    }
    while(!pq.empty())
    {
        ListNode *f = pq.top();
        pq.pop();
        ListNode *next = f->next;
        curr->next = f;
        f->next = NULL;
        curr = f;
        if(next != NULL)
            pq.push(next);
    }
    return head->next;
}

ListNode *insert(ListNode *root, int data)
{
    if(root == NULL)
    {
        ListNode *temp = new ListNode(data);
        root = temp;
    }
    else
    {
        ListNode *temp = new ListNode(data);
        ListNode *curr = root;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<ListNode*> roots;
    for(int i = 0;i < n;i++)
    {
        ListNode *root = NULL;
        while(true)
        {
            int element;
            cin >> element;
            root = insert(root, element);
            char ch = cin.peek();
            if(ch == '\n' || ch == EOF)
                break;
        }
        roots.push_back(root);
    }
    ListNode *result = mergeKLists(roots);
    while(result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
/*
case 1  
Input
3 1 10 20 4 11 13 3 8 9
Output
1 3 4 8 9 10 11 13 20

case 2
Input
4 3 12 15 18 5 7 9 10 13 8 16 17 19 2 20 22 24
Output
2 3 5 7 8 9 10 12 13 15 16 17 18 19 20 22 24

case 3
Input
3 8 57 76 142 172 85 90 98 174 191 3 8 57 61 70
Output
3 8 8 57 57 61 70 76 85 90 98 142 172 174 191

case 4
Input
2 27 60 75 83 87 74 45 52 137 150 153 167
Output
27 45 52 60 75 83 87 74 137 150 153 167
*/