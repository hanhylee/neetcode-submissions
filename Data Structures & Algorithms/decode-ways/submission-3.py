class Solution:
    def numDecodings(self, s: str) -> int:
        # given a string of numbers

        # data processing
        """
        notes:
        - no leading zeroes
        - valid digits: 1-26

        dynamic programming:
        - start from the front to account for leading zeros
        - dp[0] = 1 if s[0] != 0 else 0
        - dp[1] = dp[0] + 1 if 1 <= s[0:2] <= 26 else 0
        - dp[i] = dp[i-1] (if s[i] is valid) + dp[i-2] (if s[i-1:i+1] is valid)
        - return dp[-1]
        """
        if len(s) == 1:
            return 1 if int(s[0]) != 0 else 0

        dp = [0 for c in s]
        dp[0] = 1 if int(s[0]) != 0 else 0
        dp[1] += dp[0] if int(s[1]) != 0 else 0 
        dp[1] += 1 if (1 <= int(s[0:2]) <= 26 and int(s[0]) != 0) else 0

        for i in range(2, len(s)):
            #dp[i] = dp[i-1] (if s[i] is valid) + dp[i-2] (if s[i-1:i+1] is valid)
            dp[i] += dp[i-1] if 1 <= int(s[i]) <= 26 else 0
            dp[i] += dp[i-2] if (1 <= int(s[i-1:i+1]) <= 26 and int(s[i-1]) != 0) else 0

        # return number of ways a string could be decoded
        print(dp)
        return dp[-1]