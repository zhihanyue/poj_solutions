#include <cstdio>
#include <cstdlib>
#include <cstring>
//#define B 2
#define B 300
using namespace std;
int A[100008],N;
long long bucket[400],addv[400];

int num(int i)
{
    return (i-1)/B+1;
}

int main()
{
    int Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;++i)
        scanf("%d",&A[i]);
    for(int i=1;i<=N;++i)
        bucket[num(i)]+=A[i];
    for(int i=1;i<=Q;++i)
    {
        char ch;
        int a,b,x;
        scanf(" %c %d%d",&ch,&a,&b);
        if(ch=='C')
        {
            scanf("%d",&x);
            for(;a<=b && (a-1)%B!=0;++a)
            {
                A[a]+=x;
                bucket[num(a)]+=x;
            }
            for(;a<=b && b%B!=0;--b)
            {
                A[b]+=x;
                bucket[num(b)]+=x;
            }
            for(int j=a;j<=b;j+=B)
            {
                bucket[num(j)]+=x*B;
                addv[num(j)]+=x;
            }
        }
        else
        {
            long long result=0;
            for(;a<=b && (a-1)%B!=0;++a)
                result+=A[a]+addv[num(a)];
            for(;a<=b && b%B!=0;--b)
                result+=A[b]+addv[num(b)];
            for(int j=a;j<=b;j+=B)
                result+=bucket[num(j)];
            printf("%I64d\n",result);
        }
    }
    return 0;
}
