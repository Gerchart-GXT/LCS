# 数据结构作业之——最长公共子串
## 题干
* 编写程序，实现查找两个字符串中的最长公共子串
## 文件结构
1. `stringhash.h`
    * 字符串哈希   
    * 主要方法：开放寻址法，开三倍空间，字符串hash，P = 13331
```cpp
typedef unsigned long long ULL;
const int MOD = 1e5 + 3, M = 3 * MOD, P = 13331;
ULL h[M + 10];
bool used[M + 10];
//寻找hash后的位置
ULL hashFind(ULL x);
//获取字符串的hashcode
ULL hashGet(std::string s)；
```
2. `main.cpp`
    * 最长公共子串DP实现
    转移方程： 
    ```cpp
        f[i][j]:s1的前i个与s2的前j，所得到的最长公共子串的长度
        if(s1[i] == s2[j])
            f[i][j] = f[i - 1][j - 1] + 1;
        else
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
    ```
    * 转移记录；实用二元（pair）数组，记录每次`f[i][j]`的转移来源，最后进行回溯
    ```cpp
    //记录转移来源
        if (s1[i] == s2[j]) {
            g[i][j] = { i - 1, j - 1 };
        } else {
            if (f[i][j - 1] > f[i - 1][j])
                g[i][j] = { i, j - 1 };
            else
                g[i][j] = { i - 1, j };
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
        }

    //利用g数组进行回溯所有f等于最大的长度的子串
    while (tpx >= 0 && tpy >= 0) {
        if (s1[tpx] == s2[tpy])
            ans += s1[tpx];
        auto pt = g[tpx][tpy];
        tpx = pt.fi, tpy = pt.se;
    }
    if (s1[tpx] == s2[tpy])
        ans += s1[tpx];
    reverse(ans.begin(), ans.end());
    //用字符串哈希来判重
    ULL hashcode = hashGet(ans);
    ULL ph = hashFind(hashcode);
    //如果是新答案就输出并标记
    if (h[ph] != hashcode) {
        cout << ans << endl;
        used[ph] = true;
        h[ph] = hashcode;
    }
    ```