class Solution:
    def longestPalindrome(self, s: str) -> str:
        # given string
        res = ""

        # data processing
        """
        go left to right and use each character as center of palindrome
        - account for palindrome that is odd length and even length
        if len(curr) > len(res), res = curr
        """
        def longestOddPalindrome(i: int) -> str:
            offset = 0
            while i + offset < len(s) and i - offset >= 0:
                if s[i-offset] != s[i+offset]:
                    break
                offset += 1
            return s[i-offset+1:i+offset] if offset > 0 else s[i]

        def longestEvenPalindrome(i: int) -> str:
            offset = 0
            while i + offset + 1 < len(s) and i - offset >= 0:
                if s[i-offset] != s[i+offset+1]:
                    break
                offset += 1
            return s[i-offset+1:i+offset+1] if offset > 0 else s[i]
        
        for i in range(len(s)):
            longestOdd = longestOddPalindrome(i)
            res = longestOdd if len(longestOdd) > len(res) else res

            longestEven = longestEvenPalindrome(i)
            res = longestEven if len(longestEven) > len(res) else res
                
        # return longest substring of s that is a palindrome
        return res