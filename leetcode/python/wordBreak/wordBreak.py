def wordBreak(s, wordDict):
    if (not s):
        return True
    return any([wordBreak(s[len(word):], wordDict) for word in wordDict if s.startswith(word)])

if __name__ == "__main__":
    s0 = "leetcode"
    s1 = "applepenapple"
    s2 = "catsandog"
    wordDict0 = ["leet", "code"]
    wordDict1 = ["apple", "pen"]
    wordDict2 = ["cats", "dog", "sand", "and", "cat"]
    print(wordBreak(s0, wordDict0))
    print(wordBreak(s1, wordDict1))
    print(wordBreak(s2, wordDict2))
