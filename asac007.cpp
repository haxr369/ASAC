#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int N,ans, maxHigh;
int mp[104][104], visited[104][104];

const int dy[] ={0,0,-1,1};
const int dx[] ={1,-1,0,0};

//모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다

void dfs(int y, int x, int h){
    //cout << "y : "<<y<<" x : "<<x<<" high : "<<h<<'\n';
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0|| ny>=N || nx>=N || visited[ny][nx] || mp[ny][nx]-h<=0) continue;
        visited[ny][nx]=1;
        dfs(ny,nx,h);
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mp[i][j];
            maxHigh = max(maxHigh, mp[i][j]);
        }
    }

    for(int h=0; h<maxHigh; h++){
        int cnt = 0;
        fill(&visited[0][0], &visited[0][0]+10504,0);
        for(int i = 0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]||mp[i][j]-h <=0)continue;
                visited[i][j]=1;
                dfs(i,j,h);
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    
    cout << ans <<'\n';
    
    
    return 0;
}