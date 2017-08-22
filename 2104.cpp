#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#define B 320
#define num(x) (((x)-1)/B+1)
using namespace std;
int A[100008],sorted_A[100008];
vector<int> bucket[400];

int check(int x,int L,int R)
{
    //printf("check:[%d,%d]%d -> ",L,R,x);
    int k=0;
    for(;L<=R && (L-1)%B!=0;++L)
        if(A[L]<=x)
            ++k;
    for(;L<=R && R%B!=0;--R)
        if(A[R]<=x)
            ++k;
    //printf("..%d ",k);
    for(int i=L;i<=R;i+=B)
    {
        k+=upper_bound(bucket[num(i)].begin(),bucket[num(i)].end(),x)-bucket[num(i)].begin();
        //printf("..%d ",k);
    }
    //printf("%d\n",k);
    return k;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        sorted_A[i]=A[i];
    }
    sort(sorted_A+1,sorted_A+n+1);
    for(int i=1;i<=n;++i)
        bucket[num(i)].push_back(A[i]);
    for(int i=1;i<=num(n);++i)
        sort(bucket[i].begin(),bucket[i].end());
    for(int i=1;i<=m;++i)
    {
        int L,R,k;
        scanf("%d%d%d",&L,&R,&k);
        int x_L=1,x_R=n;
        while(x_L<x_R)
        {
            int x_M=x_L+(x_R-x_L)/2;
            if(check(sorted_A[x_M],L,R)>=k)
                x_R=x_M;
            else x_L=x_M+1;
        //  printf("L=%d R=%d\n",x_L,x_R);
        }
        printf("%d\n",sorted_A[x_L]);
    }
    return 0;
}
