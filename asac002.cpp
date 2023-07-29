#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int N,M, mp[104][104], visited[104][104];
int ny, nx,y,x;
string s;
queue<pair<int,int>> qu;

const int  dy [] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N>>M;

    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<M; j++){
            mp[i][j] = s[j]-'0';
        }
    }

    qu.push({0,0});
    visited[0][0]=1;

    while(qu.size()){
        pair<int,int> yyy = qu.front(); qu.pop();
        y = yyy.first;
        x = yyy.second;
        bool flag = false;
        //cout << "y : x = "<<y <<" : "<<x<<'\n';
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || nx <0 || ny>=N || nx >=M) continue;
            if(visited[ny][nx] || mp[ny][nx]==0)continue;
        
            qu.push({ny,nx});
            visited[ny][nx] = visited[y][x] +1;

            if(ny==N-1 && nx==M-1){
                flag = true;
                break;
            }

        }
        if(flag) break;

    }

    cout << visited[N-1][M-1] <<'\n';

    return 0;
}