#include <stdio.h>
#include <stdlib.h>
#define Q_size 10				//キューサイズを設定
#define Q_type int				//キューに格納するデータの型を指定
#include "j1411_queue.h"

int main(){
	int i;
	int c;
	int num;	//dequeueするデータ数
	
	init_Q();
	
	//初期画面の出力
	fprintf(stdout, "Queue size: %d", Q_size);
	fprintf(stdout, "\nPlease enter text:");
	
	//入力された一文字を，開業が入力されるまで読み込み，キューに格納する
	while((c = getchar()) != '\n'){
		enqueue(c);
	}
	
	//キューの配列内のデータを出力する
	fprintf(stdout, "\nFront: %d    Rear: %d", f, r);
	fprintf(stdout, "\nArray Q data:");
	for(i=0; i<count ; i++){
		fprintf(stdout, " %c", Q[i]);
	}
	
	//キューに格納されたデータを指定数取出し，出力する
	fprintf(stdout, "\n\nPlease enter dequeue number:");
	scanf("%d" , &num);
	fprintf(stdout, "Dequeue data:");
	for(i=0;i<num;i++){
		fprintf(stdout, " %c", dequeue());
	}
	
	//新しくデータをキューに格納する
	fprintf(stdout, "\n\nPlease enter next text(MAX num:%d):",Q_size - count);
	c = getchar();
	while((c = getchar()) != '\n'){
		enqueue(c);
	}
	
	//キューに格納されたデータをすべて取り出し、出力する
	fprintf(stderr, "Front: %d    Rear: %d", f, r);
	fprintf(stderr, "\nQueue all data:");
	while( count != 0 ){
		fprintf(stderr, " %c", dequeue());
	}
	
	//キューの配列内のデータを出力する
	fprintf(stderr, "\nArray Q data:");
	for(i=0; i<Q_size; i++){
		fprintf(stderr, " %c", Q[i]);
	}
	fprintf(stderr, "\n");
	return 0;
}