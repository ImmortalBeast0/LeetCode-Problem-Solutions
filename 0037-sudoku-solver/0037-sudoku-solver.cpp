class Solution {
public:
    int n = 9;
    int rows[9] ,cols[9] ,boxes[9];
    bool rec(int i ,int j ,vector<vector<char>>& board){
        if(j == n){
            i = i + 1;
            j = 0;
        }

        if(i == n)
            return true;

        if(board[i][j] == '.'){
            int box = (i / 3) * 3 + (j / 3);
            int r = rows[i];
            int c = cols[j];
            int b = boxes[box];
            for(int k=1;k<10;k++){
                int bit = 1 << k;
                if((rows[i] & bit) || (cols[j] & bit) || (boxes[box] & bit))
                    continue;
                
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
                board[i][j] = k + '0';

                if(rec(i,j+1,board))
                    return true;
                
                rows[i] = r;
                cols[j] = c;
                boxes[box] = b;
                board[i][j] = '.';
            }
        }else{
            if(rec(i,j+1,board))
                return true;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int k = board[i][j] - '0';
                    int bit = 1 << k;
                    int box = (i / 3) * 3 + (j / 3);
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[box] |= bit;
                }
            }
        }

        rec(0,0,board);
    }
};