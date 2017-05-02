#include <iostream>
using namespace std;

int jz[20][20],a[20][20],result[20][20],M,N;

void qufan(int i,int j)
{
    result[i][j]=!result[i][j];
    result[i+1][j]=!result[i+1][j];
    result[i-1][j]=!result[i-1][j];
    result[i][j+1]=!result[i][j+1];
    result[i][j-1]=!result[i][j-1];
}

bool solve()
{
    for(int k=0;k<(1<<N);++k)
    {
        memcpy(result,jz,sizeof(jz));
        for(int w=k,i=1;i<=N;w>>=1,++i)
        {
            a[1][N-i+1]=w&1;
            if(a[1][N-i+1])
                qufan(1,N-i+1);
        }
        for(int i=2;i<=M;++i)
            for(int j=1;j<=N;++j)
            {
                a[i][j]=result[i-1][j];
                if(a[i][j])
                    qufan(i,j);
            }
        
        bool isOK=true;
        for(int i=1;i<=M;++i)
            for(int j=1;j<=N;++j)
                if(result[i][j])
                {
                    isOK=false;
                    break;
                }
        if(isOK)
            return true;
    }
    return false;
}

int main()
{
    cin >> M >> N;
    for(int i=1;i<=M;++i)
        for(int j=1;j<=N;++j)
            cin >> jz[i][j];
    if(solve())
        for(int i=1;i<=M;++i)
            for(int j=1;j<=N;++j)
                cout << a[i][j] << ((j<N)?' ':'\n');
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
