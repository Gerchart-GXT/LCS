#include <string>
typedef unsigned long long ULL;
//开放寻址法，开三倍空间，字符串hash，P = 13331
const int MOD = 1e5 + 3, M = 3 * MOD, P = 13331;

ULL h[M + 10];
bool used[M + 10];

ULL hashFind(ULL x)
{
    ULL t = (x % MOD + MOD) % MOD;
    while (used[t] && h[t] != x) {
        t++;
        if (t == M)
            t = 0;
    }
    return t;
}

ULL hashGet(std::string s)
{
    ULL hashcode = 0;
    for (int i = s.size(); ~i; --i) {
        hashcode = hashcode * P + (int)s[i];
    }
    return hashcode;
}
