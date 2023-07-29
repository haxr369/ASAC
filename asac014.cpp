#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

/*

정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
bfs로 진입.
*/


int N,M, mp[1004][1004], visited[1004][1004], tempVisited[1004][1004];
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
queue<pair<int,int>> qu;

int bfs(){
    int day = 0;
    while(1){
        int cnt =0;
        int temp = qu.size();
        for(int i=0; i<temp; i++){
            pair<int,int> q = qu.front(); qu.pop();

            for(int j=0; j<4; j++){
                int ny = q.first + dy[j];
                int nx = q.second + dx[j];
                if(ny<0 || nx<0 || ny>= N || nx>=M) continue;
                if(visited[ny][nx] || mp[ny][nx] != 0) continue;
                cnt++;
                mp[ny][nx] = 1;
                qu.push({ny,nx});
            }
        }
        
        if(cnt==0) break;
        day++;
    }
    return day;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >>M>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> mp[i][j];
            if(mp[i][j]==1){ qu.push({i,j}); visited[i][j]=1;}
        }
    }
    int ans = bfs();

    bool flag = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(mp[i][j]==0){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    if(flag) cout << ans <<'\n';
    else cout << -1 << '\n';

    return 0;
}