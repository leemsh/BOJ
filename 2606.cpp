#include<iostream>
#include<queue>
using namespace std;
int arr[101][101] = {0,};
int n, m;
queue<int> q;
int visited[101] = {0,};

int result = 0;

void bfs(int now) {

    //cout<<"visited "<<now<<endl;

    for(int i = 1; i <= n; i++) {
        if(arr[now][i] == 1 && visited[i] == 0) {
            //cout<<"pushed "<<i<<endl;
            visited[i] = 1;
            result++;
            q.push(i);
        }
    }
    if(!q.empty()) {
        int temp = q.front();
        //cout<<"popped "<<temp<<endl;
        q.pop();
        bfs(temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b;cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    visited[1] = 1;
    bfs(1);
    cout<<result<<"\n";
    return 0;
}