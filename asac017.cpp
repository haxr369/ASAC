#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int T, W, H, visited[1004][1004], manVisi[1004][1004];
char mp[1004][1004];
string S;
queue<pair<int,int>> qu, manQu;
const int dy[] ={-1,1,0,0};
const int dx[] ={0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T>0){
        while(manQu.size()) manQu.pop();
        fill(&visited[0][0], &visited[0][0]+1008016, 0);
        fill(&manVisi[0][0], &manVisi[0][0]+1008016, 0);

        cin >>W>>H;
        for(int i=0; i<H; i++){
            cin >> S;
            for(int j=0; j<W; j++){
                mp[i][j] = S[j];
                if(mp[i][j] =='@'){
                    manQu.push({i,j});
                    manVisi[i][j]=1;
                }
                else if(mp[i][j]=='*'){
                    qu.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        while(qu.size()){
            pair<int,int> q = qu.front(); qu.pop();

            for(int i=0; i<4; i++){
                int ny = q.first + dy[i];
                int nx = q.second + dx[i];
                if(ny<0 || nx<0 || ny>=H || nx>=W) continue;
                if(visited[ny][nx] || mp[ny][nx]=='#' || mp[ny][nx]=='*') continue; 
                visited[ny][nx] = visited[q.first][q.second] + 1;
                qu.push({ny, nx});
            }
        }

        bool flag = false;
        int time = 0;
        pair<int,int> ii = manQu.front();
        if(ii.first==0 || ii.second ==0 || ii.first==H-1 || ii.second==W-1){time++; flag = true; manQu.pop();}
        while(manQu.size()){
            pair<int,int> q = manQu.front(); manQu.pop();
            
            for(int i=0; i<4; i++){
                int ny = q.first + dy[i];
                int nx = q.second + dx[i];
                if(ny<0 || nx<0 || ny>=H || nx>=W) continue;
                if(manVisi[ny][nx] || mp[ny][nx]=='#') continue; 
                int temp = manVisi[q.first][q.second] + 1;
                if(visited[ny][nx] && (temp >= visited[ny][nx])) continue; // 방문하지 않았을 때, 사람이 방문하는 건 통과시켜야함.
                manVisi[ny][nx] = temp;
                manQu.push({ny, nx});

                if(ny==0 || nx==0 || ny==H-1 || nx==W-1){
                    flag = true;
                    time = manVisi[ny][nx];
                    break;
                }
            }
            if(flag) break;
        }

        if(flag) cout << time<<'\n';
        else cout << "IMPOSSIBLE\n";

        T--;
    }

    return 0;
}