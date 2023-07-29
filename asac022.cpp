#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int K, switched, ans=-1;
string N;
int mp[14], visited[1000004][11];
/**
 * K번 스위칭을 시도해서 G라는 숫자가 나온다면, 다른 방식으로 K번 스위칭해서 G를 굳이 다시 만들 필요 없다 -> 방문체크
 * N은 최대 1000000까지 가능하므로 visited[1000004][14] -> 생성한 숫자에 방문체크!!
 * 
*/


int check(){
    int cnt = 0;
    int sit=1;
    for(int i=N.size()-1; i>=0; i--){
        cnt += mp[i]*sit;
        sit*=10;
    }
    return cnt;
}

void swap(int i, int j){
    int temp = mp[i];
    mp[i] = mp[j];
    mp[j] = temp;
    return ;
}

void dfs(int k){

    if(k == K){
        ans = max(ans, check());
        return ;
    }

    for(int i=0; i<N.size()-1; i++){
        for(int j=i+1; j<N.size(); j++){
            if(i==0&mp[j]==0) continue;
            swap(i,j);
            int temp = check();
            if(visited[temp][k+1]){
                swap(i,j);
                continue;
            }
            //cout << "temp : "<<temp<<" i : "<<i<<" j : "<<j<<" k : "<<k+1<<'\n';
            visited[temp][k+1] = 1;
            dfs(k+1);
            swap(i,j);
        }
    }

    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<N.size(); i++) mp[i] = N[i]-'0';
    visited[check()][0] = 1;
    dfs(0);
    cout <<ans<<'\n';
    return 0;
}