#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x,y;
    cout<<"enter 1st sequence : ";
    cin>>x;
    cout<<"enter 2nd sequence : ";
    cin>>y;
    
    swap(x,y);
    
    int len_x = x.length();
    int len_y = y.length();
    
    int arr[len_x+1][len_y+1]={0};
    
    int ax[len_x+1][len_y+1]={0};
    int ay[len_x+1][len_y+1]={0};
    
    
    for(int i=0;i<=len_x;i++){
        for(int j=0;j<=len_y;j++){
            arr[i][j] = 0;
        }
    }
    
      
    for(int i=0;i<=len_x;i++){
        for(int j=0;j<=len_y;j++){
            ax[i][j] = 0;
        }
    }
    
      
    for(int i=0;i<=len_x;i++){
        for(int j=0;j<=len_y;j++){
            ay[i][j] = 0;
        }
    }
    
    
    for(int i=1;i<=len_x;i++){
        for(int j=1;j<=len_y;j++){
            
            if(x[i-1]==y[j-1]){
                arr[i][j]=arr[i-1][j-1]+2;
                ax[i][j]=i-1;
                ay[i][j]=j-1;
            }
            else{
                arr[i][j] = max({arr[i-1][j-1]-1,arr[i][j-1]-1,arr[i-1][j]-1,0});
                if((arr[i-1][j-1]-1) == arr[i][j]){
                    ax[i][j]=i-1;
                    ay[i][j]=j-1;
                    
                
                }
                
                if((arr[i][j-1]-1) == arr[i][j]){
                    ax[i][j]=i;
                    ay[i][j]=j-1;
                    
                }
                
                if((arr[i-1][j]-1) == arr[i][j]){
                    ax[i][j]=i-1;
                    ay[i][j]=j;
                    
                }
            }
        }
    }
    
     
    for(int i=1;i<=len_x;i++){
        for(int j=1;j<=len_y;j++){
            cout<<arr[i][j]<<' '; 
        }
        cout<<endl;
    }
    
    
    cout<<"array for back tracking"<<endl;
    
     
    for(int i=1;i<=len_x;i++){
        for(int j=1;j<=len_y;j++){
            cout<<ax[i][j]<<' '; 
        }
        cout<<endl;
    }
    
    cout<<endl;
     
    for(int i=1;i<=len_x;i++){
        for(int j=1;j<=len_y;j++){
            cout<<ay[i][j]<<' '; 
        }
        cout<<endl;
    }
    
    
    cout<<"sequence"<<endl;
    
    cout<<arr[len_x][len_y]<<endl;
    
    int i=len_x;
    int j=len_y;
    //int count =0;
    while(i>0 && j>0){
        cout<<arr[ax[i][j]][ay[i][j]]<<endl;
        i--;
        j--;
        
    }
    
    string x1 ="_"+x;
    string y1 ="_"+y;
    
    //cout<<endl<<count;
    
    string x_new="";
    string y_new="";
    
    i=len_x;
    j=len_y;
    
    while(i>0 && j>0){
        if(x[ax[i][j]+1]==y[ay[i][j]+1]){
           x_new += x1[ax[i][j]+1];
           y_new += y1[ay[i][j]+1];
           i--;
           j--;
        }  
        if(x1[ax[i][j]]!=y1[ay[i][j]]){
            int temp1=0;
            int temp2=0;
            
            x_new[i]='_';
            y_new[j]='_';
            temp1=i;
            temp2=j;
            
            i--;
            j--;
            
           if(x1[ax[i][j]]==y1[ay[i][j]]){
             x_new += x1[ax[i][j]];
             y_new += y1[ay[i][j]];
             i--;
             j--;
             
             if(x_new[temp1]==x1[i]){
                 y_new[j]=y1[temp2];
             }
             
             if(y_new[temp2]==y1[j]){
                 x_new[i]=x1[temp1];
             }
             
         
             }
           
        }  
       }
       
       cout<<x_new[i]<<endl;
       cout<<y_new[j]<<endl;
    
    
    
    
    
    return 0;
}
