Q_type Q[Q_size];			//�L���[��p��
int f, r;

//�L���[�̏�����������֐�
void init_Q(){
	f = 0;
	r = -1;
}
//�L���[�̃f�[�^����Ԃ��֐�(count�̑��)
int stock_Q(){
	if(f-r != 1){	return (( (r + Q_size) - f ) % Q_size) + 1;	}	//�L���[�̃f�[�^����0�o�Ȃ����̏o��
	else{	return 0;	}
}

//�L���[�Ƀf�[�^���i�[����֐�
void enqueue(Q_type d) {
	//�f�[�^�����L���[�̏���𒴂��Ă��Ȃ����̊m�F
	if( stock_Q() < Q_size - 1 ){
		r++;				//���rear���C���N�������g���Ă���
		if( r == Q_size ){	//�f�[�^������ꏊ(��o�b�t�@)�����߂�
			r = 0;
		}
		Q[r] = d;			//�f�[�^������
	}
	else{					//�G���[����
		fprintf(stderr, "Error : queue is full \n");
		exit(1);
	}
}

//�L���[�̃f�[�^�����o���֐�
Q_type dequeue() {
	int i = 0;
	//�f�[�^�������Ă��邩�̊m�F
	if( stock_Q() > 0 ){
		i = f;				//���o���f�[�^�̏ꏊ��ۑ�(tmp)
		f++;				
		if(f == Q_size){	//����Ƀf�[�^�����o���ꏊ(��o�b�t�@)�����߂�
			f = 0;
		}
		
		return Q[i];		//�f�[�^�𑗂�o��
	}
	else{
		fprintf(stderr, "Error : queue is empty \n");
		exit(1);
	}
}

//�L���[�̃f�[�^��\��
void print_Q() {
	while( stock_Q() != 0 ){
		fprintf(stderr, " %c", dequeue());
	}
}