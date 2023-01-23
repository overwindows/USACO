"""
ID: chen.wu1
PROG: stamps
LANG: PYTHON3
"""
# from collections import deque


def main():
    stamps = []
    with open('stamps.in', 'r') as fin:
        K, N = map(int, fin.readline().split())
        for line in fin.readlines():
            stamps.extend(list(map(int, line.split())))
    stamps.sort()
    # stamps.reverse()
    # assert N == len(stamps)
    # dp = deque([[0] * (K+1) for _ in range(stamps[0]+1)])

    # dp = deque([K+1]*(stamps[0]+1))
    dp = [K+1] * 2000000
    for stamp in stamps:
        # dp[stamp][1] = 1
        dp[stamp] = 1
    x = 1
    # print(dp)
    while True:
        # if x > stamps[0]:
        #     # dp.append([0] * (K+1))
        #     dp.append(K+1)

        # for k in range(1, K+1):
        #     for stamp in stamps:
        #         if x > stamps[0] and dp[-1-stamp][k-1] == 1:
        #             dp[-1][k] = 1
        #             break
        #         elif x - stamp >= 0 and x <= stamps[0] and dp[x - stamp][k-1] == 1:
        #             dp[x][k] = 1
        #             break
        for stamp in stamps:
            # if x > stamps[0]:
            # dp[-1] = min(dp[-1], dp[-1-stamp]+1)
            if x > stamp:
                if dp[x] > dp[x-stamp]+1:
                    dp[x] = dp[x-stamp]+1
            else:
                break
            # elif x-stamp >= 0:
            #     dp[x] = min(dp[x], dp[x-stamp]+1)
        # print(dp)
        # if x > stamps[0]:
        #     dp.popleft()
        # print(x)
        # if sum(dp[min(x, stamps[0])]) == 0:
        # if dp[min(x, stamps[0])] > K:
        if dp[x] > K:
            x -= 1
            break
        else:
            x += 1

    with open('stamps.out', 'w') as fout:
        fout.write(str(x) + '\n')


if __name__ == '__main__':
    main()
