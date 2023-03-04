#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int arr[],int n){
    int i=1;
    int j,temp;
    for(int i=1;i<n;i++){
        j=i;
        while(j>0 && arr[j]<arr[j-1]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

void bublesort(int *arr,int n){
    int i,j,temp;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(int argc,char *argv[])
{
    
    //int arr[10]={6,3,9,2,5,8,1,7,4,0};
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=rand()%n;

    //bublesort(arr,n);

    clock_t t;
    t=clock();

    insertion_sort(arr,n);

    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }

    t=clock()-t;
    printf("%f ms\n",1000*((float)t)/CLOCKS_PER_SEC);


    return 0;
}