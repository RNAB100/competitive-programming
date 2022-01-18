#include<bits/stdc++.h>
using namespace std;

#define pb    push_back
#define mp    make_pair 
#define ff    first
#define ss    second
 
#define all(x)  (x).begin(), (x).end()//fortrav
#define rall(x) (x).rbegin(), (x).rend()//revtrav
 
#define sz(a)    (a).size()
#define SET(a)    memset(a, -1,sizeof a)

typedef   long long int  ll;
typedef   vector<ll>     vll;

//constant
#define Pi     3.141592653589793
#define mod    998244353//1000000007
#define N      100005
#define INF    2147483647 
// 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) 

int main() {
	ll i, j, n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> adj[n];
	for(i = 0; i < m; i++) {
		ll a, b, wt;
		//a--,b--;
		cin >> a >> b >> wt;
		adj[a].pb({b, wt});
		adj[b].pb({a, wt});
	}
	// three array needed for prim's algo
	ll parent[n];
	bool mst[n];
	ll key[n];
	//pq --> key value ,idx;
	//minimum priority queue or min heap
	priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> >pq;
	for(i = 0; i < n; i++) {
		key[i] = INF;
		mst[i] = false;	
	}
	key[0] = 0; //initialize smallest non-existing node of mst 0
	parent[0] = -1;
	pq.push({0,0});
	while(pq.empty() == 0) { //n-1 nodes of spanning tree
		ll u = pq.top().ss; //getting u in logn
		pq.pop();
		mst[u] = true; //put u node on mst
		for(auto it : adj[u]) { //all adj nodes of u
			ll v = it.ff;
			ll weight = it.ss;
			//if v isn't in mst update weight in key array and parent
			if(mst[v] == false && weight < key[v]) { 
				parent[v] = u;
				key[v] = weight;
				pq.push({key[v],v});
			}			

		}

	}
	for(i = 1; i < n; i++){//u has no parents
		cout << parent[i] << " - " << i << endl;
	}
	return 0;
}
 