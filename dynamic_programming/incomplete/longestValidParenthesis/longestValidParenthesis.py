def longestValidParenthesis(s):
    found = [0] * len(s)
    total = 0
    max = 0
    for i in range(len(s)):
        if s[i] == '(':
            found[i] = found[i - 1] + 1
        elif s[i] == ')' and i > 0 and found[i - 1] > 0:
            print found
            found[i] = found[i - 1] - 1
            total = total + 2
            if total > max:
                max = total
        else:
            print "here"
            total = 0
    return total

if __name__ == "__main__":
    #print(longestValidParenthesis("(()"))
    #print(longestValidParenthesis(")()())"))
    #print(longestValidParenthesis("()(())"))
    print(longestValidParenthesis("()(()"))
