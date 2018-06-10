def lengthOfSubstr(s):
    dict = {}
    i = 0
    j = 0
    n = len(s)
    maximum = 0
    while (i < n and j < n):
        if (s[j] in dict):
            i = max(i,dict[s[j]] + 1)
        dict[s[j]] = j
        j = j + 1
        if (maximum < j - i):
            maximum = j - i
    return maximum

if __name__ == "__main__":
    str0 = "abcde"
    str1 = "abcabcbb"
    str2 = "bbbbb"
    str3 = "pwwkew"
    str4 = "a"
    str5 = ""
    str6 = "ohom"
    str7 = "au"
    str8 = "abba"
    print(lengthOfSubstr(str0))
    print(lengthOfSubstr(str1))
    print(lengthOfSubstr(str2))
    print(lengthOfSubstr(str3))
    print(lengthOfSubstr(str4))
    print(lengthOfSubstr(str5))
    print(lengthOfSubstr(str6))
    print(lengthOfSubstr(str7))
    print(lengthOfSubstr(str8))
