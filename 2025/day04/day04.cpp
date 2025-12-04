#include <bits/stdc++.h>
using namespace std;

int part1(vector<vector<char>> stage, int rows, int col)
{
    int result = 0;
    for(int i=0;i<rows;i++){
      for(int j=0;j<col;j++){
         if(stage[i][j]=='@'){
            int rolls = 0;
            if(j-1>=0 && stage[i][j-1]=='@') rolls++;
            if(j-1>=0 && i-1>=0 && stage[i-1][j-1]=='@') rolls++;
            if(i-1>=0 && stage[i-1][j]=='@') rolls++;
            if(j+1<col && i-1>=0 && stage[i-1][j+1]=='@') rolls++;
            if(j+1<col && stage[i][j+1]=='@') rolls++;
            if(j+1<col && i+1<rows && stage[i+1][j+1]=='@') rolls++;
            if(i+1<rows && stage[i+1][j]=='@') rolls++;
            if(j-1>=0 && i+1<rows && stage[i+1][j-1]=='@') rolls++;
            if(rolls<4){
                result++;
            }
         }
      }
    }
    return result;
}

int part2(vector<vector<char>> stage, int rows, int col)
{
    int result = 0;
    int lastresult = 0;

    while(true){
        for(int i=0;i<rows;i++){
          for(int j=0;j<col;j++){
             if(stage[i][j]=='@'){
                int rolls = 0;
                if(j-1>=0 && stage[i][j-1]=='@') rolls++;
                if(j-1>=0 && i-1>=0 && stage[i-1][j-1]=='@') rolls++;
                if(i-1>=0 && stage[i-1][j]=='@') rolls++;
                if(j+1<col && i-1>=0 && stage[i-1][j+1]=='@') rolls++;
                if(j+1<col && stage[i][j+1]=='@') rolls++;
                if(j+1<col && i+1<rows && stage[i+1][j+1]=='@') rolls++;
                if(i+1<rows && stage[i+1][j]=='@') rolls++;
                if(j-1>=0 && i+1<rows && stage[i+1][j-1]=='@') rolls++;
                if(rolls<4){
                    result++;
                    stage[i][j]='.';
                }
             }
          }
        }
        if(result == lastresult) break;
        lastresult = result;
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    ifstream file("day04.txt");
    vector<vector<char>> stage;

    while(getline(file, line)){
      vector<char> ln;
      for(int i=0;i<line.size();i++){
         ln.push_back(line[i]);
      }
      stage.push_back(ln);
    }

    int col = stage[0].size();
    int rows = stage.size();

    int p1 = part1(stage, rows, col);
    int p2 = part2(stage, rows, col);

    cout<<"P1: "<<p1<<"\n";
    cout<<"P2: "<<p2<<"\n";

    return 0;
}
