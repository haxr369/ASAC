#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int K, switched, ans;
string N;
int mp[10], visited[1000004][11];
/**
 * K번 스위칭을 시도해서 G라는 숫자가 나온다면, 다른 방식으로 K번 스위칭해서 G를 굳이 다시 만들 필요 없다 -> 방문체크
 * N은 최대 1000000까지 가능하므로 visited[1000004][14] -> 생성한 숫자에 방문체크!!
 * 
*/



int check(){
    int cnt = 0;
    int sit=1;
    for(int i=N.size()-1; i>=0; i++){
        cnt += mp[i]*sit;
        sit*=10;
    }
    return cnt;
}

void dfs(int trial){

    if(switched == K){
        ans = max(ans, check());
        return ;
    }



    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<N.size(); i++) mp[i] = N[i];

    dfs(0);

    return 0;
}