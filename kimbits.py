"""
ID: chen.wu1
PROG: kimbits
LANG: PYTHON3
"""
import pprint


def main():
    fin = open('kimbits.in', 'r')
    fout = open('kimbits.out', 'w')

    N, L, I = map(int, fin.readline().split())

    dp = [[0 for _ in range(L+1)] for _ in range(N+1)]

    for i in range(N+1):
        dp[i][0] = 1
        for j in range(1, L+1):
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
    
    for i in range(N+1):
        for j in range(1,L+1):
            dp[i][j] += dp[i][j-1]

    # pprint.pprint(dp)
    i = 0
    # n = 0
    # m = 0

    # assert dp[N][L] > I, dp[N][L]

    res = []
    for k in range(N, 0, -1):
        if dp[k-1][L] >= I:
            res.append('0')
        else:
            res.append('1')
            I -= dp[k-1][L]
            L -= 1
    
    # for k in range(N+1):
    #     inc = sum(dp[k])
    #     # print(k, inc)
    #     if inc >= I:
    #         break
    #     else:
    #         i = inc
    #         m = k
    
    # n = 2**(m+1)-1

    # # print(i,n,m,I)
    # while i < I:
    #     s = bin(n)
    #     if s.count('1') <= L:
    #         i += 1
    #     # if n == 0:
    #     #     i+=1
    #     # elif n > 0:
    #     #     l = 0
    #     #     nn = n
    #     #     while nn:
    #     #         nn = nn & (nn-1)
    #     #         l += 1
    #     #         if l > L:
    #     #             break
    #     #     # print(n, l)
    #     #     if l <= L:
    #     #         i += 1
    #     n += 1
    #     # print(i,n)

    # n -= 1

    s = ''.join(res)
    fout.write(s.zfill(N) + '\n')


if __name__ == '__main__':
    main()
