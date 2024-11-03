#include<iostream>
#include<vector>
using namespace std;

int n, m;

void solve(vector<int> arr, int temp) {
    if(arr.size()==m) {
        for(int i=0;i<arr.size();i++) {
            cout<<arr[i]<<" ";
        }
        return;
    }
    for(int i = temp;i<=n;i++) {
        vector<int> tarr = arr;
        tarr.push_back(i);
        for(int ii:tarr) {
            cout<<ii<<" ";
        }
        cout<<endl;
        solve(tarr, temp+1);
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