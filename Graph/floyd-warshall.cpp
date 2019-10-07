/**************************************************************************************
Floyd-Warshall algorithm finding shortest distance between all
pairs of vertices in graph. Works in O(N^3)
Based on problem Codeforces:Greg and Graph:
https://codeforces.com/problemset/problem/295/B
Input is taken as adjacancy matrix.
No edge  is represented as -1 in input.
**************************************************************************************/

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
#define SIZE 501
#define INF (ll)1e9

ll d[SIZE][SIZE];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			cin>>d[i][j];
			if(d[i][j]==-1){
				d[i][j]=INF;
			}
		}
	}
	/*
	Basic Floyed warshall  to calculate distance between all vertices:
	valid for negative edges also:
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (d[i][k] < INF && d[k][j] < INF)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			}
		}
	}
	*/
	ll arr[n+1];
	for(ll i=0;i<n;++i){
		cin>>arr[n-i];
	}
	vector<ll> vsum;
	for (ll k = 1; k <=n;k++){
		for (ll i=1;i<=n;++i){
			for (ll j=1;j<=n;++j){
				d[i][j] = min(d[i][j], d[i][arr[k]] + d[arr[k]][j]); 
			}
		}
		ll sum=0;
		 for (ll i=1;i<=k;++i){
			for (ll j=1;j<=k;++j){
				sum+=d[arr[i]][arr[j]];
			}
		}
		vsum.pb(sum);
	}	
	for(ll i=vsum.size()-1;i>=0;--i){
		cout<<vsum[i]<<" ";
	}
	cout<<endl;
}