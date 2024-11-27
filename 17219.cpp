#include <algorithm>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;cin>>t>>k;
    map<string, string> m;
    for(int testCase = 1; testCase <= t; testCase++) {
        string a, b;cin>>a>>b;
        m[a] = b;
    }
    for(int i=0;i<k;i++) {
        string a; cin>>a;
        cout<<m[a]<<'\n';
    }
    return 0;
}