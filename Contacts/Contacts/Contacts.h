#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 200

typedef struct PerInfo {            //定义联系人信息结构体
	char name[20];
	int age;
	char gender[10];
	char tel[20];
	char relat[10];
	char addr[30];
} PerInfo;


typedef struct Contact {       //通讯录结构体
	PerInfo data[MAX];   //存放联系人信息
	int count;        //记录当前通讯录中实际人数
} Contact;


//初始化通讯录
void InitContact(Contact* pc );

void AddContact(Contact* pc);
//显示全部联系人
void ShowContact(const Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);


//排序联系人
void SortContact(Contact* pc);


