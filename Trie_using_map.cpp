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
#define MAX 100001
#define MOD 1000000007
#define mod 100000

struct node
{
	bool is_end;
	unordered_map<char,node*> map;
};

node* get_node()
{
	node* Node = new node;
	Node->is_end=false;
	return Node; 
}

void insert(string s, node* root)
{
	if(root == nullptr)root = get_node();

	node* tmp = root;
    char x;
	for(int i=0;i<s.length();i++)
	{
		x = s[i];
		if(tmp->map.find(x) == tmp->map.end())
		{
			tmp->map[x] = get_node();
		}
		tmp=tmp->map[x];
	}
	tmp->is_end = true;
}

bool search(string s, node* root)
{
	if(root == nullptr)return false;

	node* tmp = root;

	for(int i=0;i<s.length();i++)
	{
		tmp = tmp->map[s[i]];

		if(tmp == nullptr)return false;
	}

	return tmp->is_end;
}

int main()
{	
    node* root = get_node();

   
  
    return 0;

  
}-
