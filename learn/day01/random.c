//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("************* 1. Start Game ************\n");
//	printf("************* 2. Exit Game ************\n");
//	printf("**********************************\n");
//}
//
//
//void game()
//{
//	int num = 0;
//	int guess = 0;
//	num = rand() % (100 - 1 + 1) + 1;
//	while (1)
//	{
//		printf("Please enter your guess (1-100): ");
//		scanf("%d", &guess);
//			if (guess > num)
//				printf("Your guess is too high!\n");
//			else if (guess < num)
//				printf("Your guess is too low!\n");
//			else
//			{
//			printf("Congratulations! You guessed the number %d correctly!\n", num);
//			break;
//			}
//	}
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	while (1)                                     												
//	{                                                 
//		menu();                                   
//		int input = 0;                          
//		printf("Please enter your choice: ");               
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//				game();
//				break;
//			case 2:
//				printf("Exiting the game. Goodbye!\n");
//				return 0;	
//			default:
//				printf("Invalid choice. Please try again.\n");
//				break;
//		}
//	}
//	return 0;
//}
//// 0~RAND_MAX (32767) 0~32767,���Զ���ȡģ%100���õ�0~99���ټ�1���õ�1~100�������
//// Seed the random number generator,����ÿ�ζ����ã�ֻ���ڹ��̿�ʼʱ����һ�Σ�int *p = NULL ��ָ��Ϊ0
////srand()�������ɵ��������α�������ʹ��ʱ����Ϊ���ӣ���֤ÿ�����г���ʱ���ɵ��������ͬ												
////���������ͬ�������ɵ����������Ҳ��ͬ������srand(1234); srand(1234);ÿ�����ɵ���������ж���ͬ
////srand(time(NULL))����ʱ���̫�̣�����������ͬ����������У���Ϊtime()�����ľ�������
////��ε���srand(time(NULL))�ᵼ�����ɵ������������ͬ���ر����ڶ�ʱ���ڣ�ͬһ�룩��ε���ʱ
////�����ڳ���ʼʱ����һ��srand(time(NULL))��Ȼ�����rand()�����������������ݵ�ǰʱ�����ɲ�ͬ�����������