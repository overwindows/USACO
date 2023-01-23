/*
ID: chen.wu1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    std::ifstream fin("stamps.in");
    std::ofstream fout("stamps.out");
    int K, N;
    fin >> K >> N;
    int stamps[200];
    for (int i = 0; i < N; i++)
        fin >> stamps[i];
    fin.close();
    qsort(stamps, N, sizeof(int), compare);

    int dp[2000000];
    for (int i = 0; i < 2000000; i++)
        dp[i] = K + 1;
    for (int i = 0; i < N; i++)
        dp[stamps[i]] = 1;
    int x = 1;

    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            if (x > stamps[i])
                dp[x] = std::min(dp[x], dp[x - stamps[i]] + 1);
            else
                break;
        }
        if (dp[x] > K)
        {
            x--;
            break;
        }
        else
            x++;
    }

    fout << x << std::endl;

    fout.close();

    return 0;
}
