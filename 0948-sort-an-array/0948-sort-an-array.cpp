class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        vector<int> temp(high-low+1);
        int i = low;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j <= high){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else
                temp[k++] = nums[j++];
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }

        while(j <= high){
            temp[k++] = nums[j++];
        }

        for(int i = low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }

    void mergesort(vector<int>&nums,int low,int high){
        if(low < high){
            int mid = low + (high-low)/2;
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};