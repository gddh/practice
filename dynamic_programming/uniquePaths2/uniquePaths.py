def uniquePathsWithObstacles(obstacleGrid):
    rowLen = len(obstacleGrid[0])
    colLen = len(obstacleGrid)
    graph = [[0] * rowLen for row in obstacleGrid]
    graph[0][0] = 1 if obstacleGrid[0][0] == 0 else 0
    for i in range(0, colLen):
        for j in range(0, rowLen):
            if obstacleGrid[i][j] != 1 and not (i == 0 and j == 0):
                graph[i][j] = graph[i - 1][j] + graph[i][j - 1]
    return graph[colLen - 1][rowLen - 1]

if __name__ == "__main__":
    #grid = [
    #      [0,0,0],
    #      [0,1,0],
    #      [0,0,0]]
    #uniquePathsWithObstacles(grid)
    grid = [[0]]
    print(uniquePathsWithObstacles(grid))

