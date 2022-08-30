/**
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[m][n];

    if (obstacleGrid[0][0] == 1) {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }

    for (int i=1; i<n; ++i) {
        if (obstacleGrid[0][i] == 1 || dp[0][i-1] == 0) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = 1;
        }
    }
    for (int i=1; i<m; ++i) {
        if (obstacleGrid[i][0] == 1 || dp[i-1][0] == 0) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = 1;
        }
    }

    for (int i=1; i<m; ++i) {
        for (int j=1; j<n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                if (dp[i-1][j] == 0 && dp[i][j-1] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (dp[i-1][j] == 0) {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                if (dp[i][j-1] == 0) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> nums = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(nums) << endl;
}