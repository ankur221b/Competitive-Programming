# time complexity O(v2)
# space complexity O(v2)

from collections import defaultdict
INF = 10000000000

def min_key(key,vis):

    mi,idx = INF,-1

    for i in range(len(key)):
        if not vis[i] and key[i]<mi:
            mi=key[i]
            idx=i

    return idx

def primsMST(graph):
    n = len(graph)
    weight = 0
    vis = defaultdict(bool)

    key = [INF for i in range(n)]
    
    key[0]=0

    for i in range(n):
        u = min_key(key,vis)
        vis[u]=True
        weight += key[u]
        for v in range(n):
            if u!=v and not vis[v] and graph[u][v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
    
    print(weight)


graph = [[ 0, 2, 0, 6, 0 ], 
        [ 2, 0, 3, 8, 5 ], 
        [ 0, 3, 0, 0, 7 ], 
        [ 6, 8, 0, 0, 9 ], 
        [ 0, 5, 7, 9, 0 ]];

primsMST(graph)
