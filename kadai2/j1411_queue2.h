Q_type Q[Q_size];			//キューを用意
int f, r;

//キューの初期化をする関数
void init_Q(){
	f = 0;
	r = -1;
}
//キューのデータ数を返す関数(countの代替)
int stock_Q(){
	if(f-r != 1){	return (( (r + Q_size) - f ) % Q_size) + 1;	}	//キューのデータ数が0出ない時の出力
	else{	return 0;	}
}

//キューにデータを格納する関数
void enqueue(Q_type d) {
	//データ数がキューの上限を超えていないかの確認
	if( stock_Q() < Q_size - 1 ){
		r++;				//先にrearをインクリメントしてから
		if( r == Q_size ){	//データを入れる場所(環状バッファ)を決める
			r = 0;
		}
		Q[r] = d;			//データを入れる
	}
	else{					//エラー処理
		fprintf(stderr, "Error : queue is full \n");
		exit(1);
	}
}

//キューのデータを取り出す関数
Q_type dequeue() {
	int i = 0;
	//データが入っているかの確認
	if( stock_Q() > 0 ){
		i = f;				//取り出すデータの場所を保存(tmp)
		f++;				
		if(f == Q_size){	//次回にデータを取り出す場所(環状バッファ)を決める
			f = 0;
		}
		
		return Q[i];		//データを送り出す
	}
	else{
		fprintf(stderr, "Error : queue is empty \n");
		exit(1);
	}
}

//キューのデータを表示
void print_Q() {
	while( stock_Q() != 0 ){
		fprintf(stderr, " %c", dequeue());
	}
}