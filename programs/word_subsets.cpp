#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-subsets/
bool help(int frequency[], int matchingFrequency[])
{
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] < matchingFrequency[i])
            return false;
    }
    return true;
}
vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<string> ans;
    int matchingFrequency[26] = {0};
    for (string s : words2)
    {
        int frequency[26] = {0};
        for (char ch : s)
            frequency[ch - 'a'] += 1;
        for (auto str : frequency)
            cout << str << " ";
        cout << endl;
        for (int i = 0; i < 26; i++)
            matchingFrequency[i] = max(matchingFrequency[i], frequency[i]);
    }
    for (string s : words1)
    {
        int frequency[26] = {0};
        for (char ch : s)
            frequency[ch - 'a'] += 1;
        for (auto str : frequency)
            cout << str << " ";
        cout << endl;
        if (help(frequency, matchingFrequency))
            ans.push_back(s);
    }
    return ans;
}
int main()
{
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    cout << "words 1: ";
    for (auto i : words1)
        cout << i << ", ";
    cout << endl;
    cout << "words 2: ";
    for (auto i : words2)
        cout << i << ", ";
    cout << endl;
    vector<string> ans = wordSubsets(words1, words2);
    for (auto i : ans)
        cout << i << ", ";
    cout << "\b \b";
    cout << "\b \b";
    cout << endl;

    return 0;
}