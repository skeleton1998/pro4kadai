#include <stdio.h>
#include <stdlib.h>
#define Q_size 10				//�L���[�T�C�Y��ݒ�
#define Q_type int				//�L���[�Ɋi�[����f�[�^�̌^���w��
#include "j1411_queue.h"

int main(){
	int i;
	int c;
	int num;	//dequeue����f�[�^��
	
	init_Q();
	
	//������ʂ̏o��
	fprintf(stdout, "Queue size: %d", Q_size);
	fprintf(stdout, "\nPlease enter text:");
	
	//���͂��ꂽ�ꕶ�����C�J�Ƃ����͂����܂œǂݍ��݁C�L���[�Ɋi�[����
	while((c = getchar()) != '\n'){
		enqueue(c);
	}
	
	//�L���[�̔z����̃f�[�^���o�͂���
	fprintf(stdout, "\nFront: %d    Rear: %d", f, r);
	fprintf(stdout, "\nArray Q data:");
	for(i=0; i<count ; i++){
		fprintf(stdout, " %c", Q[i]);
	}
	
	//�L���[�Ɋi�[���ꂽ�f�[�^���w�萔��o���C�o�͂���
	fprintf(stdout, "\n\nPlease enter dequeue number:");
	scanf("%d" , &num);
	fprintf(stdout, "Dequeue data:");
	for(i=0;i<num;i++){
		fprintf(stdout, " %c", dequeue());
	}
	
	//�V�����f�[�^���L���[�Ɋi�[����
	fprintf(stdout, "\n\nPlease enter next text(MAX num:%d):",Q_size - count);
	c = getchar();
	while((c = getchar()) != '\n'){
		enqueue(c);
	}
	
	//�L���[�Ɋi�[���ꂽ�f�[�^�����ׂĎ��o���A�o�͂���
	fprintf(stderr, "Front: %d    Rear: %d", f, r);
	fprintf(stderr, "\nQueue all data:");
	while( count != 0 ){
		fprintf(stderr, " %c", dequeue());
	}
	
	//�L���[�̔z����̃f�[�^���o�͂���
	fprintf(stderr, "\nArray Q data:");
	for(i=0; i<Q_size; i++){
		fprintf(stderr, " %c", Q[i]);
	}
	fprintf(stderr, "\n");
	return 0;
}