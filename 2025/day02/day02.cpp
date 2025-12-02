#include <bits/stdc++.h>
using namespace std;
bool invalid_id(long long x){
    string s=to_string(x);
    if(s.size()%2!=0) return 0;
    int half=s.size()/2;
    string a=s.substr(0, half); string b=s.substr(half);
    if(a==b) return 1;
    return 0;
}
bool invalid_id2(long long x) {
    string s=to_string(x);
    int n=s.size();
    for(int len=1;len<=n/2;len++) {
        if(n%len!=0) continue;
        string seq=s.substr(0, len); 
        bool ok=true;
        for(int i=0;i<n;i+=len) {
            if(s.substr(i, len)!=seq) {
                ok=0;
                break;
            }
        }
        if(ok!=0) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("day02.txt");
    string line;
    getline(file, line);
    long long sum=0, sum2=0; int i=0;
    while(i<line.size()){
        long long start=0;
        while(i<line.size() && isdigit(line[i])){
            start=start*10 + (line[i]-'0');
            i++;
        }
        if(i>=line.size()) break;
        i++;
        long long end=0;
        while(i<line.size() && isdigit(line[i])){
            end=end*10 + (line[i]-'0');
            i++;
        }
        if(i<line.size() && line[i]==',') i++;
        for(long long x=start;x<=end;x++){
            if(invalid_id(x)){
                sum += x;
            }
            if(invalid_id2(x)){
                sum2 += x;
            }
        }
    }
    cout<<"P1: "<<sum<<"\n";
    cout<<"P2: "<<sum2<<"\n";
    return 0;
}
