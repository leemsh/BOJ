#include<iostream>
#include<vector>
using namespace std;

int n, m;

void solve(vector<int> arr, int temp) {
    if(arr.size()>m)return;
    if(arr.size()==m) {
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = 0 ;i<n;i++) {
        vector<int> arr1 = arr;
        arr1.push_back(i);
        solve(arr1, temp+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<int>arr;
    solve(arr,0);
    return 0;
}