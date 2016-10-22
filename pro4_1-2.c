
//スタックを用いた文字列変換
//j1411 完山 尚葵

#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"

#include "stack.h"	//スタックに関する変数＆関数の読み込み

//合間で書き込み処理を何回も行うバージョン
//(利点 ： メモリを食わない。　 欠点 ： 処理時間が長くなる)
int main(){
	int ch, pch, small;
	small = 0;		//小文字と大文字を判定するフラグ_小文字:1
	init_stack();
	fprintf(stdout, "Please enter English text: \n");
	pch = ' ';		//前に入力されたものを格納する変数の初期化 (初期時はスペース)
	
	while( ( ch = getchar() ) != '\n' ){		//改行が入力されるまで処理を続ける
		
		if(ch != ' ' && ch != '.' && ch != ',' ){
			if(pch == ' ' || pch == '.' || pch == ','){
				if(ch >= 97 && ch <= 122){	small = 1; }	//小文字の時、フラグを立てる
			}
			if(small == 1){
				push(ch);						//一度スタックする
			}
			else{
				fprintf(stdout, format, ch);	//そのまま書き込み
			}
		}
		else{
			if(small == 1){
				while(stack_stock() > 0){
					fprintf(stdout, format, pop());	//スタックされているものをポップし表示する
				}
				small = 0;						//小文字判定フラグを初期化
			}
			fprintf(stdout,format,ch);				//空白の挿入
		}
		pch = ch;
	}
	while(stack_stock() > 0){					//余りを表示
		fprintf(stdout, format, pop());
	}
	fprintf(stdout, "\n---Finish---\n");
	
	return 0;
}