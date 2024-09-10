class Solution {
public:

    void dfs(int sr, int sc , int color , int inicolor, vector<vector<int>>&image,
                int n ,int m ,vector<int> &delrow, vector<int>&delcol){

            image[sr][sc] = color ;

            for( int i = 0 ; i<4 ; i++){
                int newrow = sr+delrow[i];
                int newcol = sc+delcol[i];
                if(newrow <n && newrow >=0 && newcol <m && newcol >=0){
                    if(image[newrow][newcol] == inicolor){
                        dfs(newrow,newcol,color,inicolor,image,n,m,delrow,delcol);
                    }
                }
            }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == color) return image;
        int inicolor = image[sr][sc] ;
        vector<int>delrow = {0,0,-1,1};
        vector<int>delcol = {-1,1,0,0};
        dfs(sr,sc,color,inicolor,image,n,m,delrow,delcol);

        return image;
    }
};