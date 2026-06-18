class Solution {
public:

    /*
        we have hour 1 <= hour <= 12

        the clock has total 360 deg 

        now each 1 , 2 ,3 ,4 ,5 total 12 points 
        each difference in angle is 

                360 / 12 = 30 deg (each)

        we know now the hour deg start from the line to end

        but hour hand absolute location also depends on minute hand movement and position because if minute hand to reach at any point it reflect on the hour hand 

        so .. 

        total minute points are 0 .... 59 - 60 points 

        for every 60 minutes hour hand one move 

        so , every a minute 30 / 60 = 0.5 

        every minute of minute hand hour hand moves 0.5 

        then 
            hour hand deg + hour hand effect by minute hand = deg

        hour deg = (hour * 30 ) + (minute * 0.5);

        let minute hand deg ,
        
        it each differce 360 / 60 - 6 
        each minute contribute 6 deg 


        then hour hand degree is
        min deg = minute * 6 ;


    */


    double angleClock(int hour, int minutes) {
        double h = (hour * 30) + (minutes * 0.5f);
        double m = (minutes * 6);

        double diff = abs(h - m);
        return min(diff ,360 - diff);
    }
};