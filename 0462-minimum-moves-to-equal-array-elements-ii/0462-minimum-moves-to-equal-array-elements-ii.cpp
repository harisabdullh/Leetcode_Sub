class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=nums.size()/2;
        //sab number ko iske barabar krna hai
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=abs(nums[i]-nums[mid]);
        }
        return cnt;

    }
};