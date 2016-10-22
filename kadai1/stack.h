
//スタック処理に関するヘッダファイル
//J1411 完山 尚葵

stack_type stack[stack_size];
int sp;

//スタックポインタの初期化
void init_stack(){ sp = -1; }
//スタックにデータを格納
void push(stack_type d){
	if( sp < stack_size-1 ){
		stack[++sp] = d;
	}
	else{
		fprintf(stderr, "Error: stack full \n");
		exit(1);
	}
}
//スタック内のデータ数を返す
int stack_stock(){
	return sp+1;
}

//スタックのデータを取り出す
stack_type pop(){
	if( sp >= 0){
		return stack[sp--];
	}
	else{
		fprintf(stderr, "Error : stack empty \n");
	}
}

//スタック内のデータを出力
void print_stack(){
	int i;
	printf("stack data :");
	for(i=0;i<=sp;i++){
		printf(" %d",stack[i]);
	}
	printf("\n");
}