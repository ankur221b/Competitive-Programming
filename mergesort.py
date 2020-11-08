# time complexity O(n log n)
# space complexity O(n)

def merge(left,right,v):
    n,m = len(left),len(right)
    i,j,k = 0,0,0

    while i<n and j<m:
        if left[i]<right[j]:
            v[k] = left[i]
            i+=1
            k+=1
        else:
            v[k] = right[j]
            j+=1
            k+=1
    
    while i<n:
        v[k] = left[i]
        i+=1
        k+=1
    
    while j<m:
        v[k] = right[j]
        j+=1
        k+=1

def mergesort(v):
    n = len(v)
    if n<2:
        return
    m = n//2

    left,right = [],[]

    for i in range(m):
        left.append(v[i])
    for i in range(m,n):
        right.append(v[i])

    mergesort(left)
    mergesort(right)
    merge(left,right,v)
    
  v = [2,6,7,4,8,3,1,5]
  
  mergesort(v)

  print(v)



    



