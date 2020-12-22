/**************************************************************************************
Krusal algorithm for finding Minimum Spanning Tree using DSU
Time Complexity : O(M*Log(n))
Space Complexity : O(M+N)
Input is taken as adjacancy matrix.
It is Assumed that node numbering starts from 1.
Tested on :
https://www.hackerrank.com/challenges/johnland/problem
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
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
#define SIZE 100005 //Max No. of Nodes in Graph


// Disjoint Set union by rank with Path compression:
ll parent[SIZE], mrank[SIZE];

void make_set(ll v) {
    parent[v] = v;
    mrank[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (mrank[a] < mrank[b])
            swap(a, b);
        parent[b] = a;
        if (mrank[a] == mrank[b])
            mrank[a]++;
    }
}


vector<pair<ll,pll> > edges;
vector<pair<ll,pll> > MST;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll N,M;
	cin>>N>>M;
	ll cost=0;
	for (ll i = 1; i <= N; i++)
		make_set(i);
    edges.clear();
    MST.clear();

	for(ll i=0;i<M;++i){
		ll u,v,w;
		cin>>u>>v>>w;
		edges.pb(mp(w,mp(u,v)));
	}
	sort(edges.begin(),edges.end());
	for (auto e : edges) {
	    if (find_set(e.second.first) != find_set(e.second.second)) {
	        cost += e.first;
	        MST.push_back(e);
	        union_sets(e.second.first, e.second.second);
	    }
	}
	cout<<cost<<endl;
	for(auto e:MST){
		cout<<e.second.first<<" "<<e.second.second<<" "<<e.first<<endl;
	}
}
