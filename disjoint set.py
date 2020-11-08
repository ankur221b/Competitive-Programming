
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
