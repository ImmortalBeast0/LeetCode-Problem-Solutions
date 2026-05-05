class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        //All in One 
        int rows[9] ={},cols[9] ={},boxes[9] ={};

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(b[i][j] == '.')
                    continue;

                int id = b[i][j] - '1';
                int bit = 1 << id;
                int box = (i / 3) * 3 + (j / 3);
                if(rows[i] & bit | cols[j] & bit | boxes[box] & bit)
                    return false;

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit; 
            }
        }

        return true;
    }
};