#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
static int FindByName(Contact* pc, char name[]);
static void RelatSelet(Contact* p);
static void ModifySelet(Contact* p, int ret);

//��ʼ��ͨѶ¼
void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}



//�����ϵ��
void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == MAX) {
		printf("ͨѶ¼�������޷��������\n");
		return;
	}
	printf("������������ӵ���ϵ������:>\n");
	scanf("%s", pc->data[pc->count].name);   //�����ǵ�ַ
	printf("������������ӵ���ϵ������:>\n");
	scanf("%d", &(pc->data[pc->count].age)); //age���ǵ�ַ�Ǳ�������Ҫ����ַ
	printf("������������ӵ���ϵ���Ա�:>\n");
	scanf("%s", pc->data[pc->count].gender);
	printf("������������ӵ���ϵ�˵绰:>\n");
	scanf("%s", pc->data[pc->count].tel);
	RelatSelet(pc);
	printf("������������ӵ���ϵ�˵�ַ:>\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("��ӳɹ�\n");
}


//��ϵѡ��
static void RelatSelet(Contact* p) {
	int i = 0;
	while(1) {
		printf("****************************************\n");
		printf("************    1.����     **************\n");
		printf("************    2.ͬѧ    **************\n");
		printf("************    3.ͬ��     **************\n");
		printf("************    4.����     **************\n");
		printf("************    5.����     **************\n");
		printf("****************************************\n");

		printf("��ѡ��������ӵ���ϵ�˹�ϵ:>\n");
		scanf("%d", &i);
		switch(i) {
		case 1:
			strcpy(p->data[p->count].relat, "����");
			break;
		case 2:
			strcpy(p->data[p->count].relat, "ͬѧ");
			break;
		case 3:
			strcpy(p->data[p->count].relat, "ͬ��");
			break;
		case 4:
			strcpy(p->data[p->count].relat, "����");
			break;
		case 5:
			strcpy(p->data[p->count].relat, "����");
			break;
		default:
			printf("�����������������\n");
			continue; // ����ѭ������ʾ�û���������
		}
		break;
	} 
}


//��ʾȫ����ϵ��
void ShowContact(const Contact* pc) {
	assert(pc);
	printf("%-20s\t%-5s\t%-10s\t%-20s\t%-10s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ϵ", "��ַ");
	for (int i = 0; i < pc->count; i++) {
		printf("%-20s\t%-5d\t%-10s\t%-20s\t%-10s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].gender,
			pc->data[i].tel,
			pc->data[i].relat,
			pc->data[i].addr);
	}
}


//ɾ����ϵ��
void DelContact(Contact* pc) {
	assert(pc);
	int i = 0;
	char name[20] = { 0 };
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ�գ�����ִ��ɾ������\n");
		return;
	}
	printf("����������ɾ������ϵ������:>\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	
	if (ret < MAX) {
		if (ret == -1) {
			printf("���������ϵ�˲�����\n");
			return;
		}
		for (i = ret; i < pc->count - 1; i++) {
			pc->data[i] = pc->data[i + 1];
		}
	}
	else
		memset(&pc->data[i], 0, sizeof(Contact));
	pc->count--;
	printf("ɾ���ɹ�");
}


//������ϵ�ˣ��ҵ������±꣬û���ҵ�����-1
static int FindByName(Contact* pc, char name[]) {
	assert(pc);
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

//������ϵ�ˣ����������������ȫ����Ϣ
void SearchContact(Contact* pc) {
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ�գ����ܲ���ɾ������\n");
		return;
	}
	printf("������������ҵ���ϵ������:>\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("���������ϵ�˲�����\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-10s\t%-20s\t%-10s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ϵ", "��ַ");
		printf("%-20s\t%-5d\t%-10s\t%-20s\t%-10s\t%-30s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].gender,
			pc->data[ret].tel,
			pc->data[ret].relat,
			pc->data[ret].addr);
	}
}


//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc) {
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ�գ����ܲ���ɾ������\n");
		return;
	}
	printf("�����������޸ĵ���ϵ������:>\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("���������ϵ�˲�����\n");
		return;
	}
	else {
		ModifySelet(pc, ret);
	}
}

//�޸���Ϣѡ��
static void ModifySelet(Contact* pc,int ret) {
	int i = 0;
	char name[20];
	int age = 0;
	char gender[10];
	char tel[20];
	char relat[10];
	char addr[30];
	while (1) {
		printf("****************************************\n");
		printf("************    1.����     **************\n");
		printf("************    2.����    **************\n");
		printf("************    3.�Ա�     **************\n");
		printf("************    4.�绰    **************\n");
		printf("************    5.��ϵ     **************\n");
		printf("************    6.��ַ     **************\n");
		printf("************    0.�˳�     **************\n");
		printf("****************************************\n");
		printf("��ѡ�������޸ĵ���ϵ�����:>\n");
		scanf("%d", &i);
		switch (i) {
		case 1:
			printf("���޸ĵ�����Ϊ:>");
			scanf("%s", name);
			strcpy(pc->data[ret].name, name);
			break;
		case 2:
			printf("���޸ĺ������Ϊ:>");
			scanf("%d", &pc->data[ret].age);
			break;
		case 3:
			printf("���޸ĺ���Ա�Ϊ:>");
			scanf("%s", gender);
			strcpy(pc->data[ret].gender, gender);
			break;
		case 4:
			printf("���޸ĺ�ĵ绰����Ϊ:>");
			scanf("%s", tel);
			strcpy(pc->data[ret].tel, tel);
			break;
		case 5:
			printf("���޸ĺ�Ĺ�ϵΪ:>");
			scanf("%s", relat);
			strcpy(pc->data[ret].relat, relat);
			break;
		case 6:
			printf("���޸ĺ�ĵ�ַΪ:>");
			scanf("%s", addr);
			strcpy(pc->data[ret].addr, addr);
			break;
		case 0:
			return;
		default:
			printf("�����������������\n");
			continue; // ����ѭ������ʾ�û���������
		}
		break;
	}
}

int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((PerInfo*)e1)->age - ((PerInfo*)e2)->age;
}
//��һ����������
void SortContact(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PerInfo), cmp_stu_by_age);
	printf("����ɹ���\n");
}

