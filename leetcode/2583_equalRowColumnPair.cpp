#include "base.hpp"

/*
class Solution {
  public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> rowSeries, colSeries;
    int pairs = 0;

    for (int i = 0; i < grid.size(); i++) {
      vector<int> row;
      for (int j = 0; j < grid[i].size(); j++) row.push_back(grid[i][j]);
      rowSeries[row]++;
    }

    for (int j = 0; j < grid[0].size(); j++) {
      vector<int> col;
      for (int i = 0; i < grid.size(); i++) col.push_back(grid[i][j]);
      colSeries[col]++;
    }

    set<vector<int>> series;
    for (auto s : rowSeries)
      series.insert(s.first);

    for (auto s : colSeries)
      if (series.find(s.first) != series.end())
        pairs += rowSeries[s.first] * colSeries[s.first];

    return pairs;
  }
};
*/

class Solution {
  public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> series;
    int pairs = 0;

    for (auto s : grid) series[s]++;

    for (int j = 0; j < grid[0].size(); j++) {
      vector<int> col;
      for (int i = 0; i < grid.size(); i++)
        col.push_back(grid[i][j]);
      pairs += series[col];
    }

    return pairs;
  }
};