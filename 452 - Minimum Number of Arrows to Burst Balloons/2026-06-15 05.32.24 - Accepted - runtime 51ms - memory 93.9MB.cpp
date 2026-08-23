class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto& a, auto& b) {
            return a[1]<b[1];
        });

        int arrow=1;
        long long end=points[0][1];
        for(int i=1; i<points.size(); i++){
            if (points[i][0]>end){
                arrow++;
                end =points[i][1];
            }
        }
        return arrow;
    }
};