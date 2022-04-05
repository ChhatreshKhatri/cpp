#include<bits/stdc++.h>
using namespace std;
struct cmp{
	bool operator () (const pair<char,int> &p1, const pair<char,int>& p2) {
		return p1.second < p2.second;
	}
};

string generateWord(string seq, string word) {
	vector<pair<char,int>> arr;
	unordered_map<char, int> umap;
	for(int i = 0; i <(int)seq.size(); i++) {
		if(umap.find(seq[i])  != umap.end()) {
			return "New language Error";
			break;
		}else{
			umap[seq[i]] = i;
		}
	}

	for( int i = 0; i < (int)word.size(); i++) {
		if(umap.find(word[i]) != umap.end()) {
			arr.push_back(make_pair(word[i], umap[word[i]] ) );
		}
	}

	sort(arr.begin(),arr.end(),cmp());
	string ans = "";
	for(auto i: arr) {
		
		ans  = ans +  i.first;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	
	string sequence;
	getline(cin,sequence);
	
	string word;
	getline(cin,word);
	// cout<<seq<<endl<<word<<endl;
	transform(sequence.begin(),sequence.end(),sequence.begin(),::tolower);
	transform(word.begin(),word.end(),word.begin(),::tolower);

	istringstream ss(word);
	string w;
	vector<string> res;
	bool flag = true;
	while(ss >> w) {		
		string x = generateWord(sequence,w);
		if(x == "New language Error") {
			cout<<x;
			flag = false;
			break;
		}else{
			res.push_back(x);
		}			
	}
	if(flag == true) {
		if(res.size() <= 1) {
		cout<<res[0];
	}else{
		for(auto i : res) {
			cout<<i<<" ";
		}
	}
	}
	return 0;
}