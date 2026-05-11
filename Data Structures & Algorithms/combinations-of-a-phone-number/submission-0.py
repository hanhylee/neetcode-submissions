class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []

        res = []
        numLetters = {
            "2": ["A","B","C"],
            "3": ["D","E","F"],
            "4": ["G","H","I"],
            "5": ["J","K","L"],
            "6": ["M","N","O"],
            "7": ["P","Q","R","S"],
            "8": ["T","U","V"],
            "9": ["W","X","Y","Z"],
        }

        #------------------
        def backtrack(stack: str, idx: int) -> None:
            nonlocal res, numLetters

            if idx == len(digits):
                res.append(stack.lower())
                return

            for letter in numLetters[digits[idx]]:
                stack += letter
                backtrack(stack, idx+1)
                stack = stack[:-1]
                
        #------------------

        backtrack("", 0)

        return res