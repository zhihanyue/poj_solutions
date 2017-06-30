#include <iostream>
#include <algorithm>
using namespace std;

int X[1008];
int main()
{
    while(true)
    {
        int R,N;
        cin >> R >> N;
        if(R==-1 && N==-1)
            break;
        for(int i=1;i<=N;++i)
            cin >> X[i];
        sort(X+1,X+N+1);
        int i=1,ans=0;
        while(i<=N)
        {
            int j=i+1;
            while(j<=N && X[i]+R>=X[j])
                ++j;
            i=j-1;
            while(j<=N && X[i]+R>=X[j])
                ++j;
            i=j;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
