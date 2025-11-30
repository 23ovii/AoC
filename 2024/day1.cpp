#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> left, right;
    int l, r;
    while (cin >> l >> r) {
    left.push_back(l);
    right.push_back(r);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int td=0;
    for(int i=0;i<left.size();i++){
        td += abs(left[i]-right[i]);
    } cout<<td;
    return 0;
}