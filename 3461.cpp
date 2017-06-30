#include <cstdio>
#include <cstring>
#include <cstdlib>
#define TMAX 10008
#define PMAX 1000008
using namespace std;

char T[TMAX],T_len;
char P[PMAX],P_len;
int f[TMAX];

void getfail()
{
    int j=0;
    f[1]=0;
    for(int i=2;i<=T_len+1;++i) {
        while(j>0 && T[i]!=T[j+1]) j=f[j];
        if(T[i]==T[j+1]) ++j;
        f[i]=j;
    }
}

int KMP()
{
    int j=0,res=0;
    for(int i=1;i<=P_len+1;++i) {
        while(j>0 && P[i]!=T[j+1]) j=f[j];
        if(P[i]==T[j+1]) ++j;
        if(j==T_len) ++res;
    }
    return res;
}

int main()
{
    int casecnt;
    scanf("%d",&casecnt);
    while(casecnt--) {
        scanf("%s%s",T+1,P+1);
        T_len=strlen(T+1);
        P_len=strlen(P+1);
        getfail();
        printf("%d\n",KMP());
    }
    return 0;
}
