#include <iostream>
using namespace std;
int A[100008],N;

int lowbit(int i)
{
    return i&(-i);
}

struct BIT
{
    long long bit[100008];
    long long sum(int i)
    {
        long long result=0;
        for(;i>0;i-=lowbit(i))
            result+=bit[i];
        return result;
    }
    void add(int i,int v)
    {
        for(;i<=N;i+=lowbit(i))
            bit[i]+=v;
    }
}BIT1,BIT2;

int main()
{
    int Q;
    cin >> N >> Q;
    for(int i=1;i<=N;++i)
    {
        cin >> A[i];
/*      BIT1.add(i,A[i]);
        BIT1.add(i+1,-A[i]);
        BIT2.add(i,-(i-1)*A[i]);
        BIT2.add(i+1,i*A[i]);*/
        BIT2.add(i,A[i]);
    }
    for(int i=1;i<=Q;++i)
    {
        char ch;
        long long a,b,x;
        cin >> ch >> a >> b;
        if(ch=='C')
        {
            cin >> x;
            BIT1.add(a,x);
            BIT1.add(b+1,-x);
            BIT2.add(a,-(a-1)*x);
            BIT2.add(b+1,b*x);
        }
        else cout << (BIT1.sum(b)*b+BIT2.sum(b))-(BIT1.sum(a-1)*(a-1)+BIT2.sum(a-1)) << endl;
    }
    return 0;
}
