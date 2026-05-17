class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # given list of UNDIRECTED edges
        # CONSTRAINT: there is at least 1 edge that causes graph to cycle

        """
        APPROACH
        - disjoint sets
        - return the first edge that creates a cycle
        """

        n = len(edges)
        parent = [i for i in range(n+1)]

        def union(a: int, b: int) -> bool:
            rootA = find(a)
            rootB = find(b)
            if rootA != rootB:
                parent[rootB] = rootA
                return True
            return False
        
        def find(a: int) -> int:
            if parent[a] == a:
                return a
            #path compression
            parent[a] = find(parent[a])
            return parent[a]
        
        for a, b in edges:
            if not union(a, b):
                return [a, b]

        # return the edge that can be removed so the graph is still connected
        # return the last edge in edges if there are multiple answers
        return []
