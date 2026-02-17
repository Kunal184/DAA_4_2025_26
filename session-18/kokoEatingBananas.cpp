class Solution {
public:
    
    int findMax(vector<int> arr){
            int mx = arr[0];
            for(const int &x:arr) mx = max(x, mx);
            return mx; 
        }
    bool canEatAll(vector<int> arr, int perHour, int hours){
            int currentHours = 0;
            for(const int &x:arr){
                currentHours+=ceil(double(x)/perHour);
                if(currentHours>hours) return false;
            }
            return true;
        }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = findMax(piles);
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canEatAll(piles, mid, h)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};