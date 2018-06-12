def minimumTotal(triangle):
    path = [cost for cost in triangle[-1]]
    for row in reversed(triangle[:-1]):
        for i in range(len(row)):
            path[i] = min(path[i], path[i + 1]) + row[i]
    return(path[0])

if __name__ == "__main__":
    #triangle = [
    #     [2],
    #    [3,4],
    #   [6,5,7],
    #  [4,1,8,3]]
    #minimumTotal(triangle)
    #triangle = [
    #     [2],
    #    [3,7],
    #   [8,5,6],
    #  [6,1,9,3]]
    #minimumTotal(triangle)
    triangle = [
         [3],
        [6,4],
       [5,2,7],
      [9,1,8,6]]
    minimumTotal(triangle)
