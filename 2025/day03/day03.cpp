#include <bits/stdc++.h>
using namespace std;
string max_k_digits(const string &s, int k) {
    if(k==0) return "";
    if(s.length()==k) return s;
    char max_digit=s[0];
    int max_pos=0;
    for(int i=0;i<=s.length()-k;i++){
        if(s[i]>max_digit) {
            max_digit=s[i];
            max_pos=i;
        }
    }
    return max_digit+max_k_digits(s.substr(max_pos+1), k-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("day03.txt");
    string line;
    long long sum1=0, sum2=0;
    while(getline(file, line)) {
        string first_two=max_k_digits(line, 2);
        sum1+=stoll(first_two);
        string first_twelve=max_k_digits(line, 12);
        sum2+=stoll(first_twelve);
    }
    cout<<"P1: "<<sum1<<"\n";
    cout<<"P2: "<<sum2<<"\n";
    return 0;
}
