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
  string element;
    int from,to;
    node* child[26];
};

node* get_node()
{
  node* Node = new node;
  Node->is_end = false;
  for(int i=0;i<26;i++)Node->child[i] = NULL;
  return Node; 
}

void insert(string s, node* root,int& c)
{

  node* tmp = root;
    
  for(int i=0;i<s.length();i++)
  {
        int index = (int)s[i]-(int)'A';
        if(!tmp->child[index])
        {
            int from_tmp = tmp->to;
            tmp->child[index] = get_node();
            tmp->child[index]->from = from_tmp;
            tmp->child[index]->to = c+1;
            tmp->child[index]->element = s[i];
            c++;
            cout<<tmp->child[index]->from<<"->"<<tmp->child[index]->to<<":"<<tmp->child[index]->element<<endl;
        }
        tmp = tmp->child[index];

  }
  tmp->is_end = true;
}



int main()
{ 
    node* root = get_node();
    root->from = 0;
    root->to = 0;


    int n,c=0;
    cin>>n;
    string s;

    for(int i=0;i<n;i++)
    {
        cin>>s;
        insert(s,root,c);
    }
    

    

  
    return 0;

  
}