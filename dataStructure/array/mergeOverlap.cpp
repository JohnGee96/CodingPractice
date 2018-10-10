// Problem : merge a list of overlap intervals [n, m] [m-2, k]
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void merge_intervals(vector<pair<int, int>>& v1, vector<pair<int,int>>& result) {
    pair<int, int> cur_interval;
    pair<int, int> result_interval = v1[0];
    result.push_back(result_interval);
    for (int i=1; i<v1.size(); ++i) {
        cur_interval = v1[i];
        if (result_interval.second >= cur_interval.first)
            result[result.size() - 1].second = max(result_interval.second, cur_interval.second);
        else {
            result_interval = pair<int,int>(cur_interval.first,cur_interval.second);
            result.push_back(result_interval);
        }
    }
}

int main(int argc, char* argv[]) {
  vector<pair<int, int>> v1 {
                          make_pair<int,int>(4,12),
                          make_pair<int,int>(13,16),
                          make_pair<int,int>(19,20),
                          make_pair<int,int>(20,24)
                        };
  vector<pair<int, int>> v2 {
                          make_pair<int,int>(2, 10),
                          make_pair<int,int>(4, 14)};

  vector<pair<int, int>> result;
  merge_intervals(v1, result);

  for(int i=0 ; i < result.size() ; i++)
  {
    cout << result[i].first << ", " << result[i].second << " | ";
  } 

  cout<<"Result Size: "<<result.size()<<endl;
  result.clear();
  
  merge_intervals(v2, result);
  for(int i=0 ; i < result.size() ; i++)
  {
    cout << result[i].first << ", " << result[i].second << " | ";
  } 

  cout<<"Result Size: "<<result.size()<<endl;
  result.clear();

  vector<pair<int, int>> v3 = {{1,5}, {2,3}, {4,6}};
  merge_intervals(v3, result);

  for(int i=0 ; i < result.size() ; i++)
  {
    cout << result[i].first << ", " << result[i].second << " | ";
  } 

  cout<<"Result Size: "<<result.size()<<endl;
  result.clear();

}