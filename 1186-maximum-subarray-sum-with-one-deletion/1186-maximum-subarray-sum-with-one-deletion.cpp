class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int onedelete=arr[0],nodelete=arr[0],res=arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            onedelete=max(onedelete+arr[i],nodelete);
            nodelete=max(nodelete+arr[i],arr[i]);
            res=max({res,nodelete,onedelete});
        }
        return res;
    }
};