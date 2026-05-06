class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False
        if len(s) == 0:
            return True
        
        s_idx = 0;

        for c in t:
            if s_idx == len(s) - 1:
                return True
            if s[s_idx] == c:
                s_idx += 1;
                print(f"found {c}")
        
        return False;