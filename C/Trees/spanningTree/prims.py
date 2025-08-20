import math
from queue import PriorityQueue

graph = {
    'a': {'b': 2, 'c': 5},
    'b': {'a': 2, 'c': 1, 'd': 4},
    'c': {'a': 5, 'b': 1, 'd': 3, 'e': 7},
    'd': {'b': 4, 'c': 3, 'e': 6},
    'e': {'c': 7, 'd': 6}
}

def init_graph(graph, start):
    key = {}
    parent = {}
    for vertex in graph.keys():
        key[vertex] = math.inf
        parent[vertex] = None
    key[start] = 0
    return key, parent

def prim(graph, start):
    key, parent = init_graph(graph, start)
    q = PriorityQueue()
    queue_items = []
    for vertex in graph.keys():
        q.put((key[vertex], vertex))
        queue_items.append(vertex)
    while not q.empty():
        _, temp = q.get()
        if temp in queue_items:
            queue_items.remove(temp)
        for neighbor in graph[temp].keys():
            weight = graph[temp][neighbor]
            if (neighbor in queue_items) and (weight < key[neighbor]):
                parent[neighbor] = temp
                key[neighbor] = weight
                q.put((key[neighbor], neighbor))
    return key, parent

s = 'a'
key, parent = prim(graph, s)
print(key)
print(parent)
