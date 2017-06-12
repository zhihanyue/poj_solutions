#include <iostream>
using namespace std;
int a[100008];

int main()
{
    int casecnt;
    cin >> casecnt;
    while(casecnt--)
    {
        int N,S;
        cin >> N >> S;
        for(int i=1;i<=N;++i)
            cin >> a[i];
        int ans=INT_MAX;
        for(int L=1,R=1,sum=a[1];L<=N;sum-=a[L++])
        {
            while(sum<S && R<N)
                sum+=a[++R];
            if(sum<S)
                break;
            ans=min(ans,R-L+1);
        }
        if(ans==INT_MAX)
            cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
