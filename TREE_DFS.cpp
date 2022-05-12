#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define N  200005

vector <ll> ara[N];
void tree_dfs(ll curr, ll par=0) {
	for(auto child : ara[curr]) {
		if(child == par) continue;
		tree_dfs(child, curr);	
	}
}
//HERE
void solve() {
	ll i, j, n;
	cin >> n;
	for(i = 2; i <= n; i++) {
		ll par;
		cin >> par;
		ara[par].push_back(i);
	}
	tree_dfs(1);
  for (i = 1; i <= n; i++) ara[i].clear();
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
