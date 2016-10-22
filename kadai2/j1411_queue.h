Q_type Q[Q_size];			//キューを用意
int f, r, count;			//count : キューのデータ数

//キューの初期化をする関数
void init_Q(){
	f = count = 0;
	r = -1;
}

//キューにデータを格納する関数
void enqueue(Q_type d) {
	//データ数がキューの上限を超えていないかの確認
	if( count < Q_size ){
		r++;				//先にrearをインクリメントしてから
		if( r == Q_size ){	//データを入れる場所(環状バッファ)を決める
			r = 0;
		}
		Q[r] = d;			//データを入れる
		count++;			//データ数をインクリメント
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
	if( count > 0 ){
		i = f;				//取り出すデータの場所を保存(tmp)
		f++;				
		if(f == Q_size){	//次回にデータを取り出す場所(環状バッファ)を決める
			f = 0;
		}
		count--;			//データ数をデクリメント
		return Q[i];		//データを送り出す
	}
	else{
		fprintf(stderr, "Error : queue is empty \n");
		exit(1);
	}
}
	