#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//バブルソート(降順)
void bubble_sort(int a[], int n){
	int i,j;
	for( i=n-1; i>0; i--){
	    for( j=0; j<i; j++){
		if( a[j] < a[j+1] ){
		    a[j] += a[j+1];
		    a[j+1] -= a[j];
		    a[j] += a[j+1];
		    a[j+1] = 0-a[j+1];
		}
	    }
	}
}

int main(){
	int d[MAX], n,i;
	n=0;
	fprintf(stdout, "Input data: ");
	//EOF(ctrl + z) が入力されるまで，入力された数値を配列dに代入
	while(scanf("%d", &d[n]) != EOF){
	    n++;
	}
	//バブルソートの実行
	bubble_sort(d,n);
	//バブルソートの結果出力
	fprintf(stdout, "\nOutput data: ");
	for(i=0; i<n-1; i++){
	    printf("%d ", d[i]);
	}
	printf("%d \n", d[n-1]);
	return 0;
}
