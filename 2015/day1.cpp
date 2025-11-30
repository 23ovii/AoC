#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; int floor=0, pos;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') floor++;
        else if(s[i]==')') floor--;
        // 2nd part
        if(floor==0 && s[i+1]==')'){
            pos=i+2;
            break;
        }
    } cout<<pos;
    return 0;
}