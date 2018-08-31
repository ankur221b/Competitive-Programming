#include <iostream>
using namespace std;
#define ll long long 

ll merge(ll *v,ll start,ll mid,ll end)
{
    ll tmp[end-start+1], p=start, q=mid+1, k=0, inversion=0 ;
    
    while(p<=mid && q<=end)
    {
        if(v[p]>v[q])
        {
            tmp[k] = v[q];
            q++;
            k++;
            inversion += (mid-p+1); // inversion count
        }
        else
        {
            tmp[k] = v[p];
            p++;
            k++;
        }
    }
    
   
    while(p<=mid)
    {
        tmp[k]=v[p];
        p++;
        k++;
    }
   
    while(q<=end)
    {
        tmp[k]=v[q];
        q++;
        k++;
    }
   
    // copying elements from temporary array
    for(int i=0;i<k;i++)
    {
        v[start++]=tmp[i];
    }

    return inversion;

}

ll mergesort(ll *v,ll start,ll end)
{
    ll inversion=0;

    if(start>=end)return 0; //Base case

    ll mid = (start+end) >> 1;

    inversion += mergesort(v,start,mid); //sort left half
    inversion += mergesort(v,mid+1,end); //sort right half
    
    inversion += merge(v,start,mid,end);  //merging both halves
    
    return inversion;
}

int main() {
    ll n;
    cin>>n;
    ll v[n];
    for(int i=0;i<n;i++)cin>>v[i];

    ll inversions = mergesort(v,0,n-1);

    cout << inversions << endl;

    for(int i:v)cout<<i<<" "; 
    
}
