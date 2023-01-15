"""
ID: chen.wu1
PROG: inflate
LANG: PYTHON3
"""

def main():
    # minutes = None
    # points = None
    with open('inflate.in','r') as fin:
        M,N = fin.readline().strip().split()
        M = int(M)
        N = int(N)
        # min_minute = 10000000
        mns_pts = []
        hash_tbl = {}
        for i in range(N):
            point, minute = fin.readline().strip().split()
            int_mnt = int(minute)
            int_pts = int(point)
            if int_mnt not in hash_tbl:
                hash_tbl[int_mnt] = int_pts
            else:
                if int_pts > hash_tbl[int_mnt]:
                    hash_tbl[int_mnt] = int_pts
            # min_minute = min(min_minute, int(minute))
        
        for k,v in hash_tbl.items():
            mns_pts.append((k, v))

    # dp = [[0]*N for _ in range(M+1)]
    # for m in range(M+1):
    #     for n in range(N):
    #         if n > 0 and m >= minutes[n]:
    #             # assert n > 0 and m > minutes[n]
    #             dp[m][n] = max(dp[m][n], dp[m-minutes[n]][n] + points[n], dp[m][n-1])
    #         else:     
    #             if n > 0:
    #                 dp[m][n] = max(dp[m][n], dp[m][n-1])
    #             elif m >= minutes[n]:
    #                 dp[m][n] = max(dp[m][n], dp[m-minutes[n]][n] + points[n])
    #             else:
    #                 pass
    mns_pts.sort()
    N = len(mns_pts)
    dp = [0]*(M+1)
    # print(min_minute)
    for m in range(M+1):
        for n in range(N):  #sorted asc
            if m < mns_pts[n][0]:
                break
            dp[m] = max(dp[m], dp[m-mns_pts[n][0]] + mns_pts[n][1])

                
    # print(dp)    
    # @lru_cache(maxsize=sys.maxsize)
    # def solution(i, Minutes):
    #     if Minutes < 0:
    #         return 0
    #     point = points[i]
    #     if Minutes == 0:
    #         return point
    #     max_point = 0
    #     # print(point)
    #     for i in range(N):
    #         max_point = max(max_point, point+solution(i, Minutes-minutes[i]))
    #     return max_point
    # max_point = 0
    # for i in range(N):
    #     print(i)
    #     max_point = max(max_point , solution(i, M-minutes[i]))
    
    with open('inflate.out','w') as fout:
        #fout.write(str(dp[M][N-1]))
        fout.write(str(dp[M]))
        fout.write('\n')

if __name__ == "__main__":
    main()