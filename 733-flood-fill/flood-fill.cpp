class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color){
            return image;
        }

        int m = image.size();
        int n = image[0].size();

        int dr[] = { -1 , 1 , 0 , 0};
        int dc[] = { 0 , 0 , -1 , 1}; 

        queue<pair<int , int>>q;
        q.push({sr , sc});
        image[sr][sc] = color;

        while(!q.empty()) {
            auto[r , c] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
        int newRow = r + dr[i];
        int newCol = c + dc[i]; 

        if(newRow >= 0 && newRow < m &&
        newCol >= 0 && newCol < n){
            if (image[newRow][newCol] == originalColor) {
            image[newRow][newCol] = color;
            q.push({newRow, newCol});
            }
        }
            }
        }  
        return image; 
    }
};