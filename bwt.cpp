#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 10001
#define MOD 1000000007
#define mod 100000


int main()
{
    string s;
    cin>>s;
    int n=s.length();

    vector<char> v(all(s));
    vector< vector<char> > vv;

    vv.push_back(v);

    for(int i=0;i<s.length()-1;i++)
    {
    	char tmp=v.back();
    	v.pop_back();
    	v.insert(v.begin(),tmp);
    	vv.push_back(v);
    }

    sort(all(vv));
    for(int i=0;i<vv.size();i++)
    {
    	cout<<vv[i][n-1];
    }


 



    
  
}