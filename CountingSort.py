# time complexity O(n+k)
# space complexity O(n+k)

def CountingSort(v,n,k):
    # k is number of unique elements

    # count array
    count = [0]*(max(v)+1)
    for i in v:
        count[i]+=1

    # running sum

    summ = [0]*len(count)
    summ[0] = count[0]

    for i in range(1,len(summ)):
        summ[i] = count[i]+summ[i-1]

    # sorted array
    res = [0]*n
    for i in range(n):
        res[summ[v[i]]-1] = v[i]
        summ[v[i]]-=1
    print(res)


    
  v = list(map(int,input().split()))

  n=len(v)
  k = len(set(v))

  print(v)
  CountingSort(v,n,k)




    



