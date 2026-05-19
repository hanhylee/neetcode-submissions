class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # given int array
        # digits[i] = ith digit of large integer
        # ordered from most sig to least sig digit (left to right)

        # CONSTRAINT: no leading zero

        # data processing
        """
        start from the rightmost digit
        if need to carry over, process the next digit
        continue till reach index 0
        if need to carry over, insert element 1 at index 0
        """

        i = len(digits)-1
        digits[i] += 1

        while digits[i] == 10:
            digits[i] = 0
            i -= 1
            if i >= 0:
                digits[i] += 1
            else:
                digits.insert(0, 1)

        # return array after incrementing integer by 1
        return digits