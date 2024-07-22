#include<iostream>
#include<string> //string, stoi()
#include<vector> //vector 
#include<algorithm> //reverse()
#include<stack> //stack 
#include<cctype> //islower()
using namespace std;
int f(int x){ return 2*x-3; }
int g(int x,int y){ return 2*x+y-7; }
int h(int x,int y,int z){ return 3*x-2*y+z; }
int main(){
    string s;
    vector<string>v;
    while(cin>>s) v.push_back(s);
    reverse(v.begin(),v.end());
    stack<int>st;
    for(string now:v){
        if(islower(now[0])){
            int ans;
            if(now=="f"){
                int a=st.top(); st.pop();
                st.push(f(a));
            }
            else if(now=="g"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(g(a,b));
            }
            else if(now=="h"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                int c=st.top(); st.pop();
                st.push(h(a,b,c));
            }
        }
        else st.push(stoi(now)); 
    }
    cout<<st.top()<<"\n";
    return 0;
}
