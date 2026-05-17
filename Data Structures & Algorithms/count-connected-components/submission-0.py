class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # given graph of n nodes from 0 to n-1
        # given list of edges

        parent = [i for i in range(n)]

        def union(a: int, b: int) -> None:
            rootA = find(a)
            rootB = find(b)
            if rootA != rootB:
                parent[rootB] = rootA
        
        def find(a: int) -> int:
            if parent[a] == a:
                return a
            #path compression
            parent[a] = find(parent[a])
            return parent[a]

        for a, b in edges:
            union(a, b)

        res = 0
        for i, root in enumerate(parent):
            if root == i:
                res += 1

        # return number of connected components
        return res
