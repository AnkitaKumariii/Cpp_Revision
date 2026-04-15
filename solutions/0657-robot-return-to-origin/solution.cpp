class Solution {
public:
    bool judgeCircle(string moves) {
        int count1 = 0; 
        int count2 = 0;
        int count3 = 0; 
        int count4 = 0;  
        for(int i = 0; i <moves.size(); i++) {
            if(moves[i] == 'U') count1++;
            else if(moves[i] == 'D') count2++;
            else if(moves[i] == 'L') count3++;
            else if(moves[i] == 'R') count4++;
        }
        return count1 == count2 && count3 == count4;
    }
};
