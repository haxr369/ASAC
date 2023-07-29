#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

int N, visited[400], ans;
vector<int> vi;

/*
N개 행 각각에 1개의 퀸이 들어간다.
*/

bool deadPosi(int idx, int queen){
    int ny = queen; int nx = idx;

    for(int i : vi){
        int qy = i/N; int qx = i%N;

        if(qy==ny || qx==nx) return true;
        int dy = qy-ny;
        int dx = qx - nx;
        if(abs(dy)==abs(dx)) return true;
    }
    return false;
}

void dfs(int queen){
    if(queen == N){
        ans++;
        return ;
    }
    //cout << "idx : "<<idx <<" queen : "<<queen<<'\n';
    for(int i=0; i<N; i++){
        
        if(visited[i] || deadPosi(i, queen)) continue;
        visited[i]=1;
        vi.push_back(i+queen*N);
        dfs(queen+1);
        visited[i]=0;
        vi.pop_back();
    }
    return ;
}


int main(){
    cin >> N;

    for(int i=0; i<N;i++){
        visited[i]=1;
        vi.push_back(i);
        dfs(1);
        visited[i]=0;
        vi.pop_back();
    }

    cout << ans <<'\n';
}