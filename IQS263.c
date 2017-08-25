/**
	******************************************************************************
	* File Name          : IQS263.c
	* Description        : This file contains the common defines of the application
	******************************************************************************
	*
	* COPYRIGHT(c) 2017 Akash kapashia
        * Created by Akash kapashia
	******************************************************************************
*/


#include "IQS263.h"
#include "stm32l0xx_hal.h"


static int PROX_THRESHOLD	 = 0x10; //0x10
static int TOUCH_THRESHOLD = 0x20;
static int TOUCH_THRESHOLD_CH1 = 0x20; //0x20
static int TOUCH_THRESHOLD_CH2 = 0x20; //0x20
static int TOUCH_THRESHOLD_CH3 = 0x20; //0x20
static int MOVEMENT_THRESHOLD = 0x03;
static int RESEED_BLOCK = 0x00;
static int HALT_TIME = 0x00;
static int I2C_TIMEOUT = 0x04;



uint8_t CH1_Event=0;
uint8_t CH2_Event=0;
uint8_t CH3_Event=0;
uint8_t IQS263_Threshold[8];

extern I2C_HandleTypeDef  hi2cxt;


/**
 *
 * @param NONE
 * @return NONE
 
*/
void Init_IQS263( )
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */

	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	/*Configure GPIO pin : SD_CS_Pin */
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
  	uint8_t data_buffer[8]={0};
	 HAL_Delay(10);
	
	
	/*....................READING SYSTEM FLAGS..........................*/
	 while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
	
		HAL_I2C_Mem_Read( &hi2cxt, IQS263_ADD, (uint8_t)SYS_FLAGS, I2C_MEMADD_SIZE_8BIT,  data_buffer, 2,50);
		while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 
	
	
	/*....................READING DEVICE INFO..........................*/
	 while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
		
		HAL_I2C_Mem_Read(&hi2cxt, IQS263_ADD,( uint8_t ) DEVICE_INFO, I2C_MEMADD_SIZE_8BIT,  &data_buffer[0],2,	70);
		while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 
	
		/*....................READING ACTIVE CHANNELS..........................*/
	
		while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
			
		HAL_I2C_Mem_Read( &hi2cxt, IQS263_ADD, ACTIVE_CHANNELS, I2C_MEMADD_SIZE_8BIT,  data_buffer, 1,60);
		while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 
 
		/*....................READING THRESHOLDS..........................*/
		
		while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
 
		HAL_I2C_Mem_Read( &hi2cxt, IQS263_ADD, THRESHOLDS, I2C_MEMADD_SIZE_8BIT,  IQS263_Threshold, 8,60);
		while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 
	
		/*....................WRITING THRESHOLDS..........................*/

	IQS263_Threshold[0]= PROX_THRESHOLD	  ; //0x10
	IQS263_Threshold[1]= TOUCH_THRESHOLD  ;
	IQS263_Threshold[2]= TOUCH_THRESHOLD_CH1  ; //0x20
	IQS263_Threshold[3]= TOUCH_THRESHOLD_CH2  ; //0x20
	IQS263_Threshold[4]= TOUCH_THRESHOLD_CH3  ; //
	IQS263_Threshold[5]= 14  ; //
	IQS263_Threshold[6]= HALT_TIME ;
	IQS263_Threshold[7]=250;
		
		while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
		
		HAL_I2C_Mem_Write( &hi2cxt, IQS263_ADD, THRESHOLDS, I2C_MEMADD_SIZE_8BIT,  IQS263_Threshold, 8,60);
	  while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 	
		while (HAL_I2C_IsDeviceReady(&hi2cxt, IQS263_ADD, 10, 300) == HAL_TIMEOUT);
	
		/*....................READING THRESHOLDS..........................*/
		 
		while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);

		HAL_I2C_Mem_Read( &hi2cxt, IQS263_ADD, THRESHOLDS, I2C_MEMADD_SIZE_8BIT,  IQS263_Threshold, 8,60);
	 	while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 	
		while (HAL_I2C_IsDeviceReady(&hi2cxt, IQS263_ADD, 10, 300) == HAL_TIMEOUT);
	
		/*....................READING PROXI SETTING..........................*/

		 while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);

	   HAL_I2C_Mem_Read( &hi2cxt, IQS263_ADD, PROX_SETTINGS, I2C_MEMADD_SIZE_8BIT,  data_buffer, 5,60);
	   while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		 {
		 } 	
		 while (HAL_I2C_IsDeviceReady(&hi2cxt, IQS263_ADD, 10, 300) == HAL_TIMEOUT);
	
		/*....................WRITING PROXI SETTING..........................*/

	  while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
			 
		  data_buffer[0]=0;
			data_buffer[2]=8;
		
		HAL_I2C_Mem_Write( &hi2cxt, IQS263_ADD, PROX_SETTINGS, I2C_MEMADD_SIZE_8BIT,  data_buffer, 5,	60);
	 while (HAL_I2C_GetState(&hi2cxt) != HAL_I2C_STATE_READY)
		{
		} 
		while (HAL_I2C_IsDeviceReady(&hi2cxt, IQS263_ADD, 10, 300) == HAL_TIMEOUT);
	
		
}

/**
 *
 * @param NONE
 * @return NONE
 
*/


void IQS263_READ_TOUCH_Events(){
  
	uint8_t data[2]={0};  
/*....................READING TOUCH EVENTS..........................*/

	while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);

		HAL_I2C_Mem_Read(&hi2cxt, IQS263_ADD, TOUCH_BYTES, I2C_MEMADD_SIZE_8BIT,data,1,70);
	
		
	  CH1_Event=data[0]&0x02;
    CH2_Event=data[0]&0x04;
    CH3_Event=data[0]&0x08;
	
}
