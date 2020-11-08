# time complexity O(n3)
# space complexity O(n2)

def FloydWarshall(v):

    n = len(v)

    dist = [[float('inf') for j in range(n)] for i in range(n)]

    for i in range(n):
        for j in range(n):
            dist[i][j]=v[i][j]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])


    print(dist)


INF = float('inf')
G = [[0, 3, INF, 5],
     [2, 0, INF, 4],
     [INF, 1, 0, INF],
     [INF, INF, 2, 0]]

FloydWarshall(G)



    



