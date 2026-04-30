#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        int low = 0, high = tails.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (tails[mid] < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low == tails.size()) {
            tails.push_back(x);
        } else {
            tails[low] = x;
        }
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}