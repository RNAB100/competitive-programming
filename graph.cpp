#include<bits/stdc++.h>
#define pi acos(-1)
#define mx 100000000
#define lil -100000000
#define mod 1e18
#define pb push_back
#define scan(x) scanf("%d",&x)
#define vi vector<int>
typedef long long ll;
using namespace std;

void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
///dfs
int n,m,j=0;
vi ara[100001];
int vis[100001]={0};
int pre[100001]={0};
int post[100001]={0};
void dfs(int v)
{
  vis[v]=1;
  pre[v]=j++;
  // cout<<v<<" ";
  for(int i=0;i<ara[v].size();i++){
    int child=ara[v][i];
    if(vis[child]==0){
      dfs(child);
    }
  }
  post[v]=j++;
}
int main()
{   
    fastio();
    int i,j,k,l,t,x;
    cin>>n;
    int a,b;
    for(i=1;i<=n;i++){
      cin>>a>>b;
      ara[a].pb(b);
      ara[b].pb(a);
    }
    dfs(1);
    for(i=1;i<=n;i++)cout<<pre[i]+1<<" ";
    cout<<endl;
    for(i=1;i<=n;i++)cout<<post[i]+1<<" ";
    cout<<endl;
  return 0;
} 