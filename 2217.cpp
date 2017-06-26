#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAXN 1000008
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define watch(a,size) for(int __i=0;__i<(size);++__i) printf("[%d]=%d ",__i,(a)[__i]);printf("\n");
typedef pair<int,int> sta;
char A[2*MAXN],B[MAXN],fA_len;

int sa[MAXN],rank[2*MAXN],lcp[MAXN],sa_k;

bool cmp(int x,int y)
{
    return sta(rank[x],rank[x+sa_k])<sta(rank[y],rank[y+sa_k]);
}

void getsa(char *a,int n)//->sa,rank
{
    memset(rank,-1,sizeof(rank));
    fromto(1,n,i) {sa[i]=i;rank[i]=a[i];}
    for(sa_k=1;sa_k<=n;sa_k*=2) {
        sort(sa+1,sa+n+1,cmp);
        static int newrank[2*MAXN];
        newrank[sa[1]]=1;
        fromto(2,n,i) newrank[sa[i]]=newrank[sa[i-1]]+cmp(sa[i-1],sa[i]);
        fromto(1,n,i) rank[i]=newrank[i];
    }
}

void getlcp(char *a,int n)//sa,rank->lcp
{
    int h=0;
    fromto(1,n,i) rank[sa[i]]=i;//!!!
    fromto(1,n,i) {
        if(rank[i]<=1) continue;
        if(h>0) --h;
        int j=sa[rank[i]-1];
        while(i+h<=n && j+h<=n && a[i+h]==a[j+h]) ++h;//!!!
        lcp[rank[i]]=h;
    }
}

int main()
{
    int casecnt; scanf("%d",&casecnt); getchar();
    while(casecnt--) {
        gets(A+1);gets(B+1);
        fA_len=strlen(A+1);
        B[0]='$';
        strcat(A+1,B);
        int A_len=strlen(A+1);
        getsa(A,A_len);
        getlcp(A,A_len);
        int ans=0;
        fromto(2,A_len,i) if((sa[i]<=fA_len)!=(sa[i-1]<=fA_len)) ans=max(ans,lcp[i]);
        printf("Nejdelsi spolecny retezec ma delku %d.\n",ans);
    }
    return 0;
}
