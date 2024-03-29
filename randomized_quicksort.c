#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick_sort(int arr[],int left,int right);
int partition(int arr[],int left,int right);
int random_partition(int arr[], int low, int high);
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

    //for(int i=0;i<6;i++) printf("%d ",arr[i]);

    t=clock()-t;
    printf("%f ms\n",1000*((float)t)/CLOCKS_PER_SEC);

    return 0;
}

void bublesort(int *arr,int n){
    int i,j,temp;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void quick_sort(int arr[],int left,int right){
    if(left<right){
        int pivot=random_partition(arr,left,right);

        quick_sort(arr,left,pivot-1);
        quick_sort(arr,pivot+1,right);
    }
}

int random_partition(int arr[], int low, int high) {
    //srand(time(NULL));
    int temp;
    int random = low + rand() % (high - low);
    //swap(&arr[random], &arr[high]);
    temp=arr[random];
    arr[random]=arr[high];
    arr[high]=temp;

    return partition(arr, low, high);
}

int partition(int arr[],int left,int right){
    int pivot=arr[right];
    int i=left-1,temp;

    for(int j=left;j<right;j++){
        if(arr[j]<=pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        
        }
    }
    i++;
    temp=arr[i];
    arr[i]=pivot;
    arr[right]=temp;

    return i;
}