class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int l[] = {0,0,1,-1};
        int p[] = {1,-1,0,0};

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({sr,sc});
        int ch = image[sr][sc];
        vis[sr][sc] = 1;

        while(!q.empty()){
            auto &[x,y] = q.front();
            q.pop();
            for(int i = 0; i<4; i++){
                if(x+l[i]<0 || x+l[i]>=n || y+p[i]<0 || y+p[i]>=m) continue;
                if(!vis[x+l[i]][y+p[i]] && image[x+l[i]][y+p[i]] == ch){
                    q.push({x+l[i],y+p[i]});
                    vis[x+l[i]][y+p[i]] = 1;
                }

            }

        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 1){
                    image[i][j] = color;
                }
            }
        }

        return image;





    }
};