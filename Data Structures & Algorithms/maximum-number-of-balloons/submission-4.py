import math

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = {}

        for word in text:
            if word in freq:
                freq[word] += 1
            else:
                freq[word] = 1
        
        min_val = math.inf;
        for c in "ban":
            if c in freq:
                min_val = min(min_val, freq[c]);
            else:
                min_val = 0;

        for c in "lo":
            if c in freq:
                min_val = min(min_val, freq[c] // 2);
            else:
                min_val = 0;

        return min_val == math.inf if 0 else min_val;