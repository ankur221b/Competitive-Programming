# time complexity 
#     best case O(n log n)
#     average case O(n log n)
#     worst case O(n2) The worst case occurs when the partition process always picks greatest or smallest element as pivot

# space complexity (used by call stack)
#     O(n) generally
#     O(log n) using tail recursion
    


def partition(v,s,e):
    pivot = v[e]
    idx = s

    for i in range(s,e):
        if v[i]<=pivot:
            v[i],v[idx]=v[idx],v[i]
            idx+=1
    v[idx],v[e]=v[e],v[idx]

    return idx


def quick(v,s,e):

    if s>=e:
        return

    p = partition(v,s,e)
    quick(v,s,p-1)
    quick(v,p+1,e)


v = list(map(int,input().split()))

quick(v,0,len(v)-1)

print(v)
