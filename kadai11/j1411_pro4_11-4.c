#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int tmp[MAX];	//ソート対象のデータを一時的に格納する配列

//マージソート(昇順)
void merge_sort(int a[],int le, int ri){
	int i,j,k,m;

	if(le >= ri){ return; } 	//ソート終了
	
	m = (le+ri) / 2;		//基準値の場所を決める(中央値)
	merge_sort(a, le, m);
	merge_sort(a, m+1, ri); 
	for(i=le; i<=m; i++){
		tmp[i] = a[i];
	}
	for(j=0; j<=ri-m-1; j++){
		tmp[ri-j] = a[j+m+1];
	}
	i=le;	j=ri;
	for(k=le; k<=ri; k++){
		if(tmp[i] <= tmp[j]){
			a[k] = tmp[i++];
		}
		else{
			a[k] = tmp[j--];
		}
	}
}

int main(){
	int n,i;
	int d[MAX];
	n = 0;
	fprintf(stdout, "Input data: ");
	//EOF(ctrl + z) が入力されるまで，入力された数値を配列dに代入
	while(scanf("%d", &d[n]) != EOF){
	    n++;
	}
	//マージソートの実行
	merge_sort(d,0,n-1);
	//マージソートの結果出力
	fprintf(stdout, "\nOutput data: ");
	for(i=0; i<n-1; i++){
	    fprintf(stdout,"%d ", d[i]);
	}
	fprintf(stdout,"%d \n", d[n-1]);
	return 0;
}
