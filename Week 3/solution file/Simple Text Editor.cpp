#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    string data;
    stack<string> log;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a==1){
            string w;
            cin>>w;
            log.push(data);
            data +=w;
        }
        else if(a==2){
            int k;
            cin>>k;
            log.push(data);
            data=data.substr(0,data.size()-k);
        }
        else if(a==3){
            int k;
            cin>>k;
            if(k>=1 && k<=(int)data.size()){
                cout<<data[k-1]<<endl;
            }
        }
        else if(a==4){
            if(!log.empty()){
                data = log.top();
                log.pop();
            }
        }
    }
       
    return 0;
}
