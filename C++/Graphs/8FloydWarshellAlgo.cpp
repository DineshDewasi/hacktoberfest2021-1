//used to find the shortest path in algo
// can be a good choice even if it is only needed to find a single shortest path in the
// graph. However, the algorithm can only be used when the graph is so small that a
// cubic time complexity is fast enough.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        for (int k = 0; k < matrix.size(); k++)
            for (int i = 0; i < matrix.size(); i++)
                for (int j = 0; j < matrix.size(); j++)
                    if (matrix[i][k] == -1 || matrix[k][j] == -1)
                        continue;
                    else if (matrix[i][j] == -1)
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    else
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends