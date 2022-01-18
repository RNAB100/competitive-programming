#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define MX  200000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) 

ll a[MX+5];
int block_s=550;

 struct Query
 {
 	int l,r,id;
 	//int lb = l / block_s;
 	bool operator<(const Query &oth)const
    {
        int b_a = l / block_s;
        int b_b = oth.l / block_s;
        if(b_a == b_b) return r < oth.r;
        return b_a < b_b;
    }
 };
 Query queries[MX+5];
 
/*bool comp(Query a, Query b)//MO's ordering
{
	if(a.lb == b.lb) return a.r < b.r;//same block 
        return a.lb < b.lb;
}*/

ll freq[1000005]={0};
ll ans=0;
 void add(int idx)
 {
 	ll m=freq[a[idx]];
 	ans-=(m*m)*a[idx];
 	//ans+=(m*2ll+1)*a[idx];//(a+1)^2-a^2=2a+1;  //choto bad diye boro nicchi in add
 	freq[a[idx]]++;
 	m++;
 	ans+=(m*m)*a[idx];
 }
 void remov(int idx)
 {
 	ll m=freq[a[idx]];
 	ans-=(m*m)*a[idx];
 	//ans+=(-m*2ll+1)*a[idx];//((a-1)^2-(a^2)=-2a+1)  //boro bad diye choto nicchi in remov
 	freq[a[idx]]--;
 	m--;
 	ans+=(m*m)*a[idx];
 }
int main()
{
	fastio;
	int n,q;
	cin>>n>>q;
	int i;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<q;i++){  //offline 
		cin>>queries[i].l>>queries[i].r;
		--queries[i].l;
		--queries[i].r;
		queries[i].id=i;
	}
	sort(queries,queries+q);
	int L=0,R=-1;
    ans=0;
	ll ara[MX+5];
	for(i=0;i<q;i++){
		while(L<queries[i].l){
			remov(L);
			L++;
		}
		while(L>queries[i].l){
			L--;
			add(L);
		}
		while(R<queries[i].r){
			R++;
			add(R);
		}
		while(R>queries[i].r){
			remov(R);
			R--;
		}
		ara[queries[i].id]=ans;
	}
	for(i=0;i<q;i++){
	 cout<<ara[i];
	 cout<<"\n";	
	}	
	return 0;
}