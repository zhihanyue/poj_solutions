#include <cstdio>
#include <climits>
#include <algorithm>
#define INF INT_MAX
using namespace std;
int L[500008],R[500008],len;
int xdtree[200008];

void xd_init(int o,int L,int r)
{
    if(L+1==r) {
        xdtree[o]=(L==1)?0:INF;
        return;
    }
    int M=L+(r-L)/2;
    xd_init(o*2,L,M);
    xd_init(o*2+1,M,r);
    xdtree[o]=min(xdtree[o*2],xdtree[o*2+1]);
}

int xd_min_L,xd_min_r;
int xd_min(int o,int L,int r)
{
    if(xd_min_L<=L && r<=xd_min_r) return xdtree[o];
    if(xd_min_L>=r || xd_min_r<=L) return INF;
    int M=L+(r-L)/2;
    return min(xd_min(o*2,L,M),xd_min(o*2+1,M,r));
}

int xd_up_pos,xd_up_val;
void xd_update(int o,int L,int r)
{
    if(L>xd_up_pos || r<=xd_up_pos) return;
    if(L+1==r) {
        xdtree[o]=min(xdtree[o],xd_up_val);
        return;
    }
    int M=L+(r-L)/2;
    xd_update(o*2,L,M);
    xd_update(o*2+1,M,r);
    xdtree[o]=min(xdtree[o*2],xdtree[o*2+1]);
}

int main()
{
    int n;
    scanf("%d%d",&n,&len);
    for(int i=1;i<=len;++i) scanf("%d%d",&L[i],&R[i]);
    xd_init(1,1,n+1);
    for(int i=1;i<=len;++i) {
        xd_min_L=L[i];xd_min_r=R[i]+1;
        xd_up_pos=R[i];xd_up_val=xd_min(1,1,n+1);
        if(xd_up_val!=INF) ++xd_up_val;
        xd_update(1,1,n+1);
    }
    xd_min_L=n;xd_min_r=n+1;
    printf("%d\n",xd_min(1,1,n+1));
    return 0;
}
