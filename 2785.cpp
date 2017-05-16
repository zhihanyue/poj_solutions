#include <cstdio>
#include <algorithm>
using namespace std;
int a[4008],b[4008],c[4008],d[4008];
int add[16000008],len=0;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            add[len++]=-(a[i]+b[j]);
    sort(add,add+len);
    unsigned long long ans=0;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            ans+=upper_bound(add,add+len,c[i]+d[j])-lower_bound(add,add+len,c[i]+d[j]);
    printf("%d\n",ans);
    return 0;
}
