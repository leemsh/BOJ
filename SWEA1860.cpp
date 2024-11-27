#include <algorithm>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int testCase = 1; testCase <= t; testCase++) {
        int n,m,k;cin>>n>>m>>k;
        map<int, int> map;
        for(int i = 0; i < n; i++) {
            int x;cin>>x;
            if(map[x])map[x]++;
            else map[x]=1;
        }
        int stack = 0;
        string s = "Possible";
        for(auto iter = map.begin();iter!=map.end();iter++) {
            if(iter->first / m * k  - stack < iter->second) {
                s = "Impossible";
            }
            else {
                stack += iter->second;
            }
        }
        cout<<"#"<<testCase<<" "<<s<<"\n";
    }
    return 0;
}