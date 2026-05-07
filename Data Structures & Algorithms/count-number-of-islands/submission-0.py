class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # input: 2d array of 1's and 0's
        # 1 represents land
        # 0 represents water
    
        """
        APPROACH:
        - DFS? mark lands as 0
        """

        res = 0

        def isValid(x: int, y: int) -> bool:
            # bounds check
            if x < 0 or y < 0 or y >= len(grid) or x >= len(grid[0]):
                return False
            
            # valid value check
            if grid[y][x] == "0":
                return False

            return True

        def dfs(x: int, y: int) -> None:
            north = (x, y-1)
            south = (x, y+1)
            east = (x-1, y)
            west = (x+1, y)

            for direction in [north, south, east, west]:
                i, j = direction
                if isValid(i, j):
                    grid[j][i] = "0"
                    dfs(i, j)

        for y in range(len(grid)):
            for x in range(len(grid[0])):
                if grid[y][x] == "1":
                    print(f"found island starting at ({x}, {y})")
                    res += 1
                    dfs(x, y)

        # output: return number of islands
        return res