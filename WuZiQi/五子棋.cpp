#include <iostream>
using namespace std;

void QiPanInit(char *a);
void QiPanPrt(char A[][9]);
int WinOrLose(char A[][9], char b);
int main(void)
{
	int flag;
	char qipan[9][9]; //���ڴ洢����
	char qizi[2] = { 'o', '@' }; //���ӣ�o�������ӣ�@��
	int i = 0;//�غ��� �����ж��ǰ׷����ӻ��Ǻڷ�����
	QiPanInit(&qipan[0][0]);
	cout << "   ˫��������" << endl;
	cout << "��Ϸ����" << endl
		<< "1.�ֻغ��ƣ��׷������ӣ�" << endl
		<< "2.���ӷ�ʽΪ�������ӵ��С��У��кš��кž���1��ʼ����" << endl
		<<"3.�ȴﵽ���������һ��ʤ����" << endl;
	QiPanPrt(qipan);
	
	while (i >= 0){ //������ѭ����ֱ������Ӯ����
		int hang=0, lie=0;
		if (i % 2 == 0){
			cout << "�׷�����" << endl;
			cout << "�������ӵ��С���" << endl;
			cin >> hang >> lie;
			if (hang > 9 || hang < 1 || lie>9 || lie < 1 || qipan[hang][lie] != '+'){
				cout << "������С������󣬻��߸õ��������ӣ����������룡" << endl; //û��i++,�غ������� ѭ�����������ǵ�ǰ�غ�
			}else{
				qipan[hang-1][lie-1] = qizi[0]; //�滻Ϊ����
				flag = WinOrLose(qipan, qizi[0]);
				if (flag == 1) {
					cout << "�׷�ʤ��" << endl << endl;
					QiPanPrt(qipan);
					system("pause");
					return 0;
				}else if (flag == 0){
					QiPanPrt(qipan);
					i++;
				}
				else if (flag == 2){
					cout << "����������ƽ�֣�" << endl << endl;
					system("pause");
					return 0;
				}
			}
		}else{
			cout << "�ڷ�����" << endl;
			cout << "�������ӵ��С���" << endl;
			cin >> hang >> lie;
			if (hang > 9 || hang < 1 || lie>9 || lie < 1 || qipan[hang][lie] != '+'){
				cout << "������С������󣬻��߸õ��������ӣ����������룡" << endl; //û��i++,�غ������� ѭ�����������ǵ�ǰ�غ�
			}
			else{
				qipan[hang-1][lie-1] = qizi[1]; //�滻Ϊ����
				flag = WinOrLose(qipan, qizi[1]);
				if (flag == 1) {
					cout << "�ڷ�ʤ��" << endl << endl;
					QiPanPrt(qipan);
					system("pause");
					return 0;
				}
				else if (flag == 0){
					//��������
					QiPanPrt(qipan);
					i++;
				}
				else if (flag == 2){
					cout << "����������ƽ�֣�" << endl << endl;
					system("pause");
					return 0;
				}
			}
		}
	}

	return 0;
}

void QiPanInit(char *a) //��ʼ������
{
	int i, j;
	for (i = 0; i <= 9; i++){

		for (j = 0; j <= 9; j++){
			*a = '+';
			a++;
		}
	}
}

void QiPanPrt(char A[][9]) //�������
{
	int i,j;
	for (i = 0; i < 9; i++){

		for (j = 0; j < 9; j++){			
			cout << A[i][j] << " ";			
		}
		cout << i+1 << endl; //�к�
	}
	cout << "1 2 3 4 5 6 7 8 9"<<endl     //�к�
		 <<"-------------------"<<endl; //���̷ֽ���
}

int WinOrLose(char A[][9],char b) //��������Ϣ�͵�ǰ�����ӽ����������ж���Ӯ
{
	int i,j;
	char const* p;  //pΪconst����֤�������жϹ����ж������������޸�
	/*
	�������ҡ��������±������̣��������Ӻ͵�ǰ����һ������������ң������£�Ʋ���£��������ж��Ƿ�����������
	1.��Ϊ�������ҡ��������±������̣�������֮ǰ�����ӣ�λ��Ŀǰ���ӵ����Ϸ�λ���Ѿ��б����
	  ���Բ���Ҫ�жϺ����������ϣ�Ʋ���ϣ��������Ƿ���������
    2.�����µ������ж�����Ϊ����5��5���򣨹��˸����򲻿������������飩
	  Ʋ���µ������ж�����Ϊ����5��5����
	  �����µ������ж�����Ϊ�ϰ�����
	  �����ҵ������ж�����Ϊ�������
	*/
	p = &A[0][0]; //������������
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			if (*p == b){
				//�ҵ����ӿ�ʼ�жϣ��������鷵��ֵ1��û�з���ֵ0				
				//������
				if (*(p + 10) == b && *(p + 20) == b && *(p + 30) == b && *(p + 40) == b) return 1;
			}
			p++;
		}
		p++;
		p++;
		p++;
		p++;
		//pָ����һ�п�ͷ
	}

	p = &A[4][0]; //������������
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			//Ʋ����
			if (*(p + 8) == b && *(p + 16) == b && *(p + 24) == b && *(p + 32) == b) return 1;
		}
		p++;
		p++;
		p++;
		p++;
	}

	p = &A[0][0]; //�����ϰ�����
	for (i = 0; i < 5; i++){
		for (j = 0; j < 9; j++){
			//������
			if (*(p + 9) == b && *(p + 18) == b && *(p + 27) == b && *(p + 36) == b) return 1;
		}
	}

	p = &A[0][0]; //�����������
	for (i = 0; i < 9; i++){
		for (j = 0; j < 5; j++){
			//������
			if (*(p + 1) == b && *(p + 2) == b && *(p + 3) == b && *(p + 4) == b) return 1;
		}
		p++;
		p++;
		p++;
		p++;
	}

	int count=0;
	p = &A[0][0];
	for (i = 0; i < 80; i++){		
			if (*p == '+') count++;
			p++;
	}
	if (count!=0) {
		//ɶҲû��
		return 0;
	}else{
		//��������
		return 2;
	}
		
}