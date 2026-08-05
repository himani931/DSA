class Solution {
public:
    bool check(vector<int> base , vector<int> newbox) {
        if(newbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2]) return true;
        else return false;
    }

    int solve(int n , vector<vector<int>> &a) {
        vector<int> curr(n+1 , 0);
        vector<int> next(n+1 , 0);

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int j = i-1 ;  j >= -1 ; j--) {
                int take = 0 ; 
                if(j == -1 ||  check(a[i] , a[j])) {
                    take = a[i][2] + next[i+1];
                }

                int notTake = 0 + next[j+1];
                curr[j+1] = max(take , notTake);
            }
            next = curr;
        }
        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a : cuboids) {
            sort(a.begin() , a.end());
        }

        sort(cuboids.begin() , cuboids.end());

        return solve(cuboids.size() , cuboids);

        }
};