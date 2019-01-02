#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define MAX 100001
#define MOD 1000000007

// finding root of component
int root(int v[],int a)
{
    while(v[a]!=a)
    {
        a = v[v[a]];
        
    }
    return a;
}

// union of two components
void uni(int v[],int size[],int a , int b)
{
    int A = root(v,a);
    int B = root(v,b);
    if(A==B)return;
    
    if(size[A]<size[B])
    {
        v[A]=v[B];
        size[B]+=size[A];
        size[A]=0;
    }
    else
    {
        v[B]=v[A];
        size[A]+=size[B];
        size[B]=0;
    }
    
}

// check if components are connected
bool find(int v[],int a , int b)
{
    return root(v,a)==root(v,b);
}

//initialise the arrays 
void init(int v[],int s[],int n)
{
    for(int i=1;i<=n;i++)
    {
        v[i]=i;
        s[i]=1;
    }
}


int main()
{
    
    while(m--)
    {
        
        
    }    
    
    return 0;
}