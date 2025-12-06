#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ifstream file("day06.txt");
    string line;
    vector<vector<string>> stage;
    while(getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> row;
        while(ss >> token) {
            row.push_back(token);
        }
        stage.push_back(row);
    }
    unsigned long long result = 0;
    int rows = stage.size();
    int cols = stage[0].size();
    for(int j=0;j<cols;j++) {
        unsigned long long prod = 1;
        unsigned long long sum = 0;
        if(stage[rows-1][j] == "*") {
            for(int i=0;i<rows-1;i++) {
                prod *= stoull(stage[i][j]);
            }
            result += prod;
        } else {
            for(int i=0;i<rows-1;i++) {
                sum += stoull(stage[i][j]);
            }
            result += sum;
        }
    }
    cout << result;
    return 0;
}
