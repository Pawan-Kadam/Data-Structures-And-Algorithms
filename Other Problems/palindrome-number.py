# LeetCode - 9. Palindrome Number
# Link - https://leetcode.com/problems/palindrome-number/


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        old = x
        new = 0
        
        while x > 0:
            new = new*10 + x%10
            x //= 10
            
        return old == new
