#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(!fresh)return 0;

        int time=0;
        vector<pair<int,int>>directions{{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            int size=q.size();
            bool rotted=false;

            for(int i=0; i<size; i++){
                auto node=q.front();
                int x=node.first, y=node.second;
                q.pop();

                for(auto& direction: directions){
                    int dx=direction.first, dy=direction.second;
                    int nx=dx+x, ny=dy+y;

                    if(nx>=0 && ny>=0 && nx<rows && ny<cols && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                        rotted=true;
                    }
                }
            }
            if(rotted)time++;
        }
        return fresh==0?time:-1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    cout<<s.orangesRotting(grid)<<endl; // Output: 4
    return 0;
}