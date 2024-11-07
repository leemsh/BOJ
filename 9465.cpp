#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[2][100001]={0,};
int arr[2][100001]={0,};


int solution(int i, int j) {
    if(j<0) return 0;
    if(j==0) return dp[i][j] = arr[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    if(i==0)return dp[i][j] = arr[i][j] + max(solution(1,j-1),max(solution(0,j-2), solution(1,j-2)));
    return dp[i][j] = arr[i][j] + max(solution(0,j-1),max(solution(1,j-2), solution(0,j-2)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        memset(dp,-1,sizeof(dp));
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++) {
            cin>>arr[0][i];
        }
        for(int i=0;i<n;i++) {
            cin>>arr[1][i];
        }
        cout<<max(solution(0,n), solution(1,n))<<'\n';
    }
    return 0;
}