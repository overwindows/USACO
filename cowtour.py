"""
ID: chen.wu1
PROG: cowtour
LANG: PYTHON3
"""
import pprint
import heapq
import time


def main():
    t0 = time.time()
    with open('cowtour.in', 'r') as fin:
        n = int(fin.readline())
        x_y = []
        for i in range(n):
            x1, y1 = map(int, fin.readline().split())
            x_y.append((x1, y1))
        # print(x)
        # print(y)
        graph = []
        for i in range(n):
            row = list(fin.readline().strip())
            graph.append(list(map(float, row)))

    candidates = []
    # print(graph)
    t1 = time.time()
    # print(t1-t0)

    for i in range(n):
        for j in range(n):
            # if graph[i][j] == 0 and i == j:
            if i == j:
                # assert graph[i][j] == 1
                graph[i][j] = 0
                continue
            if graph[i][j] == 0:
                graph[i][j] = float('inf')
            else:
                x0_y0 = x_y[i]
                x1_y1 = x_y[j]
                dist = ((x0_y0[0]-x1_y1[0])**2 + (x0_y0[1]-x1_y1[1])**2)**0.5
                # print(dist)
                graph[i][j] = dist
                # assert dist != float('inf') and i!=j
                heapq.heappush(candidates, (dist, i, j))
    t2 = time.time()
    # print(t2-t1)
    # for k in range(n):
    #     for i in range(n):
    #         for j in range(n):
    #             if i == j or i == k or j == k:
    #                 continue
    #             graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    visted = set()
    while candidates:
        # candidates.sort()
        dist, i, j = heapq.heappop(candidates)
        visted.add((i, j))

        for k in range(n):
            if (i, k) in visted or (k, i) in visted or j == k or i == k:
                continue
            if graph[i][k] > graph[i][j] + graph[j][k] and graph[j][k] != float('inf'):
                graph[i][k] = graph[i][j] + graph[j][k]
                graph[k][i] = graph[i][k]
                # assert graph[i][k] != float('inf')
                # candidates.append((graph[i][k], i, k))
                heapq.heappush(candidates, (graph[i][k], i, k))
            """
            if graph[i][k] != float('inf') and graph[j][k] > graph[i][j] + graph[i][k]:
                graph[j][k] = graph[i][j] + graph[i][k]
                graph[k][j] = graph[j][k]
                # assert graph[j][k] != float('inf')
                # candidates.append((graph[k][j], j, k))
                heapq.heappush(candidates, (graph[j][k], j, k))
            """
    t3 = time.time()
    print(t3-t2)
    # print(graph)

    diameters = [0 for i in range(n)]

    longest_paths = []
    for i in range(n):
        longest_path = 0
        for j in range(n):
            if graph[i][j] == float('inf'):
                assert graph[j][i] == float('inf')
                continue
            if i == j:
                continue
            longest_path = max(graph[i][j], longest_path)
        longest_paths.append(longest_path)
    # print(longest_paths,max(longest_paths))

    for ix in range(n):
        # print(longest_paths)
        longest_path = 0
        for j in range(n):
            if graph[ix][j] == float('inf') and graph[j][ix] == float('inf'):
                continue
            if j == ix:
                continue
            # print(ix, j, longest_paths[j])
            longest_path = max(longest_paths[j], longest_path)
        # print(ix, longest_path)
        # assert longest_path > 0, (ix, longest_path)
        diameters[ix] = longest_path

    shortest_path = float('inf')
    for i in range(n):
        for j in range(n):
            if graph[i][j] == float('inf'):
                # assert graph[j][i] == float('inf')
                # assert i!=j
                path = longest_paths[i] + longest_paths[j] + \
                    ((x_y[i][0]-x_y[j][0])**2 + (x_y[i][1]-x_y[j][1])**2)**0.5
                largest_i = diameters[i]
                largest_j = diameters[j]
                shortest_path = min(shortest_path, max(
                    path, largest_i, largest_j))
                # print(i,j,path)
    t4 = time.time()
    print(t4-t3)

    with open('cowtour.out', 'w') as fout:
        fout.write("{:.6f}".format(shortest_path) + '\n')


if __name__ == '__main__':
    main()
