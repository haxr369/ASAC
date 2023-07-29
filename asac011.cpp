#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int R,C,K, ans;
char mp[5][5];
int visited[5][5];

const int dy [] = {-1,1,0,0};
const int dx[] = {0,0,1,-1};

void dfs(int y, int x, int deep){
    if(y==0 && x == C-1 && deep == K){
        ans++;
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || nx <0 || ny >= R || nx >= C || visited[ny][nx] || mp[ny][nx]=='T') continue;
        visited[ny][nx] = 1;
        dfs(ny,nx, deep+1);
        visited[ny][nx] = 0;

    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R>>C>>K;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> mp[i][j];
        }
    }
    visited[R-1][0] = 1;
    dfs(R-1, 0, 1);
    cout << ans <<'\n';
    return 0;
}