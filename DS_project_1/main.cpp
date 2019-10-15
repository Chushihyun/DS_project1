//
//  main.cpp
//  DS_project_1
//
//  Created by 朱世耘 on 2019/9/24.
//  Copyright © 2019 sy_chu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int row,column;
int** A;

void check_matrix(){
    for (int m=row+4; m>=0; m--) {
        for (int n=0; n<column+2; n++) {
            cout<<A[m][n]<<" ";
        }
        cout<<endl;
        if(m==row+1){
            for(int i=0; i<column+2; i++)   cout<<"%"<<" ";
            cout<<endl;
        }
    }
    cout<<endl;
}

class object{
public:
    int left;
    int right;
    int height;
    string shape;
    int element[4][2];//裝方塊形狀位置 {( , )( , )( , )( , )}  element[][0]=row,[][1]=column
    void set_element(){
        //case
        if(shape=="T1"){
            element[0][0]=0 ; element[0][1]=1 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=1 ; element[3][1]=2;
        }
        else if (shape=="T2"){
            element[0][0]=0 ; element[0][1]=1 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=2 ; element[3][1]=1;
        }
        else if (shape=="T4"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=2 ; element[3][1]=0;
        }
        else if (shape=="T3"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=0 ; element[2][1]=2 ; element[3][0]=1 ; element[3][1]=1;
        }
        else if (shape=="L1"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=2 ; element[2][1]=0 ; element[3][0]=1 ; element[3][1]=0;
        }
        else if (shape=="L2"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=1 ; element[3][1]=2;
        }
        else if (shape=="L3"){
            element[0][0]=2 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=2 ; element[3][1]=1;
        }
        else if (shape=="L4"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=0 ; element[2][1]=2 ; element[3][0]=1 ; element[3][1]=2;
        }
        else if (shape=="J1"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=2 ; element[3][1]=1;
        }
        else if (shape=="J2"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=0 ; element[2][1]=1 ; element[3][0]=0 ; element[3][1]=2;
        }
        else if (shape=="J3"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=2 ; element[2][1]=0 ; element[3][0]=2 ; element[3][1]=1;
        }
        else if (shape=="J4"){
            element[0][0]=1 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=1;
            element[2][0]=1 ; element[2][1]=2 ; element[3][0]=0 ; element[3][1]=2;
        }
        else if (shape=="Z2"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=2 ; element[3][1]=1;
        }
        else if (shape=="Z1"){
            element[0][0]=1 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=1;
            element[2][0]=0 ; element[2][1]=1 ; element[3][0]=0 ; element[3][1]=2;
        }
        else if (shape=="S2"){
            element[0][0]=0 ; element[0][1]=1 ; element[1][0]=1 ; element[1][1]=1;
            element[2][0]=1 ; element[2][1]=0 ; element[3][0]=2 ; element[3][1]=0;
        }
        else if (shape=="S1"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=1 ; element[3][1]=2;
        }
        else if (shape=="I2"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=0 ; element[2][1]=2 ; element[3][0]=0 ; element[3][1]=3;
        }
        else if (shape=="I1"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=1 ; element[1][1]=0;
            element[2][0]=2 ; element[2][1]=0 ; element[3][0]=3 ; element[3][1]=0;
        }
        else if (shape=="O"){
            element[0][0]=0 ; element[0][1]=0 ; element[1][0]=0 ; element[1][1]=1;
            element[2][0]=1 ; element[2][1]=1 ; element[3][0]=1 ; element[3][1]=0;
        }
    }

    void adjust_element(int x,int y){
        //every element 向(x,y)移
        //x軸
        for (int i=0; i<4; i++) {
            element[i][1] += x;
        }
        //y軸
        for (int i=0; i<4; i++) {
            element[i][0] += y;
        }
    }
    
    object(string kind,int position){
        shape=kind;
        left=position;
        set_element();
        adjust_element(position,0);
    }
};

bool candrop(object tmp){
    bool check=1;
    tmp.adjust_element(0,-1);
    for (int i=0; i<4; i++) {
        if (A[tmp.element[i][0]][tmp.element[i][1]]==1) {
            check=0;
        }
    }
    return check;
}

void putin(object tmp){
    //initial tmp position on the top
    tmp.adjust_element(0,row+1);
    
    //if(can drop) drop
    //else put tmp into A
    //可以往下掉，扣除原本就有的（當作原本沒有來做）
    while(candrop(tmp)==true){
        tmp.adjust_element(0,-1);
    }
    
    for (int i=0; i<4; i++) {
        A[tmp.element[i][0]][tmp.element[i][1]]=1;
    }
}

void clear_full_row(){
    //消除滿的列，往下掉
    bool check;
    for (int y=1; y<=row; y++) {
        check=1;
        for ( int x=1; x<=column; x++) {
            if (A[y][x]!=1) {
                check=0;
            }
        }
        if (check==1) {
            //往下掉，top全設0
            for (int x=1; x<=column; x++) {
                for (int y1=y; y1<=row+3; y1++) {
                    A[y1][x]=A[y1+1][x];
                }
                A[row+4][x]=0;
            }
            y--;
        }
    }
}

bool status_valid(){
    
    //check if A out of boundary
    //if valid return 1
    
    bool check=true;
    for (int x=1; x<=column; x++) {
        for (int y=row+1; y<=row+4; y++) {
            if (A[y][x]==1) {
                check=false;
            }
        }
    }
    return check;
}

//輸入 高 寬
int main() {

    freopen("Tetris.data","r",stdin);
    freopen("Tetris.output","w",stdout);
    
    A=new int*[45];
    for (int i=0; i<45; i++) {
        A[i]=new int[17];
    }
    
    cin>>row>>column;
    if(row<=0||column<=0){
        return 0;
    }
    //initial  A matrix;
    //set boundary into 1 and inside into 0
    for (int m=0; m<row+5; m++) {
        for (int n=0; n<column+2; n++) {
            if ((m==0)||(n==0)||(n==column+1))
                A[m][n]=1;
            else
                A[m][n]=0;
        }
    }
    
    //throw blocks
    while (1>0) {
        
        string shape;
        int pos;
        cin>>shape;
        if (shape=="End")   break;
        cin>>pos;
        object tmp(shape,pos);
        
        //put tmp into A
        putin(tmp);
        
        //check if all row is 1
        clear_full_row();
        
        //check_matrix();
        
        //check now status is valid
        //if not, then break
        if(status_valid()==false) break;
        
    }
    
    //output matrix
    for (int m=row; m>=1; m--) {
        for (int n=1; n<=column; n++) {
            cout<<A[m][n];
        }
        cout<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

