#include <iostream>
#define lowbit(i) ((i)&(-(i)))
using namespace std;
int A[100008],N;

template <typename T,int max>
struct BIT
{
    T bit[max],len,S[max];
    void init(int arr[],int _len)
    {
        len=_len;
        S[0]=0;
        for(int i=1;i<=len;++i)
            S[i]=S[i-1]+arr[i];
        for(int i=1;i<=len;++i)
            bit[i]=S[i]-S[i-lowbit(i)];
    }
    T sum(int i)
    {
        T result=0;
        for(;i>0;i-=lowbit(i))
            result+=bit[i];
        return result;
    }
    void add(int i,int v)
    {
        for(;i<=len;i+=lowbit(i))
            bit[i]+=v;
    }
};
BIT<long long,100008> BIT1,BIT2;

int main()
{
    int Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;++i)
        scanf("%d",&A[i]);
    BIT1.len=N;
    BIT2.init(A,N);
    for(int i=1;i<=Q;++i)
    {
        char ch;
        int a,b,x;
        scanf(" %c %d%d",&ch,&a,&b);
        if(ch=='C')
        {
            scanf("%d",&x);
            BIT1.add(a,x);
            BIT1.add(b+1,-x);
            BIT2.add(a,-(a-1)*x);
            BIT2.add(b+1,b*x);
        }
        else printf("%I64d\n",(BIT1.sum(b)*b+BIT2.sum(b))-(BIT1.sum(a-1)*(a-1)+BIT2.sum(a-1)));
    }
    return 0;
}
