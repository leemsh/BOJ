#include<iostream>
#include<cstring>
using namespace std;

int arr[1024][1024];
int dp[1024][1024];

int solution(int x1, int y1, int x2, int y2) {
    if(x2 == 0 && y2 == 0) return 0;
    if(x2 == 0 && y1 > 0) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n,m;cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int a; cin>>a;
            sum+=a;
            arr[i][j] = sum;
        }
    }


    return 0;
}