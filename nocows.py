"""
ID: chen.wu1
PROG: nocows
LANG: PYTHON3
"""


def main():
    N, K = 0, 0
    with open('nocows.in', 'r') as fin:
        N, K = [int(x) for x in fin.readline().split()]
    sign_k = [False] * (K+1)
    dp = [[0] * (K+1) for _ in range(N+1)]
    dp[1][1] = 1
    sign_k[1] = True
    for n in range(2, N+1):
        for k in range(2, K+1):
            if sign_k[k-1]:
                for i in range(1, n-1):
                    if dp[n-i-1][k-1] == 0:
                        continue
                    r = dp[n-i-1][k-1]
                    sum_dp_i = sum(dp[i][1:k])
                    if sum_dp_i == 0:
                        continue
                    else:
                        dp[n][k] += (sum_dp_i * r * 2) % 9901
                        dp[n][k] -= (dp[i][k-1] * r) % 9901

                    # for j in range(1, k):
                    #     l = dp[i][j]
                    #     if j == k-1:
                    #         dp[n][k] += (l*r) % 9901
                    #     else:
                    #         dp[n][k] += (dp[i][j] * r * 2) % 9901

                    dp[n][k] %= 9901
                    if not sign_k[k] and dp[n][k] > 0:
                        sign_k[k] = True
    # print(dp)
    with open('nocows.out', 'w') as fout:
        fout.write(str(dp[N][K]))
        fout.write('\n')


if __name__ == '__main__':
    main()
