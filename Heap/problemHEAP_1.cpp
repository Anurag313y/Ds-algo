///// Problem1 -Median of running stream
//////--------> Numbers are coming we need to tell median aftereach input
//Solution Approach: 1) keep onr maxheap and one min heap
/////////////////////2) divide array in 2 parts  
///////////////////3) for answer: size of max heap != size of min heap then ans = Top of larger size heap
/////////////////// else avg to top of both element  
#include<bits/stdc++.h>
using namespace std;

priority_queue<int , vector<int>,greater<int>> pqmin;
priority_queue<int , vector<int>> pqmax;
 

void insert(int x){
   if(pqmin.size() == pqmax.size())
   {
       if(pqmax.size()==0)
       {
           pqmax.push(x);
           return;
       }

       if(x< pqmax.top())
       {
           pqmax.push(x);

       }
       else{
           pqmin.push(x);
       }
   }

   else{

       if(pqmin.size() < pqmax.size())
       {
           if(x>= pqmax.top())
           {
                pqmin.push(x);
           }
           else{
               int temp = pqmax.top();
               pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
           }
       }

       else{

           if(x<=pqmin.top())
           {
               pqmax.push(x);
           }
           else{
                int temp = pqmin.top();
               pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
           }
       }
   }
}

double findMedian(){
    if(pqmin.size() == pqmax.size())
    {
        return (pqmin.top()+pqmax.top())/2.0;
    }
    else if(pqmax.size()>pqmin.size())
    {
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}
int main(){
    insert(10);
    cout<<findMedian()<<endl;
    insert(15);
    cout<<findMedian()<<endl;
    insert(21);
    cout<<findMedian()<<endl;
    insert(30);
    cout<<findMedian()<<endl;
    insert(18);
    cout<<findMedian()<<endl;
    insert(19);
    cout<<findMedian()<<endl;
    return 0;
}
