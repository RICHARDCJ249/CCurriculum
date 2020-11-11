/*
 * Copyright (C) ��ĺ����(NightDust) 2020
 * All Rights Reserved
 *
 * Email��lingwangsheng249@gmail.com
 *
 * FileName��CLedDispaly.c
 * CreateTime��2020/11/11 11:05
 * Description:A6 ��LED�������ʾ
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include <windows.h>


typedef struct
{
	char showChar;		//Ҫ��ʾ���ַ�	Ĭ��A
	unsigned char color;//Ҫ��ʾ����ɫ	Ĭ�Ϻ�ɫ
	int showNum;		//Ҫ��ʾ������	Ĭ��0
	int pulseInterval;	//��˸ʱ������	Ĭ�ϲ���˸��0��

}Led;

/// <summary>
/// ����Led�ṹ��
/// </summary>
/// <param name="showChar">��ʾ�õ��ַ�</param>
/// <param name="showNum">��ʾ������</param>
/// <param name="led">ledָ�����</param>
/// <returns>-1: �ڴ�ռ�����쳣 0:�����ɹ�</returns>
int createLed(char showChar, int showNum, Led* led) {
	if (led == NULL)
	{
		printf("Error to create pointer to led");
		return -1;
	}
	led->color = 0x0;
	led->pulseInterval = 0;
	led->showChar = showChar;
	led->showNum = showNum;
	return 0;
}

/// <summary>
/// ����Led��ɫ
/// </summary>
/// <param name="color">Ҫ���õ���ɫ</param>
/// <param name="led">ledָ�����</param>
/// <returns>0:�ɹ� -1:led��ָ�� 1:��ɫ��Χ�쳣</returns>
int setLedColor(unsigned char color, Led* led) {
	if (led != NULL)
	{
		if (color >= 0x00 && color <= 0x0F)
		{
			led->color = color;
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return 1;
	}
}


/// <summary>
/// ���ü����˸ʱ��
/// </summary>
/// <param name="PulseInterval">�����˸ʱ��</param>
/// <param name="led">ledָ�����</param>
/// <returns>0: ���óɹ� 1:����ʧ�� ledָ������</returns>
int setLedPulseInterval(int PulseInterval, Led* led) {
	if (led != NULL)
	{
		led->pulseInterval = PulseInterval;
		return 0;
	}
	else
	{
		return 1;
	}
}

/// <summary>
/// ����������ʾ���ַ�
/// </summary>
/// <param name="showChar">��ʾ���ַ�</param>
/// <param name="led">ledָ�����</param>
/// <returns>0: ���óɹ� 1:����ʧ�� ledָ������</returns>
int setLedChar(char showChar, Led* led) {
	if (led != NULL)
	{
		led->showChar = showChar;
		return 0;
	}
	else
	{
		return 1;
	}
}

/// <summary>
/// ������ʾ������
/// </summary>
/// <param name="showNum">��ʾ������</param>
/// <param name="led">ledָ�����</param>
/// <returns>0: ���óɹ� 1:����ʧ�� ledָ������</returns>
int setLedNum(int showNum, Led* led) {
	if (led != NULL)
	{
		led->showNum = showNum;
		return 0;
	}
	else
	{
		return 1;
	}
}

/// <summary>
/// ��ʾLED
/// </summary>
/// <param name="led">led����</param>
/// <returns>�ɹ�</returns>
int showLed(Led* led) {
	char sColor[8];
	sprintf(sColor, "color %x", led->color);
	system(sColor);
	switch (led->showNum)
	{
	case 0:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 7; i++)
		{
			printf("%c%-6c%c\n", led->showChar, ' ', led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	case 1:
		for (size_t i = 0; i < 9; i++)
		{
			printf("%8c\n", led->showChar);
		}
		break;
	case 2:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%-8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	case 3:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	case 4:
		for (size_t i = 0; i < 4; i++)
		{
			printf("%c%6c%c\n", led->showChar, ' ', led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 4; i++)
		{
			printf("%8c\n", led->showChar);
		}
		break;
	case 5:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%-8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	case 6:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%-8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%c%6c%c\n", led->showChar, ' ', led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	case 7:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 8; i++)
		{
			printf("%8c\n", led->showChar);
		}
		break;
	case 8:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%c%6c%c\n", led->showChar, ' ', led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%c%6c%c\n", led->showChar, ' ', led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	case 9:
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%c%6c%c\n", led->showChar, ' ', led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	default:
		system("color 4");
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%-8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		for (size_t i = 0; i < 3; i++)
		{
			printf("%-8c\n", led->showChar);
		}
		for (size_t i = 0; i < 8; i++)
		{
			printf("%c", led->showChar);
		}
		printf("\n");
		break;
	}
	return 0;
}

int main(void) {
	Led led;
	char c, isShowAll;
	int num = 0;
	printf("Do you want to show all? (Y/N):            ");
	scanf("%c", &isShowAll);
	printf("Please input a char to create led display: ");
	getchar();
	scanf("%c", &c);
	createLed(c, num, &led);
	if (isShowAll == 'Y' || isShowAll == 'y')
	{
		for (int i = 0; i < 10; i++)
		{
			system("cls");
			setLedNum(i, &led);
			setLedColor(i, &led);
			showLed(&led);
			Sleep(1000);
		}
	}
	else
	{
		printf("Please input a num to dispaly led:         ");
		scanf("%d", &num);
		showLed(&led);
	}
	return 0;
}