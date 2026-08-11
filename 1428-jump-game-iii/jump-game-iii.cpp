class Solution {
    bool fun(vector<int>&arr, int idx, vector<bool>&vis, int n){
        if(arr[idx] == 0) return true;
        if(vis[idx]) return false;

        vis[idx] = true;

        if(idx + arr[idx] < n){
            if(fun(arr,idx + arr[idx], vis, n)) return true;
        }
        if(idx - arr[idx] >= 0){
            if(fun(arr,idx - arr[idx], vis, n)) return true;
        }

        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();
        vector<bool>vis(n,0);
        return fun(arr,start, vis, n);

    }
};