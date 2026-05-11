class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = []
        
        #----------------------
        def dfs(word: str, visited: set[int], idx: int, i: int, j: int) -> bool:
            # termination step
            if idx == len(word):
                return True

            # bounds check
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
                return False
            
            # visited check
            if (i, j) in visited:
                return False

            # letter check
            if word[idx] != board[i][j]:
                return False

            # recursion
            visited.add((i, j))
            north = dfs(word, visited, idx+1, i-1, j) 
            south = dfs(word, visited, idx+1, i+1, j) 
            east = dfs(word, visited, idx+1, i, j+1) 
            west = dfs(word, visited, idx+1, i, j-1)
            return north or south or east or west

        #----------------------
        for i in range(len(board)):
            for j in range(len(board[0])):
                for word in words:
                    if dfs(word, set(), 0, i, j):
                        if word not in res:
                            res.append(word)

        return res