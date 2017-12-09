#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    cin >> M;
    for(int k=1;k<=M;++k)
    {
        int len,N;
        cin >> len >> N;
        int ans1=0,ans2=0;
        for(int i=1;i<=N;++i)
        {
            int a;
            cin >> a;
            ans1=max(ans1,min(a,len-a));
            ans2=max(ans2,max(a,len-a));
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    //system("pause");
    return 0;
}
