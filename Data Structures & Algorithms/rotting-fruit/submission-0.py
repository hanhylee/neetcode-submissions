from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # given 2d array of integers
        # 0 = empty cell
        # 1 = fresh fruit
        # 2 = rotten fruit

        # fruit becomes rotten if it is adjacent to a rotten fruit

        """
        approach
        - go through the grid and get positions of rotten fruits and number of fresh fruits
        - apply BFS to turn fresh fruits to rotten until complete
        - if any fresh fruit remaining, return -1 else return minutes
        """
        ROWS, COLS = len(grid), len(grid[0])
        q = deque()
        numFreshFruit = 0
        minutes = 0

        #=========================
        def bfs():
            nonlocal ROWS, COLS, q, numFreshFruit, minutes
            while q:
                r, c, time = q.popleft()
                minutes = max(minutes, time)
                for i, j in [(r-1, c), (r+1, c), (r, c-1), (r, c+1)]:
                    if 0 <= i < ROWS and 0 <= j < COLS and grid[i][j] == 1:
                        grid[i][j] += 1
                        numFreshFruit -= 1
                        q.append((i, j, time+1))

        #=========================

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    q.append((r,c,0))
                if grid[r][c] == 1:
                    numFreshFruit += 1
        
        bfs()

        # return min number of minutes till there are no fresh fruits remaining
        # if impossible, return -1
        return -1 if numFreshFruit > 0 else minutes
