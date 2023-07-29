#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int M,N,K, q,w,e,r;
int mp[104][104], visited[104][104];
vector<int> vi;

const int dy[] ={0,0,-1,1};
const int dx[] ={1,-1,0,0};

//모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다

int dfs(int y, int x, int area){
    //cout << "y : "<<y<<" x : "<<x<<" area : "<<area<<'\n';
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0|| ny>=M || nx>=N || visited[ny][nx] || mp[ny][nx]==1) continue;
        visited[ny][nx]=1;
        area = dfs(ny,nx,area+1);
    }
    return area;
}

void fillMap(int lx, int ly, int rx, int ry){
    for(int i = ly; i<ry; i++){
        for(int j=lx; j<rx; j++){
            mp[i][j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M>>N>>K;

    for(int i=0; i<K; i++){
        cin >>q>>w>>e>>r;
        fillMap(q,w,e,r);
    }

    for(int i = 0; i<M; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]||mp[i][j])continue;
            visited[i][j]=1;
            int a = dfs(i,j,1);
            vi.push_back(a);
        }
    }

    cout << vi.size()<<'\n';
    sort(vi.begin(), vi.end());
    for(int i: vi) cout << i<<' ';
    cout <<'\n';
    
    return 0;
}