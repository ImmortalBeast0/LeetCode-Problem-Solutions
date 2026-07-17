class Solution {
    public int minSensors(int n, int m, int k) {
        int l = k + k + 1;
        return (int)(Math.ceil((double)n / l) * Math.ceil((double)m/l)); 
    }
}

/*

lets say given grid as Rectangle 
and then given Max(|r1 - r2|,|c1 - c2|)
form a Square 

now we need to cover the Reactangle by the Minimum number of squares 

, (n * m) => Rectangle Area 

  we know Square from the center covers K 
    thats means ,K is the half of the length 
    lets say K + K is the full length , but it extend by 1 ,which is including the center point so .

  (K + K + 1) => Square Area 

  Reactangle Area / Square Area 
    is Wrong because it means we can Broke the Square pices and fill it by over there ,but by the question its not possible 

then need to find minimum number of squares needs is 
    lets say side length of square is a (K + K + 1)

    Ceil((L / A) * (L / B)) for ceiling for count the full squares as it is

*/