//
//  main.cpp
//  test
//
//  Created by 朱世耘 on 2019/10/1.
//  Copyright © 2019 sy_chu. All rights reserved.
//

#include <iostream>
using namespace std;

int z=15;
int s=40;

int** A=new int*[42];


void change_matrix(int m,int n,int x){
    A[m][n]=x;
}

int main() {
    for(int i=0; i<40; i++) {
        A[i]=new int[17];
    }
    
    int row,column;
    cin>>row>>column;
    
    //initial the [row]*[column] matrix;
    for (int m=0; m<row+2; m++) {
        for (int n=0; n<column+2; n++) {
            if ((m==0)||(m==row+1)||(n==0)||(n==column+1))
                A[m][n]=1;
            else
                A[m][n]=0;
        }
    }
    
    for (int y=1; y<=row; y++) {
        for (int x=1; x<=column; x++) {
            A[y][x]=A[y+1][x];
        }
    }
    for (int x=1; x<=column; x++) {
        A[row+1][x]=9;
    }
    
    
    int m,n,input;
    //cin>>m>>n>>input;
    //change_matrix(m, n, input);
    
    for (int x=0; x<=row+1; x++) {
        for (int y=column+1; y>=0; y--) {
            cout<<A[x][y]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
