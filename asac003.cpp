#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int N,S,ans;
int mp[24], visited[24];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >>N>>S;
    for(int i=0; i<N; i++){
        cin >> mp[i];
    }
    
    for(int i=1; i<(1<<N); i++){ // 모든 부분수열 탐색.
        int cnt =0;
        for(int j = 0; j<N; j++){
            
            if(i&(1<<j)){
                cnt+=mp[j];
            }
        }
        //cout <<cnt<<'\n';
        if(cnt == S) ans++;
    }
   

    cout << ans <<'\n';
    return 0;
}