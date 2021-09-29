/////find  unique element in array  ,,,, where 
// where all no. except one are present 3 times
#include<bits/stdc++.h>
using namespace std;

bool getBit(int n, int pos){
   
    return ((n&(1<<pos))!=0);
}
int setBit(int n , int pos){
    return (n|(1<<pos));
}
void unique(int arr[], int n){
    int result =0;
   for(int i=0;i<64;i++){
       int sum=0;
       for(int j=0;j<n;j++){
           if(getBit(arr[j],i)){
               sum++;
           }
       }

       if(sum%3!=0){
        result = setBit(result,i);
       }
   }
   cout<< result; 
}

int main()
{
int arr[] ={1,2,3,1,2,3,1,2,3,5};
unique(arr,10);
return 0;
}