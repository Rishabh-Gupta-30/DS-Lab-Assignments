#include<bits/stdc++.h>
using namespace std;

pair<int, int> maxSubarraySum(vector<int>& arr, int n){
    int maxSum = INT_MIN;
    int sum = 0;
    int start, end;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            start = i+1;
        }
        if(sum > maxSum){
            maxSum = sum;
            end = i;
        }
    }
    return {start, end};
}

int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements :" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Max subarray :" << endl;
    int start = maxSubarraySum(arr, n).first;
    int end = maxSubarraySum(arr, n).second;
    int sum = 0;
    for(int i=start; i<=end; i++){
        sum += arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Max subarray sum :" << sum << endl;
    return 0;
}
