#include<bits/stdc++.h>
#define pi acos(-1)
#define mx 1e7
#define mod 1000000007
#define vi vector<ll>
#define pb push_back
typedef long long ll;
using namespace std;
vector<bool>isprime(mx+1,0);
vi p,sg,segment;
void sieve()
{
    int n=mx;
    isprime[0]=isprime[1]=1;
    isprime[2]=0;
    p.pb(2);
    for(int i=4;i<=n;i+=2)isprime[i]=1;
    for(int i=3;i*i<=n;i+=2){
        if(isprime[i]==0){
            for(int j=i*i;j<=n;j+=2*i)
                isprime[j]=1;
        }
    }
    for(int i=3;i<=mx;i+=2){
    if(isprime[i]==0)p.pb(i);
   }
}
void Segsieve(ll l,ll r)
{
  ll i,j;
  sg.clear();
  for(i=l;i<=r;i++){
    sg.pb(i);
  }
  ll root=sqrt(r)+1;
  if(l==0)sg[1]=0;
  else if(l==1)sg[0]=0;
  for(i=0;i<=root;i++){
    ll start=p[i]*p[i];
    if(start<l){
      start=((l+p[i]-1)/p[i])*p[i];
    }
    for(j=start;j<=r;j+=p[i]){
      sg[j-l]=0;
    }
  }
}
int main()
{
  ll i,j,l,r,m,n,t;
  sieve();
  cin>>t;
  while(t--){
    cin>>l>>r;
    Segsieve(l,r);
    for(i=l;i<=r;i++){
      if(sg[i-l]!=0)segment.pb(sg[i-l]);
    }
    for(auto it:segment)cout<<it<<endl;
    segment.clear();  
  }

 return 0;
}
