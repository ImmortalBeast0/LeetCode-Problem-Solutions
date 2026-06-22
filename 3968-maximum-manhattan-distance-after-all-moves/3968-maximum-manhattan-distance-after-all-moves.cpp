class Solution {
public:

    void move(char dir ,int &x ,int &y){
        if(dir == 'U')
            x += 1;
        else if(dir == 'D')
            x -= 1;
        else if(dir == 'L')
            y -= 1;
        else
            y += 1;
    }
    
    int maxDistance(string moves) {
        
        int cnt_unScore = 0;
        int x = 0,y = 0;

        for(char c : moves){
            if(c == '_'){
                cnt_unScore += 1;
                continue;
            }
            move(c,x,y);
        }

        return abs(x) + abs(y) + cnt_unScore;

    }
};