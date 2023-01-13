"""
ID: chen.wu1
PROG: agrinet
LANG: PYTHON3
"""

import heapq


def main():
    graph = None
    with open('agrinet.in', 'r') as fin:
        N = int(fin.readline().strip())
        graph = [[0]*N for _ in range(N)]
        x, y = 0, 0

        for line in fin.readlines():
            costs = [int(x) for x in line.strip().split()]
            for cost in costs:
                graph[x][y] = cost
                y += 1
                if y == N:
                    x += 1
                    y = 0

    # print(graph)

    fibers = []
    for i in range(N):
        for j in range(i, N):
            if graph[i][j] == 0:
                continue
            heapq.heappush(fibers, (graph[i][j], i, j))

    visited = [i for i in range(N)]
    min_cost = 0

    while fibers:
        cost, i, j = heapq.heappop(fibers)
        if visited[i] == visited[j]:
            pass
        else:
            grp = visited[j]
            for k in range(N):
                if visited[k] == grp:
                    visited[k] = visited[i]
            min_cost += cost

    with open('agrinet.out', 'w') as fout:
        fout.write(str(min_cost) + '\n')


if __name__ == '__main__':
    main()
