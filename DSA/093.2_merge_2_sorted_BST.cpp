#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};
void convertIntoSortedLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (root == NULL)
        return;
    convertIntoSortedLL(root->right, head);
    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;
    convertIntoSortedLL(root->left, head);
}
TreeNode<int> *mergeSortedLL(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int countNodes(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
TreeNode<int> *sortedLLtoBST(TreeNode<int> *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    TreeNode<int> *left = sortedLLtoBST(head, n / 2);
    TreeNode<int> *root = head;
    root->left = left;
    head = head->left;
    root->right = sortedLLtoBST(head, n / 2 - 1);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // convert LL in sorted doubly linkedlist inplace
    TreeNode<int> *head1;
    convertIntoSortedLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2;
    convertIntoSortedLL(root2, head2);
    head2->left = NULL;

    // merge sorted linkedlist
    TreeNode<int> *head = mergeSortedLL(head1, head2);

    // conver sorted linkedlist to BST
    return sortedLLtoBST(head, countNodes(head));
}
int main()
{

    return 0;
}