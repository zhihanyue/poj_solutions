#include <cstdio>
#include <algorithm>
using namespace std;
int X[100008],N;

int check(int x)
{
    int C=1,k=X[1];
    for(int i=2;i<=N;++i)
    {
        if(X[i]>=k+x)
        {
            ++C;
            k=X[i];
        }
    }
    return C;
}

int main()
{
    int C;
    scanf("%d%d",&N,&C);
    for(int i=1;i<=N;++i)
        scanf("%d",&X[i]);
    sort(X+1,X+N+1);
    
    int L=1,R=X[N]-X[1]+2;
    while(L<R)
    {
        int M=L+(R-L)/2;
        if(check(M)<C)
            R=M;
        else L=M+1;
    }
    printf("%d\n",L-1);
    //system("pause");
    return 0;
}
