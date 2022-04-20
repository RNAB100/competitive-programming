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
#define N     200001
#define INF   2147483647 
// 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) 
// ll dp[N]={0};
ll st[4*N];
ll a[N];
void built_tree(ll si,ll ss,ll se) //segment idx,start,end
{
  if(ss==se){ //leaf
    st[si]=a[ss];
    return;
  }
  ll mid=(ss+se)/2;
  built_tree(2*si,ss,mid);
  built_tree(2*si+1,mid+1,se);
  st[si]=min(st[2*si],st[2*si+1]);
}
void update(ll si, ll ss, ll se, ll pos, ll new_val) { //segment idx,start,end
    if (ss==se) {
        st[si] = new_val;
    } 
    else {
        ll mid=(ss+se)/2;
        if (pos <= mid)
            update(si*2, ss, mid, pos, new_val);
        else
            update(si*2+1, mid+1, se, pos, new_val);
        st[si] = min(st[si*2] , st[si*2+1]);
    }
}
ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
  if(qs>se||qe<ss) return INF;//completely outside
  if(ss>=qs && se<=qe) return st[si]; //completely inside
  ll mid=(ss+se)/2;
  ll l=query(2*si,ss,mid,qs,qe);
  ll r=query(2*si+1,mid+1,se,qs,qe);
  return min(l,r);
}
//main code:
void solve(){
  ll i,j,n,m,k,x,y,z;
  cin>>n;
  for1(i,n)cin>>a[i];
  built_tree(1,1,n);
  cin>>k;
  while(k--){
    ll p,q;
    cin>>p>>q;
    ll ans=query(1,1,n,p+1,q+1);
    cout<<ans<<endl;
  } 
return;
}

int main()
{
   fastio;
   int tst,t=1;
   //cin>>t;
   for1(tst,t){
     // cout<<"Case "<<tst<<":";
    solve();
   }
  return 0;
}
