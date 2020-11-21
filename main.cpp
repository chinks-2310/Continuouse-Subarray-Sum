class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i,sum=0,n=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        if(k==0)
        {
            for(i=1;i<nums.size();i++)
            {
                if(nums[i]==0 && nums[i-1]==0)
                {
                    return true;
                }
            }
            return false;
        }
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end())
            {
                if(i-mp[sum%k]>=2)
                {
                    return true;
                }
            }
            else
            {
                mp[sum%k]=i;
            }
        }
        return false;
    }
};
