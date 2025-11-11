class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(1, x):
            if i * i > x:
                return i - 1
        return 1