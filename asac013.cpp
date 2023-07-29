#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int L,R,C;
int sl, sr, sc, el, er, ec;
char mp[30][30][30];
string S;
int visited[30][30][30];

const int dl[] = {1,-1,0,0,0,0};
const int dr[] = {0,0,1,-1,0,0};
const int dc[] = {0,0,0,0,1,-1};

struct Posi{
    int l;
    int r;
    int c;
};

int bfs(){
    visited[sl][sr][sc] = 1;
    queue<Posi> qp;
    qp.push({sl,sr,sc});
    bool flag = false;
    while(qp.size()){
        int t = qp.size();
        for(int i=0; i<t; i++){
            Posi p = qp.front(); qp.pop();
            
            for(int i=0; i<6; i++){
                int nl = p.l + dl[i];
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];
                if(nl<0 || nr <0 || nc<0 || nl>=L || nr >= R || nc >= C) continue;
                if(visited[nl][nr][nc] || mp[nl][nr][nc]=='#')continue;
                visited[nl][nr][nc] = visited[p.l][p.r][p.c]+1;
                qp.push({nl,nr,nc});
                if(nl==el&&nr==er && nc == ec){
                    flag = true;
                    break;
                }
            }
            if(flag)break;

        }
        if(flag)break;
    }
    if(flag) return visited[el][er][ec]-1;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        cin >> L >> R>> C;
        if(L==0 && R ==0 && C == 0) break;
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                cin >> S;
                for(int k=0; k<C; k++){
                    mp[i][j][k] = S[k];
                    if(mp[i][j][k]=='S'){
                        sl = i; sr=j; sc=k;
                    }
                    else if(mp[i][j][k]=='E'){
                        el=i; er=j; ec=k;
                    }
                }
            }
        }
        fill(&visited[0][0][0], &visited[0][0][0]+27000,0);
        

        if(sl==el && sr==er && sc == ec){
            cout << "Escaped in 0 minute(s).\n";
        }
        else {
            int time = bfs();
            if(time==-1){
                cout << "Trapped!\n";
            }
            else{
                cout << "Escaped in "<<time<<" minute(s).\n";
            }
        }

    }
    return 0;
}
