#include <stdio.h>
#include <stdlib.h>

//二分木の構造体宣言
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}TREE;

TREE *root;		//根のノードを指すポインタ

//連結リストを構築する関数
void construct_tree(){
	TREE *p,*q;
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
		
		//入力された数字をノードに格納して木を構築する
		for(i=0; i<k; i++){
			n = sscanf(&buf[ noIndex[i] ], "%d" , &y);
			if(n != 1){
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			if(i == 0){
				q = (TREE *)malloc( sizeof(TREE) );
				q -> data = y;
				q -> left = NULL;
				q -> right = NULL;
				root = q;
			}
			else{
				p = root;
				while(p != NULL){
					if( y < p->data ){
						if( p -> left != NULL )		p = p->left;
						else{
							q = (TREE *)malloc( sizeof(TREE) );
							q -> data = y;
							q -> left = NULL;
							q -> right = NULL;
							p->left = q;
							break;
						}
					}
					else{
						if( p -> right != NULL )	p = p->right;
						else{
							q = (TREE *)malloc( sizeof(TREE) );
							q -> data = y;
							q -> left = NULL;
							q -> right = NULL;
							p -> right = q;
							break;
						}
					}
					
				}
			}
		}
	}
}

//連結リストを出力する関数
void print_tree(int depth, TREE *p){
	int i;
	if(p == NULL)	return;
	//木のデータを出力
	print_tree(depth+1, p->right);
	for(i=0; i < depth; i++){
		fprintf(stdout, "   ");
	}
	fprintf(stdout, "  %4d\n", p-> data);
	print_tree(depth+1, p->left);
}

int main(){
	root = NULL;			//二分木の初期化
	construct_tree();		//二分木の構築
	print_tree(0, root);	//二分木の出力
	return 0;
}