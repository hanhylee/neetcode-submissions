from functools import reduce
import operator
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # Runs the XOR operation entirely in C
        return reduce(operator.xor, nums)
