#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ifstream file("day01.txt");
    vector<string> pos;
    string word;
    while(file>>word){
        pos.push_back(word);
    }
    int dial = 50; int password = 0; int password2 = 0;
    for(int i=0;i<pos.size();i++){
        string instr=pos[i];
        char litera=instr[0];
        int numar=stoi(instr.substr(1));
        if(litera=='R') {
            for(int j=0;j<numar;j++) {
                dial=(dial+1)%100;
                if(dial==0) password2++;
            }
        } else{
            for(int j=0;j<numar;j++) {
                dial=(dial-1+100)%100;
                if(dial==0) password2++;
            }
        }
        if(dial==0) password++;
    }
    cout<<"P1: "<<password<<"\n";
    cout<<"P2: "<<password2<<"\n";
    return 0;
}
