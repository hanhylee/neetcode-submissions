class Solution:
    def solve(self, board: List[List[str]]) -> None:
        # given 2d array of "X" and "O"
        # a group of "O" is surrounded if all adjacent cells of the group are "X"

        """
        approach:
        find groups of "O" that are from the edge
        turn all other "O" to "X"
        """

        ROWS, COLS = len(board), len(board[0])

        #=================
        def dfs(r: int, c: int) -> None:
            nonlocal ROWS, COLS

            if r < 0 or c < 0 or r >= ROWS or c >= COLS:
                return
            if board[r][c] != "O":
                return
            board[r][c] = "M"
            for direction in [(r-1, c), (r+1, c), (r, c+1), (r, c-1)]:
                i, j = direction
                dfs(i, j)

        #=================

        # convert "O" belonging to island connected to edge to "A"
        for r in range(ROWS):
            dfs(r, 0)
            dfs(r, COLS-1)
        for c in range(COLS):
            dfs(0, c)
            dfs(ROWS-1, c)

        # convert "O" to "X" and convert "M" to "O"
        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "M":
                    board[r][c] = "O"

        # modify all surrounded "O" to "X"
        # no return