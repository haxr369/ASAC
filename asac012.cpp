#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

// R=G -> 적록색약
int N, visited[104][104];
char mp[104][104];
string s;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,1,-1};

void nomalDfs(int y, int x, char op){

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=N || visited[ny][nx])continue;
        if(op != mp[ny][nx]) continue;
        visited[ny][nx] = 1;
        nomalDfs(ny, nx, op);
    }
    return ;
}

void omalDfs(int y, int x, char op){

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=N || visited[ny][nx])continue;
        if(op=='B' && mp[ny][nx]!='B')continue;
        if((op=='G' || op=='R') && mp[ny][nx]=='B') continue;
        visited[ny][nx] = 1;
        omalDfs(ny, nx, op);
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<N; j++){
            mp[i][j] = s[j];
        }
    }

    int nomal = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j])continue;
            visited[i][j]=1;
            nomalDfs(i,j, mp[i][j]);
            nomal++;
        }
    }
    fill(&visited[0][0], &visited[0][0]+10416,0);
    int omal = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j])continue;
            visited[i][j]=1;
            omalDfs(i,j, mp[i][j]);
            omal++;
        }
    }
    cout << nomal <<" "<<omal<<'\n';
    return 0;
}