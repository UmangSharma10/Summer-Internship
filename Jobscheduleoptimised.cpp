class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
   static bool compare(Job a, Job b){
        return(a.profit > b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> v;
        sort(arr,arr+n,compare);
        int maxi = arr[0].dead;
        for(int i = 1; i < n; i++){
            maxi = max(maxi , arr[i].dead);
        }
        int slot[maxi + 1];
        for(int i = 0; i <=maxi; i++ )
            slot[i] = -1;
            
            int countjobs = 0, jobprofit = 0;
            
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead; j > 0; j++ ){
                if(slot[j] == -1){
                    slot[j] = i;
                    countjobs++;
                    jobprofit+= arr[i].profit;
                    break;
                }
            }
        }
        v.push_back(countjobs);
        v.push_back(jobprofit);
        return v;
    } 
};
