#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> myarr;
int n, m;
int isInArray[100001] = {0,};

void solve(vector<int> arr, int temp) {
    if(arr.size()>m)return;
    if(arr.size()==m) {
        for(int i:arr)
            cout<<i<<" ";
        cout<<'\n';
        return;
    }

    int i = 0;
    if(!arr.empty()) {
        for(i = 0;i<myarr.size();i++) {
            if(myarr[i]==arr.back()) break;
        }
    }

    for(i;i<myarr.size();i++) {

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
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(isInArray[a]==0){
            myarr.push_back(a);
            isInArray[a]=1;
        }
    }

    sort(myarr.begin(), myarr.end());
    // for(int i: myarr) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    vector<int>arr;
    solve(arr,0);
    return 0;
}