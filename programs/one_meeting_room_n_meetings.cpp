/*
QUESTION 01
Time spent 1m 3s
Not Attempted 0
In a firm, we have only one meeting room. And there are N meetings in the form of (S[i], F[i]). Where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. What is the maximum number of meetings that can be accommodated in this meeting room?



Format:

Input:

The first line of the input consists of a number denoting the test cases. The description of T test cases is as follows: The first line consists of the size of an array. The second line has an array that consists of starting time of all the meetings each separated by a space, that is S[i]. And the third line has the array that consists of the end time of all the meetings each separated by a space, that is F[i].

Output:

In each separate line. Print the indices of the meetings taking place in increasing order of time, separated by space.



Constraints:

1 ≤ T ≤ 70

1 ≤ N ≤ 100

1 ≤ S[ i ], F[ i ] ≤ 100000



Example:

Input:

2

6

1 3 0 5 8 5

2 4 6 7 9 9

8

75250 50074 43659 8931 11273 27545 50879 77924

112960 114515 81825 93424 54316 35533 73383 160252 

Output:

1 2 4 5

6 7 1

Explanation:

Testcase 1: Four meetings can be held - {1, 2}, {3, 4}, {5, 7}, {8, 9} with indices (1, 2, 4, 5)

Testcase 2: Three meetings can be held - {27545, 35533}, {50879, 73383}, {75250, 112960} with indices (6, 7, 1)
*/



#include <bits/stdc++.h> 
using namespace std; 
  
// Structure for storing starting time,  
// finishing time and position of meeting. 
struct meeting { 
    int start; 
    int end; 
    int pos; 
}; 
  
// Comparator function which can compare 
// the second element of structure used to 
// sort pairs in increasing order of second value. 
bool comparator(struct meeting m1, meeting m2) 
{ 
    return (m1.end < m2.end); 
} 
  
// Function for finding maximum meeting in one room 
void maxMeeting(int s[], int f[], int n) 
{ 
    struct meeting meet[n]; 
    for (int i = 0; i < n; i++)  
    { 
        // Starting time of meeting i. 
        meet[i].start = s[i];  
          
        // Finishing time of meeting i 
        meet[i].end = f[i];  
          
        // Original position/index of meeting 
        meet[i].pos = i + 1;  
    } 
  
    // Sorting of meeting according to their finish time. 
    sort(meet, meet + n, comparator); 
  
    // Vector for storing selected meeting. 
    vector<int> m; 
  
    // Initially select first meeting. 
    m.push_back(meet[0].pos); 
  
    // time_limit to check whether new  
    // meeting can be conducted or not. 
    int time_limit = meet[0].end; 
  
    // Check for all meeting whether it  
    // can be selected or not. 
    for (int i = 1; i < n; i++) { 
        if (meet[i].start >= time_limit) 
        { 
            // Push selected meeting to vector 
            m.push_back(meet[i].pos); 
              
            // Update time limit. 
            time_limit = meet[i].end;  
        } 
    } 
  
    // Print final selected meetings. 
    for (int i = 0; i < m.size(); i++) { 
        cout << m[i] << " "; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        int s[n],f[n],a[n];
        for(int i=0;i<n;i++)
           cin>>s[i];
        for(int i=0;i<n;i++)
          cin>>f[i];
        maxMeeting(s, f, n);
        cout<<endl;
    }
    return 0; 
} 
/*
case 1
Input
2 6 1 3 0 5 8 5 2 4 6 7 9 9 8 75250 50074 43659 8931 11273 27545 50879 77924 112960 114515 81825 93424 54316 35533 73383 160252
Output
1 2 4 5
6 7 1
case 2
Input
1 6 15 16 17 20 18 235 23 52 10 41 47 240
Output
3 1 6

case 3
Input
1 6 15 16 17 20 18 235 23 52 10 41 47 240
Output
3 1 6

case 4
Input
2 5 5428 6324 7852 42 752 8521 8632 7521 55 876 3 500 4523 4756 325 4852 4572
Output
4 5 3
1 3
*/