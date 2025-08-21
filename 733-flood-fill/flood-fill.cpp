class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j, int oldcolor ,int color){
        int n = image.size();
        int m = image[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m)return;
        if(oldcolor != image[i][j])return;


        image[i][j] = color;
        dfs(image , i + 1 , j , oldcolor, color);
        dfs(image , i - 1 , j , oldcolor, color);
        dfs(image , i  , j + 1, oldcolor, color);
        dfs(image , i  , j -1 , oldcolor, color);

        
            }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldcolor = image[sr][sc];
    if(oldcolor == color)return image;
    dfs(image,sr,sc,oldcolor,color);
    return image;
    }
};