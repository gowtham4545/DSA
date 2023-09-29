// TODO: Frog Jump with k distances

/*
There is an array of heights corresponding to 'n' stones. You have to reach from stone 1 to stone ‘n’.
From stone 'i', it is possible to reach stones 'i'+1, ‘i’+2… ‘i’+'k' , and the cost incurred will be | Height[i]-Height[j] |, where 'j' is the landing stone.
Return the minimum possible total cost incurred in reaching the stone ‘n’.
*/

int minimizeCost(int n, int k, vector<int> &h){
    vector<int> v(n,INT_MAX);
    v[0]=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+k && j<n;j++){
            v[j]=min(v[j],v[i]+abs(h[j]-h[i]));
        }
    }
    return v[n-1];
}