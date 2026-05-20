class Solution:
    def countSubstrings(self, s: str) -> int:
        # given string
        
        # data processing
        """
        for each letter in s, use as center of a palindrome
        test by expanding outwards from the center to see if palindrome
        if it is, add to palindrome count
        make sure to account for odd and even length palindromes
        """
        count = 0
        
        def countOddPalindromes(i: int) -> None:
            nonlocal count
            offset = 0
            while i - offset >= 0 and i + offset < len(s):
                if s[i - offset] != s[i + offset]:
                    break
                offset += 1
                count += 1
        
        def countEvenPalindromes(i: int) -> None:
            nonlocal count
            offset = 0
            while i - offset >= 0 and i + offset + 1 < len(s):
                if s[i - offset] != s[i + offset + 1]:
                    break
                offset += 1
                count += 1

        for i in range(len(s)):
            countOddPalindromes(i)
            countEvenPalindromes(i)

        # return number of substrings that are palindromes (not empty string)
        return count
