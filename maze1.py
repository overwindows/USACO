"""
ID: chen.wu1
PROG: maze1
LANG: PYTHON3
"""
import pprint


def floodfill(fmz, i, j):
    stck = [(i, j, 0)]
    visited = set()
    # max_steps = 0
    while stck:
        i, j, v = stck.pop(0)
        # max_steps = max(max_steps, v)
        if i > -1 and i < len(fmz) and j > -1 and j < len(fmz[0]):
            if (i, j) in visited:
                continue
            if fmz[i][j] != -1:
                fmz[i][j] += v
                visited.add((i, j))
                stck.append((i-1, j, fmz[i][j]))
                stck.append((i+1, j, fmz[i][j]))
                stck.append((i, j-1, fmz[i][j]))
                stck.append((i, j+1, fmz[i][j]))

    # return max_steps


def refresh(fmt_maze, maze, h, w):
    for i in range(2*h+1):
        for j in range(2*w+1):
            if maze[i][j] == '+' or maze[i][j] == '-' or maze[i][j] == '|':
                fmt_maze[i][j] = -1
            elif maze[i][j] == ' ':
                if i % 2 and j % 2:
                    fmt_maze[i][j] = 1
                else:
                    fmt_maze[i][j] = 0


def main():
    with open('maze1.in', 'r') as fin:
        w, h = map(int, fin.readline().split())
        maze = []
        fmt_maze = [[0] * (2*w+1) for i in range(2*h+1)]
        for i in range(2*h+1):
            row = fin.readline()
            row = row + ' ' * (2*w+1 - len(row))
            maze.append(row)
        # print(maze)
        for i in range(2*h+1):
            for j in range(2*w+1):
                if maze[i][j] == '+' or maze[i][j] == '-' or maze[i][j] == '|':
                    fmt_maze[i][j] = -1
                elif maze[i][j] == ' ' and i % 2 and j % 2:
                    fmt_maze[i][j] = 1

        exits = []
        for i in range(2*w+1):
            if fmt_maze[0][i] == 0:
                exits.append((0, i))
            if fmt_maze[2*h][i] == 0:
                exits.append((2*h, i))

        for i in range(2*h+1):
            if fmt_maze[i][0] == 0:
                exits.append((i, 0))
            if fmt_maze[i][2*w] == 0:
                exits.append((i, 2*w))
        steps = []
        fmt_mazes = []
        for i, j in exits:
            floodfill(fmt_maze, i, j)
            fmt_mazes.append([row[:] for row in fmt_maze])
            refresh(fmt_maze, maze, h, w)

        # pprint.pprint(fmt_mazes)
        for i in range(2*h+1):
            for j in range(2*w+1):
                if fmt_mazes[0][i][j] != -1 and fmt_mazes[1][i][j] != 0:
                    steps.append(min(fmt_mazes[0][i][j], fmt_mazes[1][i][j]))
        # print(steps)
    with open('maze1.out', 'w') as fout:
        fout.write(str(max(steps)) + '\n')


if __name__ == '__main__':
    main()
