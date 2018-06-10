def lengthOfSubstr(s):
    i = 0
    j = 0
    max = 0
    n = len(s)
    seen = set()
    while (i < n and j < n):
        if (s[j] in seen):
            seen.remove(s[i])
            i = i + 1
        else:
            seen.add(s[j])
            j = j + 1
            if (max < j - i):
                max = j - i
    return max


if __name__ == "__main__":
    str0 = "abcde"
    str1 = "abcabcbb"
    str2 = "bbbbb"
    str3 = "pwwkew"
    str4 = "au"
    str5 = "a"
    str6 = ""
    str7 = "ohom"
    print(lengthOfSubstr(str0))
    print(lengthOfSubstr(str1))
    print(lengthOfSubstr(str2))
    print(lengthOfSubstr(str3))
    print(lengthOfSubstr(str4))
    print(lengthOfSubstr(str5))
    print(lengthOfSubstr(str6))
    print(lengthOfSubstr(str7))






