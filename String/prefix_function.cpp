/*
Prefix function.: O(N)
About it: https://cp-algorithms.com/string/prefix-function.html
Based on problem:https://codeforces.com/contest/1326/problem/D2

pi[i] is the length of the longest proper prefix of the substring str[0…i] 
which is also a suffix of this substring.
Here it used to calculate longest prefix palindrome in O(n).
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb  push_back
#define ppb pop_back
#define mp  make_pair
#define SIZE 2000004
string str;
string temp;

// prefix_function
ll pi[SIZE];
void prefix_function(string s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		ll i;
		ll n=str.size();
		for(i=0;i<n/2;++i){
			if(str[i]!=str[n-i-1])
				break;
		}
		string s=str.substr(i,n-2*i);
		// cout<<s<<endl;
		string revs=s;
		reverse(revs.begin(),revs.end());
		temp=s;	
		temp+='*';
		temp+=revs;
		prefix_function(temp);
		ll idx=pi[temp.size()-1];
		// cout<<t<<endl;
		// cout<<idx<<endl;
		string s1=str.substr(0,i)+s.substr(0,idx)+str.substr(n-i,i);
		temp=revs;
		temp+='*';
		temp+=s;
		prefix_function(temp);
		idx=pi[temp.size()-1];
		string s2=str.substr(0,i)+s.substr(s.size()-idx,idx)+str.substr(n-i,i);
		if(s2.size()>s1.size()){
			cout<<s2<<endl;
		}
		else{
			cout<<s1<<endl;
		}
	}
}