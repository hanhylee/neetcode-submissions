class Solution:
    def isHappy(self, n: int) -> bool:
        # given positive int

        # data processing
        """
        replace number with the sum of the squares of its digits
        repeat this until number == 1 or infinitely loops
        """
        def sumOfDigitsSquared(n: int) -> int:
            digitsSquared = 0
            while n != 0:
                digit = n % 10
                digitsSquared += digit**2
                n = n // 10
            return digitsSquared

        prev = set()

        while n != 1:
            print(n)
            if n in prev:
                return False
            prev.add(n)
            n = sumOfDigitsSquared(n)

        # return true if int is a non-cyclical number else false
        return True