def minPathSum(grid):
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if not (i == 0 and j == 0):
                if i == 0:
                    grid[i][j] = grid[i][j - 1] + grid[i][j]
                elif j == 0:
                    grid[i][j] = grid[i - 1][j] + grid[i][j]
                else:
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]
    for row in grid:
        print row
    return grid[len(grid) - 1][len(grid[0]) - 1]

if __name__ == "__main__":
    grid = [[1,3,1],
            [1,5,1],
            [4,2,1]]
    print(minPathSum(grid))
