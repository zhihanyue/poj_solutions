#include <cstdio>
#include <cstdlib>
using namespace std;
int A[100008],N;
long long xdtree[400008],addv[400008];

void init(int o,int L,int r)
{
    addv[o]=0;
    if(L+1==r)
    {
        xdtree[o]=A[L];
        return;
    }
    int M=L+(r-L)/2;
    init(o*2,L,M);
    init(o*2+1,M,r);
    xdtree[o]=xdtree[o*2]+xdtree[o*2+1];
}

void pushdown(int o,int L,int r)
{
    if(L+1!=r)
    {
        addv[o*2]+=addv[o];
        addv[o*2+1]+=addv[o];
        int M=L+(r-L)/2;
        xdtree[o*2]+=(M-L)*addv[o];
        xdtree[o*2+1]+=(r-M)*addv[o];
    }
    addv[o]=0;
}

int qu_L,qu_r;
long long qu_ans;
void query(int o,int L,int r)
{
    if(L>=qu_r || r<=qu_L)
        return;
    if(qu_L<=L && r<=qu_r)
    {
        qu_ans+=xdtree[o];
        return;
    }
    pushdown(o,L,r);
    int M=L+(r-L)/2;
    query(o*2,L,M);
    query(o*2+1,M,r);
}

int up_L,up_r;
long long up_add;
void update(int o,int L,int r)
{
    if(L>=up_r || r<=up_L)
        return;
    if(up_L<=L && r<=up_r)
    {
        addv[o]+=up_add;
        xdtree[o]+=(r-L)*up_add;
        return;
    }
    pushdown(o,L,r);
    int M=L+(r-L)/2;
    update(o*2,L,M);
    update(o*2+1,M,r);
    xdtree[o]=xdtree[o*2]+xdtree[o*2+1];
}

int main()
{
    int Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;++i)
        scanf("%d",&A[i]);
    init(1,1,N+1);
    for(int i=1;i<=Q;++i)
    {
        char ch;
        int a,b,x;
        scanf(" %c %d%d",&ch,&a,&b);
        if(ch=='C')
        {
            scanf("%d",&x);
            up_L=a;
            up_r=b+1;
            up_add=x;
            update(1,1,N+1);
        }
        else
        {
            qu_L=a;
            qu_r=b+1;
            qu_ans=0;
            query(1,1,N+1);
            printf("%I64d\n",qu_ans);
        }
    }
    return 0;
}
