#include<iostream>
#include<vector>
#include<queue>

//1260 DFS와 BFS
using namespace std;
int arr[1001][1001] = {0,};
vector<int> stack;
queue<int> q;
vector<int> dfsAns;
vector<int> bfsAns;

int dfsvisit[1001] = {0,};
int bfsvisit[1001] = {0,};


void dfs(int start) {
    int check = 0;
    for(int i=0;i<1001;i++) {
        if(arr[start][i] == 1 && dfsvisit[i] == 0) {
            check = 1;
            dfsvisit[i] = 1;
            stack.push_back(i);
            dfsAns.push_back(i);
            dfs(i);
        }
    }

    if(check == 0 && !stack.empty()) {
        stack.pop_back();
        if(!stack.empty()) dfs(stack.back());
    }
}

void bfs(int start) {
    for(int i=0;i<1001;i++) {
        if(arr[start][i] == 1 && bfsvisit[i] == 0) {
            q.push(i);
            bfsvisit[i] = 1;
            bfsAns.push_back(i);
        }
    }
    if(!q.empty()) {
        int front = q.front();
        q.pop();
        bfs(front);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin>>n>>m>>v;

    int a, b;
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfsvisit[v] = 1;
    stack.push_back(v);
    dfsAns.push_back(v);
    dfs(v);

    bfsvisit[v] = 1;
    q.push(v);
    bfsAns.push_back(v);
    bfs(v);

    for(int i=0;i<dfsAns.size();i++) {
        cout<<dfsAns[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<bfsAns.size();i++) {
        cout<<bfsAns[i]<<" ";
    }

    return 0;
}