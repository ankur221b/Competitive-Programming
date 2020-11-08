# time complexity O(n)

from random import randint

def partition(v,l,r):
    idx = randint(l,r) # random pivoting
    v[idx],v[r] = v[r],v[idx]
    pivot = v[r]
    tmp = l
    for i in range(l,r):
        if v[i]<=pivot:
            v[i],v[tmp] = v[tmp],v[i]
            tmp+=1
    v[tmp],v[r]=v[r],v[tmp]
    return tmp

def quickselect(v,k,l,r):
    
    if r==l:
        return v[l]
        
    idx = partition(v,l,r)

    if idx-l==k-1:
        return v[idx]
    if idx-l>k-1:
        return quickselect(v,k,l,idx-1)
    else:
        return quickselect(v,k-(idx-l+1),idx+1,r)

n = int(input())
v = list(map(int,input().split()))
k = int(input())
print(quickselect(v,k,0,n-1))
