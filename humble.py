"""
ID: chen.wu1
PROG: humble
LANG: PYTHON3
"""

import heapq


def main():
    with open('humble.in', 'r') as fin:
        K, N = fin.readline().strip().split()
        humbles = [int(x) for x in fin.readline().strip().split()]
        K = int(K)
        N = int(N)
    original_humbles = humbles[:]
    humbles_set = set(original_humbles)
    upper_bound = 0
    heapq.heapify(humbles)
    ix = 0
    while ix < N:
        # print(len(humbles))
        if not upper_bound and len(humbles) > N:
            upper_bound = max(humbles)
        min_humble = heapq.heappop(humbles)
        for i in range(K):
            if min_humble*original_humbles[i] not in humbles_set:
                if upper_bound and min_humble*original_humbles[i] > upper_bound:
                    break
                heapq.heappush(humbles, min_humble*original_humbles[i])
                humbles_set.add(min_humble*original_humbles[i])
        ix += 1
        # print(min_humble)

    with open('humble.out', 'w') as fout:
        fout.write(str(min_humble)+'\n')


if __name__ == '__main__':
    main()
