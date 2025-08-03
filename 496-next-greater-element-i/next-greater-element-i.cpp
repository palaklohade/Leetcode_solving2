class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>result( n, -1);
        unordered_map<int , int> freq;
        stack<int> st;

        for(int num = 0 ; num < n ; num++){
            freq[nums1[num]] = num;
        }

        for(int num : nums2){
            while(!st.empty() && num > st.top() ){
                int top = st.top(); st.pop();

                if(freq.count(top)){
                    result[freq[top]] = num;
                }

            }
            st.push(num);
        }
        return result;
    }
};