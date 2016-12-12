#include <stdio.h>
#include <stdlib.h>

//連結リストの構造体宣言
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}LISTEL;

LISTEL root;		//リストの先頭のノードを指す構造体を宣言する

//連結リストを構築する関数
void construct_list(){
	LISTEL *p, *q;
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
		
		//入力された数字をリストに格納する
		for(i=0; i<k; i++){
			n = sscanf(&buf[ noIndex[i] ], "%d" , &y);
			if(n != 1){
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			p = (LISTEL *)malloc( sizeof(LISTEL) );
			q = (LISTEL *)malloc( sizeof(LISTEL) );
			
			q = root.next;		//先頭のノードのアドレスを格納
			
			p -> data = y;		//追加するノードに入力された数字を格納
			p -> next = q;		//追加するノードが指す，次のノードを先頭ノードにする	
			p -> prev = &root;	//追加するノードが指す，前のノードを先頭を指すノードにする
			root.next = p;		//先頭を指すノードが，追加するノードを指すようにする
			q -> prev = p;		//追加前の先頭ノードが，指す前のノードを追加するノードにする
		}
	}
}

//連結リストを出力する関数
void print_list(){
	LISTEL *p, *q;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	q = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root.next;
	q = root.prev;
	
	if(p == &root || q == &root){	//リストが空でないかを確認
		fprintf(stderr, "There is no data!");
		return;
	}
	//リスト内のデータを先頭から出力
	fprintf(stdout, "List data(From Last): ");
	while(p != &root){
		fprintf(stdout," %2d", p -> data);
		p = p -> next;
	}
	fprintf(stdout, "\n");
	
	//リスト内のデータを末尾から出力
	fprintf(stdout, "List data(From First): ");
	while(q != &root){
		fprintf(stdout," %2d", q -> data);
		q = q -> prev;
	}
	fprintf(stdout, "\n");
}

int main(){
	root.next = &root;		//リストの初期化
	root.prev = &root;
	construct_list();	//リストの構築
	print_list();		//リストの出力
	return 0;
}