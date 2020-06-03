//Link: https://leetcode.com/problems/shortest-common-supersequence/ 
class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m = X.size(), n = Y.size();
        int L[X.size()+1][Y.size()+1] = {0};
        for (int i=0; i<=m; i++) 
        {
            for (int j=0; j<=n; j++) 
            { 
                if (i == 0 || j == 0) 
                    L[i][j] = 0; 
                else if (X[i-1] == Y[j-1])
                    L[i][j] = L[i-1][j-1] + 1; 
                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]); 
            }
        }
        int i = m, j = n; 
        string ans = "";
        int i1 = m-1, i2 = n-1;
        while (i > 0 && j > 0) 
        {
            if (X[i-1] == Y[j-1]) 
            {
                char c = X[i-1];
                while(i1 >= 0 && X[i1] != c)
                    ans.push_back(X[i1--]);
                i1--;
                while(i2 >= 0 && Y[i2] != c)
                    ans.push_back(Y[i2--]);
                i2--;
                ans.push_back(c);
                i--; j--;
            }
            else if (L[i-1][j] > L[i][j-1]) 
                i--;
            else
                j--; 
        }
        
        while(i1 >= 0)
            ans.push_back(X[i1--]);
        while(i2 >= 0)
            ans.push_back(Y[i2--]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};