"""
ID: chen.wu1
PROG: money
LANG: PYTHON3
"""


def main():
    V, N = 0, 0
    units = []
    with open('money.in', 'r') as fin:
        V, N = [int(x) for x in fin.readline().split()]
        for line in fin.readlines():
            units.extend([int(x) for x in line.split()])
    units.sort()
    dp = [0] * (N+1)
    dp[0] = 1
    for v in range(V):
        for n in range(1, N+1):
            if n >= units[v]:
                dp[n] += dp[n-units[v]]

    # print(dp)
    with open('money.out', 'w') as fout:
        fout.write(str(dp[N]))
        fout.write('\n')


if __name__ == '__main__':
    main()
