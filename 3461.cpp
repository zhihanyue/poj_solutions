#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int f[10000];

int KMP(char P[],char T[])
{
    int cnt=0;
    int n=strlen(P+1)+1,m=strlen(T+1)+1,j=0;
    for(int i=1;i<=n;++i) {
        while(j>0 && T[j+1]!=P[i]) j=f[j];
        if(T[j+1]==P[i]) ++j;
        //此时的j表示以i位置为尾的最大匹配长度 
        if(j==m-1) ++cnt;
    }
    return cnt;
}

void getfail(char T[])
{
    int m=strlen(T+1)+1,j=0;
    f[1]=0;
    for(int i=2;i<=m;++i) {//错位匹配法，不能计算后缀为整个串的情况 
        while(j>0 && T[j+1]!=T[i])
            j=f[j];
        if(T[j+1]==T[i])
            ++j;
        f[i]=j;//记录每一次失配的正确转移位置 
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
