#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char delimiter){
    vector<string> splits;
    string split;
    istringstream ss(s);
    while (getline(ss, split, delimiter)){
        splits.push_back(split);
    }
    return splits;
}
long long part1(vector<long long> freshid, ifstream &file){
    string line;
    long long result=0;
    while(getline(file, line)){
        if(line=="") break;
        long long id=stoll(line);
        for(int i=0;i<freshid.size();i+=2){
            if(id<freshid[i]) continue;
            else{
                if(id>freshid[i+1]) continue;
                result++;
                break;
            }
        }
    }
    return result;
}
long long part2(vector<long long> freshIDs){
    long long result=0;
    while(true){
        vector<long long> nonOverlappingIDs;
        nonOverlappingIDs.push_back(freshIDs[0]);
        nonOverlappingIDs.push_back(freshIDs[1]);
        for(int i = 2; i < freshIDs.size(); i+=2){
            long long start = freshIDs[i];
            long long end = freshIDs[i+1];
            bool nonOverlap = true;
            for(int j = 0; j < nonOverlappingIDs.size(); j+=2){
                long long nonOverlapStart = nonOverlappingIDs[j];
                long long nonOverlapEnd = nonOverlappingIDs[j+1];
                if(!(start > nonOverlapEnd || end < nonOverlapStart)){
                    nonOverlap = false;
                    if(start < nonOverlapStart) nonOverlappingIDs[j] = start;
                    if(end > nonOverlapEnd) nonOverlappingIDs[j+1] = end;
                    break;
                }
            }
            if(nonOverlap){
                nonOverlappingIDs.push_back(start);
                nonOverlappingIDs.push_back(end);
            }
        }
        if(freshIDs == nonOverlappingIDs){
            for(int i = 0; i < freshIDs.size(); i+=2){
                result += freshIDs[i+1] - freshIDs[i] + 1;
            }
            break;
        }
        freshIDs = nonOverlappingIDs;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("day05.txt");
    string line;
    vector<long long> freshid;
    while(getline(file, line)){
        if(line=="") break;
        vector<string> s=split(line, '-');
        freshid.push_back(stoll(s[0]));
        freshid.push_back(stoll(s[1]));
    }
    long long resultP1 = part1(freshid, file);
    long long resultP2 = part2(freshid);
    cout<<"P1: "<<resultP1<<"\n";
    cout<<"P2: "<<resultP2<<"\n";
    return 0;
}