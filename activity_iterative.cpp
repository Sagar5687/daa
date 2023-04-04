#include<iostream>
#include<string>
using namespace std;
int main(){
    
    int n,i,j,min,temp;
    cin>>n;
    string name[n];
    string temp1;
    int start[n];
    int end[n];
    
    for(i=0;i<n;i++)
    cin>>name[i]>>start[i]>>end[i];
    
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++){
            if(end[j]<end[min])
            min=j;
        }
        if(min!=i){
            temp=end[i];
            end[i]=end[min];
            end[min]=temp;
            temp=start[i];
            start[i]=start[min];
            start[min]=temp;
            temp1=name[i];
            name[i]=name[min];
            name[min]=temp1;
        }
    }
    
    
    
     
    int k=0;
    string order[n];
    order[k]=name[k];
    int maximum=end[k];
    k++;
   
    for(i=1;i<n;i++){
        if(start[i]>maximum){
            
            order[k]=name[i];
            maximum=end[i];
            k++;
        }
        
    }
    
    for(i=0;i<k;i++)
    cout<<order[i]<<" ";
}
