#include <cstdio>
#include <cstring>
#include <cstdlib>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
using namespace std;

template<typename _Tp>
_Tp mypower(_Tp __x, unsigned int __n)
{
    _Tp __y = {{{0},{0,1},{0,0,1},{0,0,0,1},{0,0,0,0,1}},4,4};
    if(__n % 2)
        __y = __x;
    while (__n >>= 1) {
        __x *= __x;
        if (__n % 2) __y *= __x;
    }
    return __y;
}

struct juzhen
{
    int a[5][5],n,m;
    bool operator*=(juzhen anojz)
    {
        juzhen thisjz=*this;
        if(thisjz.m!=anojz.n) return false;
        memset(a,0,sizeof(a));
        fromto(1,thisjz.n,i) fromto(1,anojz.m,j) fromto(1,thisjz.m,k)
            a[i][j]=(a[i][j]+thisjz.a[i][k]*anojz.a[k][j])%10007;
        n=thisjz.n;
        m=anojz.m;
        return true;
    }
};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        juzhen k={{{0},{0,2,0,1,1},{0,0,2,1,1},{0,1,1,2,0},{0,1,1,0,2}},4,4},temp={{{0},{0,0},{0,0},{0,1},{0,0}},4,1},ans=mypower(k,N);
        ans*=temp;
        printf("%d\n",ans.a[3][1]);
    }
    return 0;
}
