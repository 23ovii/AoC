#include <bits/stdc++.h>
using namespace std;

void part1(vector<string> grid){
    int rows=grid.size(),cols=grid[0].size();
    int splits=0,start_col=0;
    for(int j=0;j<cols;j++) if(grid[0][j]=='S') start_col=j;
    vector<int> beam_rows,beam_cols;
    beam_rows.push_back(1);
    beam_cols.push_back(start_col);
    while(!beam_rows.empty()){
        vector<int> new_rows,new_cols;
        for(int k=0;k<beam_rows.size();k++){
            int r=beam_rows[k],c=beam_cols[k];
            if(r>=rows||c<0||c>=cols||grid[r][c]=='|') continue;
            char cell=grid[r][c];
            grid[r][c]='|';
            if(cell=='^'){
                splits++;
                new_rows.push_back(r+1); new_cols.push_back(c-1);
                new_rows.push_back(r+1); new_cols.push_back(c+1);
            }else{
                new_rows.push_back(r+1); new_cols.push_back(c);
            }
        }
        beam_rows=new_rows;
        beam_cols=new_cols;
    }
    cout<<"Part 1: "<<splits<<endl;
}

void part2(vector<string> grid){
    int rows=grid.size(),cols=grid[0].size();
    int start_col=0;
    for(int j=0;j<cols;j++) if(grid[0][j]=='S') start_col=j;
    vector<long long> current_row(cols,0);
    current_row[start_col]=1;
    for(int r=1;r<rows;r++){
        vector<long long> next_row(cols,0);
        for(int c=0;c<cols;c++){
            if(current_row[c]==0) continue;
            long long cnt=current_row[c];
            char cell=grid[r][c];
            if(cell=='^'){
                if(c-1>=0) next_row[c-1]+=cnt;
                if(c+1<cols) next_row[c+1]+=cnt;
            }else{
                next_row[c]+=cnt;
            }
        }
        current_row=next_row;
    }
    long long total=0;
    for(int c=0;c<cols;c++) total+=current_row[c];
    cout<<"Part 2: "<<total<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream file("day07.txt");
    string line;
    vector<string> grid;
    while(getline(file,line)) grid.push_back(line);
    part1(grid);
    part2(grid);
    return 0;
}