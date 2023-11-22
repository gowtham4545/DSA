// Find the kth smallest element in an array.

#include<bits/stdc++.h>
using namespace std;



int main()
{
    priority_queue<int> p;
    p.push(5);
    p.push(3);
    p.push(4);
    p.push(1);
    while(p.size()){
        cout<<p.top()<<' ';
        p.pop();
    }
    
    return 0;
}