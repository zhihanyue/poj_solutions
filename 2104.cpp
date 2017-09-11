#include <cstdio>
#include <vector>
#include <algorithm>
#define N_MAX 100008
using namespace std;
int A[N_MAX],n;
int num[N_MAX];
vector<int> xdtree[N_MAX*4];

void init(int o,int L,int r)
{
    if(L+1==r)
    {
        xdtree[o].push_back(A[L]);
        return;
    }
    int M=L+(r-L)/2;
    init(o*2,L,M);
    init(o*2+1,M,r);
    xdtree[o].resize(xdtree[o*2].size()+xdtree[o*2+1].size());//!!!
    merge(xdtree[o*2].begin(),xdtree[o*2].end(),xdtree[o*2+1].begin(),xdtree[o*2+1].end(),xdtree[o].begin());
}

int qu_ans,qu_L,qu_r,qu_x;
void query(int o,int L,int r)
{
    if(r<=qu_L || L>=qu_r)
        return;
    if(qu_L<=L && r<=qu_r)
    {
        qu_ans+=lower_bound(xdtree[o].begin(),xdtree[o].end(),qu_x)-xdtree[o].begin();
        return;
    }
    int M=L+(r-L)/2;
    query(o*2,L,M);
    query(o*2+1,M,r);
}

int main()
{
    int q_M;
    scanf("%d%d",&n,&q_M);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        num[i]=A[i];
    }
    sort(num+1,num+n+1);
    init(1,1,n+1);
    while(q_M--)
    {
        int L,R,k;
        scanf("%d%d%d",&L,&R,&k);
        int bL=1,bR=n+1;
        while(bL<bR)
        {
            int bM=bL+(bR-bL)/2;
            qu_ans=1;
            qu_L=L;
            qu_r=R+1;
            qu_x=num[bM];
            query(1,1,n+1);
            if(qu_ans<=k)
                bL=bM+1;
            else bR=bM;
        }
        printf("%d\n",num[bL-1]);
    }
    return 0;
}
