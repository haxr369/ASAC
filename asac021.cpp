#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

/*
26개의 알파벳. 26자리의 비트마스킹으로 사용 유무를 저장.
최대 거리이므로 dfs를 사용.
*/

int R,C, visited[24][24], ans;
int mp[24][24];
int bits[26];
string S;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

void dfs(int y, int x, int deep){
    //cout << "y : "<<y <<" x : "<<x<<" mp : "<<mp[y][x]<<'\n';
    ans = max(deep, ans);

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=R||nx>=C) continue;
        //cout <<"ny : "<<ny<<" nx : "<<nx<<" visited : "<<visited[ny][nx] <<" bits : "<<bits[mp[ny][nx]]<<'\n';
        if(visited[ny][nx] || bits[mp[ny][nx]]) continue;

        visited[ny][nx] = 1;
        bits[mp[ny][nx]] = 1;
        dfs(ny, nx, deep+1);
        visited[ny][nx] = 0;
        bits[mp[ny][nx]] = 0;
    }

    return ;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R>> C;
    for(int i=0; i<R; i++){
        cin >> S;
        for(int j=0; j<C; j++){
            mp[i][j] = S[j]-'A';
        }
    }
    visited[0][0] = 1;
    bits[mp[0][0]]=1;
    dfs(0,0,1);
    cout << ans <<'\n';
    return 0;
}