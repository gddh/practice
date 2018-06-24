def spiralOrder(matrix):
    if len(matrix) == 0 or len(matrix[0] == 0):
        return 0
    visited = [[0] * len(row) for row in matrix]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    di = 0
    x = 0
    next_x = 0
    y = 0
    next_y = 0
    res = []
    for _ in range(len(matrix[0]) * len(matrix)):
        res.append(matrix[y][x])
        visited[y][x] = 1 
        next_x = dx[di] + x
        next_y = dy[di] + y
        if (next_x < len(matrix[0]) and next_x >= 0 and
                next_y < len(matrix) and next_y >= 0 and
                visited[next_y][next_x] == 0):
            x = next_x
            y = next_y
        else:
            di = (di + 1) % 4
            x = dx[di] + x
            y = dy[di] + y

    return res


if __name__ == "__main__":
    x = [
          [1, 2, 3, 4],
          [5, 6, 7, 8],
          [9,10,11,12]
        ]
    x = [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
    print(spiralOrder(x))
