
//スタックを用いたプログラムの整合性チェックプログラム
//j1411 完山 尚葵

#include <stdio.h>
#include <stdlib.h>
#define stack_size 100			//スタックサイズの設定
#define stack_type char			//スタックに格納する値の型を設定
#define format "%c"				//スタック内のデータ出力時のフォーマット
#include "stack.h"				//スタックに関する変数＆関数の読み込み
#define BUFLEN 100				//読み込む文字列の最大長を設定

/****             pro4_1-3.c               ****/
int main(){
	int ch, chst, err = 0, i = 0;
	char buf[BUFLEN];
	init_stack();				//スタックの初期化
	fprintf(stdout, "Please enter c program : \n");
	
	while(1){
		if( i == 0 ){ fgets(buf, sizeof(buf), stdin); }

		
		if(buf[1] == '\0'){		//空行のときにループ脱出
			if(stack_stock() <= 0 && err == 0){
				fprintf(stdout, "Parentheses are correct !! \n");
			}
			else{
				fprintf(stdout, "Parentheses error !! \n");
			}

#ifdef DEBUG
			while(stack_stock() > 0){					//余りを表示
				fprintf(stdout, format, pop());
			}
#endif

			break;
		}
		//2行目以降での改行時，bufのリセット
		else if( buf[i] == '\0' ){	i = 0; 	continue; }
		else{				//改行でないとき，条件判定とスタックを行う。
			if( buf[i] == '{' || buf[i] == '(' || buf[i] == '['){	//始まりの括弧
				push(buf[i]);
			}
			else if( buf[i] == '}' || buf[i] == ']' || buf[i] == ')'){	//終わりの括弧
				if( stack_stock() > 0 ) { 		//始まり括弧がスタックされていれば
					ch = pop();		//とりあえず引っ張ってっ来る
					if( ch == '{' && buf[i] == '}' ){}		//正しければスルー
					else if( ch == '(' && buf[i] == ')'){}	//同上
					else if( ch == '[' && buf[i] == ']'){}	//同上
					else{									//違っていれば，見なかったことにしてエラーを返す。
						push(ch);
						err = 1; 
					}
				}
				else{ err = 1; }				//されていなければエラー
			}
		}
		i++;	//iのインクリメント
	}
	
	return 0;
}