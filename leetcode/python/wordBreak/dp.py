def wordBreak(s, wordDict):
    size = len(s)
    breaks = [False] * size
    for i in range(size):
        if breaks[i] == False and s[0 : i + 1] in wordDict:
            breaks[i] = True
        if breaks[i] == 1:
            for j in range(len(s[i + 1:])):
                if (s[i + 1 : i + 1 + j + 1] in wordDict):
                    breaks[i + j + 1] = True
                if (i + j + 1 == size - 1 and breaks[j + i + 1] == True):
                    return True
    return breaks[size - 1]

if __name__ == "__main__":
    s = "leetcode"
    wordDict = ["leet", "code"]
    print(wordBreak(s, wordDict))
    s = "leetcodeleet"
    wordDict = ["leet", "code"]
    print(wordBreak(s, wordDict))
    s = "applepenapple"
    wordDict = ["apple", "pen"]
    print(wordBreak(s, wordDict))
    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    print(wordBreak(s, wordDict))
    s = "a"
    wordDict = ["a"]
    print(wordBreak(s, wordDict))
    s = "ab"
    wordDict = ["a", "b"]
    print(wordBreak(s, wordDict))

