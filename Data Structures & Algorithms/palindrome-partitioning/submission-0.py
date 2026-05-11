class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # given string
        res = []
        memo = {}

        """
        brute force approach:
        1. split a string into substrings
        2. check whether each substring is a palindrome

        alternatively:
        1. go from left to right with a center pointer
        2. treat the center pointer as the center of a palindrome
        3. use a while loop and a left and right pointer to determine whether it is a palindrome
        4. for each time it is a palindrome, run partition on left and right substrings
        5. add those to res if all are palindromes (no string left)
        """
        #-------------------------
        def isPalindrome(l: int, r: int) -> bool:
            nonlocal memo
            curr_l, curr_r = l, r

            while curr_l < curr_r:
                if s[curr_l] == s[curr_r]:
                    curr_l += 1
                    curr_r -= 1
                else:
                    return False
            memo[(l, r)] = True
            return True

        #-------------------------
        def backtrack(partitions: List[str], idx: int) -> None:
            if idx == len(s):
                print(f"appending {partitions}")
                res.append(partitions.copy())
                return

            # test if all characters form a palindrome
            l, r = idx, idx
            while r < len(s):
                if isPalindrome(l, r):
                    partitions.append(s[l:r+1])
                    backtrack(partitions, r+1)
                    partitions.pop()
                r += 1

        #-------------------------
            
        backtrack([], 0)

        # return all LISTs of palindromic substrings
        return res
