#include<algorithm>
#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(void){
    int a;
    cin>>a;
    vector<int> num;
    int mid =a/2;
    copy_n(istream_iterator<int>(cin),a,back_inserter(num));
    nth_element(num.begin(),num.begin()+ mid,num.end());
    cout<<num[mid]<<endl;
}
