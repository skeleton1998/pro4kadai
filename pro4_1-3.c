
//�X�^�b�N��p�����v���O�����̐������`�F�b�N�v���O����
//j1411 ���R ����

#include <stdio.h>
#include <stdlib.h>
#define stack_size 100			//�X�^�b�N�T�C�Y�̐ݒ�
#define stack_type char			//�X�^�b�N�Ɋi�[����l�̌^��ݒ�
#define format "%c"				//�X�^�b�N���̃f�[�^�o�͎��̃t�H�[�}�b�g
#include "stack.h"				//�X�^�b�N�Ɋւ���ϐ����֐��̓ǂݍ���
#define BUFLEN 100				//�ǂݍ��ޕ�����̍ő咷��ݒ�

/****             pro4_1-3.c               ****/
int main(){
	int ch, chst, err = 0, i = 0;
	char buf[BUFLEN];
	init_stack();				//�X�^�b�N�̏�����
	fprintf(stdout, "Please enter c program : \n");
	
	while(1){
		if( i == 0 ){ fgets(buf, sizeof(buf), stdin); }

		
		if(buf[1] == '\0'){		//��s�̂Ƃ��Ƀ��[�v�E�o
			if(stack_stock() <= 0 && err == 0){
				fprintf(stdout, "Parentheses are correct !! \n");
			}
			else{
				fprintf(stdout, "Parentheses error !! \n");
			}

#ifdef DEBUG
			while(stack_stock() > 0){					//�]���\��
				fprintf(stdout, format, pop());
			}
#endif

			break;
		}
		//2�s�ڈȍ~�ł̉��s���Cbuf�̃��Z�b�g
		else if( buf[i] == '\0' ){	i = 0; 	continue; }
		else{				//���s�łȂ��Ƃ��C��������ƃX�^�b�N���s���B
			if( buf[i] == '{' || buf[i] == '(' || buf[i] == '['){	//�n�܂�̊���
				push(buf[i]);
			}
			else if( buf[i] == '}' || buf[i] == ']' || buf[i] == ')'){	//�I���̊���
				if( stack_stock() > 0 ) { 		//�n�܂芇�ʂ��X�^�b�N����Ă����
					ch = pop();		//�Ƃ肠�������������Ă�����
					if( ch == '{' && buf[i] == '}' ){}		//��������΃X���[
					else if( ch == '(' && buf[i] == ')'){}	//����
					else if( ch == '[' && buf[i] == ']'){}	//����
					else{									//����Ă���΁C���Ȃ��������Ƃɂ��ăG���[��Ԃ��B
						push(ch);
						err = 1; 
					}
				}
				else{ err = 1; }				//����Ă��Ȃ���΃G���[
			}
		}
		i++;	//i�̃C���N�������g
	}
	
	return 0;
}