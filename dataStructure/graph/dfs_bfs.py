class GraphTraversal(object):
    def __init__(self, adj_table):
        self.adj_table = adj_table
        self.num_nodes = len(adj_table)
        self.visited = set()

    def dfs(self, node):
        print(node)
        self.visited.add(node)
        for n, adj in enumerate(self.adj_table[node]):
            if adj and n not in self.visited:
                self.visited.add(n)
                self.dfs(n)

    def dfs_complete(self):
        for n, _ in enumerate(self.adj_table):
            if n not in self.visited:
                self.dfs(n)


    def bfs(self, node):
        queue = [node]
        while queue:
            vertex = queue.pop()
            for n, adj in enumerate(self.adj_table[vertex]):
                if adj and n not in self.visited:
                    print(n)
                    self.visited.add(n)
                    queue.append(n)

        # Search Disconnected Component
        for n, _ in enumerate(self.adj_table):
            if n not in self.visited:
                self.bfs(n)
            


t = [[1,0,1,1],[0,1,0,0],[1,0,1,0],[1,0,0,1]]
g = GraphTraversal(t)

# g.dfs(0)
g.dfs_complete()
g.visited.clear()
# g.bfs(0)
# g.visited.clear()
    

