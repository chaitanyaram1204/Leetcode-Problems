class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        int n = arr.size();
        while(left < n-1 && arr[left] <= arr[left+1]){
            left++;
        }
        while(right > 0 && arr[right-1] <= arr[right]){
            right--;
        }

        if(left >= right) return 0;

        int result = min(right,n-left-1);
        int i = 0;
        while(i <= left){
            while(right < n && arr[i] > arr[right]){
                right++;
            }
            result = min(result,right-i-1);
            i++;
        }
        return result;
    }
};