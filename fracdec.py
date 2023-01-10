"""
ID: chen.wu1
PROG: fracdec
LANG: PYTHON3
"""


def main():
    with open('fracdec.in', 'r') as fin:
        n, d = map(int, fin.readline().strip().split())
    _int = n//d
    _dec = []
    dup = set()
    queue = []
    _frac = n % d
    if _frac == 0:
        with open('fracdec.out', 'w') as fout:
            fout.write(str(_int) + '.0'+'\n')
            return

    while _frac != 0:
        _frac *= 10
        if _frac in dup:
            break
        dup.add(_frac)
        queue.append(_frac)
        _dec.append(_frac//d)
        _frac %= d

    for i in range(len(queue)):
        if queue[i] == _frac:
            _dec.insert(i, '(')
            _dec.append(')')
            break
    _int = str(_int)+'.'
    _int_dec = _int+''.join(map(str, _dec))
    with open('fracdec.out', 'w') as fout:
        for i in range(len(_int_dec)):
            if i != 0 and i % 76 == 0:
                fout.write('\n')
            fout.write(str(_int_dec[i]))
        fout.write('\n')


if __name__ == '__main__':
    main()
