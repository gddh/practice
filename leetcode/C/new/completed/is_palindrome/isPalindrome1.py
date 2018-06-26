class Solution:
    def isPalindrome(self, x):
        if (x < 0):
            return False
        temp = x
        second_num = 0
        while (temp > 0):
            second_num = (temp % 10) + second_num * 10
            temp = temp // 10
        return second_num == x


print(Solution().isPalindrome(0))
