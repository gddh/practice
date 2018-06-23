def longestValidParentheses(s):
    stack = [-1]
    max_count = 0
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i) 
        elif s[i] == ')':
            stack.pop()
            if stack != []:
                top = stack[len(stack) - 1]
                max_count = max(max_count, i - top)
            else:
                stack.append(i)
    return max_count

if __name__ == '__main__':
    print(longestValidParentheses("()"))
