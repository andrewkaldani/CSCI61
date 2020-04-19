#include<iostream>
#include<stack>
#include<algorithm>
#include <string>
#include<vector>
using namespace std;

int order(char o){
  if (o == '-' || o == '+')
		return 1;
	else if (o == '*' || o == '/')
		return 2;
	else if (o == '^')
		return 3;
    else{
	return -1;
}
}
bool isOperator(char C){
  return ((!isalnum(C) && !isdigit(C)));
}

string inToPost(string in){
  stack<char> s1;
  string postfix = " ";
  in = '(' + in + ')';
  int size = in.size();
  for(int i = 0; i <size; i++)
  {
    if(isalnum(in[i])||isdigit(in[i]))
    {
      postfix= postfix + in[i];
    }

    else if(in[i]=='('){
      s1.push('(');
    }
    else if(in[i]=='^'){
      s1.push('^');
    }
    else if(in[i]==')'){
      while(s1.top() != '('){
        postfix+=s1.top();
        s1.pop();

      }
      s1.pop();
    }
      else{
        if (isOperator(s1.top())) {
  				while (order(in[i])
  				<= order(s1.top())) {
  					postfix = postfix + s1.top() + " ";
  					s1.pop();
  				}
  				s1.push(in[i]);
		}
  }
}

return postfix;
}
string inToPre(string in){
  string pre;
  reverse(in.begin(),in.end());
  for(int i = 0; i < in.size(); i++){
    if(in[i]=='('){

      in[i]=')';
        i++;
    }
    else if(in[i]==')'){

      in[i]='(';
        i++;
    }
  }
  pre = inToPost(in);
  reverse(pre.begin(),pre.end());
  return pre;
}
bool operator2(char c) {
  switch (c) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}

string prefixtoinfix(string pre){
  stack<string> s2;
  for( int i = pre.size()-1; i >=0; i--){
    if(operator2(pre[i]))
    {
      string a = s2.top();
      s2.pop();
      string b = s2.top();
      s2.pop();
      string concat =   a + pre[i] + b ;
      s2.push(concat);
    }
    else{
      s2.push(string(1,pre[i]));
    }
  }
  return s2.top();
}
int main()
{
    string s;
    cout<< "Enter Infix: "<<endl;
    cin>>s;
    cout << "infixToPrefix: "<<inToPre(s) <<endl;
    cout<< "Enter prefix: "<<endl;
    string p;
    cin>>p;
    cout<<"prefixtoinfix: "<<prefixtoinfix(p)<<endl;
    return 0;
}
