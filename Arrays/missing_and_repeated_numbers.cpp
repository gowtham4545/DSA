// Missing and Repeated Numbers

/*
Given an unsorted array of size n. Array elements are in the range of 1 to n. 
One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
Find these two numbers.
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v={4, 3, 2, 7, 8, 1, 6, 5, 5};

    int sum=0,squaredSum=0,n=v.size(),naturalSum=0,naturalSquaredSum=0;
    naturalSum=n*(n+1)/2;
    naturalSquaredSum=n*(n+1)*(2*n+1)/6;
    for(auto el:v){
        sum+=el;
        squaredSum+=(el*el);
    }
    // a-b
    int diff=abs(sum-naturalSum);
    // a^2 - b^2
    int squaredDiff=abs(squaredSum-naturalSquaredSum);
    // calculating a & b
    int a=(squaredDiff/diff+diff)/2;
    int b=a-diff;
    if(naturalSum-sum==a-b){
        cout<<"Missing Number: "<<a<<endl;
        cout<<"Repeated Number: "<<b<<endl;
    }
    else{
        cout<<"Missing Number: "<<b<<endl;
        cout<<"Repeated Number: "<<a<<endl;
    }
    
    return 0;
}