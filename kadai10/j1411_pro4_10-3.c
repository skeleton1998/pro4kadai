#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX];

//クイックソート(昇順)
void quick_sort(int le, int ri,int n){
	int i,j,k,pivot,tmp;

	if(le == ri){ return; } 	//ソート終了
	k = (le+ri) / 2;		//基準値の場所を決める(中央値)
	pivot = d[k];			//基準値を代入	
	i = le;	  j = ri;
	//ソート開始の記述
	fprintf(stdout,"<< Sort region: left = %d, right = %d, pivot = %d >>\n",le,ri,pivot);
	fprintf(stdout,"Before:");
	for(k=0;k<n;k++){
	    fprintf(stdout, " %d",d[k]);
	}

	while(i <= j){
	   while(d[ i ] < pivot ){ i++; }//基準値以上
	   while(d[ j ] > pivot ){ j--; }//基準値以下  を探す
	   if(i >= j){ break; }		 //見つからない(交換する必要がないとき)
	   tmp = d[ i ];		 //入れ替え
	   d[ i ] = d[ j ];
	   d[ j ] = tmp;
	   i++;	  j--;
	}
	//ソート内容の表示
	fprintf(stdout,"\nAfter:");
	for(k=0;k<n;k++){
	    fprintf(stdout, " %d",d[k]);
	}
	fprintf(stdout,"\nPartition : left[ %d - %d ], right[ %d - %d ]\n\n",le,i-1,j+1,ri);
	
	if(le < i-1){ //深く左に探索をかける
		if(le != i-1){ fprintf(stdout,"<<Left call : quick_sort(%d,%d)>>\n",le,i-1); } 
		quick_sort(le, i-1, n);
	}
	if(ri > j+1){//残った右の探索(抜け出していく)
		if(ri != j+1){ fprintf(stdout,"<<Right call : quick_sort(%d,%d)>>\n",j+1,ri); } 
		quick_sort(j+1, ri, n);
	}	
}

int main(){
	int n,i;
	n = 0;
	fprintf(stdout, "Input data: ");
	//EOF(ctrl + z) が入力されるまで，入力された数値を配列dに代入
	while(scanf("%d", &d[n]) != EOF){
	    n++;
	}

	fprintf(stdout,"\n");
	//クイックソートの実行
	quick_sort(0,n-1,n);
	//クイックソートの結果出力
	fprintf(stdout, "\nOutput data: ");
	for(i=0; i<n-1; i++){
	    fprintf(stdout,"%d ", d[i]);
	}
	fprintf(stdout,"%d \n", d[n-1]);
	return 0;
}
