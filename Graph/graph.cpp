#include <cstdlib>
#include <set>
#include <iostream>
#include <vector>
 using namespace std;
void longestPath(vector< pair<int,int> > graph[], int str, int len, int *maxLength, vector <bool> &check){
  int curr_len = 0;
  check[str] =1;
  pair<int,int> diag;
  for(int i =0; i <graph[str].size();i++){
    diag = graph[str][i];
    if(!check[diag.first]){
      curr_len = len+diag.second;
      longestPath(graph,diag.first,curr_len,maxLength,check);

    }
    if ((*maxLength) < curr_len) {*maxLength = curr_len;}
           curr_len = 0;
    }
}
int longestLength(vector<pair<int,int> > graph[], int l){
  int maxLength = INT_MIN;
  for(int i =1; i<=l; i++){
    vector<bool > check(l+1,false);
    longestPath(graph,i,0,&maxLength,check);
  }
  return maxLength;
}

int main(){
   vector< pair<int,int> > graph[8];
   int l =2;
   graph[1].push_back(make_pair(1, 8));
   graph[1].push_back(make_pair(1, 4));
   graph[2].push_back(make_pair(2, 4));
   graph[2].push_back(make_pair(5, 6));
   graph[3].push_back(make_pair(7, 8));
   graph[3].push_back(make_pair(9, 10));

   cout << "Maximum length: "<< longestLength(graph, l);
   return 0;
}
