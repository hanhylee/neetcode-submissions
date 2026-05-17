from collections import defaultdict

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # given list of UNDIRECTED edges
        # CONSTRAINT: there is at least 1 edge that causes graph to cycle

        """
        APPROACH
        - DFS for cycle detection
        - build graph once and cycle back in a single dfs
        """
        visited = [0 for i in range(len(edges)+1)]
        cycle   = [0 for i in range(len(edges)+1)]

        def buildAdjacencyList() -> dict:
            adj = defaultdict(list)
            for a, b in edges:
                adj[a].append(b)
                adj[b].append(a)
            return adj

        adj = buildAdjacencyList()
        cycleStart = -1

        def dfs(curr: int, parent: int) -> bool:
            nonlocal visited, adj, cycleStart
            if visited[curr] == 1:
                cycleStart = curr
                return True

            visited[curr] = 1
            for neighbor in adj[curr]:
                if neighbor == parent:
                    continue
                if dfs(neighbor, curr):
                    if cycleStart != -1:
                        cycle[curr] = 1
                    if curr == cycleStart:
                        cycleStart = -1
                    return True

            return False
        
        dfs(1, -1)

        for a, b in reversed(edges):
            if cycle[a] and cycle[b]:
                return [a, b]

        # return the edge that can be removed so the graph is still connected
        # return the last edge in edges if there are multiple answers
        return []
