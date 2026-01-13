#include <bits/stdc++.h>
using namespace std;

int maxDepth = 0;
int currentDepth = 0;
long ops = 0;

void complexRec(int n) {
    currentDepth++;
    maxDepth = max(maxDepth, currentDepth);

    if (n <= 2) {
        ops++;
        currentDepth--;
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            ops++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        ops++;
    }

    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
        ops += n;
    } else {
        reverse(small.begin(), small.end());
        ops += n;
    }

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    currentDepth--;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    complexRec(n);

    cout << "Number of operations = " << ops << endl;
    cout << "Recursion depth = " << maxDepth << endl;
}


/*
Recurrence Relation ->
T(n) = 3T(n/2) + nlogn

Time complexity ->
T(n) = Θ(n^(log3))

Depth ->
n/2^k = 1, k = log2(n)
*/
