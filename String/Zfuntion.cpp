/*
Z function. O(N)
About it: http://e-maxx.ru/algo/z_function
Based on problem:https://codeforces.com/contest/432/problem/D
z[i] is the length of the longest common prefix between s and the suffix of s starting at i.
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
#define SIZE 100005
ll cnt[SIZE];
ll z[SIZE];
bool is[SIZE];
void z_funtion(string s){
    ll n = (ll) s.length();
    ll l =0,r = 0;
    for (ll i = 1; i <n; ++i) {
        ll cur = 0;
        if (i <= r)
            cur = min(r - i + 1, z[i - l]);
        while (i + cur <n && s[cur]==s[i + cur])
            cur++;
        if (i + cur - 1 > r) {
            l = i; r = i + cur - 1;
        }
        z[i] = cur;
    }
    z[0] = n;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string str;
	cin>>str;
	ll num=0;
	z_funtion(str);
	for(ll i=0;i<str.size();++i){
		if(i+z[i]==str.size()){
			num++;
			is[z[i]]=true;
		}
		cnt[z[i]]++;
	}
	// cout<<endl;
	for(ll i=str.size()-1;i>=1;--i){
		cnt[i]+=cnt[i+1];
	}
	cout<<num<<endl;
	for(ll i=1;i<=str.size();++i){
		if(is[i]){
			cout<<i<<" "<<cnt[i]<<endl;
		}
	}
	cout<<endl;

}