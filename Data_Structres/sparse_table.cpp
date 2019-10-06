/*
* Sparse table. Solves static RMQ problem (without element changes).
* O(NlogN) on precomputation, O(1) on minimum query.(Can be used for any idempotent functions ,Eg: MAX .. etc)
* For sum like queries it will take Log(n) time(better use segment tree).
* Based on the problem RMQSQ from SPOJ.com:
* https://www.spoj.com/problems/RMQSQ/
* ComputeLogs()
* buildST(Number of array element)
* query(l,r)
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

#define MAX 100001
#define LMAX 20 //log(MAX)
ll lg[MAX];
ll arr[MAX];
ll st[LMAX][MAX];

void computeLogs(){
	for(ll i=2;i<MAX;++i){
    	lg[i]=lg[i/2]+1;
    }
}


void buildST(ll n){
	for(ll i=0;i<=lg[n];++i){
		ll curlen=1<<i;
		for(ll j=0;j+curlen<=n;++j){
			if(curlen==1){
				st[i][j]=arr[j];
			}
			else{
				st[i][j]=min(st[i-1][j],st[i-1][j+curlen/2]); //dividing interval 
															  //[l,l+2^k -1]-> [l,l+2^(k-1)-1]+[l+2^(k-1)-1],l+2^k-1]
			}
		}
	}
}

ll query(ll l,ll r){
	ll p=lg[r-l+1];
	ll plen=1<<p;
	return min(st[p][l],st[p][r-plen+1]); // this can only be applied to idempotent function in O(1)

}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n;
    cin>>n;
    for(ll i=0;i<n;++i){
    	cin>>arr[i];
    }
    computeLogs();
    buildST(n);
    ll q;
    cin>>q;
    // cout<<st[1][1]<<endl;
    while(q--){
    	ll l,r;
    	cin>>l>>r;
    	cout<<query(l,r)<<endl;
    }
    
}