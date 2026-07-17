class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int t = m+n;
        int f = (t-1)/2, sec = t/2;

        int p1 = 0, p2 = 0;
        int cnt = 0;
        int x=INT_MIN,y=INT_MIN;

        while(p1<n && p2<m){
            if(nums1[p1] < nums2[p2]){
                if(cnt == f) x = nums1[p1];
                if(cnt == sec) y = nums1[p1];
                p1++;
            }
            else{
                if(cnt == f) x = nums2[p2];
                if(cnt == sec) y = nums2[p2];
                p2++;  
            }
            cnt++;
        }

        if(y!=INT_MIN){
            if(t&1) return y;
            else return (x+y)/2.0;
        }

        if(p1==n){
            if(x == INT_MIN && f>=0) x = nums2[f + p2 - cnt];
            y = nums2[sec-cnt+p2];
        }
         if(p2==m){
            if(x == INT_MIN && f>=0) x = nums1[f + p1 - cnt];
            y = nums1[sec-cnt+p1];
        }

         if(y!=INT_MIN){
            if(t&1) return y;
            else return (x+y)/2.0;
        }

        return 0;



    }
};