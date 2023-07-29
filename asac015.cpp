#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

/*
 U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼
 첫째 줄에 F, S, G, U, D

*/

int F,S,G,U,D;
int visited[1000004];
queue<int> qu;

int bfs(){
    visited[S-1]=1;
    qu.push(S-1);
    bool flag = false;

    while(qu.size()){
        int x = qu.front(); qu.pop();
        //cout << "used : "<<visited[x]<< " x : "<<x<<'\n';

        for(int nx : {x+U, x-D}){
            if(nx<0 || nx>=F || visited[nx]) continue;
            visited[nx] = visited[x]+1;
            qu.push(nx);
            if(nx==G-1){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if(flag) return visited[G-1]-1;
    else return -1;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> F>>S>>G>>U>>D;

    if(S==G){
        cout << 0 <<'\n';
        return 0;
    }

    int ans = bfs();

    if(ans==-1) cout << "use the stairs\n";
    else cout << ans <<'\n';
    return 0;
}