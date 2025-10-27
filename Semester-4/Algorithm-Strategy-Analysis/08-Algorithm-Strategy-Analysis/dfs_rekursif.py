def dfs(graph, start, visited):
    if start in visited:
        return
    print(start, end=' ')
    visited.add(start)
    for neighbor in graph[start]:
        dfs(graph, neighbor, visited)

# Example usage
graph = {
    "Ani" : ["Budi"],
    "Budi" : ["Ani", "Caca", "Dina"],
    "Caca" : ["Budi", "Dina"],
    "Dina" : ["Budi", "Caca"],
    "Fikri" : ["Gina"],
    "Gina" : ["Fikri", "Hendra"],
    "Hendra" : ["Gina"]
}

visited = set()
jumlah_graf = 0
for person in graph:
    if person not in visited:
        dfs(graph, person, visited)
        jumlah_graf += 1

print(f"\nJumlah graf pertemanan: {jumlah_graf}")
