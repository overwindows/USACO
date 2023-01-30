"""
ID: chen.wu1
PROG: fact4
LANG: PYTHON3
"""


def main():
    with open('fact4.in', 'r') as fin:
        N = int(fin.readline())
    x = 1
    for n in range(1, N+1):
        x = x * n
        if x % 10:
            # x = x % 10
            pass
        else:
            while not x % 10:
                x = x // 10
            # x = x % 10
            pass
    x = x % 10
    with open('fact4.out', 'w') as fout:
        fout.write(str(x))
        fout.write('\n')


if __name__ == '__main__':
    main()
