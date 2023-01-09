"""
ID: chen.wu1
PROG: concom
LANG: PYTHON3
"""


def main():
    ctrl = [[False] * 101 for _ in range(101)]
    owned = [[0] * 101 for _ in range(101)]
    origin_owned = [[0] * 101 for _ in range(101)]
    new_ctrl = []

    with open('concom.in', 'r') as fin:
        _ = int(fin.readline())
        for line in fin.readlines():
            i, j, p = [int(x) for x in line.split()]
            if p > 50:
                ctrl[i][j] = True
                ctrl[i][i] = True
                ctrl[j][j] = True
                new_ctrl.append((i, j))
            owned[i][j] = p
            origin_owned[i][j] = p


    while len(new_ctrl) > 0:
        # print(new_ctrl)
        new_new_ctrl = []
        
        for i, k in new_ctrl:
            assert ctrl[i][k]
            for j in range(1,101):
                if not ctrl[i][j]:
                    if k == i or k == j:
                        continue
                    owned[i][j] += owned[k][j]
                    if owned[i][j] > 50 or ctrl[k][j]:
                        ctrl[i][j] = True
                        owned[i][j] = origin_owned[i][j]
                        new_new_ctrl.append((i, j))

        if len(new_new_ctrl) == 0:
            break
        new_ctrl = new_new_ctrl

    res = []
    for i in range(1, 101):
        for j in range(1, 101):
            if i == j:
                continue
            if ctrl[i][j]:
                res.append((i, j))
    res.sort()

    with open('concom.out', 'w') as fout:
        for r in res:
            fout.write(str(r[0]) + ' ' + str(r[1]) + '\n')


if __name__ == '__main__':
    main()
