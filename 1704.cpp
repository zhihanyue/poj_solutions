#include <cstdio>
#include <algorithm>
using namespace std;
int a[1008];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",&a[i]);
        if(n%2!=0) a[n++]=0;
        sort(a,a+n);
        int x=0;
        for(int i=1;i<n;i+=2) x^=a[i]-a[i-1]-1;
        printf(x?"Georgia will win\n":"Bob will win\n");
    }
    return 0;
}
