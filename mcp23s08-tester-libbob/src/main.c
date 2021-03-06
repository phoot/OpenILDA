/* Copyright (C) 2014 by Arjan van Vught <pm @ http://www.raspberrypi.org/forum/>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//
#include <mcp23s08.h>

static char pins[8] = {
		MCP23S08_PIN_GP7, \
		MCP23S08_PIN_GP6, \
		MCP23S08_PIN_GP5, \
		MCP23S08_PIN_GP4, \
		MCP23S08_PIN_GP3, \
		MCP23S08_PIN_GP2, \
		MCP23S08_PIN_GP1, \
		MCP23S08_PIN_GP0 };

static char patterns[10][8] = {
	{ 0,0,0,0,0,0,0,0 },	//0
	{ 1,1,1,1,1,1,1,1 },	//1
	{ 1,0,0,0,0,0,0,0 },	//2
	{ 0,1,0,0,0,0,0,0 },	//3
	{ 0,0,1,0,0,0,0,0 },	//4
	{ 0,0,0,1,0,0,0,0 },	//5
	{ 0,0,0,0,1,0,0,0 },	//6
	{ 0,0,0,0,0,1,0,0 },	//7
	{ 0,0,0,0,0,0,1,0 },	//8
	{ 0,0,0,0,0,0,0,1 },	//9
};

static int loops [2][12] = {
	{ 0,1, -1 },
	{ 0,2,3,4,5,6,7,8,9,0,1, -1 }
};

void show_pattern(device_info_t *device_info, int pattern) {
	int x;
	char pin;

	
	printf("pattern : %d\t", pattern);
	for (x = 0; x < sizeof(pins) ; x++) {
		pin = patterns[pattern][x];
		printf("%d", pin);
		if (pin)
			mcp23s08_gpio_set(device_info, pins[x]);
		else
			mcp23s08_gpio_clr(device_info, pins[x]);
	}
	
	printf("\n");

	return;
}

void show_loop(device_info_t *device_info, int loop, int secs) {
	int pattern;
	int loopIndex = 0;

	printf("loop : %d\n", loop);

	while (loops[loop][loopIndex] != -1) {
		pattern = loops[loop][loopIndex];
		show_pattern(device_info, pattern);
		sleep(1);
		loopIndex++;
	}

	return;
}

unsigned int slave_address = MCP23S08_DEFAULT_SLAVE_ADDRESS;
unsigned int chip_select = 0;

int main(int argc, char **argv) {
	device_info_t device_info;

	while ((argc > 1) && (argv[1][0] == '-')) {
		switch (argv[1][1]) {
		case 'a':
			sscanf (&argv[1][2], "%x", &slave_address);
			break;
		case 'c':
			sscanf (&argv[1][2], "%d", &chip_select);
			break;
		default:
			fprintf(stderr, "Warning: Unsupported argument \"%s\"!\n", argv[1]);
			exit(1);
		}
		++argv;
		--argc;
	}

	device_info.slave_address = slave_address;
	device_info.chip_select = chip_select;

	if (mcp23s08_start(&device_info) != MCP23S08_OK) {
		fprintf(stderr,"Cannot start mcp23s08_start\n");
		exit(EXIT_FAILURE);
	}

	printf("slave address : 0x%x\n", device_info.slave_address);
	printf("chip select   : %.1d\n", device_info.chip_select);

	int x;
	for (x = 0 ; x < sizeof(pins) ; x++ ){
		mcp23s08_gpio_fsel(&device_info, pins[x], MCP23S08_FSEL_OUTP);
	}

	for(;;)
		show_loop(&device_info, 1, 1);

	mcp23s08_end();

	return 0;

}
