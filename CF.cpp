/*
	ARNAB SINGHA
*/
#include<bits/stdc++.h>

#define for0(i,n)    for(i=0;i<n;i++)
#define for1(i,n)    for(i=1;i<=n;i++)
#define forc(i,l,r)  for(i=l;i<=r;i++)
#define forr0(i,n)   for(i=n-1;i>=0;i--)
#define forr1(i,n)   for(i=n;i>=1;i--)

#define pb    push_back
#define mp    make_pair 
#define ff    first
#define ss    second

#define all(x)  (x).begin(), (x).end()//fortrav
#define rall(x) (x).rbegin(), (x).rend()//revtrav

#define sz(a)    (a).size()
#define SET(a)    memset(a, -1, sizeof a)

#define cyes  cout<<"YES"<<endl
#define cno   cout<<"NO"<<endl
#define nl    cout<<endl

using namespace std;
typedef   long long int  ll;
typedef   vector<ll>     vll;
typedef   vector<vll>    vvll;
typedef   map<ll,ll>     mll;

//constant
#define Pi    3.141592653589793
#define mod   1000000007
#define nn    1000005
#define INF   2147483647 
// 
#define  fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifdef   LOCAL
#include "debug.h"
#else
#define  debug(...)
#define  sdebug(...) //for array -name, size
#endif

//HERE
void solve() {
	ll i, j, n, m, k, q, x, y;
	cin >> n >> m;
	ll ara [n + 5][m + 5];
	ll pre [n + 5][m + 5];
	memset(ara, 0LL, sizeof(ara));
	memset(pre, 0LL, sizeof(pre));
	for1(i, n) {
		for1(j, m) {
			cin >> ara[i][j];
		}
	}
	//2d prefix sum
	for1(i, n) {
		for1(j, m) {
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + ara[i][j]; 
		}
	}
	// sub-matrix sum from prefix grid
	ll l1 , r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	ll ans = pre[l2][r2] -  pre[l1 - 1][r2] - pre[l2][r1 - 1] + pre[l1 - 1][r1 - 1];
	cout << ans << endl;
	return;
}

int main() {
	fastio;
	int tst, t = 1;
	//cin >> t;
	for1(tst, t){
		//cout<<"Case "<<tst<<":"<<endl;
		solve();
	}
	return 0;
}
