class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int ele = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0); 
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};