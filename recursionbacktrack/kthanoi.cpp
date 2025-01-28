#include<iostream>
using namespace std;
void kthhanoi(int disc , int  source, int target , int aux,int k){
    if(k<=(1<<(disc-1)-1)){
        kthhanoi(disc-1 , source , aux , target , k);
    }
    else if( k == (1<<(disc-1))){
        cout<<"moving from "<< source<<"to"<<target<<"using "<<aux<<'\n';
    }
    else{
        kthhanoi(disc-1 ,aux , target , source , k - (1<<(disc-1)));
    }
}
int main(){
    
}