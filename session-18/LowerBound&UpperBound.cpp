#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int target){
    int l = 0, r = arr.size() - 1;
    int ans = arr.size();

    while(l <= r){
        int mid = (l + r) / 2;

        if(arr[mid] >= target){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int target){
    int l = 0, r = arr.size() - 1;
    int ans = arr.size();

    while(l <= r){
        int mid = (l + r) / 2;

        if(arr[mid] > target){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {10, 20, 30, 30, 30, 40, 50};
    int target = 30;

    cout << "Lower Bound Index: " << lowerBound(arr, target) << endl;
    cout << "Upper Bound Index: " << upperBound(arr, target) << endl;

    return 0;
}
