"""
ID: chen.wu1
PROG: lamps
LANG: PYTHON3
"""
from functools import lru_cache
import sys


def main():

    sys.setrecursionlimit(20000)
    sys.getrecursionlimit()

    N = 0
    C = 0
    lamps_on = None
    lamps_off = None
    with open('lamps.in', 'r') as fin:
        inputs = fin.readlines()
        N = int(inputs[0].strip())
        C = int(inputs[1].strip())
        lamps_on = [int(x) for x in inputs[2].strip().split()]
        lamps_off = [int(x) for x in inputs[3].strip().split()]
    assert lamps_on[-1] == -1
    assert lamps_off[-1] == -1
    lamps_on.pop()
    lamps_off.pop()

    # print(N, C, lamps_on, lamps_off)

    init_lamps = []
    odd_lamps = []
    even_lamps = []
    triple_lamps = []

    final_lamps_on = []
    final_lamps_off = []

    for i in range(1, N+1):
        if i % 2 == 0:
            even_lamps.append(1)
            odd_lamps.append(0)
        else:
            odd_lamps.append(1)
            even_lamps.append(0)

        if i % 3 == 1:
            triple_lamps.append(1)
        else:
            triple_lamps.append(0)

        init_lamps.append(1)

        final_lamps_on.append(0)
        final_lamps_off.append(0)

    for x in lamps_on:
        final_lamps_on[x-1] = 1

    for x in lamps_off:
        final_lamps_off[x-1] = 1

    init = int(''.join([str(c) for c in init_lamps[::-1]]), 2)
    odd = int(''.join([str(c) for c in odd_lamps[::-1]]), 2)
    even = int(''.join([str(c) for c in even_lamps[::-1]]), 2)
    triple = int(''.join([str(c) for c in triple_lamps[::-1]]), 2)
    final_on = int(''.join([str(c) for c in final_lamps_on[::-1]]), 2)
    final_off = int(''.join([str(c) for c in final_lamps_off[::-1]]), 2)

    # print(init, odd, even, triple, final_on, final_off)

    ret = set()

    @lru_cache(maxsize=sys.maxsize)
    def dfs(stats, C):
        if C == 0:
            # print(bin(stats))
            if stats & final_on == final_on and stats & final_off == 0:
                ret.add(stats)
                return
            else:
                return
        # button 1: all lamps
        dfs(stats ^ init, C-1)

        # button 2: odd lamps
        new_stats = (odd - (stats & odd)) + (stats & (init ^ odd))
        dfs(new_stats, C-1)

        new_stats = (even - (stats & even)) + (stats & (init ^ even))
        # button 3: even lamps
        dfs(new_stats, C-1)

        new_stats = (triple - (stats & triple)) + (stats & (init ^ triple))
        # button 4: triple lamps
        dfs(new_stats, C-1)

    dfs(init, C)
    outputs = []

    with open('lamps.out', 'w') as fout:
        if len(ret) == 0:
            fout.write('IMPOSSIBLE\n')
            return
        for x in ret:
            res = []
            while x:
                res.append(x % 2)
                x = x // 2
            for i in range(N - len(res)):
                res.append(0)
            outputs.append(''.join([str(c) for c in res])+'\n')

        outputs.sort()
        fout.writelines(outputs)


if __name__ == '__main__':
    main()

"""
20 
3 
-1 
1 3 5 -1 
"""
