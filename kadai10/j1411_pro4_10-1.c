#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX];

//クイックソート(昇順)
void quick_sort(int le, int ri){
	int i,j,k,pivot,tmp;

	if(le == ri){ return; } 	//ソート終了
	k = (le+ri) / 2;		//基準値の場所を決める(中央値)
	pivot = d[k];			//基準値を代入	
	i = le;	  j = ri;
	while(i <= j){
	   while(d[ i ] < pivot ){ i++; }//基準値以上
	   while(d[ j ] > pivot ){ j--; }//基準値以下  を探す
	   if(i >= j){ break; }		 //見つからない(交換する必要がないとき)
	   tmp = d[ i ];		 //入れ替え
	   d[ i ] = d[ j ];
	   d[ j ] = tmp;
	   i++;	  j--;
	}
	if(le < i-1){ quick_sort(le, i-1); }	//深く左に探索をかける
	if(ri > j+1){ quick_sort(j+1, ri); }	//残った右の探索(抜け出していく)
}

int main(){
	int n,i;
	n = 0;
	fprintf(stdout, "Input data: ");
	//EOF(ctrl + z) が入力されるまで，入力された数値を配列dに代入
	while(scanf("%d", &d[n]) != EOF){
	    n++;
	}
	//クイックソートの実行
	quick_sort(0,n-1);
	//クイックソートの結果出力
	fprintf(stdout, "\nOutput data: ");
	for(i=0; i<n-1; i++){
	    fprintf(stdout,"%d ", d[i]);
	}
	fprintf(stdout,"%d \n", d[n-1]);
	return 0;
}
