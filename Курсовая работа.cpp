// ��������� �������� ������ ����
// ��������� l2
// ������� l1
#include <iostream>
#include <stdio.h> // ������� ������������ ����� - ������
#include <stdlib.h> // ������� malloc
struct ochered{
	int data;
	struct ochered* next;
}; //  ������� ��������� ������� � ���������� �� ����. �������

typedef struct ochered Ftype; // ����������� ������� �� ��� Ftype

Ftype* CreateFtype(int data){
	Ftype *a;
	a = (Ftype*)malloc(sizeof(Ftype));
	a->data = data;
	a->next = NULL;
	return a;
} // ������� ������ ������� �������

Ftype* AddFtype(Ftype* a,int data){
	while(a->next != NULL){
		a = a->next;
	}
	Ftype* CreatedFtype = (Ftype*)malloc(sizeof(Ftype));
	CreatedFtype->next = NULL;
	CreatedFtype->data = data;
	a->next = CreatedFtype;
	return a->next;
} // ������� ����������� �������� �������. ������������� ���������� ����� ���������� �������� �������.

void PrintFtype(Ftype* uk){
	Ftype* a = uk;
	int i=1;
	printf("�������:\n");
	while(a != NULL){
		printf("�������[%d] %d\n",i,a->data);
		a = a->next;
		i++;
}
printf("\n");
} // ����� ����� ����� ������� � �������

int LengthFtype(Ftype* uk){
	int len = 0;
	if (uk == NULL) return 0;
	else{
		while(uk != NULL){
		uk = uk->next;
		len++;
		}
	return len;
	}
} // ���������� ����� �������

void DeleteAllFtype(Ftype* uk){
	Ftype* a = uk;
	Ftype* buffer = uk;
	do{
		buffer = a->next;
		free(a);
		a = buffer;
	}while(a != NULL);
} // ������� ��� �������� �������, ��� ���� ������ ������

Ftype* DeleteFirstFtype(Ftype* e){
	Ftype* buf = e->next;
	free(e);
	e = buf;
	return e;
} // ������� ������ ������� �������, ��� ���� ������� ������

int readInt(){
	int num =0;
	std::cout<<"������� ����� �����:";
	scanf("%d",&num);
	return num;
} // ������ ������ ����� �����. ���������� ���

Ftype* MenuFtype(){
	int number=-1;
	int mode =0;
	int REMEBMER = 0; // ����������� ���������� ������ ��� 6��� ������
	Ftype* e = NULL;
	Ftype* last = NULL;
	while(1){
	printf("��������� ��������:\n");
	printf("1. ������ ������ � ��������\n");
	printf("2. ������� ������� ������\n");
	printf("3. ��������� ����� �� �������\n");
	printf("4. ������� �������� �������� � ������ �������\n");
	printf("5. ������� ������ �������\n");
	printf("6. ����� ������� �� ������ �������\n");
	printf("7. �������� �������� � ������ �������\n");
	printf("8. �������� ������� � ����� �������\n");
	printf("9. ����������� �������\n");
	printf("10. ��������� ������ � ��������\n\n");
	printf("�������� ����� ����:\n");

	scanf("%d",&number);
	system("cls"); // �������� �������
	
	if (number == 1 && mode == 1) std::cout<<"�� ��� ������ ������ � ��������.\n";
	if (number == 1) mode = 1;
	if (mode ==1){
		if (number ==2 && LengthFtype(e)>0){
				DeleteAllFtype(e);
				e = NULL;
				last = NULL;
		}
		if (number ==3) LengthFtype(e)?std::cout<<"������� �� �����.\n":std::cout<<"������� �����.\n";
		if (LengthFtype(e)>0){
		if (number ==4) std::cout<<"�������� �������� � ������ = "<<e->data<<"\n";
		if (number ==5) e=DeleteFirstFtype(e);
		if (number ==6){
			REMEBMER = e->data;
			std::cout<<"�������� ������� �������� �������� = "<< REMEBMER <<"\n";
			e = DeleteFirstFtype(e);
		}
		if (number ==7) e->data = readInt();
		}
		else if (number>=4 && number<=7) std::cout<< "������. ������� �����.\n";
		if (number ==8) LengthFtype(e)?last=AddFtype(e,readInt()):e = CreateFtype(readInt()); // ���� ����� = 0, �� ���������� �-� ��������� ������ ����, ����� �-� ��������� ����������� �-��
		if (number ==9) PrintFtype(e);
		if (number ==10) return e;
	}
	else std::cout << "�� �� ������ ������ � ��������. ����� 1.\n";
}
} // ���� �������

int main(){
	setlocale(LC_ALL, "Russian"); // ��������� �������� ����� � ������
	
	MenuFtype();
	
	return 0;
}

