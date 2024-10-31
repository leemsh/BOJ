// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<utility>
// using namespace std;
//
// pair<int,int> findmax(int a, int b, vector<pair<int,int>> arr){
//     pair<int,int>maxval=make_pair(0,0);
//     for(int i = a;i<=b;i++){
//         if(arr[i]>maxval)maxval=arr[i];
//     }
//     return maxval;
// }
//
// int solution(int a, int b, vector<pair<int,int>> arr){
//     if(a>=b) return 0;
//     pair<int,int> maxval = findmax(a,b,arr);
//     int sum = 0;
//     for(int i=a;i<=maxval.second;i++){
//         sum+=maxval.first-arr[i].first;
//     }
//     return sum + solution(maxval.second + 1, b, arr);
// }
//
// int main(int argc, char** argv)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int test_case;
//     int T; cin>>T;
//
//     for(test_case = 1; test_case <= T; test_case++) {
//         int n; cin>>n;
//         vector<pair<int, int>> arr;
//         for(int i=0;i<n;i++){
//             int a; cin>>a;
//             arr.push_back(make_pair(a,i));
//         }
//         cout<<"#"<<test_case<<" "<<solution(0,n-1,arr)<<"\n";
//     }
//     return 0;
// }
// 시간이 느린걸까 여튼 뒤로 탐색하는걸로 변경
#include<iostream>
#include<vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T; cin>>T;

    for(test_case = 1; test_case <= T; test_case++) {
        int n; cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a; cin>>a;
            arr.push_back(a);
        }
        int result = 0;
        int maxnum = 0;
        for(int i = n;i>0;i--) {
            if(arr.back()>maxnum) {
                maxnum = arr.back();
            }
            else {
                result += maxnum-arr.back();
            }
            arr.pop_back();
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
    }
    return 0;
}