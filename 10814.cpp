#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<pair<int,pair<int,string>>> arr;

    for(int i=0;i<n;i++) {
        int a; string b;
        cin>>a>>b;
        arr.push_back(make_pair(a,make_pair(i,b)));
    }

    sort(arr.begin(),arr.end());

    for(pair<int,pair<int, string>> a:arr) {
        cout<<a.first<<" "<<a.second.second<<endl;
    }
    return 0;
}