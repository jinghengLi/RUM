#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
static int FindByName(Contact* pc, char name[]);
static void RelatSelet(Contact* p);
static void ModifySelet(Contact* p, int ret);

//初始化通讯录
void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}



//添加联系人
void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == MAX) {
		printf("通讯录已满，无法继续添加\n");
		return;
	}
	printf("请输入您想添加的联系人姓名:>\n");
	scanf("%s", pc->data[pc->count].name);   //数组是地址
	printf("请输入您想添加的联系人年龄:>\n");
	scanf("%d", &(pc->data[pc->count].age)); //age不是地址是变量，需要传地址
	printf("请输入您想添加的联系人性别:>\n");
	scanf("%s", pc->data[pc->count].gender);
	printf("请输入您想添加的联系人电话:>\n");
	scanf("%s", pc->data[pc->count].tel);
	RelatSelet(pc);
	printf("请输入您想添加的联系人地址:>\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("添加成功\n");
}


//关系选择
static void RelatSelet(Contact* p) {
	int i = 0;
	while(1) {
		printf("****************************************\n");
		printf("************    1.家人     **************\n");
		printf("************    2.同学    **************\n");
		printf("************    3.同事     **************\n");
		printf("************    4.亲戚     **************\n");
		printf("************    5.朋友     **************\n");
		printf("****************************************\n");

		printf("请选择您想添加的联系人关系:>\n");
		scanf("%d", &i);
		switch(i) {
		case 1:
			strcpy(p->data[p->count].relat, "家人");
			break;
		case 2:
			strcpy(p->data[p->count].relat, "同学");
			break;
		case 3:
			strcpy(p->data[p->count].relat, "同事");
			break;
		case 4:
			strcpy(p->data[p->count].relat, "亲戚");
			break;
		case 5:
			strcpy(p->data[p->count].relat, "朋友");
			break;
		default:
			printf("输入错误，请重新输入\n");
			continue; // 继续循环，提示用户重新输入
		}
		break;
	} 
}


//显示全部联系人
void ShowContact(const Contact* pc) {
	assert(pc);
	printf("%-20s\t%-5s\t%-10s\t%-20s\t%-10s\t%-30s\n", "姓名", "年龄", "性别", "电话", "关系", "地址");
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


//删除联系人
void DelContact(Contact* pc) {
	assert(pc);
	int i = 0;
	char name[20] = { 0 };
	if (pc->count == 0) {
		printf("通讯录为空，不能执行删除操作\n");
		return;
	}
	printf("请输入你想删除的联系人姓名:>\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	
	if (ret < MAX) {
		if (ret == -1) {
			printf("你输入的联系人不存在\n");
			return;
		}
		for (i = ret; i < pc->count - 1; i++) {
			pc->data[i] = pc->data[i + 1];
		}
	}
	else
		memset(&pc->data[i], 0, sizeof(Contact));
	pc->count--;
	printf("删除成功");
}


//查找联系人，找到返回下标，没有找到返回-1
static int FindByName(Contact* pc, char name[]) {
	assert(pc);
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

//查找联系人，输入姓名，输出其全部信息
void SearchContact(Contact* pc) {
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0) {
		printf("通讯录为空，不能查找删除操作\n");
		return;
	}
	printf("请输入你想查找的联系人姓名:>\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("你输入的联系人不存在\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-10s\t%-20s\t%-10s\t%-30s\n", "姓名", "年龄", "性别", "电话", "关系", "地址");
		printf("%-20s\t%-5d\t%-10s\t%-20s\t%-10s\t%-30s\n",
			pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].gender,
			pc->data[ret].tel,
			pc->data[ret].relat,
			pc->data[ret].addr);
	}
}


//修改联系人信息
void ModifyContact(Contact* pc) {
	assert(pc);
	char name[20] = { 0 };
	if (pc->count == 0) {
		printf("通讯录为空，不能查找删除操作\n");
		return;
	}
	printf("请输入你想修改的联系人姓名:>\n");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("你输入的联系人不存在\n");
		return;
	}
	else {
		ModifySelet(pc, ret);
	}
}

//修改信息选择
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
		printf("************    1.姓名     **************\n");
		printf("************    2.年龄    **************\n");
		printf("************    3.性别     **************\n");
		printf("************    4.电话    **************\n");
		printf("************    5.关系     **************\n");
		printf("************    6.地址     **************\n");
		printf("************    0.退出     **************\n");
		printf("****************************************\n");
		printf("请选择您想修改的联系人类别:>\n");
		scanf("%d", &i);
		switch (i) {
		case 1:
			printf("您修改的名字为:>");
			scanf("%s", name);
			strcpy(pc->data[ret].name, name);
			break;
		case 2:
			printf("您修改后的年龄为:>");
			scanf("%d", &pc->data[ret].age);
			break;
		case 3:
			printf("您修改后的性别为:>");
			scanf("%s", gender);
			strcpy(pc->data[ret].gender, gender);
			break;
		case 4:
			printf("您修改后的电话号码为:>");
			scanf("%s", tel);
			strcpy(pc->data[ret].tel, tel);
			break;
		case 5:
			printf("您修改后的关系为:>");
			scanf("%s", relat);
			strcpy(pc->data[ret].relat, relat);
			break;
		case 6:
			printf("您修改后的地址为:>");
			scanf("%s", addr);
			strcpy(pc->data[ret].addr, addr);
			break;
		case 0:
			return;
		default:
			printf("输入错误，请重新输入\n");
			continue; // 继续循环，提示用户重新输入
		}
		break;
	}
}

int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((PerInfo*)e1)->age - ((PerInfo*)e2)->age;
}
//按一定条件排序
void SortContact(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PerInfo), cmp_stu_by_age);
	printf("排序成功！\n");
}

