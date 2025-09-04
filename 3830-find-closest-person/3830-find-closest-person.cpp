class Solution {
public:
    int findClosest(int x, int y, int z) {

        int distance_person1 = abs(x-z);
        int distance_person2 = abs(y-z);


        if(distance_person1<distance_person2) return 1;
        else if(distance_person1>distance_person2) return 2;
        else return 0;



        
        
    }
};