#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick_sort(int arr[],int left,int right);
int partition(int arr[],int left,int right);
int findMedian(int arr[],int left,int right);
void bublesort(int *arr,int n);


int main(int argc,char *argv[])
{

    // int arr[]={6,3,9,2,5,8};
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=rand()%n;

    //bublesort(arr,n);

    clock_t t;
    t=clock();

    quick_sort(arr,0,n-1);

    //for(int i=0;i<n;i++) printf("%d ",arr[i]);

    t=clock()-t;
    printf("%f ms\n",1000*((float)t)/CLOCKS_PER_SEC);

    return 0;
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

void quick_sort(int arr[],int left,int right){
    if(left<right){
        int pivot=partition(arr,left,right);

        quick_sort(arr,left,pivot-1);
        quick_sort(arr,pivot+1,right);
    }
}
int partition(int arr[], int left, int right)
{
    int pivotIndex = findMedian(arr, left, right);
    int pivotValue = arr[pivotIndex];
    int temp;
    //swap(arr[pivotIndex], arr[right]);
    temp=arr[pivotIndex];
    arr[pivotIndex]=arr[right];
    arr[right]=temp;
    int storeIndex = left;
    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivotValue)
        {
            //swap(arr[i], arr[storeIndex]);
            temp=arr[i];
            arr[i]=arr[storeIndex];
            arr[storeIndex]=temp;
            storeIndex++;
        }
    }
    //swap(arr[storeIndex], arr[right]);
    temp=arr[storeIndex];
    arr[storeIndex]=arr[right];
    arr[right]=temp;
    return storeIndex;
}

int findMedian(int arr[],int left,int right){
    int center=(left+right)/2;
    int temp;

    if(arr[left]>arr[center]){
        temp=arr[left];
        arr[left]=arr[center];
        arr[center]=temp;
    }
    else if(arr[left]>arr[right]){
        temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
    }
    else if(arr[center]>arr[right]){
        temp=arr[center];
        arr[center]=arr[right];
        arr[right]=temp;
    }
    return center;


}