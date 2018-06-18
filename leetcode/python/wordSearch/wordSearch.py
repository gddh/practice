def isSafe(i, j, board):
    return (i >= 0 and i < len(board) and
            j >= 0 and j < len(board[0])) 

def found(board, i, j, word):
    if len(word) == 0:
        return True
    if isSafe(i, j, board) and board[i][j] != word[0]:
        return False
    elif isSafe(i, j, board):
        tmp = board[i][j]
        board[i][j] = 1
        res = (found(board, i, j + 1, word[1:]) or
                found(board, i, j - 1, word[1:]) or
                found(board, i + 1, j, word[1:]) or
                found(board, i - 1, j, word[1:]))
        board[i][j] = tmp
        return res


def exist(board, word):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if (found(board, i, j, word)):
                return True
    return False

if __name__ == "__main__":
    #board = [
    #          ['A','B','C','E'],
    #          ['S','F','C','S'],
    #          ['A','D','E','E']
    #        ]
    #word = "ABCCED"
    #print(exist(board, word))
    #word = "SEE"
    #print(exist(board, word))
    #word = "ABCB"
    #print(exist(board, word))
    board = [["a","a","a","a"],
             ["a","a","a","a"],
             ["a","a","a","a"]]
    word = "aaaaaaaaaaaaa"
    print len(word)
    print(exist(board, word))
