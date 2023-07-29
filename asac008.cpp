#include<iostream>
#include<queue>
using namespace std;

int N,K,ans, visited[100004],ti;
queue<int> qu;

void bfs(){
    if(N==K) return;
    qu.push(N);
    visited[N]=1;

    
    while(qu.size()){
        bool flag = false;
        int quSize = qu.size();
        for(int t=0; t<quSize; t++){
            int x = qu.front(); qu.pop();
            //cout << "t : "<<ti<<" x : "<<x<<'\n';
            for(int nx : {x-1, x+1, 2*x}){
                if(nx<0 || nx>100000 || visited[nx]) continue;
                visited[nx]=visited[x];
                qu.push(nx);
                if(nx == K){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        ti++;
        if(flag)break;
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >>N>>K;
    bfs();
    cout << ti<<'\n';
    return 0;
}