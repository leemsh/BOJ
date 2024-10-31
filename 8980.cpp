#include <algorithm>
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<pair<int, int>,int>> arr;
int memo[2001] = {0,};
int capacity = 0;
int n,c,m;
int result = 0;

void solution(int n) {
    if(n>=arr.size()) return;
    cout<<"# "<<n<<"\n";
    capacity -= memo[arr[n].first.first];
    cout<<memo[arr[n].first.first]<<" arrive\n";
    memo[arr[n].first.first] = 0;
    if(arr[n].second<c-capacity) {
        memo[arr[n].first.second] = arr[n].second;
        capacity += arr[n].second;
        result += arr[n].second;
        cout<<arr[n].second<<" store\n";
    }
    else {
        memo[arr[n].first.second] = c-capacity;
        result += c-capacity;
        cout<<c-capacity<<" store\n";
        capacity += c-capacity;
    }
    solution(n+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>c>>m;
    for(int i=0;i<m;i++) {
        int x,y,z;cin>>x>>y>>z;
        arr.push_back(make_pair(make_pair(x,y),z));
    }
    sort(arr.begin(),arr.end());
    for(pair<pair<int,int>,int> i:arr) {
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";
    }
    solution(0);
    cout<<result<<endl;
    return 0;
}