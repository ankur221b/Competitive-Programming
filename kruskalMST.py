# time complexity O(E log V) or O(E log E)

def make_set(v,parent,size):
    parent[v] = v
    size[v] = 1

def find_set(v):
    
    while parent[v]!=v:
        v = parent[parent[v]]
    
    return v

def union_set(a,b,size,parent):

    a = find_set(a)
    b = find_set(b)

    if a != b:
        if size[a]<size[b]:
            a,b = b,a
    
        parent[b] = a
        size[a] += size[b]
        size[b]=0

def kruskalMST(edges,size,parent):
    edges.sort()
    total = 0
    for i in edges:
        u,v,w = i[1],i[2],i[0]

        if find_set(u)!=find_set(v):
            union_set(u,v,size,parent)
            total += w
    print(total)


n,m = map(int,input().split())

parent = [0]*(n+1)
size = [0]*(n+1)

for i in range(1,n+1):
    make_set(i,parent,size)

edges = []

for i in range(m):
    u,v,w = map(int,input().split())
    edges.append([w,u,v])
    edges.append([w,v,u])


kruskalMST(edges,size,parent)
