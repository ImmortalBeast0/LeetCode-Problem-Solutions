class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        //row check
        for(int i=0;i<9;i++){
            int freq[10] = {0}; 
            for(int j=0;j<9;j++)
                if(b[i][j] != '.')
                freq[b[i][j] - '0']+=1;
            for(int j=0;j<10;j++)
                if(freq[j] > 1)
                    return false;
        }

        //column check
        for(int j=0;j<9;j++){
            int freq[10] = {0};
            for(int i=0;i<9;i++)
                if(b[i][j] != '.')
                freq[b[i][j] - '0']++;
            for(int j=0;j<10;j++)
                if(freq[j] > 1)
                    return false;
        }

        //3 X 3 grid check
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){

                int freq[10] = {0};
                for(int r=i;r<i+3;r++)
                    for(int c=j;c<j+3;c++)
                        if(b[r][c] != '.')
                        freq[b[r][c] - '0']++;

                for(int k=0;k<10;k++)
                    if(freq[k] > 1)
                        return false;
            }
        }

        return true;
    }
};