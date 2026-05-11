class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # given number of queens to put on a board
        res = []

        """
        APPROACH
        - backtracking putting queens in position
        - add state to res if n queens are on the board
        - backtrack if invalid queen position
        """
        #-----------------
        # returns true if there are no queens in the same row, col and diag
        # we're using a single idx instead of 2 coordinates
        # on a 4x4 board, idx 5 refers to (1, 1) this is calculated by:
        # y = idx // n      = 5 // 4    = 1
        # x = idx - y * n   = 5 - 4 * 1 = 1
        def validQueen(state: set[int], idx: int) -> bool:
            y = idx // n
            x = idx - y * n

            if not state:
                return True

            for queen_idx in state:
                queen_y = queen_idx // n
                queen_x = queen_idx - queen_y * n

                # check row
                if queen_y == y:
                    # print(f"queen invalid due to row conflict")
                    return False

                # check col
                if queen_x == x:
                    # print(f"queen invalid due to col conflict")
                    return False

                # check diag
                if abs(queen_x - x) == abs(queen_y - y):
                    return False
            
            # print(f"queen valid at ({y}, {x})")
            return True

        #-----------------
        def saveBoard(state: set[int]) -> None:
            nonlocal res
            board = []
            for i in range(n):
                row = ""
                for j in range(n):
                    if (i * n + j) in state:
                        row += "Q"
                    else:
                        row += "."
                board.append(row)
            print(board)
            res.append(board)

        #-----------------
        def backtrack(state: set[int], numQueens: int, idx: int) -> bool:
            nonlocal res
            if numQueens == n:
                saveBoard(state)
                return
            
            for i in range(idx, n**2):
                if validQueen(state, i):
                    state.add(i)
                    backtrack(state, numQueens+1, (i // n + 1) * n)
                    state.discard(i)

        #-----------------
        backtrack(set(), 0, 0)

        # return distinct solutions to puzzle as a list of list of strings
        # each list represents a solution, each string in the list represents a row
        # "." is an empty space, "Q" is a queen
        return res
