
//スタックを用いた逆ポーランド電卓
//J1411 完山 尚葵

#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type int
#define format "%d "

#include "stack.h"	//スタックに関する変数＆関数の読み込み

//逆ポーランド電卓の定数の定義
#define RET 0
#define NUM 1
#define PLUS 2
#define MINUS 3
#define MULT 4
#define DIV 5
#define OTHER 6


//キーボード入力された情報を取り込む
int gettoken(int *num){
	int c,n;

	//スペースまたはタブ以外が入力されるまで待つ	
	//（スペースまたはタブが入力されたら何もしない）
	while((c = getchar()) == ' ' || c == '\t'){
		;
	}

	//スペースまたはタブ以外が入力された場合
	//（変数cに，入力された文字のコードが格納されている）
	switch(c){
		//数字が入力されていた場合
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			
			n = c- '0';		//入力された数字を文字コードから数値に変換
			while(1){		//次に入力された文字が数字の場合，処理を続ける
				c = getchar();				//次に入力された文字を格納
				if('0' <= c && c <= '9'){	//続けて数字が入力されていた場合
					n = 10*n + c- '0';		//入力された数字（2桁以上）をnに格納
				}
				else{						//次に入力された文字が数字でなかった場合
					break;
				}
			}
			*num = n;		//nの値をポインタnumが指す場所に格納する
			return NUM;	//数字が入力されたことを返す

		case '+':
			return PLUS;	//「+」が入力されたことを返す
		
		case '-':
			return MINUS;	//「-」が入力されたことを返す

		case '*':
			return MULT;	//「*」が入力されたことを返す

		case '/':
			return DIV;		//「/」が入力されたことを返す
			
		case '\n':			//改行が入力されたことを返す
			return RET;

		default:			//上記のもの以外が入力されたことを返す
			return OTHER;
	}
}


int main(){
	int token, num, x;


	token = gettoken(&num);		//最初に入力された文字のIDをtokenに格納する
	
	init_stack();				//スタックを初期化
	
	while(token != RET){		//改行が入力されるまで処理を続ける
		switch(token){
			case NUM:			//数字が入力されていた場合
				push(num);		//スタックに格納
				break;

			case PLUS:				//「+」が入力されていた場合
				push(pop()+pop());	//1回目に取り出した値と2回目に取り出した値を加算し，スタックに格納
				break;

			case MINUS:				//「-」が入力されていた場合
				x= pop();			//1回目に取り出した値（スタックの一番上にある値）を格納
				push(pop() - x);	//2回目に取り出した値から，1回目の値を引いて，スタックに格納
				break;

			case MULT:					//「*」が入力されていた場合
				push(pop() * pop());	//1回目に取り出した値と2回目に取り出した値を乗算し，スタックに格納
				break;

			case DIV:					//「/」が入力されていた場合
				x= pop();				//1回目に取り出した値（スタックの一番上にある値）を格納
				if(x != 0){				//取り出した値が0でない場合
					push(pop()/x);		//2回目に取り出した値を，1回目に取り出した値で割り，スタックに格納
					break;
				}
				else{					//1回目に取り出した値が0だった場合（0で割り算してしまう場合）
					fprintf(stderr, "Error: zero devide\n");	//エラー内容を出力する
					exit(1);									//プログラムを終了させる
				}

			case OTHER:				//数字や四則演算子，改行でないものが入力された場合
				fprintf(stderr, "Error: illegal character\n");	//エラー内容を出力する
				exit(1);										//プログラムを終了させる
		}
		
		print_stack();				//スタックに格納されているデータを出力する
		token = gettoken(&num);		//次に入力された文字のIDをtokenに格納する
	}

	
	//入力された，全ての文字列を読み，演算が終わった場合

	if(stack_stock() == 1){					//スタック内のデータが1つだけの場合
		fprintf(stderr,"\nFinal data:%5d\n", pop());		//スタック内のデータを出力
	}
	else{									//スタック内のデータが2つ以上の場合
		fprintf(stderr, "Error: Expression syntax\n");	//エラー内容を出力
		exit(1);										//プログラムを終了させる
	}
}