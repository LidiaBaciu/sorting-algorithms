#include <stdio.h>
#include <stdlib.h>

void swap( int *number1, int *number2){

        int temp = *number1;
        *number1 = *number2;
        *number2 = temp;

}

void printf_vector( int *a, int n){

        int i;

        for( i = 0 ; i < n; i++){
                printf("\t%d ", *(a+i));
        }
}

void bubble_sort( int *a, int n){

        int i;
        int j;

        for( i = 0; i < n-1; i++){
                for( j = i+1; j <n; j++){
                        if( *(a+i) > *(a+j)){
                                swap((a+i), (a+j));
                        }
                }
        }
        printf_vector(a, n);
}

void selection_sort(int *a, int n){

        int i;
        int j;
        int min_index;

        for( i = 0; i < n-1; i++){
                min_index = i;

                for( j = i+1; j <n; j++){
                        if(*(a+j) < *(a+min_index)){
                                min_index = j;
                        }
                }

                swap((a+min_index), (a+i));
        }

        printf_vector(a, n);

}

void insertion_sort( int *a, int n){

        int i;
        int j;
        int key;

        for( i = 1; i < n; i++){
                key = *(a+i);
                j = i -1;

                while( j >= 0 && *(a+j) > key){
                        *(a+j+1) = *(a+j);
                        j--;
                }
                *(a+j+1) = key;
        }

        printf_vector(a, n);

}

void merge( int *a, int left, int middle, int right){

        int indexLeft;
        int indexRight;
        int indexTotal;
        int dimensionLeft = middle - left + 1;
        int dimensionRight = right - middle;

        int *leftArray = (int *)malloc(dimensionLeft*sizeof(int));
        int *rightArray = (int *)malloc(dimensionRight*sizeof(int));

        for( indexLeft = 0; indexLeft < dimensionLeft; indexLeft++){
                *(leftArray + indexLeft) = *(a + left+ indexLeft);
        }
        for( indexRight = 0; indexRight < dimensionRight; indexRight++){
                *(rightArray + indexRight) = *(a + middle + 1 + indexRight);
        }

        indexLeft = 0;
        indexRight = 0;
        indexTotal = left;

        while( indexLeft < dimensionLeft && indexRight < dimensionRight){
                if( *(leftArray + indexLeft) <= *(rightArray + indexRight)){
                        *(a + indexTotal) = *(leftArray + indexLeft);
                        indexLeft++;
                }else{
                        *(a + indexTotal) = *(rightArray + indexRight);
                        indexRight++;
                }
                indexTotal++;
        }

        while( indexLeft < dimensionLeft){
                *(a + indexTotal) = *(leftArray + indexLeft );
                indexLeft++;
                indexTotal++;
        }
        while( indexRight < dimensionRight){
                *(a + indexTotal) = *(rightArray + indexRight);
                indexRight++;
                indexTotal++;
        }

}

void merge_sort(int *a, int left, int right){

        int middle;

        if( left < right){
                middle = left+ (right - left)/2;

                merge_sort(a, left, middle);
                merge_sort(a, middle+1, right);

                merge(a, left, middle, right);
        }


}

int partition( int *a, int low, int high){
/*This function takes last element as pivot, places the pivot element at its correct position in sorted array
and places all smaller (smaller than pivot) to left of pivot
and all greater elements to right of pivot
*/

        int pivot = *(a + high);
        int index = low - 1; // index of smaller element
        int j;

        for( j = low; j <= high - 1; j++){
                if( *(a+j) <= pivot ){
                        index++;
                        swap((a+index), (a+j));
                }
        }
        swap( (a+index+1), (a+high));

        return (index+1);
}

void quick_sort( int *a, int low, int high){
/*
a ---> array to be sorted
low ---> starting index
high ---> ending index
partion_index ---> *(a+partion_index) is now at the right place
*/
        int partition_index;

        if( low < high){
                partition_index = partition(a, low, high);

                quick_sort(a, low, partition_index-1);
                quick_sort(a, partition_index+1, high);

        }
}


int main()
{
        int number;
        printf("The number of elements of the array is: ");
        scanf("%d", &number);

        int *a = (int *)malloc(number *sizeof(int));
        int i;
        for( i =0; i < number; i++){
                printf("pointer[%d] este:", i);
                scanf("%d", (a+i));
        }

        //bubble_sort(a, number);
        //selection_sort(a, number);
        //insertion_sort(a, number);
        merge_sort(a, 0, number-1);
        //quick_sort(a, 0, number-1);
        printf_vector(a, number);


    return 0;
}
