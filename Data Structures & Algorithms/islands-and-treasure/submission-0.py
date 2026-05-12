from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # given 2d array of integers
        # -1 = water cell that cannot be traversed
        # 0 = treasure chest
        # INF = land cell that can be traversed
        INF = 2147483647

        # fill each land cell with the distance to its nearest treasure chest
        # if a land cell cannot reach a treasure chest, then value stays INF
        # traversal can only occur UP, DOWN, LEFT, RIGHT

        """
        approach:
        - distance = number of cells that need to be traversed
        - from each treasure, we can do BFS to fill the land with the distance from the treasure
        - we keep the minimum value at that land cell
        - we ignore water cells and treasure cells
        """
        q = deque()

        #=============================
        def bfs() -> None:
            nonlocal q
            
            while q:
                curr = q.popleft()
                i, j, dist = curr

                # water check
                if grid[i][j] < -1:
                    continue
                
                for y, x in [(i-1, j), (i+1, j), (i, j+1), (i, j-1)]:
                    if 0 <= y < len(grid) and 0 <= x < len(grid[0]) and grid[y][x] == INF:
                        grid[y][x] = dist+1
                        q.append((y, x, dist+1))

        #=============================
        
        # find all treasures and add to queue
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    q.append((i, j, 0))
        
        # run multi-source BFS
        bfs()

        # modify grid in place (no return)
