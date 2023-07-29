#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int N, cnt;
vector<int> vi;
string s;
int mp[25][25], visited[25][25];

const int dy[] ={0,0,-1,1};
const int dx[] ={1,-1,0,0};

int dfs(int y, int x, int area){
    //cout << "y : "<<y<<" x : "<<x<<" area : "<<area<<'\n';
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || nx<0|| ny>=N || nx>=N || visited[ny][nx] || mp[ny][nx]==0) continue;
        visited[ny][nx]=1;
        area = dfs(ny,nx,area+1);
    }

    return area;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >>N;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<N; j++){
            mp[i][j] = s[j]-'0';
        }
    }

    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]||mp[i][j]==0)continue;
            visited[i][j]=1;
            cnt++;
            int a = dfs(i,j,1);
            vi.push_back(a);
        }
    }

    sort(vi.begin(), vi.end());
    cout << vi.size()<<'\n';
    for(int i : vi) cout << i<<'\n';
    
    return 0;
}