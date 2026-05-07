class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # input: 2d array of strings (1 char) and word to find
        
        """
        APPROACH:
        - backtracking
        - start from each char that the string starts with
        - search through valid neighbors (in bounds, not visited)
        - base case: all characters in word have been found -> return true
        - if neighbor is not what we're looking for, return
        """

        def isValid(coord: tuple, visited: List[tuple]) -> bool:
            # bounds check
            x, y = coord
            if x < 0 or y < 0:
                return False
            if x >= len(board[0]) or y >= len(board):
                return False
            
            # visited check
            if coord in visited:
                return False
            
            return True

        def backtrack(coord: tuple, visited: List[tuple], idx: int) -> bool:
            x, y = coord
            if idx > len(word):
                return False
            if board[y][x] != word[idx]:
                return False
            if idx == len(word) - 1 and board[y][x] == word[idx]:
                return True
        
            north = (x, y-1)
            south = (x, y+1)
            west = (x-1, y)
            east = (x+1, y)

            for direction in [north, south, west, east]:
                visited.append(coord)
                if isValid(direction, visited):
                    if backtrack(direction, visited, idx + 1):
                        return True
                visited.pop()
            
            return False

        for j in range(len(board)):
            for i in range(len(board[0])):
                if backtrack((i,j), [], 0):
                    return True

        # return: true if word is present in grid
        return False