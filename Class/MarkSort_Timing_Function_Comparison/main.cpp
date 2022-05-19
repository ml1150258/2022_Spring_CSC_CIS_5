/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 17, 2022, 9:35 AM
 * Purpose:  All Projects start by using the CPP Template
 *           It shows where to place/code your projects
 */

//System Level Libraries
#include <iostream>  //Input-Output Library
#include <cstdlib>   //Setting Random Number Seed
#include <ctime>     //Time Library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void swap1(int &,int &);
void swap2(int &,int &);
void smlPos(int [],int,int);
void mrkSort3(int [],int);
void mrkSort1(int [],int);
void copyAry(int [],int [],int);

//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=160000;
    int array[SIZE],brray[SIZE];
    int perLine;
    
    //Initialize Variables
    perLine=10;
    fillAry(array,SIZE);
    copyAry(brray,array,SIZE);
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);
    
    //Map the inputs/known to the outputs
    int beg=time(0);
    mrkSort3(array,SIZE);
    int end=time(0);
    cout<<"Three function sort took "<<end-beg<<" seconds"<<endl;
    beg=time(0);
    mrkSort1(brray,SIZE);
    end=time(0);
    cout<<"One function sort took "<<end-beg<<" seconds"<<endl;

    
    //Display the outputs
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);

    //Exit the program
    return 0;
}

void copyAry(int b[],int a[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void mrkSort1(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void mrkSort3(int a[],int n){
    for(int i=0;i<n-1;i++){
        smlPos(a,n,i);
    }
}

void smlPos(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap1(a[pos],a[i]);
        }
    }
}

void swap2(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

void swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
}