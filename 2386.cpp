#include <iostream>
using namespace std;
bool a[108][108];
bool vis[108][108];
void dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=-1;i<=1;++i)
        for(int j=-1;j<=1;++j)
            if(a[x+i][y+j] && !vis[x+i][y+j])
                dfs(x+i,y+j);
}

int main()
{
    int N,M;
    cin >> N >> M;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
        {
            char tempch;
            cin >> tempch;
            a[i][j]=(tempch=='W');
        }
    int ans=0;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            if(a[i][j] && !vis[i][j])
            {
                ++ans;
                dfs(i,j);
            }
    cout << ans << endl;
    return 0;
}
