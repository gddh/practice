def swap(s, i1, i2):
    tmp = s[i1]
    s[i1] = s[i2]
    s[i2] = tmp

def permute(s, l, r):
    if (l == r):
        print ''.join(s)
    for i in xrange(l, r + 1):
        s[l], s[i] = s[i], s[l]
        permute(s, l + 1, r)
        s[l], s[i] = s[i], s[l]


def permutes(s):
    permute(list(s), 0, len(s) - 1)

if __name__ == "__main__":
    permutes("ABC")
