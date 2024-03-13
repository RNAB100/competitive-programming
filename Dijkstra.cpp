/*
	ARNAB SINGHA
*/
#include<bits/stdc++.h>

using namespace std;

#define  fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using ll = long long int;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;

//here
vector<pair<int, int>> g[N];

int dijkstra (int source, int destination) {
	vector<int> vis(N, 0);
	vector<int> dist(N, INF);

	set<pair<int, int>> st;

	st.insert({0, source});
	dist[source] = 0;
	while(st.size() > 0) {
		auto node = *st.begin();
		int v_dist  = node.first;
		int v = node.second;
		st.erase(st.begin());
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto child : g[v]) {
			int child_node = child.first;
			int wt = child.second;
			if(dist[v] + wt < dist[child_node]) {
				dist[child_node] = dist[v] + wt;
				st.insert({dist[child_node], child_node});
			}
		}
	}
	return dist[destination];
}
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i < N; i++) g[i].clear();
	for(int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y, wt});
		g[y].push_back({x, wt}); //for undirectional
	}
	ll ans = dijkstra(1, n);
	if(ans == INF) cout << "Impossible" << endl;
	else cout << ans << endl;
	return;
}
int main() {
	fastio;
	int test = 1;
	cin >> test;
	for(int t = 1; t <= test; t++) {
		cout << "Case " << t << ": ";
		solve();
	}
	return 0;
}