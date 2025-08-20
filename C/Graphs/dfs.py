graph = {
    'A': ['B', 'C'],
    'B': ['A', 'C'],
    'C': ['A', 'B', 'D'],
    'D': ['C', 'E', 'F'],
    'E': ['D', 'F'],
    'F': ['D', 'E']
}

def DFS(graph, start):
    visited = []
    stack = []
    stack.append(start)
    while len(stack) != 0:
        temp = stack.pop()
        if temp not in visited:
            visited.append(temp)
            for node in reversed(graph[temp]):  # reverse to keep traversal order consistent
                if node not in visited:
                    stack.append(node)
            
    print("The order of traversal is:")
    traversal_order = visited[0]
    for item in visited[1:]:
        traversal_order += f" -> {item}"
    print(traversal_order)

DFS(graph, 'A')
