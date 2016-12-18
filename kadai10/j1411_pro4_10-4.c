#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct item{
	double data;
	int num;
}Item;

Item d[MAX];

//クイックソート(昇順)
void quick_sort(int le, int ri){
	int i,j,k;
	double pivot;
	Item tmp;

	if(le == ri){ return; } 	//ソート終了
	k = (le+ri) / 2;		//基準値の場所を決める(中央値)
	pivot = d[k].data;		//基準値を代入	
	i = le;	  j = ri;

	while(i <= j){
	   while(d[ i ].data < pivot ){ i++; }//基準値以上
	   while(d[ j ].data > pivot ){ j--; }//基準値以下  を探す
	   if(i >= j){ break; }		 //見つからない(交換する必要がないとき)
	   tmp = d[ i ];		 //入れ替え
	   d[ i ] = d[ j ];
	   d[ j ] = tmp;
	   i++;	  j--;
	}
	
	if(le < i-1){ //深く左に探索をかける
		quick_sort(le, i-1);
	}
	if(ri > j+1){//残った右の探索(抜け出していく)
		quick_sort(j+1, ri);
	}	
}

int main(){
	int n,i,seed;
	n = 0;

	//乱数の種の設定
	fprintf(stdout, "Input random-seed: ");
	scanf("%d",&seed);

	//並び替えに使うデータの個数を入力
	fprintf(stdout, "Input the number of data: ");
	scanf("%d",&n);

	//データの個数に対するエラー処理
	if(n > MAX){
		fprintf(stderr, "N is too large!\n");
		exit(1);
	}

	srand(seed);
	//乱数の生成
	for(i=0; i<n; i++){
		//実数の乱数を格納する
		d[i].data = (double)(rand()%30000000) / 1000.0 ;
		//100以降の値を順に格納していく
		d[i].num = 100+i ;
	}

	//生成されたデータ(並び替え前のデータ)の出力
	fprintf(stdout, "\nInput data:\n");
	for(i=0; i<n; i++){
	    fprintf(stdout,"d[%3d]: data = %10.3f, num = %4d\n",i,d[i].data,d[i].num);
	}

	//クイックソートの実行
	quick_sort(0,n-1);
	
	//並び替え後のデータの出力
	fprintf(stdout, "\nOutput data:\n");
	for(i=0; i<n; i++){
	    fprintf(stdout,"d[%3d]: data = %10.3f, num = %4d\n",i,d[i].data,d[i].num);
	}
	return 0;
}
