#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#define maxn 500008
using namespace std;
typedef pair<int,int> sta;

int rk[2*maxn], sa[maxn],lcp[maxn];
int tmp[maxn];
int k,n;
bool cmp_sa(int x, int y)
{
    return sta(rk[x],rk[x+k])<sta(rk[y],rk[y+k]);
}
 
void construct_sa(char *s, int len)
{
    memset(rk,-1,sizeof(rk));
    n = strlen(s);
    for (int i = 0; i < n; i++){
        sa[i] = i;
        rk[i] = s[i];
    }
    sa[n]=n;
    for (k = 1; k <= n; k*=2)
    {
        sort(sa, sa + n + 1, cmp_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1 : 0);
        for (int i = 0; i <= n; i++) rk[i] = tmp[i];
    }
}
 
void construct_lcp(char *s, int len)
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
 
char str1[maxn], str2[maxn];
 
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
        int len2=strlen(str1);
        construct_sa(str1,len2);
        construct_lcp(str1,len2);
        int ans = 0;
        for (int i = 0; i < len2; i++)
        {
            if ((sa[i] < len) != (sa[i + 1]) < len){
                ans = max(ans, lcp[i]);
            }
        }
        printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
    }
    return 0;
}
