#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a==1){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(a==2){
            if(!q.empty()){
                q.pop();
            }
        }
        else if(a==3){
            if(!q.empty()){
                cout<<q.front()<<endl;
            }
        }
    }
     
    return 0;
}
