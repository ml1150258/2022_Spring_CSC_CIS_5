/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 24, 2022, 10:35 AM
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
int* fillAry(int);
void prntAry(int [],int,int);
void swap1(int &,int &);
void bubSort(int [],int);

//Execution begins here!
int main(int argc, char* argv[]) {
    //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=100;
    int *array;
    int perLine;
    
    //Initialize Variables
    perLine=10;
    array=fillAry(size);
    prntAry(array,size,perLine);
    
    //Map the inputs/known to the outputs
    bubSort(array,size);
    
    //Display the outputs
    prntAry(array,size,perLine);

    //Exit the program
    delete []array;
    return 0;
}

void bubSort(int a[],int n){
    bool swap;
    int redList=n-1;
    do{
        swap=false;
        for(int i=0;i<redList;i++){
            if(a[i]>a[i+1]){
                swap1(i[a],*(a+i+1));
                swap=true;
            }
        } 
        redList--;
    }while(swap);
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

int* fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
    return a;
}