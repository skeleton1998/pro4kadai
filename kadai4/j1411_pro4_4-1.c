#include <stdio.h>
#include <stdlib.h>

//連結リストの構造体宣言
typedef struct node{
	int data;
	struct node *next;
}LISTEL;

LISTEL root;		//リストの最初のノードを指すポインタ

//連結リストを構築する関数
void construct_list(){
	LISTEL *p;
	int n, y, i, k, noIndex[50];
	char buf[100];
	while(1){
		fprintf(stdout, "Input data: ");
		fgets(buf, sizeof(buf), stdin);
		
		if(buf[0] == '\n'){
			return;
		}
		i=0;	k=0;
		//最初に入力された文字がスペースでない場合，配列の場所をnoIndex[]に格納
		if(buf[i] != ' '){
			noIndex[k++] = i;
		}
		//2つ目以降に入力された文字がスペースでない場合，配列の場所をnoIndex[]に格納
		while(buf[i] != '\0'){
			i++;
			if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n'){
				noIndex[k++] = i;
			}
		}
		//文字数がオーバーした場合
		if(buf[i-1] != '\n'){
			fprintf(stderr, "Error : Too long input data\n");
			exit(1);
		}
		
		//入力された数字を循環リストに格納する
		for(i=0; i<k; i++){
			n = sscanf(&buf[ noIndex[i] ], "%d" , &y);
			if(n != 1){
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			//追加するノードを指すポインタのメモリを動的に確保する
			p = (LISTEL *)malloc( sizeof(LISTEL) );
			//追加するノードに入力された数字を格納
			p -> data = y;
			//新たに構築するノードのポインタに，先頭ノードのアドレスを代入する
			p -> next = root.next;
			//先頭ノードを指すポインタに，追加したノードのアドレスを代入する
			root.next = p;	
		}
	}
}

//連結リストを出力する関数
void print_list(){
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	//リストの先頭ノードのアドレスをpに代入する
	p = root.next;
	if(p == &root){
		fprintf(stderr, "There is no data!");
		return;
	}
	fprintf(stdout, "List data: ");
	while(p != &root){
		fprintf(stdout," %4d", p -> data);
		p = p -> next;
	}
	fprintf(stdout, "\n");
}

int main(){
	root.next = &root;	//リストの初期化
	construct_list();	//リストの構築
	print_list();		//リストの出力
	return 0;
}