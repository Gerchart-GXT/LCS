#include "./stringhash.h"
#include <algorithm>
#include <iostream>
#include <string>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> PII;

const int N = 2e3 + 10;
int f[N][N];
PII g[N][N];
int main()
{
    string s1, s2;
    puts("Please input the 1st string:");
    cin >> s1;
    puts("Please input the 2nd string:");
    cin >> s2;
    for (int i = 0; i <= s1.length(); ++i)
        for (int j = 0; j <= s2.length(); ++j) {
            if (s1[i] == s2[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
                g[i][j] = { i - 1, j - 1 };
            } else {
                if (f[i][j - 1] > f[i - 1][j])
                    g[i][j] = { i, j - 1 };
                else
                    g[i][j] = { i - 1, j };
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
    puts("LCS's length is:");
    auto cnt = f[s1.length() - 1][s2.length() - 1];
    cout << cnt << endl;
    puts("Thy are(is):");
    for (int i = 0; i < s1.length(); ++i)
        for (int j = 0; j < s2.length(); ++j) {
            if (f[i][j] == cnt) {
                string ans;
                int tpx = i, tpy = j;
                while (tpx >= 0 && tpy >= 0) {
                    if (s1[tpx] == s2[tpy])
                        ans += s1[tpx];
                    auto pt = g[tpx][tpy];
                    tpx = pt.fi, tpy = pt.se;
                }
                if (s1[tpx] == s2[tpy])
                    ans += s1[tpx];
                reverse(ans.begin(), ans.end());
                ULL hashcode = hashGet(ans);
                ULL ph = hashFind(hashcode);
                if (h[ph] != hashcode) {
                    cout << ans << endl;
                    used[ph] = true;
                    h[ph] = hashcode;
                }
            }
        }
    puts("Press any key to exit!");
    getchar();
    getchar();
    return 0;
}