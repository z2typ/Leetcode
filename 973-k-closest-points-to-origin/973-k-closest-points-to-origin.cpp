struct Point{
    int x;
    int y;
    long long dist_squared;
    Point(int x,int y){
        this->x = x;
        this->y = y;
        dist_squared = x*x + y*y;
    }
    
    bool operator <(Point & a){
        return this->dist_squared < a.dist_squared;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        
        
        vector<Point> pt;
        for(vector<int> point : points){
            pt.push_back(Point(point[0],point[1]));
        }
        
        sort(pt.begin(),pt.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<k;i++){
            ans.push_back({pt[i].x,pt[i].y});
        }
        return ans;
            
    }
};