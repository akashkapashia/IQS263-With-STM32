/**
	******************************************************************************
	* File Name          : IQS263.H
	* Description        : This file contains the common defines of the application
	******************************************************************************
	*
	* COPYRIGHT(c) 2017 Akash kapashia
  * Created by Akash kapashia
	******************************************************************************
	*/
/* Define to prevent recursive inclusion -------------------------------------*/


 #ifndef __IQS263_H
 #define __IQS263_H
	 
		 
#define IQS263_ADD              0x44<<1	
#define DEVICE_INFO             0x00
#define SYS_FLAGS               0x01
#define COORDINATES             0x02
#define TOUCH_BYTES             0x03
#define COUNTS                  0x04
#define LTA                     0x05
#define DELTAS                  0x06
#define MULTIPLIERS             0x07
#define COMPENSATION            0x08
#define PROX_SETTINGS           0x09
#define THRESHOLDS              0x0A
#define TIMINGS_AND_TARGETS     0x0B
#define GESTURE_TIMERS          0x0C
#define ACTIVE_CHANNELS         0x0D
#define PROX_SETTINGS0			    0x09


/*	BIT DEFINITIONS FOR IQS263	*/

/*	Bit definitions	*/
/*	System Flags - STATUS	*/
/*	Indicates ATI is busy	*/
#define	ATI_BUSY			0x04
/*	Indicates reset has occurred	*/
#define	SHOW_RESET			0x80
/*	Bit definitions - Event Bytes	*/
#define	PROX_EVENT			    0x01
#define	TOUCH_EVENT			    0x02
#define	SLIDE_EVENT			    0x04
#define	MOVE_EVENT			    0x10
#define	TAP_EVENT			      0x20
#define	FLICKLEFT_EVENT			0x40
#define	FLICKRIGHT_EVENT		0x80

  

/*	Set IQS263 in Projected mode	*/
#define	PROJ_MODE			0x10

/*	Bit definitions - ProxSettings1	*/
/*	0-Streaming Mode, 1-Event Mode	*/
#define	EVENT_MODE			0x40


/*	Delays	*/
#define HANDSHAKE_DELAY_HOLD	11		/*	11ms	*/
#define HANDSHAKE_DELAY_SET		200		/*	200µs	*/

/*	Acknowledge that chip was reset	*/
#define ACK_RESET			0x80
void Init_IQS263(void);
void Monotor_Touch_IQS263(void);
void IQS263_READ_TOUCH_Events(void);
		 





		 
		 
		 
 
  		 
#endif
		 