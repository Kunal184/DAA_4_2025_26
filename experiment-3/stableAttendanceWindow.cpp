#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    mp[0] = -1; // base case

    for(int i = 0; i < N; i++) {
        if(arr[i] == 'P') sum++;
        else sum--;

        if(mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout << maxLen;
    return 0;
}
