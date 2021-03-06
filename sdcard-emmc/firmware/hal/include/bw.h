#ifndef BW_H_
#define BW_H_

#include <bcm2835.h>
#include <device_info.h>

/// write ports
#define BW_PORT_WRITE_DISPLAY_DATA			0x00
#define BW_PORT_WRITE_COMMAND				0x01
#define BW_PORT_WRITE_STARTUPMESSAGE_LINE1	0x08
#define BW_PORT_WRITE_STARTUPMESSAGE_LINE2	0x09
#define BW_PORT_WRITE_STARTUPMESSAGE_LINE3	0x0a
#define BW_PORT_WRITE_STARTUPMESSAGE_LINE4	0x0b
#define BW_PORT_WRITE_CLEAR_SCREEN			0x10
#define BW_PORT_WRITE_MOVE_CURSOR			0x11
#define BW_PORT_WRITE_SET_CONTRAST			0x12
#define BW_PORT_WRITE_SET_BACKLIGHT_TEMP	0x13
#define BW_PORT_WRITE_REINIT_LCD			0x14
#define BW_PORT_WRITE_SET_BACKLIGHT			0x17
#define BW_PORT_WRITE_CHANGE_SLAVE_ADDRESS	0xf0

/// read ports
#define BW_PORT_READ_ID_STRING				0x01
#define BW_PORT_READ_EEPROM_SN				0x02
#define BW_PORT_READ_CURRENT_CONTRAST		0x12
#define BW_PORT_READ_CURRENT_BACKLIGHT		0x13
#define BW_PORT_READ_POWERUP_BACKLIGHT		0x17
#define BW_PORT_READ_BUTTON_SINCE_LAST		0x31
#define BW_PORT_READ_BUTTON_1				0x40
#define BW_PORT_READ_BUTTON_2				0x41
#define BW_PORT_READ_BUTTON_3				0x42
#define BW_PORT_READ_BUTTON_4				0x43
#define BW_PORT_READ_BUTTON_5				0x44
#define BW_PORT_READ_BUTTON_6				0x45

typedef enum
{
	BW_UI_BUTTON1	= 0,	///<
	BW_UI_BUTTON2	= 1,	///<
	BW_UI_BUTTON3	= 2,	///<
	BW_UI_BUTTON4	= 3,	///<
	BW_UI_BUTTON5	= 4,	///<
	BW_UI_BUTTON6	= 5		///<
} bwUiButtons;

#define BW_SPI0			BCM2835_SPI_CS0
#define BW_SPI1			BCM2835_SPI_CS1

#endif /* BW_H_ */
