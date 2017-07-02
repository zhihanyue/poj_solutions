#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int f[10008];

int KMP(char P[],char T[])
{
    int cnt=0;
    int n=strlen(P+1),m=strlen(T+1),j=0;
    for(int i=1;i<=n;++i) {
        while(j>0 && T[j+1]!=P[i]) j=f[j];//j>0 && T[j+1]!=P[i]等价于失败 
        if(T[j+1]==P[i]) ++j;
        if(j==m) ++cnt;
    }
    return cnt;
}

void getfail(char T[])
{
    int m=strlen(T+1);
    f[0]=0;f[1]=0;
    for(int i=1;i<m;++i)
    {
        int j=f[i];
        while(j>0 && T[j+1]!=T[i+1]) j=f[j];
        f[i+1]=(T[j+1]==T[i+1])?j+1:0;
        //f[i+1]=(j==0)?0:j+1; 这个没考虑在0处匹配失败的情况，是错误的写法！！！ 
    }
}

int main()
{
    static char P[1000008],T[10008];
    int casecnt;
    scanf("%d",&casecnt);
    while(casecnt--) {
        scanf("%s%s",T+1,P+1);
        getfail(T);
        printf("%d\n",KMP(P,T));
    }
    return 0;
}
