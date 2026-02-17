class Solution {
  public:
  
    bool works(vector<int> arr, int minDistance, int cows){
        int currentCows = 1;
        int prev = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i]-prev>=minDistance){
                currentCows++;
                prev = arr[i];
            }
            if(currentCows>=cows) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls. end());
        int l = 1;
        int r = stalls.back()-stalls[0];
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(works(stalls, mid, k)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};