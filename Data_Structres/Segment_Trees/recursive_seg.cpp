/*Following Segment tree is for range sum query O(log(n).
It includes only single element update on O(log(n)).
For Efficient range updates see lazy propagation*/

/*
build(root_node=1,=0,root_interval_end=n),call build() .
update(position,value,root_node=1,=0,root_interval_end=n), call update(p,  x)
query(start_range,end_range,int node = 1,int l = 0,int r = n), call query(l,  r)
*/

/*Each node, has 0 or two children. 
Left and right. If a node's interval is [l, r) and l + 1 ≠ r, 
the interval of its children will be [l, mid) and [mid, r) in order where , 
so the height of this tree will be O(log(n)) .
*/

/*root has index 1 and the children of a vertex x 
will have indices 2x and 2x + 1 in order.
If the size of the root's interval is n, segment tree could have up to 4n nodes
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
ll tree[4*SIZE];
ll n;
ll a[SIZE]={1,2,3,4,10};
void build(ll node = 1,ll l = 0,ll r = n){
	if(r - l < 2){	//	l + 1 == r
		tree[node] = a[l];
		return ;
	}
	ll mid = (l+r)/2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(ll p,ll x,ll node = 1,ll l = 0,ll r = n){
	if(r - l < 2){	//	l = r - 1 = p
		a[p] = x;
		tree[node]=x;
		return ;
	}
	ll mid = (l + r)/2;
	if(p < mid)
		update(p, x, node * 2, l, mid);
	else
		update(p, x, node * 2 + 1, mid, r);

	tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(ll x,ll y,ll node = 1,ll l = 0,ll r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return tree[node];
	ll mid = (l+r)/2;
	return query(x, y, node * 2, l, mid)+query(x, y, node * 2 + 1, mid, r);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    n=5;
    build();
    cout<<query(0,n)<<endl;
    update(n-1,1000);
    cout<<query(3,n)<<endl;
}