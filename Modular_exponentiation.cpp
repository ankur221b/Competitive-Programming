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

int main()
{
	return 0;
}