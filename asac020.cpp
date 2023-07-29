#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

/*
각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
빈 칸의 경우에는 0

0이 들어있는 위치에 1부터 9까지 숫자를 입력해야한다.

1. 각 0마다 들어갈 수 있는 후보를 만든다. -> 연결 리스트 사용.
2. 처음 0부터 후보 숫자를 넣는다.
3. 모든 후보 숫자를 넣을 수 없는 0이 나오면 return. -> dfs 사용.
*/
int mp[10][10];
vector<pair<int,int>>vp;
vector<vector<int>> vv;
bool flag = false;

void dfs(int deep){
    if(deep==vp.size()){
        flag = true;
        //cout << "완성!!\n";
        return;
    }
    pair<int,int> p = vp[deep];
    //cout << "p.first : "<<p.first<<" p.second : "<<p.second<<" 정사각형 위치 -> y :  "<<p.first/3<<" x : "<<p.second/3<<'\n';
    // 빈자리에 들어갈 수 있는 후보 숫자 찾기.
    int used[]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<9; i++){
        if(used[mp[p.first][i]] == 0) {used[mp[p.first][i]]=1; }// 행
        if(used[mp[i][p.second]] == 0) {used[mp[i][p.second]]=1; } // 열
    }
    for(int y=(p.first/3)*3; y<(p.first/3)*3 +3; y++){ // 3x3 정사각형.
        for(int x=(p.second/3)*3; x<(p.second/3)*3+3; x++ ){
            if(used[mp[y][x]]==0) {used[mp[y][x]] = 1; }
        }
    }

    //cout <<"deep : "<<deep<<'\n';
    for(int i=1; i<10; i++){
        if(used[i]==0){
            mp[p.first][p.second] = i;
            //cout <<" number : "<<i<<'\n';
            dfs(deep+1);
            if(flag) break;
            mp[p.first][p.second] = 0;
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> mp[i][j];
            if(mp[i][j]==0) vp.push_back({i,j}); // 0위치 저장.
        }
    }
    dfs(0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << mp[i][j]<<' ';
        }
        cout <<'\n';
    }
    return 0;
}