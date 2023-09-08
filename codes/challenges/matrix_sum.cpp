#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Input
    // int m = 3, n = 3,
    int k = 1;
    int m = 3, n = 3;

    // cin>>m>>n>>k;
    int nums[3][3], ans[3][3];
    int c = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nums[i][j] = c;
            c++;
        }
    }
    // Row Pre-sum
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            nums[i][j] += nums[i][j - 1];
        }
    }

    // Column Pre-sum
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < m; i++)
        {
            nums[i][j] += nums[i - 1][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x1 = (i - k) < 0 ? 0 : (i - k);
            int x2 = (i + k) > (m - 1) ? (m - 1) : (i + k);
            int y1 = (j - k) < 0 ? 0 : (j - k);
            int y2 = (j + k) > (n - 1) ? (n - 1) : (j + k);

            //(x1,y1),(x2,y2)
            if (x1 == 0 && y1 == 0)
            {
                ans[i][j] = nums[x2][y2];
            }
            else if (y1 == 0)
            {
                ans[i][j] = nums[x2][y2] - nums[x1 - 1][y2];
            }
            else if (x1 == 0)
            {
                ans[i][j] = nums[x2][y2] - nums[x2][y1 - 1];
            }
            else
            {
                ans[i][j] = nums[x2][y2] - nums[x2][y1 - 1] - nums[x1 - 1][y2] + nums[x1 - 1][y1 - 1];
            }

            //
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // your code goes here
    return 0;
}