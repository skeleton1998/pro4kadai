Q_type Q[Q_size];			//�L���[��p��
int f, r, count;			//count : �L���[�̃f�[�^��

//�L���[�̏�����������֐�
void init_Q(){
	f = count = 0;
	r = -1;
}

//�L���[�Ƀf�[�^���i�[����֐�
void enqueue(Q_type d) {
	//�f�[�^�����L���[�̏���𒴂��Ă��Ȃ����̊m�F
	if( count < Q_size ){
		r++;				//���rear���C���N�������g���Ă���
		if( r == Q_size ){	//�f�[�^������ꏊ(��o�b�t�@)�����߂�
			r = 0;
		}
		Q[r] = d;			//�f�[�^������
		count++;			//�f�[�^�����C���N�������g
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
	if( count > 0 ){
		i = f;				//���o���f�[�^�̏ꏊ��ۑ�(tmp)
		f++;				
		if(f == Q_size){	//����Ƀf�[�^�����o���ꏊ(��o�b�t�@)�����߂�
			f = 0;
		}
		count--;			//�f�[�^�����f�N�������g
		return Q[i];		//�f�[�^�𑗂�o��
	}
	else{
		fprintf(stderr, "Error : queue is empty \n");
		exit(1);
	}
}
	