"""
ID: chen.wu1
PROG: ttwo
LANG: PYTHON3
"""


def main():
    grid = []
    with open('ttwo.in', 'r') as fin:
        for _ in range(10):
            grid.append(list(fin.readline().strip()))
    # print(world)

    def find_pos(grid, c):
        for i in range(10):
            for j in range(10):
                if grid[i][j] == c:
                    return (i, j)
        return None

    def move(pos, d):
        x, y = pos
        if d == 0:  # north
            x -= 1
        elif d == 1:  # east
            y += 1
        elif d == 2:  # south
            x += 1
        else:
            y -= 1  # west
        if x < 0 or x >= 10 or y < 0 or y >= 10:
            return None
        if grid[x][y] == '*':  # obstacle
            return None
        return (x, y)

    def next_dir(d):
        return (d + 1) % 4

    def next_pos(pos, d):
        return move(pos, d) or pos

    def next_state(state):
        pos1, d1, pos2, d2 = state
        pos1 = next_pos(pos1, d1)
        pos2 = next_pos(pos2, d2)
        d1 = next_dir(d1) if pos1 == state[0] else d1
        d2 = next_dir(d2) if pos2 == state[2] else d2
        return (pos1, d1, pos2, d2)

    pos1 = find_pos(grid, 'F')
    pos2 = find_pos(grid, 'C')
    d1 = 0
    d2 = 0

    res = 0
    state = (pos1, d1, pos2, d2)
    visited = set()
    while state not in visited:
        visited.add(state)
        state = next_state(state)
        res += 1
        if state[0] == state[2]:
            break

    if state in visited:
        res = 0

    with open('ttwo.out', 'w') as fout:
        fout.write(str(res) + '\n')


if __name__ == '__main__':
    main()
