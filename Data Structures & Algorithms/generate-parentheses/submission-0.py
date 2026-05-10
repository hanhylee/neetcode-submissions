class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # given int n, which is the number of parentheses that are needed
        res = []

        """
        the invariant we need to preserve is that the number of closing
        parentheses cannot be greater than the number of opening at any
        point reading left to right in the string
        """

        def backtrack(string: str, numOpen: int, numClose: int) -> None:
            if numOpen + numClose == n * 2:
                res.append(str(string))

            if numOpen < n:
                string += "("
                backtrack(string, numOpen + 1, numClose)
                string = string[:-1]
            if numClose < numOpen:
                string += ")"
                backtrack(string, numOpen, numClose + 1)
                string = string[:-1]

        backtrack("", 0, 0)

        # return all permutations of these parenthesis such that they are valid
        return res
