"""
ID: chen.wu1
PROG: prefix
LANG: PYTHON3
"""
import sys
from functools import lru_cache


def main():
    primitives = []
    flag = True
    sequences = []
    with open('prefix.in', 'r') as fin:
        for line in fin.readlines():
            if line.strip() == '.':
                flag = False
                continue
            if flag:
                primitives.extend(line.strip().split())
            else:
                sequences.append(line.strip())
    set_primitives = set(primitives)
    # max_len_primitive = len(max(primitives, key=len))

    # @lru_cache(maxsize=sys.maxsize)
    # def longest_prefix(s: str) -> int:
    #     longest_len = 0
    #     for i in range(1, 11):
    #         if s[:i] in set_primitives:
    #             longest_len = max(i+longest_prefix(s[i:]), longest_len)
    #     return longest_len

    seq = ''.join(sequences)
    # ret = longest_prefix(seq)

    N = len(seq)
    dp = [0] * (N+1)

    # for i in range(1, N+1):
    #     for j in range(1, max_len_primitive+1):
    #         if N-i+j <= N and seq[N-i:N-i+j] in set_primitives:
    #             dp[N-i] = max(dp[N-i], dp[N-i+j]+j)

    root = {}
    for primitive in primitives:
        trie_tree = root
        for char in primitive:
            if char not in trie_tree:
                trie_tree[char] = {}
            trie_tree = trie_tree[char]

    for i in range(1, N+1):
        trie_tree = root
        ix = N-i
        while ix < N and seq[ix] in trie_tree:
            if seq[N-i:ix+1] in set_primitives:
                j = ix-N+i+1
                dp[N-i] = max(dp[N-i], dp[N-i+j]+j)
            trie_tree = trie_tree[seq[ix]]
            ix += 1

    with open('prefix.out', 'w') as fout:
        fout.write(str(dp[0]))
        fout.write('\n')


if __name__ == '__main__':
    main()
