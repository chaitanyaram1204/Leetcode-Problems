class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<float>temp;
        for(int i = 0;i<arr.size()-1;i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
            temp.push_back((float)arr[i]/arr[j]);
            }
        }
        vector<float>temp1 = temp;
        sort(temp1.begin(),temp1.end());
        float find = temp1[k-1];
      
        int pos;
        for(int i = 0;i<arr.size()-1;i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                if(find == (float)arr[i]/arr[j])
                {
                    return {arr[i],arr[j]};
                }
            }
        }
        return {};
    }
};