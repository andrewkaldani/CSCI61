#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <cassert>
#include <queue>
//#include "graph.h"
 using namespace std;

class pop{
public:
pop() {};
void add_vertex();
void add_edge(int a, int b);
bool is_edge(int a, int b);
list<int> shortest_path(int start, int end);
int n();
private:
  void length(int start, vector<int> &top);
  vector<list<int> > v;

};
int pop::n(){return v.size();}

bool pop::is_edge(int a, int b) {
  if (a >= n() || b >= n())
  return false;
  for (auto r: v[a])
  if (r == b) return true;
   return false;
}


void pop::add_vertex(){
v.push_back(list<int>());}


void pop::add_edge(int a, int b){
  assert(a<n()&&b<n());
  if (!is_edge(a, b)) {
    v[a].push_front(b); v[b].push_front(a); }
}

void pop::length(int start, vector<int> &top) {
queue<int> num;
num.push(start);
top[start] = start;
while (!num.empty()) {
  int cur = num.front();
  num.pop();
  for (auto r: v[cur]) {
    if(top[r] == -1) {
       top[r] = cur;
        num.push(r);
      }
    }
  }
}





list<int> pop::shortest_path(int start, int end) {
   vector<int> top(n(),-1);
   length(start,top);
if (top[end] == -1) {
cout << "None"; return list<int>();
}

list<int>::iterator it;
list<int> back;
for(int v = end; v!=start; v=top[v]) {
   back.push_front(v); }
back.push_front(start);
return back;
}

class finalSolve {
public:
  finalSolve() {};
  void build(string dictionary);
  void solve(string fword, string lword);
  private:
      pop graph;
    int puzzle(string one, string two);
    vector<string> dict;
  };
  int finalSolve::puzzle(string one, string two){
    int j = 0;
    for(int i =0; i < 5; i++){
      if(one[i]==two[i]){
        j++;
      }
    }
    return j;
  }

void finalSolve::build(string dictionary){
  ifstream in(dictionary);
  string line;
  cout<<"Please wait......................"<<endl<<endl;;
  while(getline(in,line)){
    if(line.length()!=0){
     graph.add_vertex();
      dict.push_back(line);
    }
  }
in.close();
string one;
string two;
for( int i = 0; i < dict.size(); i++) {
      one = dict[i];
      for( int j = i; j < dict.size(); j++) {
         two = dict[j];
         if (puzzle(one, two) == 4) {
           graph.add_edge(i,j);
         }
       }
     }


}

void finalSolve::solve(string fword, string lword){

  int one, two;
  for(int i = 0; i < dict.size(); i++) {
    if (fword == dict[i]) {
      one = i;
    }
  }
  for (int i = 0; i < dict.size();
  i++) {
    if (lword == dict[i]) {
       two = i; }
     }
     // Execute breadth-first-search to find shortest path b/w first // and last word; print out answer
     cout << fword << " -> " << lword << endl;
     list <int> answer = graph.shortest_path(one, two);
     list <int>::iterator it;
     for(it = answer.begin(); it!= answer.end(); it++) {
       cout << dict[*it] << " ";
     }
     cout <<endl<<endl;


}





int main(){
  finalSolve puzzle;
  puzzle.build("knuth.txt");
  puzzle.solve("black", "white");
  puzzle.solve("tears", "smile");
  puzzle.solve("small", "giant");
  puzzle.solve("stone", "money");
  puzzle.solve("angel", "devil");
  puzzle.solve("amino", "right");
  puzzle.solve("amigo", "signs");
  return 0;
}
