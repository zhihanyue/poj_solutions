#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int sA[100008];
int xdtree[50][100008],left[50][100008];//[d][L]~[d][r-1]

void build(int L,int r,int d)
{
    if(L+1==r)
        return;
    int M=L+(r-L)/2,x=sA[M];
    int lm=sA+M-lower_bound(sA+L,sA+M,x);//!!!!!!!!!!!!!!!!!
    int newLeft=L,newRight=M;
    for(int i=L;i<r;++i)
    {
        if(xdtree[d][i]<x)
            xdtree[d+1][newLeft++]=xdtree[d][i];
        else if(xdtree[d][i]>x)
            xdtree[d+1][newRight++]=xdtree[d][i];
        else if(lm!=0)
        {
            xdtree[d+1][newLeft++]=xdtree[d][i];
            --lm;
        }
        else xdtree[d+1][newRight++]=xdtree[d][i];
        left[d][i]=newLeft-L;
    }
    build(L,M,d+1);
    build(M,r,d+1);
}

int qu_L,qu_r,qu_k,qu_ans;
void query(int L,int r,int d)
{
    //printf("query: %d %d %d\n",qu_L,qu_r,qu_k);
    if(qu_L+1==qu_r)
    {
        qu_ans=xdtree[d][qu_L];
        return;
    }
    int M=L+(r-L)/2;
    int len_l=(L==qu_L)?0:left[d][qu_L-1];//!!!!!!!!!!!!!!!
    int len_r=left[d][qu_r-1];
    if(len_r-len_l>=qu_k)
    {
        qu_L=L+len_l;
        qu_r=L+len_r;
        query(L,M,d+1);
    }
    else
    {
        qu_L=M+qu_L-L-len_l;
        qu_r=M+qu_r-L-len_r;
        qu_k-=len_r-len_l;
        query(M,r,d+1);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&xdtree[0][i]);
        sA[i]=xdtree[0][i];
    }
    sort(sA+1,sA+n+1);
    build(1,n+1,0);
/*  printf("\n");
    for(int i=0;i<=8;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%d ",xdtree[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<=8;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%d ",left[i][j]);
        printf("\n");
    }
    printf("\n");*/
    while(m--)
    {
        int L,R,k;
        scanf("%d%d%d",&L,&R,&k);
        qu_L=L;
        qu_r=R+1;
        qu_k=k;
        qu_ans=0;
        query(1,n+1,0);
        printf("%d\n",qu_ans);
    }
    return 0;
}
