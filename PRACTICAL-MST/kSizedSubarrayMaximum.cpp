class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> mx;
        for(int i = 0; i < k; i++){
            mx.push({arr[i], i});
        }
        result.push_back(mx.top().first);
        for(int i = k; i < arr.size(); i++){
            mx.push({arr[i], i});
            while(mx.top().second<=i-k){
                mx.pop();
            }
            result.push_back(mx.top().first);
        }
        return result;
    }
};