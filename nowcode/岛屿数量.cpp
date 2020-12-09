class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int solve(vector<vector<char> >& grid) {
        // write code here
        if(grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    markBFS(grid,i,j);
                    num++;
                }
            }
        }
        return num;
    }
    
 private:
    void markBFS(vector<vector<char> >& grid, int x, int y){
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        
        queue<pair<int,int>> Q;
        Q.push(make_pair(x, y));
        grid[x][y] = '0';
        
        while(!Q.empty()){
            pair<int, int> head = Q.front();
            Q.pop();
            
            for(int i = 0; i < 4; i++){
                int x_temp = head.first + dirs[i][0];
                int y_temp = head.second + dirs[i][1];
                
                if(inBound(grid, x_temp, y_temp)){
                    if(grid[x_temp][y_temp] == '1'){
                        Q.push(make_pair(x_temp,y_temp));
                        grid[x_temp][y_temp] = '0';
                    }
                }
            }
        }
    }
    
    bool inBound(vector<vector<char> >& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }
};