class Solution {
  public:
  
  
    int sumArray(vector<int> arr){
        int sum = 0;
        for(int x:arr) sum+=x;
        return sum;
    }
    
        
    bool canPaint(vector<int> &arr, int tme, int k){
        int currentPainters = 1;
        int currentSum = 0;
        for(int x:arr){
            if(currentSum+x>tme){
                currentPainters++;
                currentSum = x;
            }
            else currentSum+=x;
            if(currentPainters>k) return false;
        }
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(), arr.end());
        int r = sumArray(arr);
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canPaint(arr, mid, k)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};