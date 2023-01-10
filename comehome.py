"""
ID: chen.wu1
PROG: comehome
LANG: PYTHON3
"""


def main():
    OFFSET = ord('A')
    dp = [[float('inf') for _ in range(58)] for _ in range(58)]
    with open('comehome.in', 'r') as fin:
        _ = fin.readline()
        for line in fin.readlines():
            x, y, d = line.split()
            # print(x, y, d, ord(y)-OFFSET)
            dp[ord(x) - OFFSET][ord(y)-OFFSET] = min(dp[ord(x) - OFFSET]
                                                     [ord(y)-OFFSET], int(d))
            dp[ord(y) - OFFSET][ord(x)-OFFSET] = min(dp[ord(y) - OFFSET]
                                                     [ord(x)-OFFSET], int(d))
            assert dp[ord(y) - OFFSET][ord(x) -
                                       OFFSET] == dp[ord(x) - OFFSET][ord(y)-OFFSET]

    # print(dp[32][25])
    min_distances = [float('inf') for _ in range(58)]
    while True:
        min_dist = float('inf')
        min_idx = -1

        for k in range(58):
            if k == 25 or min_distances[k] != float('inf'):
                continue
            if min_dist > dp[k][25] and dp[k][25] != float('inf'):
                min_dist = dp[k][25]
                min_idx = k
        if min_idx == -1:
            break
        min_distances[min_idx] = min_dist
        # print(min_distances[min_idx], min_dist, min_idx)

        for i in range(58):
            if i == min_idx:
                continue
            if dp[i][min_idx] > 0:
                dp[i][25] = min(dp[i][min_idx] + dp[min_idx][25], dp[i][25])

    min_dist = float('inf')
    min_idx = -1

    # print(min_distances)
    for i in range(25):
        if min_dist > min_distances[i]:
            min_dist = min_distances[i]
            min_idx = i

    with open('comehome.out', 'w') as fout:
        fout.write(chr(min_idx + OFFSET)+' '+str(min_dist)+'\n')


if __name__ == '__main__':
    main()
