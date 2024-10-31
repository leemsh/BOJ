// #include <algorithm>
// #include<iostream>
// #include<vector>
// #include<utility>
// using namespace std;
//
// vector<pair<pair<int, int>,int>> arr;
// int memo[2001] = {0,};
// int capacity = 0;
// int n,c,m;
// int result = 0;
//
// void solution(int n) {
//     if(n>=arr.size()) return;
//     cout<<"# "<<n<<"\n";
//     capacity -= memo[arr[n].first.first];
//     cout<<memo[arr[n].first.first]<<" arrive\n";
//     memo[arr[n].first.first] = 0;
//     if(arr[n].second<c-capacity) {
//         memo[arr[n].first.second] += arr[n].second;
//         capacity += arr[n].second;
//         result += arr[n].second;
//         cout<<arr[n].second<<" store\n";
//     }
//     else {
//         memo[arr[n].first.second] += c-capacity;
//         result += c-capacity;
//         cout<<c-capacity<<" store\n";
//         capacity += c-capacity;
//     }
//     solution(n+1);
// }
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin>>n>>c>>m;
//     for(int i=0;i<m;i++) {
//         int x,y,z;cin>>x>>y>>z;
//         arr.push_back(make_pair(make_pair(x,y),z));
//     }
//     sort(arr.begin(),arr.end());
//     for(pair<pair<int,int>,int> i:arr) {
//         cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";
//     }
//     solution(0);
//     cout<<result<<endl;
//     return 0;
// }

// 그리디로 풀기 위해서 상차 지점과 하차 지점 사이의 간격이 가장 좁은 것 부터 적재를 시작하기 위해 정렬한 후
// 수용량을 넘지 않도록 가장 많이 담게 순차적으로 담았다.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr(20000, vector<int>(5));
int memo[3000] = {0,};
int n, c, m;
int result = 0;

void checkMax(int a, int b, int x) {
    int maxMemo = 0;
    for(int i=a; i<b; i++) {
        if(memo[i]>maxMemo) maxMemo = memo[i];
    }
    if(c-maxMemo>x) {
        cout<<"start at "<<a<<", end at "<<b<<" get "<<x<<endl;
        result += x;
        for(int i=a; i<b; i++) {
            memo[i]+=x;
        }
    }else {
        cout<<"start at "<<a<<", end at "<<b<<" get "<<c-maxMemo<<" maxmemo : "<<maxMemo<<endl;
        result += c-maxMemo;
        for(int i=a; i<b; i++) {
            memo[i]+=c-maxMemo;
        }
    }
}

void solve(int n) {
    if(n==m)return;
    checkMax(arr[n][1],arr[n][2],arr[n][3]);
    return solve(n+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
        arr[i][0] = arr[i][2];
    }

    // Sort based on the first column
    sort(arr.begin(), arr.begin() + m);

    for (int i = 0; i < m; i++) {
        cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << "\n";
    }
    solve(0);
    cout << result << endl;
    return 0;
}
