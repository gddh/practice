def generateParenthesis(n):
    lst = []
    def generate(s, left, right):
        if (left == n and right == n):
            lst.append(s)
        if (left < n):
            generate(s + "(", left + 1, right)
        if (right < left):
            generate(s + ")", left, right + 1)
    generate("", 0, 0)
    return lst

if __name__ == "__main__":
    print(generateParenthesis(3))
