#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>



int members;
int A[999999999];
////////////////////////////////////////////////////////////// Merge_Sort
void merge(int A[],int p,int q,int r){

  int n1 = q-p+1;
  int n2 = r-q;
  int L[n1];
  int R[n2];
  for(int i=0;i<n1;i++){
      L[i] = A[p+i];
  }
  for(int i=0;i<n2;i++){
      R[i] = A[q+i+1];
  }
  
  int i = 0;
  int j = 0;
  int k =p;
  for(;i<n1 && j<n2 ;k++){
       
      if(L[i]<=R[j]){
          A[k] = L[i];
          i++;
          }
          
      else{
            A[k] = R[j];
            j++;
            }    
  
  }
  
  while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

}

void merge_Sort(int A[],int p, int r){
     
     if(p<r){
         
         int q=floor((p+r)/2);
         merge_Sort(A,p,q);
         merge_Sort(A,q+1,r);
         
         merge(A,p,q,r);
         
         }
}
///////////////////////////////////////////////////////// QuickSort

void swap(int *a,int *b){
int temp =*a;
*a=*b;
*b=temp;
}

int partition(int A[],int p, int r){
    int x= A[r];
    int i= p-1;
    for(int j=p;j<r;j++){
          if(A[j]<=x){
             i++;
             swap(&A[i],&A[j]);
          }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}

void quickSort(int A[],int p,int r){

     if(p<r){
        int q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
     }

}

//////////////////////////////////////////////////////// QuickSort_M
int findAverage(int A[]){
int sum=0;
for(int i =0;i<members;i++){sum+=A[i];}
return sum/members;

}

int findMin(int A[]){
int min = A[0];
for(int i =1;i<members;i++){
    if(A[i]<min){
       min = A[i];    
    
    }

}

return min;}

int findNearestToAverage(int A[]){
    int average =findAverage(A);
    int diffrences[members];
    for(int i =0;i<members;i++){diffrences[i]=abs(A[i]-average);}
    int x = findMin(diffrences);
    
    int nearest;
    int nearestindex;
    for(int i=0;i<members;i++){
        if(x==diffrences[i]){nearest=A[i];nearestindex=i;}
         
    }
    return A[nearestindex];}
    
    


int partition2(int A[], int p, int r) {
    
     
      int nh = findNearestToAverage(A);
  int counter =0;
      for (int i = p; i <= r; i++) {
      
      if (nh=A[i]){ counter=i;
        }
        
    }
    
    
    swap(&A[counter], &A[r]);

    
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= A[r]) {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    
    swap(&A[i + 1], &A[r]);

    return i + 1;
}
    
    
void QuickSort_M(int A[], int p, int r) {
    if (p < r) {
        int q = partition2(A, p, r);
        QuickSort_M(A, p, q - 1);
        QuickSort_M(A, q + 1, r);
    }
}


int main(int argc,char* argv[]){

int func_num;
scanf("%d",&func_num);

scanf("%d",&members);

for(int k=0;k<members;k++){

scanf("%d",&A[k]);

}


if(func_num == 0){

merge_Sort(A,0,members-1);
printf("MergeSort\n");
for(int i=0;i<members;i++){printf("%d\n",A[i]);}

}

if(func_num == 1){

quickSort(A,0,members-1);
printf("QuickSort\n");
for(int i=0;i<members;i++){printf("%d\n",A[i]);}

}

if(func_num == 2){

QuickSort_M(A,0,members-1);
printf("QuickSort_M\n");
for(int i=0;i<members;i++){printf("%d\n",A[i]);}

}

return 0;}
