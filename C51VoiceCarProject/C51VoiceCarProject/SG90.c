#include "SG90.h"

/********************************��������****************************************/
int cnt;
int angle;

/******************************************************************************/
/* ��������  : Timer0_Init      	        		  	      	               	  */
/* ��������  : ��ʼ��Time0��ʱ�������Զ�ʱ500΢�룬ͨ���жϿ���PWM����ռ�ձ�	  */	
/* �������  : ��	                                                          */
/* ��������  : ��					                       		              */
/* ����ֵ    : ��			                                                  */
/******************************************************************************/
void Timer0_Init()		
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x33;		//���ö�ʱ��ֵ
	TH0 = 0xFE;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
}

/******************************************************************************/
/* ��������  : SG90_Init      	        	  	      	    	           	  */
/* ��������  : ��ת�����90��λ��,��ʼ����ʱ���������						  */	
/* �������  : ��	                                                          */
/* ��������  : ��					                       		              */
/* ����ֵ    : ��			                                                  */
/******************************************************************************/
void SG90_Init()
{
	angle = MIDDLE;
	cnt = 0;
}

/******************************************************************************/
/* ��������  : Shake_Head_Left      	        	  	      	               	  */
/* ��������  : ��ת�����180��λ��											  */	
/* �������  : ��	                                                          */
/* ��������  : ��					                       		              */
/* ����ֵ    : ��			                                                  */
/******************************************************************************/
void Shake_Head_Left()
{
	angle = LEFT;
	cnt = 0;
}

/******************************************************************************/
/* ��������  : Shake_Head_Left      	        	  	      	               	  */
/* ��������  : ��ת�����0��λ��												  */	
/* �������  : ��	                                                          */
/* ��������  : ��					                       		              */
/* ����ֵ    : ��			                                                  */
/******************************************************************************/
void Shake_Head_Right()
{
	angle = RIGHT;
	cnt = 0;
}

/******************************************************************************/
/* ��������  : Shake_Head_Left      	        	  	      	               	  */
/* ��������  : ��ת�����90��λ��											  */	
/* �������  : ��	                                                          */
/* ��������  : ��					                       		              */
/* ����ֵ    : ��			                                                  */
/******************************************************************************/
void Shake_Head_Middle()
{
	angle = MIDDLE;
	cnt = 0;
}

/******************************************************************************/
/* ��������  : Time0_Handle      	        	  	      	               	  */
/* ��������  : ��ʱ���жϴ���������ģ��PWM��									  */	
/* �������  : ��	                                                          */
/* ��������  : ��					                       		              */
/* ����ֵ    : ��			                                                  */
/******************************************************************************/
void Time0_Handle() interrupt 1
{
	cnt++;
	TL0 = 0x33;		//���ö�ʱ��ֵ
	TH0 = 0xFE;		//���ö�ʱ��ֵ
	if(cnt < angle)
	{
		sg_90 = HIGH;
	}
	else
	{
		sg_90 = LOW;
	}
	if(cnt == 40)
	{
		cnt = 0;
		sg_90 = HIGH;
	}
}