#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int myarr[10];
int n, m;

void solve(vector<int> arr, int temp) {
    if(arr.size()>m)return;
    if(arr.size()==m) {
        for(int i:arr)
            cout<<i<<" ";
        cout<<'\n';
        return;
    }

    for(int i = 0 ;i<n;i++) {
        int check = 0;
        for(int j=0;j<arr.size();j++) {
            if(arr[j]==myarr[i]) {
                check = 1;
                break;;
            }
        }
        if(check==1)continue;
        vector<int> arr1 = arr;
        arr1.push_back(myarr[i]);
        // for(int k:arr1)
        //     cout<<"check : " <<k<<" ";
        // cout<<endl;
        solve(arr1, temp+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>myarr[i];
    sort(myarr, myarr+n);
    // for(int i: myarr) {
    //     cout<<i<<" ";
    // }
    //cout<<endl;
    vector<int>arr;
    solve(arr,0);
    return 0;
}