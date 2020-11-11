#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ss second
#define MAX 1001
#define MOD 1000000007
#define INF INT_MAX

ll fact[MAX];
ll inv[MAX];

ll mod_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

void init(ll n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    inv[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

ll npr(int n, int m)
{
    return (fact[n] * inv[n - m]) % MOD;
}

ll ncr(int n, int m)
{
    return (fact[n] * inv[m] * inv[n - m]) % MOD;
}

int main()
{
    return 0;
}