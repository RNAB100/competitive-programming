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
#define SET(a)    memset( a, -1,sizeof a )

#define cyes  cout<<"Yes"<<endl
#define cno   cout<<"No"<<endl
#define nl    cout<<endl

using namespace std;

typedef   vector<int>    vi;
typedef   vector<vi>     vvi;
typedef   pair<int, int> ii;
typedef   vector<ii>     vii;
typedef   long long int  ll;
typedef   vector<ll>     vll;
typedef   vector<vll>    vvll;
typedef   map<int,int>   mii;
typedef   map<ll,ll>     mll;
typedef   map<int,string>mis;
typedef   map<char,int>  mci;

//constant
#define Pi    3.141592653589793
#define mod   1000000007
#define N     100007
#define INF   2147483647 
// 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) 
// ll dp[N]={0};
ll st[4*N];
ll a[N];
ll lazy[4*N];
void built_tree(ll si,ll ss,ll se) //segment idx,start,end
{
	if(ss == se){ //leaf
		st[si] = a[ss];
		return;
	}
	ll mid = (ss+se)/2;
	built_tree(2*si, ss, mid);
	built_tree(2*si+1, mid+1, se);
	st[si] = st[2*si] +  st[2*si+1];
}
void update(ll si, ll ss, ll se, ll qs, ll qe, ll val) { //segment idx,start,end
	if(lazy[si] != 0){
		st[si] += lazy[si]*(se-ss+1);
		if(ss != se){
			lazy[2*si] += lazy[si];
			lazy[2*si+1] += lazy[si];
		}
		lazy[si] = 0;
	}
	if(qs > se || qe < ss) return;
    else if(ss >= qs && se <= qe) {
    	st[si] += val*(se-ss+1);
    	if(ss != se){
			lazy[2*si] += val;
			lazy[2*si+1] += val;
		}
    }
    else {
        ll mid=(ss+se)/2;
        update(si*2, ss, mid, qs, qe, val);
        update(si*2+1, mid+1, se, qs, qe, val);
        st[si] = st[si*2] + st[si*2+1];
    }
}
ll query(ll si, ll ss, ll se, ll qs, ll qe)
{
	if(lazy[si] != 0){
		st[si] += lazy[si]*(se-ss+1);
		if(ss != se){
			lazy[2*si] += lazy[si];
			lazy[2*si+1] += lazy[si];
		}
		lazy[si] = 0;
	}
	if(qs > se || qe < ss) return 0;//completely outside
	else if(ss >= qs && se <= qe) return st[si]; //completely inside
	ll mid = (ss+se)/2;
	ll l = query(2*si, ss, mid, qs, qe);
	ll r = query(2*si+1, mid+1, se, qs, qe);
	return l+r;
}
//main code:
void solve(){
	ll i,j,n,m,k,q,x,y,z;
	cin>>n>>q;
	memset(lazy,0,sizeof lazy);
	memset(a,0,sizeof a);
	memset(st,0,sizeof st);
	built_tree(1,1,n);
	while(q--){
		cin>>z;
		cin>>x>>y;

		if(z==0){
			cin>>k;
			update(1,1,n,x,y,k);
		}
		else{
			cout << query(1,1,n,x,y) <<endl;
		}
	}
	return;
}

int main() {
	fastio;
	int tst,t=1;
	cin>>t;
	for1(tst,t){
		//cout<<"Case "<<tst<<":"<<endl;
		solve();
	}
	return 0;
}
