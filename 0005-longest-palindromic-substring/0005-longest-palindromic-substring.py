class Solution:
    def palindrome(self, s, l, r) -> int:
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        l += 1
        r -= 1
        return (r - l + 1), l, r

    def longestPalindrome(self, s: str) -> str:
        res = 0
        st, ed = -1, -1
        for i in range(len(s)):
            a, al, ar = self.palindrome(s, i, i)
            b, bl, br = self.palindrome(s, i, i + 1)
            if a > res:
                res,st, ed = a,al, ar
            if b > res:
                res,st, ed = b,bl, br

        return s[st : ed+1]
