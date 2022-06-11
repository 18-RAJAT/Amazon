class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       //Using BS
          int start=0;
            int end=nums.size()-1;
            while(start<end)
            {
                    int mid=start+(end-start)/2;
                    if(nums[mid]<nums[mid+1]){start=mid;}
                    else{end=mid;}
            }
            return start;
    }
};