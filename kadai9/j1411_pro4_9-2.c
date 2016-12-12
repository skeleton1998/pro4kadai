#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//選択ソート(昇順)
void select_sort(int a[], int n){
	int i,j,t,min;
	for( i=0; i<n-1; i++){
	    min = i;
	    for( j=i+1; j<n; j++){
		if( a[min] > a[j] ){
		    min = j;
		}
	    }
	    t = a[i];
	    a[i] = a[min];
	    a[min] = t;
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
	//選択ソートの実行
	select_sort(d,n);
	//選択ソートの結果出力
	fprintf(stdout, "\nOutput data: ");
	for(i=0; i<n-1; i++){
	    fprintf(stdout, "%d ", d[i]);
	}
	fprintf(stdout, "%d \n", d[n-1]);
	return 0;
}
