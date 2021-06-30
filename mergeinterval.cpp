class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeinterval;
        if(intervals.size() == 0)
            return mergeinterval;
        
        sort(intervals.begin(), intervals.end());
            vector<int> timeinterval = intervals[0];
            
        for(auto i : intervals)
            if(i[0] <= timeinterval[1]){
                timeinterval[1] = max(i[1], timeinterval[1]);
            }
            else
            {
                mergeinterval.push_back(timeinterval);
                timeinterval = i;
            }
        
        mergeinterval.push_back(timeinterval);
        return mergeinterval;
    }
        
       
};
