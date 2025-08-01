class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int n = nums1.size();
        int m = nums2.size();
        int k = n + m;
        int total = k/2;

        int count = 0;
        int prev = 0;
        int i  =0;
        int j = 0;
        int cur=0;

        while(count <= total ){
            prev = cur;

            if( i < n && (j >= m || nums1[i] <= nums2[j])){
                cur = nums1[i++];
            }else{
                cur = nums2[j++];
            }
                count++;
        }
        if(k % 2 == 0){
            return (prev + cur) / 2.00;
        }
        return cur;
         }
};