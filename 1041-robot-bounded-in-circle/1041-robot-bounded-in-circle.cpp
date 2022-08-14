class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        
        int dir_x = 0,dir_y = 1;
        for(int i=0;i<4;i++){
            for(char ch : instructions){
                if(ch == 'R'){
                    int temp = dir_x;
                    dir_x = dir_y;
                    dir_y = -temp;
                }else if(ch == 'L'){
                    int temp = dir_x;
                    dir_x = -dir_y;
                    dir_y = temp;
                }else{
                    x = x + dir_x;
                    y = y + dir_y;
                }
            }
        }
        
        if(x==0 && y==0){
            return true;
        }
        return false;
    }
};