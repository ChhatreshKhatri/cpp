#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    char data;
    trieNode *children[26]; // each node can have 26 child
    bool isTerminal;        // to check the last char is end or not, Trie-> time, so tim should not be an ans as last char of time is 'e'
    trieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};
class Trie
{
public:
    trieNode *root;
    Trie()
    {
        root = new trieNode('\0'); // trie root node start with null char
    }
    // recurion
    void insertUtil(trieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // capital letter here for now
        int index = word[0] - 'A';
        trieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(trieNode *root, string word)
    {
        // base
        if (word.length() == 0)
            return root->isTerminal;
        int index = word[0] - 'A';
        trieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool prefixSearchUtil(trieNode *root, string word)
    {
        // base
        if (word.length() == 0)
            return true;
        int index = word[0] - 'A';
        trieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // recursion
        return prefixSearchUtil(child, word.substr(1));
    }
    bool searchPrefix(string word)
    {
        return prefixSearchUtil(root, word);
    }
};
int main()
{
    Trie *t=new Trie();
    t->insertWord("ABCD");
    t->insertWord("TIME");
    // t->insertWord("AB");

    cout << "ABCD present or  not " << t->searchWord("ABCD")<<endl;
    cout << "TIME present or  not " << t->searchWord("TIME")<<endl;
    cout << "TIM present or  not " << t->searchWord("TIM")<<endl;
    cout << "TIM prefix present or  not " << t->searchPrefix("TIM")<<endl;
    cout << "AB present or  not " << t->searchWord("AB")<<endl;
    cout << "AB prefix present or  not " << t->searchPrefix("AB")<<endl;


    return 0;
}