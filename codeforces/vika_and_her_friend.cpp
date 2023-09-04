#include <bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>t;
     while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int vikax, vikay;
        cin>>vikax>>vikay;
        vector<pair<int,int>> vec(k,{0,0});
        for(int i=0; i<k; i++){
            int x,y;
            cin>>x>>y;
            vec[i] = {x,y};
        }
    
        vector<pair<int, int>> diagonalPair; 

        int i = vikax, j = vikay;
        i -= 1;
        j -=1;
        while(i >=0  && j>=0){
            diagonalPair.push_back({i,j});
            i--;
            j--;
        }

        i = vikax, j = vikay;
        
        i -= 1;
        j += 1;

        while(i >=0  && j<m){
            diagonalPair.push_back({i,j});
            i--;
            j++;
        }


        i = vikax, j = vikay;
        
        i += 1;
        j -= 1;

        while(i <n  && j>=0){
            diagonalPair.push_back({i,j});
            i++;
            j--;
        }


        i = vikax, j = vikay;
        
        i += 1;
        j += 1;

        while(i <n  && j<m){
            diagonalPair.push_back({i,j});
            i++;
            j++;
        }


     for(auto it: vec){
        for(auto iter: diagonalPair){
            if(it.first == iter.first && it.second == iter.second){
                cout<<"No"<<endl;
                break;
            }
        }
     }
     cout<<"yes"<<endl;

     }
return 0;
}