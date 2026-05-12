class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # given 2d array of integers
        # 1 = land
        # 0 = water

        max_area = 0

        """
        APPROACH:
        - DFS to get all islands -> replace cells with 0 while counting island size
        - max_area = max(max_area, dfs(cell))
        """
        #============================
        def outOfBounds(i: int, j: int) -> bool:
            if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
                return True
            return False

        # returns area of connected islands
        def dfs(i: int, j: int) -> int:
            # termination steps: bounds check, visited, isLand
            if outOfBounds(i, j):
                return 0
            if grid[i][j] == 0:
                return 0
            
            grid[i][j] = 0

            north = dfs(i-1, j)
            south = dfs(i+1, j)
            east = dfs(i, j+1)
            west = dfs(i, j-1)
            
            return 1 + north + south + east + west

        #============================

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                max_area = max(max_area, dfs(i, j))

        # return maximum area of island in grid
        return max_area
