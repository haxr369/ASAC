#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;


/*
버튼 A를 누르면 N이 1 증가한다.
버튼 B를 누르면 N에 2가 곱해진 뒤, 0이 아닌 가장 높은 자릿수의 숫자가 1 줄어든다.
N이 99,999를 넘어가는 순간 탈출에 실패
버튼 B를 눌러 N에 2를 곱한 순간 수가 99,999를 넘어간다면, 탈출 실패.

최대 T회 버튼을 누를 수 있고, N을 G와 같게 만드는 것이 목표
누르는 횟수를 최소
*/

int N,T,G, visited[100004];
queue<int> qu;

int changeNumb(int x){
    int stand = 1;
    while(x/(stand*10)>0){
        stand*=10;
    }
    if(x!=0) return x-stand;
    else return 0;
}

void bfs(){
    visited[N]=1;
    qu.push(N);
    int used = 0;
    bool flag = false;
    while(1){
        int quSize = qu.size();
        while(quSize){
            int x = qu.front(); qu.pop();

            if(x+1<100000 && visited[x+1]==0){ // 버튼 A
                visited[x+1] = visited[x] + 1;
                qu.push(x+1);
                if(x+1 == G) flag = true;
            }

            if((2*x < 100000)){ // 버튼 B
                int temp = changeNumb(2*x);
                if(visited[temp]==0){
                    visited[temp] = visited[x]+1;
                    qu.push(temp);
                    if(temp == G) flag = true;
                }
            }
            if(flag) break;
            quSize--;
        }
        if(flag) break;
        used++;
        if(used==T)break;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T>> G;

    bfs();

    if(N==G) cout << 0 <<'\n';
    else if(visited[G]!= 0) cout << visited[G]-1 <<'\n';
    else cout << "ANG\n";
    return 0;
}