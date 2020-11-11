/*
 * Copyright (C) 陈暮尘·(NightDust) 2020
 * All Rights Reserved
 *
 * Email：lingwangsheng249@gmail.com
 *
 * FileName：CLedDispaly.c
 * CreateTime：2020/11/11 11:05
 * Description:A6 仿LED数码的显示
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include <windows.h>


typedef struct
{
	char showChar;		//要显示的字符	默认A
	unsigned char color;//要显示的颜色	默认黑色
	int showNum;		//要显示的数字	默认0
	int pulseInterval;	//闪烁时长与间隔	默认不闪烁（0）

}Led;

/// <summary>
/// 创建Led结构体
/// </summary>
/// <param name="showChar">显示用的字符</param>
/// <param name="showNum">显示的数字</param>
/// <param name="led">led指针对象</param>
/// <returns>-1: 内存空间分配异常 0:创建成功</returns>
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
/// 设置Led颜色
/// </summary>
/// <param name="color">要设置的颜色</param>
/// <param name="led">led指针对象</param>
/// <returns>0:成功 -1:led空指针 1:颜色范围异常</returns>
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
/// 设置间隔闪烁时间
/// </summary>
/// <param name="PulseInterval">间隔闪烁时间</param>
/// <param name="led">led指针对象</param>
/// <returns>0: 设置成功 1:设置失败 led指针对象空</returns>
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
/// 设置用于显示的字符
/// </summary>
/// <param name="showChar">显示的字符</param>
/// <param name="led">led指针对象</param>
/// <returns>0: 设置成功 1:设置失败 led指针对象空</returns>
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
/// 设置显示的数字
/// </summary>
/// <param name="showNum">显示的数字</param>
/// <param name="led">led指针对象</param>
/// <returns>0: 设置成功 1:设置失败 led指针对象空</returns>
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
/// 显示LED
/// </summary>
/// <param name="led">led对象</param>
/// <returns>成功</returns>
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