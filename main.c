#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void buble_srot(int *ary, int size){
    int i, j;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
            if (ary[j]>ary[j+1])
                swap(ary+j, ary+j+1);
}

int main(){
    int n, r, *ary, j, i, middle, sum;
    
    while (scanf("%d", &n) != EOF) {
        for (j=0; j<n; j++) {
            scanf("%d", &r);
            ary = malloc(r*sizeof(int));
            
            for (i=0; i<r; i++)
                scanf("%d", ary+i);
            
            buble_srot(ary, r);
            
            if (r%2 == 0)
                middle = (ary[(r-2)/2]+ary[r/2])/2;
            else
                middle = ary[(r-1)/2];
            
            sum = 0;
            for (i=0; i<r; i++)
                sum += abs(middle-ary[i]);
            printf("%d\n", sum);
            
            free(ary);
        }
    }
    
    return 0;
}
