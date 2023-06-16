#include <bits/stdc++.h> 
#define ll  long long 

const int N = 1000001; 

using namespace std; 

// array to store factorial of first N numbers 
ll  fact[N + 1]; 

// Function to calculate factorial of 1 to N 
void factorial(ll  mod) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (ll i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % mod; 
    } 
}

// Function to calculate binary expo
ll pwr(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b) {
       if(b % 2) res = (res * a) % mod;
       a = (a * a) % mod;
       b /= 2;
    }
    return res;
}

// Function to calculate modulo inverse
ll mod_inverse(ll n, ll mod){
    return pwr(n, mod - 2, mod);
}  

// Function to return nCr % mod
ll  nCr(ll  N, ll  R, ll  mod) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll  ans = ((fact[N] * mod_inverse(fact[R], mod)) % mod * mod_inverse(fact[N - R], mod)) % mod; 
    return ans; 
} 
  

int main() 
{ 
   
    ll  mod = 1000000007; 
    factorial(mod);
    cout << nCr(15, 3, mod);
    return 0; 
} 
