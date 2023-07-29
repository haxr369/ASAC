#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int T, I, ta, tb, tc, td;
const int dy[] = {2,2,-2,-2,1,1,-1,-1};
const int dx[] = {1,-1,1,-1,2,-2,2,-2};
int visited[304][304];

int bfs(int a, int b, int c, int d){
    if(a==c && b==d)return 0;
    
    fill(&visited[0][0], &visited[0][0]+91216,0);
    queue<pair<int,int>> qu;

    visited[a][b] = 1;
    qu.push({a, b});

    while(qu.size()){
        pair<int,int> yx = qu.front(); qu.pop();
        bool flag = false;
        for(int i=0; i<8; i++){
            int ny = yx.first + dy[i];
            int nx = yx.second + dx[i];
            if(ny<0 || nx <0 || ny >= I || nx >= I ) continue;
            if(visited[ny][nx])continue;

            visited[ny][nx] = visited[yx.first][yx.second]+1;
            qu.push({ny,nx});

            if(ny==c && nx==d){
                flag = true;
                break;
            } 
        }
        if(flag) break;
    }
    return visited[c][d]-1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T>0){
        cin >> I;
        cin >> ta >> tb;
        cin >> tc >> td;

        cout << bfs(ta,tb,tc,td) <<'\n';

        T--;
    }

    return 0;
}