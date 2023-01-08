"""
ID: chen.wu1
PROG: zerosum
LANG: PYTHON3
"""

def main():
    N = 0
    with open('zerosum.in', 'r') as fin:
        N = int(fin.readline())
    res = []
    def dfs(n, _sum, _seq, _prev):
        if n == N:
            if _sum == 0:
                # print(_seq)
                res.append(_seq)
            return
        dfs(n + 1, _sum + n + 1, _seq + '+' + str(n + 1), n+1)
        dfs(n + 1, _sum - n - 1, _seq + '-' + str(n + 1), -(n+1))

        _sum -= _prev
        if _prev > 0:
            _prev = _prev * 10 + n + 1
        else:
            _prev = _prev * 10 - n - 1
        dfs(n + 1, _sum + _prev, _seq + ' ' + str(n + 1), _prev)
        return
            
    dfs(1,1,'1',1)
    res.sort()
    with open('zerosum.out', 'w') as fout:
        for r in res:
            fout.write(r + '\n')

if __name__ == '__main__':
    main()
