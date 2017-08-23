#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#define B 1000
#define num(x) (((x)-1)/B+1)
using namespace std;
int A[100008],sorted_A[100008];
vector<int> bucket[100008/B];

int check(int x,int L,int R)
{
    int k=0;
    for(;L<=R && (L-1)%B!=0;++L)
        if(A[L]<=x)
            ++k;
    for(;L<=R && R%B!=0;--R)
        if(A[R]<=x)
            ++k;
    for(int i=L;i<=R;i+=B)
    {
        int b=num(i);
        k+=upper_bound(bucket[b].begin(),bucket[b].end(),x)-bucket[b].begin();
    }
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
    for(int i=1,size=num(n);i<=size;++i)
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
        }
        printf("%d\n",sorted_A[x_L]);
    }
    return 0;
}
