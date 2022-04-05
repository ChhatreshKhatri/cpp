#include <bits/stdc++.h>
using namespace std;
int main(){
bool flaggo=0;    
string inp1;
string numbr="";
getline(cin,inp1);
for(long unsigned int i=0;i<inp1.size();i++) inp1[i]=tolower(inp1[i]);
int n =inp1.length();
string customstring;
getline(cin,customstring);
for(long unsigned int i=0;i<customstring.size();i++) customstring[i]=tolower(customstring[i]);
int m = customstring.length();

for(long unsigned int i=0; i<n; i++){
    for(long unsigned int j=i+1;j<n;j++){
        if(inp1[i]==inp1[j]){
            flaggo=1;
        }
    }
}

string wordstring="";
for(long unsigned int i=0; i<n; i++){
    for(long unsigned int j=0; j<m; j++){
        if(inp1[i]==customstring[j]){
            wordstring+=inp1[i];
            int fla=0;
            fla++;
            
        }    
    }
        
}
int g =wordstring.length();    

for (long unsigned int i = 0; i < g; i++) {  
        if (wordstring[i] - '0' >= 0 and wordstring[i] - '0' <= 9) {
            numbr += wordstring[i];
        }
}
for(long unsigned int i = 0; i< g; i++){
        if(isdigit(wordstring[i])){
            wordstring.erase(i, 1);
            i--;
        }
    }
if(flaggo==0){    
cout<<wordstring<<" "<<numbr;
}
else{
    cout<<"New Language Error";
}
return 0;

}