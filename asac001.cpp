#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int N,M,n,m;
int mp[1004][1004], visited[1004];

void dfs(int start){

    //visited[start]=1;

    for(int i =0; i<N; i++){
        if(visited[i]||mp[start][i]==0) continue;
        visited[i] = 1;
        dfs(i);
    }

    return ;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N>>M;

    for(int i=0; i<M; i++){
        cin >>n>>m;
        mp[n-1][m-1] = mp[m-1][n-1] =1;
    }

    int ans =0;
    for(int i=0; i<N; i++){
        if(visited[i]) continue;
        visited[i]=1;
        dfs(i);
        ans++;
    }

    cout << ans <<'\n';

}