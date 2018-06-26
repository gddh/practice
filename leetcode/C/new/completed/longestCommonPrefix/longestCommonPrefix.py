class Solution(object):
    def commonPrefix(self,str1, str2):
        i = 0
        while (i < len(str1) and i < len(str2) and str1[i] == str2[i]):
            i = i + 1
        return str1[:i]

    def longestCommonPrefix(self, strs):
        if (len(strs) < 1):
            return ""
        i = 1
        prefix = strs[0]
        while (i < len(strs)):
            prefix = self.commonPrefix(strs[i], prefix)
            i = i + 1
        return prefix

lst = ["abc", "abcd", "abce", "ab"]

print(Solution().longestCommonPrefix(lst))
