struct car{
    int speed;
    int position;
    double time;
    static int dest;
    car(int position, int speed){
        this->position = position;
        this->speed = speed;
        time = 1.0*(dest-position)/speed;
    }
    bool operator < (car a){
        return this->position < a.position;
    }
};
int car::dest = 0;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        car::dest = target;
        int n = position.size();
        vector<car> cars;
        
        for(int i=0;i<n;i++){
            cars.push_back(car(position[i],speed[i]));
        }
        
        sort(cars.begin(),cars.end());
        
        int count = 0;
        stack<double> st;
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && cars[i].time > st.top()){
                st.pop();
            }
            if(st.empty()){
                st.push(cars[i].time);
                count++;
            }

        }
        
        return count;
    }
};