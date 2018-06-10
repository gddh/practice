def generate(lst, s, left, right, lim):
    if (len(s) == 2 * lim):
        lst.append(s)
    if (left < lim):
        generate(lst, s + "(", left + 1, right, lim)
    if (right < left):
        generate(lst, s + ")", left, right + 1, lim)

def generateParenthesis(n):
    lst = []
    generate(lst, "", 0, 0, n)
    print lst

if __name__ == "__main__":
    generateParenthesis(3)
