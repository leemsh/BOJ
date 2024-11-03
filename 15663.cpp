#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> input;

void putInV(vector<int> vec) {
    vector<int> temp;
    for(int i:vec) {
        temp.push_back(input[i]);
    }
    for(vector<int> i:v) {
        if(temp==i) return;
    }
    v.push_back(temp);
}

bool isSameIn(vector<int>arr) {
    for(vector<int> i:v) {
        if(i == arr) return true;
    }
    return false;
}


void solve(vector<int> arr, int temp) {
    if(arr.size()>m)return;
    if(arr.size()==m) {
        putInV(arr);
        return;
    }
    for(int i = 0 ;i<n;i++) {
        int check = 0;
        for(int j= 0;j<arr.size();j++) {
            if(i==arr[j]) {
                check=1;
                break;
            }
        }
        if(check==1) {
            continue;
        }
        vector<int> arr1 = arr;
        arr1.push_back(i);
        solve(arr1, temp+1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int a; cin>>a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    vector<int>arr;
    solve(arr,0);
    for(vector<int> i:v) {
        for(int j:i) {
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    return 0;
}