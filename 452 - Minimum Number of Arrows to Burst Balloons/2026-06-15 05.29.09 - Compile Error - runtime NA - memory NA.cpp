class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[]auto& a, auto& b {
            return [1]<b[1]
        });

        int arrow=1;
        long long end=points[0][1];
        for(int i<; point.size(); i++){
            if (points[i][0]>end){
                arrows++;
                end =points[i][1];
            }
        }
        return arrow;
    }
};