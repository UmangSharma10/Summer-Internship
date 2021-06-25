class Solution {
public:
   void dfs(vector<vector<int>> &ans,vector<vector<int>>& image, int sr, int sc,int m, int n, int c){
       if(ans[sr][sc]==c) return;
       ans[sr][sc]=c;
       if(sr+1<m && sr+1>=0 &&  image[sr+1][sc]==image[sr][sc]) dfs(ans,image,sr+1,sc,m,n,c);
       if(sr-1<m && sr-1>=0 && image[sr-1][sc]==image[sr][sc]) dfs(ans,image,sr-1,sc,m,n,c);
       if(sc+1<n && sc+1>=0 && image[sr][sc+1]==image[sr][sc]) dfs(ans,image,sr,sc+1,m,n,c);
       if(sc-1<n && sc-1>=0 && image[sr][sc-1]==image[sr][sc]) dfs(ans,image,sr,sc-1,m,n,c);
       return ;
   }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> ans(image);
        dfs(ans,image,sr,sc,m,n,newColor);
        return ans;
    }
    
};
