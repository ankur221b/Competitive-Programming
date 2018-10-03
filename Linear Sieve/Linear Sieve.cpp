#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back((x))
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define MAX 1000001

bool prime[MAX];

void get_sieve()
{
    prime[1]=false;
    
    for(int i=2;i<=MAX;i++)
    {
        prime[i]=true;
    }

    for(int i=2;i*i<=MAX;i++)
    {
        if(prime[i]==true)
        {
            for(int j=2*i;j<=MAX;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

int main() {

    get_sieve();


return 0;
}
