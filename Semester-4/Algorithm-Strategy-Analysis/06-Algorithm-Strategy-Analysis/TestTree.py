import networkx as nx
import matplotlib.pyplot as plt

G = nx.DiGraph()

# Menambahkan simpul
G.add_edges_from([
    (".-..-", ". -.. -"), (".-..-", ".- ..- -"), (".-..-", ". .-.. -"), (".-..-", ". -..- -"),
    (". -.. -", "E"), (".- ..- -", "A"), (". .-.. -", "E"), (". -..- -", "E"),
    ("A", "U"), ("U", "T"), ("E", "L"), ("L", "T"), ("E", "D"), ("D", "T"), ("E", "X"), ("X", "T")
])

# Gambar graf
plt.figure(figsize=(10, 6))
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_size=3000, node_color="lightblue", edge_color="gray", font_size=10)
plt.show()
