graph = {
    'a': {'b': 2, 'c': 3},
    'b': {'a': 2, 'c': 1, 'd': 4},
    'c': {'a': 3, 'b': 1, 'd': 5, 'e': 6},
    'd': {'b': 4, 'c': 5, 'e': 2},
    'e': {'c': 6, 'd': 2}
}

class Set:
    def __init__(self):
        self.parent = {}
        self.rank = {}
    def make_set(self, x):
        self.parent[x] = x
        self.rank[x] = 0
    def link(self, x, y):
        if self.rank[x] > self.rank[y]:
            self.parent[y] = x
        else:
            self.parent[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] = self.rank[y] + 1
    def find_set(self, x):
        if not x == self.parent[x]:
            self.parent[x] = self.find_set(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        self.link(self.find_set(x), self.find_set(y))

def kruskal(graph):
    mst = []
    set = Set()
    for vertex in graph:
        set.make_set(vertex)
    edges = []
    for u in graph:
        for v, w in graph[u].items():
            if (v, u, w) not in edges:
                edges.append((u, v, w))
    edges.sort(key=lambda x: x[2])
    for u, v, w in edges:
        if set.find_set(u) != set.find_set(v):
            mst.append((u, v, w))
            set.union(u, v)
    return mst

tree = kruskal(graph)
print("Edges in MST:", tree)
