#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#define B 1000
using namespace std;
int N,M;
int A[100008];
int I[5008],J[5008],K[5008];
int nums[100008];
vector<int> bucket[100008/B];

void solve()
{
    for(int i=0;i<N;++i)
    {
        bucket[i/B].push_back(A[i]);
        nums[i]=A[i];
    }
    sort(nums,nums+N);
    for(int i=0;i<N/B;++i)
        sort(bucket[i].begin(),bucket[i].end());
    for(int i=0;i<M;++i)
    {
        int l=I[i]-1,r=J[i],k=K[i];
        int lb=-1,ub=N-1;
        while(ub-lb>1)
        {
            int md=(lb+ub)/2;
            int x=nums[md];
            int tl=l,tr=r,c=0;
            while(tl<tr && tl%B!=0)
                if(A[tl++]<=x)
                    c++;
            while(tl<tr && tr%B!=0)
                if(A[--tr]<=x)
                    c++;
            while(tl<tr)
            {
                int b=tl/B;
                c+=upper_bound(bucket[b].begin(),bucket[b].end(),x)-bucket[b].begin();
                tl+=B;
            }
            if(c>=k)
                ub=md;
            else lb=md;
        }
        printf("%d\n",nums[ub]);
    }
}

int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    for(int i=0;i<M;++i)
        scanf("%d%d%d",&I[i],&J[i],&K[i]);
    solve();
    return 0;
}
