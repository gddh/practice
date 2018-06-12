def diff(c1, c2):
    return (c1 != c2) + 0
 
def minDistance(word1, word2):
    graph = [[0] * (len(word1) + 1) for _ in range(len(word2) + 1)]
    for i in range(len(word1) + 1):
        graph[0][i] = i
    for i in range(len(word2) + 1):
        graph[i][0] = i
    for i in range(1, len(word2) + 1):
        for j in range(1, len(word1) + 1):
            graph[i][j] = min(graph[i - 1][j] + 1, 
                                graph[i][j - 1] + 1, 
                                graph[i - 1][j - 1] + diff(word1[j - 1], word2[i - 1]))
    for row in graph:
        print row
    return graph[len(word2)][len(word1)]

if __name__ == "__main__":
    print(minDistance("", "a"))
