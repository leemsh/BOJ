#include <algorithm>
#include<iostream>
using namespace std;

int arr[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int result = 0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++) {
        result+=arr[i]*(n-i);
    }
    cout<<result;

    return 0;
}