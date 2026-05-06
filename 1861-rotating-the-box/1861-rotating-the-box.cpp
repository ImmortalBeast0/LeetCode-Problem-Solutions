class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box){

        int n = box.size() ,m = box[0].size();
        vector<vector<char>> sol (m,vector<char>(n));
        for(int i=0;i<n;i++){
            int empty = -1 ,cnt = 0;
            for(int j=m-1;j>=0;j--){
                if(box[i][j] == '.'){
                    if(empty == -1){
                    empty = j;
                    cnt = 1;
                    }else
                        cnt += 1;
                    sol[j][n-1-i] = '.';
                }
                if(box[i][j] == '*'){
                    cnt = 0;
                    empty = -1;
                    sol[j][n-1-i] = '*';
                }
                if(box[i][j] == '#'){
                    sol[j][n-1-i] = '#';
                    if(empty != -1){
                    sol[empty][n-1-i] = '#';
                    sol[j][n-1-i] = '.';
                    empty -= 1;
                    }
                }
            }
        }

        return sol;
    }
};