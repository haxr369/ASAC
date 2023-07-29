#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int N, numbs[14], ops[5], maxAns = INT_MIN, minAns=INT_MAX;
//int used[5];

/**
 * +,-,*,/
 * 0,1,2,3
 * 
 * dfs 연산자 하나씩 사용.
 * 연산자 수가 0이 되면 사용 X
 * 
*/

int math(int a, int b, int op){
    if(op==0) return a+b;
    else if(op==1) return a-b;
    else if(op==2) return a*b;
    else return a/b;
}

void dfs(int idx, int total){
    //cout << "idx : "<<idx<<" total : "<<total<<'\n';
    if(idx==N-1){
        minAns = min(total, minAns);
        maxAns = max(total, maxAns);
        return ;
    }

    for(int i=0; i<4; i++){
        if(ops[i]==0) continue;
        ops[i]--;
        int temp = total;
        total = math(total, numbs[idx+1], i);
        dfs(idx+1, total);
        total = temp;
        ops[i]++;
    }

    return ;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> numbs[i];
    }

    for(int i=0; i<4; i++){
        cin >> ops[i];
    }

    dfs(0, numbs[0]);
    
    cout << maxAns<<'\n';
    cout << minAns<<'\n';

    return 0;
}