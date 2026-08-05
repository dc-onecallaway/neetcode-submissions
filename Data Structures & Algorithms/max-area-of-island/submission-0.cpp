class Solution {
public:
    int countArea(int i, int j, vector<vector<int>> &grid,vector<vector<bool>> &visited){
        if(i<0 || (i >= grid.size())){
            return 0;
        }
        if(j<0 || (j >= grid[0].size())){
            return 0;
        }
        if(visited[i][j] || (grid[i][j] == 0)){
            return 0;
        }
        visited[i][j] = true;
        int count1 = countArea(i+1,j,grid,visited);
        int count2 = countArea(i-1,j,grid,visited);
        int count3 = countArea(i,j+1,grid,visited);
        int count4 = countArea(i,j-1,grid,visited);
        return (count1+count2+count3+count4) + 1;

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
        int maxArea = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(!visited[i][j] && (grid[i][j] == 1)){
                    int count = countArea(i,j,grid,visited);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }
};
