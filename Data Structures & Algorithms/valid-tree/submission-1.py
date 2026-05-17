class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # given n nodes
        # given a list of UNDIRECTED edges

        """
        valid tree if... no cycle? and also connected
        so union find
        """
        parent = [i for i in range(n)]

        def union(a: int, b: int) -> bool:
            rootA = find(a)
            rootB = find(b)
            if rootA != rootB:
                parent[rootB] = rootA
                return True
            else:
                return False

        def find(a: int) -> int:
            if parent[a] == a:
                return a
            # path compression
            parent[a] = find(parent[a])
            return parent[a]

        for a, b in edges:
            if not union(a, b):
                return False

        print(parent)

        numRoots = 0
        for i, root in enumerate(parent):
            print(root)
            if numRoots > 1:
                return False
            if root == i:
                numRoots += 1

        # return true if edges make up a valid tree
        return True