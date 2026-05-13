import heapq

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # given 2d array of integers
        # each int represents height above sea level
        # pacific ocean to the top and left
        # atlantic ocean to the right and bottom
        # water flows in 4 directions to a neighboring cell with height equal or lower

        """
        approach: 
        - create min priority queue of heights
        - track if they drain into pacific (1) or atlantic (2) or both (3) or neither (0) by considering all neighbors
        - if they drain into both, add to result
        """
        ROWS, COLS = len(heights), len(heights[0])
        drainsToPacific = set()
        drainsToAtlantic = set()
        res = []

        #============
        def dfs(drainsTo: set, r: int, c: int) -> None:
            drainsTo.add((r, c))
            for direction in [(r-1, c), (r+1, c), (r, c-1), (r, c+1)]:
                if direction in drainsTo:
                    continue
                i, j = direction
                if 0 <= i < ROWS and 0 <= j < COLS and heights[i][j] >= heights[r][c]:
                    dfs(drainsTo, i, j)
        #============
        
        # run dfs on each edge
        for i in range(ROWS):
            dfs(drainsToPacific, i, 0)
            dfs(drainsToAtlantic, i, COLS-1)
        for j in range(COLS):
            dfs(drainsToPacific, 0, j)
            dfs(drainsToAtlantic, ROWS-1, j)

        print(drainsToPacific)
        print(drainsToAtlantic)
        
        for coord in drainsToPacific:
            if coord in drainsToAtlantic:
                i, j = coord
                res.append([i, j])

        # return list of cells that flow to both atlantic and pacific oceans
        return res
