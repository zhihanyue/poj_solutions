#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#define maxn 500000
using namespace std;
 
int rk[maxn+50], sa[maxn+50],lcp[maxn+50];
int tmp[maxn + 50];
int k,n;
bool cmp_sa(int i, int j)
{
    if (rk[i] != rk[j]) return rk[i] < rk[j];
    else {
        int ri = i + k <= n ? rk[i + k] : -1;
        int rj = j + k <= n ? rk[j + k] : -1;
        return ri < rj;
    }
}
 
void construct_sa(char *s, int *sa)
{
    n = strlen(s);
    for (int i = 0; i <= n; i++){
        sa[i] = i;
        rk[i] = i < n ? s[i] : -1;
    }
    for (k = 1; k <= n; k <<= 1)
    {
        sort(sa, sa + n + 1, cmp_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++)
        {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; i++){
            rk[i] = tmp[i];
        }
    }
}
 
void construct_lcp(char *s, int *sa, int *lcp)
{
    n = strlen(s);
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    int h = 0;
    lcp[0] = 0; 
    for (int i = 0; i < n; i++){
        int j = sa[rk[i] - 1];
        for (h ? h-- : 0; j + h < n&&i + h < n&&s[j + h] == s[i + h]; h++);
        lcp[rk[i] - 1] = h;
    }
}
 
char str1[maxn + 50], str2[maxn + 50];
 
int main()
{
    int T; cin >> T; getchar();
    while (T--)
    {
        gets(str1);
        gets(str2+1);
        int len = strlen(str1);
        str2[0] = '#';
        strcat(str1, str2);
        construct_sa(str1 ,sa);
        construct_lcp(str1,sa,lcp);
        int ans = 0;
        for (int i = 0; i < strlen(str1); i++)
        {
            if ((sa[i] < len) != (sa[i + 1]) < len){
                ans = max(ans, lcp[i]);
            }
        }
        printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
    }
    return 0;
}
