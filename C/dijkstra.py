import math

G = {
    's':{'t':10, 'y':5},
    't':{'x':1, 'y':2},
    'x':{'z':4, },
    'y':{'x':9, 't':3, 'z':2},
    'z':{'x':6, 's':7}
}



def INITIALIZE_SIGNAL_SOURCE(G, s):
    cost = dict()
    prev = dict()
    for vertex in G.keys():
        cost[vertex] = math.inf 
        prev[vertex] = " "
    cost[s] = 0 
    return cost,prev

def RELAX(G, u, v, cost, prev):
    
    if cost[v] > cost[u] + G[u][v]:
        cost[v] = cost[u] + G[u][v]
        prev[v] = u
    return cost, prev


from queue import PriorityQueue


def DJ(G, s):
    cost, prev = INITIALIZE_SIGNAL_SOURCE(G, s)
    PQ = PriorityQueue()
    PQ.put((0, s))  
    visited = set()

    while not PQ.empty():
        current_cost, currentVertex = PQ.get()
        if currentVertex in visited:
            continue
        visited.add(currentVertex)

        for neighbor in G[currentVertex]:
            if neighbor not in visited:
                cost, prev = RELAX(G, currentVertex, neighbor, cost, prev)
                PQ.put((cost[neighbor], neighbor))  
    
    return cost, prev


def RECONSTRUCT_PATH(vertex, prev):
    path = vertex
    while prev[vertex] != " ":
        path = prev[vertex]+'->'+path
        vertex = prev[vertex]
    return path

s = 's'
cost, prev = DJ(G,s)
print(cost)
print(prev)
for vertex in G.keys():
    print(f'Shortest path from {s} to {vertex} is {RECONSTRUCT_PATH(vertex,prev)}')
    print(f'Cost is {cost[vertex]}')






