class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> v;

        // Step 1:Pair (value, original_ind) and sort by value
        for(int i=0; i<n; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        
        vector<int> ans(n,0);
        int i=0;

        // Step 2&3: Find groups and greedily fill original spots
        while(i<n){
            int j=i+1;
            vector<pair<int,int>> temp;
            temp.push_back({v[i].second,v[i].first});

            // Group numbers whose adjacent difference <= limit
            while(j<n){
                if(v[j].first-v[j-1].first<=limit){
                    temp.push_back({v[j].second,v[j].first});
                    j++;
                }
                else break;
            }

            // Sort original indices from left to right
            sort(temp.begin(), temp.end());

            // Place the smallest values into the leftmost indices
            for(int k=0; k<temp.size(); k++){
                ans[temp[k].first]=v[i+k].first;
            }
            i=j;
        }
        return ans;
    }
};