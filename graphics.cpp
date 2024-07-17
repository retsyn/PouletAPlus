/*
 * graphics.cpp
 */

#include <Arduboy2.h>
#include "graphics.h"

// Title elements
const unsigned char PROGMEM smallpoulet[] =
{
// width, height,
56, 40,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x60, 0x20, 0xb0, 0x98, 0x08, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x0c, 0xf8, 0xc0, 0x60, 0x20, 0xa0, 0xa0, 0x20, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xf8, 0x0c, 0x64, 0xf4, 0xf4, 0xf4, 0xf4, 0xe4, 0xec, 0xe8, 0xec, 0xe4, 0xe6, 0xf3, 0xf9, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf8, 0xf8, 0x7d, 0x78, 0x72, 0xc7, 0x1f, 0x7f, 0x7f, 0x1f, 0xc6, 0x70, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x03, 0x02, 0x06, 0x0c, 0x19, 0x33, 0x67, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x09, 0x1c, 0x08, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x04, 0x0e, 0x04, 0x00, 0x00, 0xfe, 0x00, 0x3c, 0x27, 0x21, 0x20, 0x20, 0x20, 0x60, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfb, 0x0e, 0x00, 0x03, 0x03, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x07, 0x0c, 0x18, 0xf8, 0xf8, 0xe4, 0xcb, 0xd5, 0xc8, 0xd0, 0x41, 0x46, 0x3c, 0x1c, 0x0c, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x63, 0x3e, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x38, 0x60, 0xc1, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x61, 0x30, 0x1c, 0x05, 0x05, 0x05, 0x05, 0x05, 0x0c, 0x18, 0x10, 0x10, 0x10, 0x10, 0x18, 0x08, 0x0c, 0x04, 0x04, 0x06, 0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM titlecard[] =
{
// width, height,
56, 16,
// FRAME 00
0x00, 0xfc, 0x06, 0xf3, 0xf9, 0xfd, 0x1d, 0xdd, 0xdd, 0xdd, 0xf9, 0xf3, 0x86, 0xdc, 0xc8, 0xe8, 0xe8, 0xe8, 0xe8, 0xc8, 0xd8, 0x98, 0x08, 0xe8, 0xe8, 0xe8, 0x08, 0x08, 0xe8, 0xe8, 0xef, 0x01, 0xfd, 0xfd, 0xfd, 0x01, 0x3f, 0x90, 0xd8, 0xc8, 0x68, 0x68, 0x68, 0x68, 0xc8, 0xd8, 0x9f, 0x01, 0xfd, 0xfd, 0xfd, 0xe1, 0xef, 0x08, 0xf8, 0x00, 
0x00, 0xff, 0x80, 0x97, 0x97, 0x97, 0x80, 0xfb, 0x0b, 0x0b, 0x19, 0x70, 0x47, 0xd7, 0x97, 0x95, 0x90, 0x90, 0x95, 0x97, 0xd7, 0x47, 0x60, 0xc7, 0x97, 0x97, 0x90, 0x90, 0x97, 0x97, 0xc7, 0x80, 0x97, 0x97, 0x97, 0x80, 0xe0, 0x47, 0xd7, 0x97, 0x90, 0x93, 0x93, 0x93, 0x93, 0xc3, 0x7b, 0x60, 0xc7, 0x97, 0x97, 0x94, 0x80, 0xfe, 0x03, 0x00,
};

const unsigned char PROGMEM aplus[] =
{
// width, height,
24, 16,
// FRAME 00
0xf8, 0x0e, 0x03, 0x01, 0xf1, 0x91, 0xf1, 0x01, 0x03, 0x06, 0xfc, 0x00, 0xe0, 0x20, 0x20, 0x20, 0x3c, 0x04, 0x04, 0x04, 0x3c, 0x20, 0x20, 0xe0, 
0x7f, 0x40, 0x40, 0x40, 0x78, 0x08, 0x7f, 0x40, 0x40, 0x40, 0x7f, 0x00, 0x03, 0x02, 0x02, 0x02, 0x1e, 0x10, 0x10, 0x10, 0x1e, 0x02, 0x02, 0x03,
};

const unsigned char PROGMEM poulet_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 
0x80, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0xfe, 0x9c, 0xff, 0xbe, 0xff, 0x3f, 0xff, 0x73, 0xff, 
0x6e, 0xff, 0xa2, 0xff, 0x9d, 0xff, 0x20, 0xff, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 
0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0xfe, 0x9c, 0xff, 0xbe, 0xff, 0x33, 0xff, 0x6f, 0xff, 
0x12, 0xff, 0x6d, 0xff, 0x6c, 0xff, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xe0, 
0x40, 0xe0, 0x40, 0xe0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x18, 0x3f, 0x0e, 0xff, 0x9f, 0xff, 0xbf, 0xff, 0x39, 0xff, 
0x37, 0xff, 0x91, 0xff, 0x0e, 0xff, 0x10, 0x3f, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 03
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 
0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x3c, 0x7f, 0x0e, 0xff, 0xdf, 0xff, 0xdf, 0xff, 
0xd3, 0xff, 0x2e, 0xff, 0x00, 0x7f, 0x21, 0x7f, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 04
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xe0, 0xc0, 0xf0, 0x60, 0xf0, 
0xe0, 0xf0, 0x20, 0xf0, 0x40, 0xf0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x0c, 0xff, 0x67, 0xff, 0x6f, 0xff, 0x1f, 0xff, 0x5e, 0xff, 
0x1d, 0x7f, 0x0c, 0x3f, 0x07, 0x1f, 0x08, 0x1f, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 05
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x80, 0xe0, 0xc0, 0xe0, 0xc0, 0xe0, 
0xc0, 0xe0, 0x40, 0xf0, 0x60, 0xf0, 0x00, 0xf0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x1f, 0x0f, 0x3f, 0x37, 0x7f, 0x37, 0x7f, 0x09, 0x7f, 
0x07, 0x7f, 0x31, 0x7f, 0x37, 0x7f, 0x00, 0x3f, 0x01, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 

// FRAME 06
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 
0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x3c, 0xff, 0x7e, 0xff, 0x77, 0xff, 0x6f, 0xff, 
0x5f, 0xff, 0x4e, 0xff, 0x34, 0xff, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 07
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0xfc, 0xd8, 0xfe, 0x3c, 0xff, 0x6e, 0xff, 0xee, 0xff, 
0xde, 0xff, 0x4e, 0xff, 0x0a, 0xff, 0xc4, 0xff, 0x00, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 08
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 
0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x20, 0xff, 0x9d, 0xff, 0xa2, 0xff, 0x6e, 0xff, 
0x73, 0xff, 0x3f, 0xff, 0xbe, 0xff, 0x9c, 0xff, 0x30, 0xfe, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 

// FRAME 09
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 
0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x6c, 0xff, 0x6d, 0xff, 0x12, 0xff, 
0x6f, 0xff, 0x33, 0xff, 0xbe, 0xff, 0x9c, 0xff, 0x30, 0xfe, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 

// FRAME 10
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xe0, 0x40, 0xe0, 0x40, 0xe0, 
0x80, 0xe0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x10, 0x3f, 0x0e, 0xff, 0x91, 0xff, 0x37, 0xff, 
0x39, 0xff, 0xbf, 0xff, 0x9f, 0xff, 0x0e, 0xff, 0x18, 0x3f, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 

// FRAME 11
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 
0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 0x21, 0x7f, 0x00, 0x7f, 0x2e, 0xff, 0xd3, 0xff, 
0xdf, 0xff, 0xdf, 0xff, 0x0e, 0xff, 0x3c, 0x7f, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 12
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0xf0, 0x20, 0xf0, 0xe0, 0xf0, 
0x60, 0xf0, 0xc0, 0xf0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x08, 0x1f, 0x07, 0x1f, 0x0c, 0x3f, 0x1d, 0x7f, 
0x5e, 0xff, 0x1f, 0xff, 0x6f, 0xff, 0x67, 0xff, 0x0c, 0xff, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 

// FRAME 13
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xf0, 0x60, 0xf0, 0x40, 0xf0, 0xc0, 0xe0, 
0xc0, 0xe0, 0xc0, 0xe0, 0x80, 0xe0, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x07, 0x00, 0x3f, 0x37, 0x7f, 0x31, 0x7f, 0x07, 0x7f, 
0x09, 0x7f, 0x37, 0x7f, 0x37, 0x7f, 0x0f, 0x3f, 0x01, 0x1f, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 

// FRAME 14
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 
0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x34, 0xff, 0x4e, 0xff, 0x5f, 0xff, 
0x6f, 0xff, 0x77, 0xff, 0x7e, 0xff, 0x3c, 0xff, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 15
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0xc4, 0xff, 0x0a, 0xff, 0x4e, 0xff, 0xde, 0xff, 
0xee, 0xff, 0x6e, 0xff, 0x3c, 0xff, 0xd8, 0xfe, 0xc0, 0xfc, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM aviator_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 
0x80, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0xfe, 0x98, 0xff, 0xba, 0xff, 0x33, 0xff, 0x73, 0xff, 
0x6a, 0xff, 0xa2, 0xff, 0x91, 0xff, 0x20, 0xff, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 
0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x30, 0xfe, 0x98, 0xff, 0xb2, 0xff, 0x33, 0xff, 0x6b, 0xff, 
0x12, 0xff, 0x61, 0xff, 0x6c, 0xff, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xe0, 
0x40, 0xe0, 0x40, 0xe0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x18, 0x3f, 0x0c, 0xff, 0x9d, 0xff, 0xb9, 0xff, 0x39, 0xff, 
0x35, 0xff, 0x91, 0xff, 0x08, 0xff, 0x10, 0x3f, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 03
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 
0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x3c, 0x7f, 0x0c, 0xff, 0xdb, 0xff, 0xd3, 0xff, 
0xd3, 0xff, 0x2a, 0xff, 0x00, 0x7f, 0x21, 0x7f, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 04
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x40, 0xf0, 0x60, 0xf0, 
0x60, 0xf0, 0x20, 0xf0, 0x40, 0xf0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x0c, 0xff, 0x66, 0xff, 0x6f, 0xff, 0x1e, 0xff, 0x5e, 0xff, 
0x1d, 0x7f, 0x0c, 0x3f, 0x06, 0x1f, 0x08, 0x1f, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 05
0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xe0, 0x40, 0xf0, 0x60, 0xf0, 
0x60, 0xf0, 0x20, 0xf0, 0x40, 0xf0, 0x00, 0xe0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0x01, 0x07, 0x03, 0xef, 0x66, 0xff, 0x6f, 0xff, 0x1e, 0xff, 0x5e, 0xff, 
0x1d, 0x7f, 0x0c, 0x3f, 0x06, 0x1f, 0x02, 0x0f, 0x01, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 

// FRAME 06
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xf0, 0xa0, 0xf0, 0xe0, 0xf0, 0xc0, 0xf0, 
0xc0, 0xe0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x0d, 0x3f, 0x1d, 0x3f, 0x19, 0x3f, 0x19, 0x3f, 
0x15, 0x3f, 0x11, 0x3f, 0x09, 0x3f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 07
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0xfc, 0xc8, 0xfe, 0x2c, 0xff, 0x4e, 0xff, 0xce, 0xff, 
0xce, 0xff, 0x4e, 0xff, 0x0a, 0xff, 0xc4, 0xff, 0x00, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 08
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 
0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x20, 0xff, 0x91, 0xff, 0xa2, 0xff, 0x6a, 0xff, 
0x73, 0xff, 0x33, 0xff, 0xba, 0xff, 0x98, 0xff, 0x30, 0xfe, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 

// FRAME 09
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 
0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x6c, 0xff, 0x61, 0xff, 0x12, 0xff, 
0x6b, 0xff, 0x33, 0xff, 0xb2, 0xff, 0x98, 0xff, 0x30, 0xfe, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 

// FRAME 10
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xe0, 0x40, 0xe0, 0x40, 0xe0, 
0x80, 0xe0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x10, 0x3f, 0x08, 0xff, 0x91, 0xff, 0x35, 0xff, 
0x39, 0xff, 0xb9, 0xff, 0x9d, 0xff, 0x0c, 0xff, 0x18, 0x3f, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 

// FRAME 11
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 
0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 0x21, 0x7f, 0x00, 0x7f, 0x2a, 0xff, 0xd3, 0xff, 
0xd3, 0xff, 0xdb, 0xff, 0x0c, 0xff, 0x3c, 0x7f, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 12
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0xf0, 0x20, 0xf0, 0x60, 0xf0, 
0x60, 0xf0, 0x40, 0xf0, 0x00, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x08, 0x1f, 0x06, 0x1f, 0x0c, 0x3f, 0x1d, 0x7f, 
0x5e, 0xff, 0x1e, 0xff, 0x6f, 0xff, 0x66, 0xff, 0x0c, 0xff, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 

// FRAME 13
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xe0, 0x40, 0xf0, 0x20, 0xf0, 0x60, 0xf0, 
0x60, 0xf0, 0x40, 0xf0, 0x00, 0xe0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x07, 0x02, 0x0f, 0x06, 0x1f, 0x0c, 0x3f, 0x1d, 0x7f, 
0x5e, 0xff, 0x1e, 0xff, 0x6f, 0xff, 0x66, 0xff, 0x03, 0xef, 0x01, 0x07, 0x00, 0x03, 0x00, 0x00, 

// FRAME 14
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xe0, 0xc0, 0xe0, 
0xc0, 0xf0, 0xe0, 0xf0, 0xa0, 0xf0, 0x00, 0xf0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x09, 0x3f, 0x11, 0x3f, 0x15, 0x3f, 
0x19, 0x3f, 0x19, 0x3f, 0x1d, 0x3f, 0x0d, 0x3f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 15
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0xc4, 0xff, 0x0a, 0xff, 0x4e, 0xff, 0xce, 0xff, 
0xce, 0xff, 0x4e, 0xff, 0x2c, 0xff, 0xc8, 0xfe, 0xc0, 0xfc, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00,
};


// Animation sequences
// Poulet
const unsigned char PROGMEM poulet_anim_idle[1] = {0};
const unsigned char PROGMEM poulet_anim_walk[4] = {1, 2, 3, 2};
const unsigned char PROGMEM poulet_anim_jump_up[1] = {4};
const unsigned char PROGMEM poulet_anim_jump_down[1] = {5};
const unsigned char PROGMEM poulet_anim_hover[2] = {4, 5};
const unsigned char PROGMEM poulet_anim_attack[1] = {6};
const unsigned char PROGMEM poulet_anim_death[1] = {7};

extern const unsigned char PROGMEM foe_anim_walk[2] = {0, 1};
extern const unsigned char PROGMEM foe_anim_die[1] = {2};


const unsigned char PROGMEM foreground[] =
{
// width, height,
8, 8,
// TILE 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// TILE 01
0x7f, 0x3f, 0x1f, 0x0f, 0x17, 0x2b, 0x55, 0xaa, 
// TILE 02
0x77, 0x77, 0x07, 0x77, 0x77, 0x77, 0x70, 0x77, 
// TILE 03
0x7e, 0x7f, 0x67, 0x7b, 0x7b, 0x7f, 0x3f, 0x00, 
// TILE 04
0x00, 0xe0, 0xfe, 0xe0, 0x00, 0xe0, 0xfe, 0xe0, 
// TILE 05
0x02, 0x02, 0x22, 0x26, 0x20, 0x20, 0x22, 0x62, 
// TILE 06
0x0f, 0xf9, 0x09, 0x09, 0x09, 0x0f, 0xf9, 0x0f, 
// TILE 07
0x28, 0xfc, 0x02, 0x95, 0x01, 0x4a, 0xfc, 0x10, 
// TILE 08
0x7e, 0x01, 0x01, 0x21, 0x21, 0x19, 0x01, 0x00, 
// TILE 09
0x00, 0x00, 0x18, 0x3c, 0x2c, 0x18, 0x00, 0x00, 
// TILE 10
0x00, 0x3c, 0x66, 0x4a, 0x42, 0x66, 0x3c, 0x00, 
};

const unsigned char PROGMEM doorspr[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0xc0, 0xe0, 0x00, 0x30, 0x30, 0x30, 0x30, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0xfc, 0x00, 0xfc, 0xfc, 0xfc, 0xe4, 0x00, 0xc8, 0xe7, 0x00, 0x00, 0x00, 
// FRAME 01
0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x30, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0x00, 0xfc, 0xe4, 0x00, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM fennec_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 
0x00, 0xc0, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xff, 0xd6, 0xff, 0xd7, 0xff, 0xdf, 0xff, 
0x26, 0xff, 0xbf, 0xff, 0xa7, 0xff, 0x1c, 0xff, 0x00, 0x3c, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 

// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 
0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xc0, 0xfe, 0xcc, 0xff, 0xce, 0xff, 0xbf, 0xff, 
0x4c, 0xff, 0x7e, 0xff, 0x4f, 0xff, 0x38, 0xff, 0x80, 0xf8, 0x00, 0xd0, 0x00, 0x00, 0x00, 0x00, 

// FRAME 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xf0, 0xc0, 0xf0, 0x80, 0xe0, 
0x00, 0xe0, 0xc0, 0xf0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0xf4, 0x60, 0xff, 0x6b, 0xff, 0x0b, 0xff, 0x1d, 0x3f, 
0x1b, 0x3f, 0x1f, 0xff, 0x5b, 0xff, 0x4c, 0xff, 0x60, 0xfe, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 

// FRAME 03
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 
0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x3c, 0x1c, 0xff, 0xa7, 0xff, 0xbf, 0xff, 0x26, 0xff, 
0xdf, 0xff, 0xd7, 0xff, 0xd6, 0xff, 0x00, 0xff, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 04
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x80, 0xf8, 0x38, 0xff, 0x4f, 0xff, 0x7e, 0xff, 0x4c, 0xff, 
0xbf, 0xff, 0xce, 0xff, 0xcc, 0xff, 0xc0, 0xfe, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 05
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xe0, 0xc0, 0xf0, 0x00, 0xe0, 
0x80, 0xe0, 0xc0, 0xf0, 0xe0, 0xf0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x60, 0xfe, 0x4c, 0xff, 0x5b, 0xff, 0x1f, 0xff, 0x1b, 0x3f, 
0x1d, 0x3f, 0x0b, 0xff, 0x6b, 0xff, 0x60, 0xff, 0x60, 0xf4, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM goob_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x38, 0xfe, 0x7c, 0xfe, 0x6c, 0xff, 0x76, 0xff, 
0x6e, 0xff, 0x7e, 0xff, 0x6c, 0xff, 0x74, 0xfe, 0x28, 0xfe, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 

// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 
0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x3e, 0xff, 0x7f, 0xff, 0x77, 0xff, 0x7b, 0xff, 
0x77, 0xff, 0x7f, 0xff, 0x77, 0xff, 0x3a, 0xff, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 02
0x00, 0xf0, 0x60, 0xf0, 0x60, 0xf0, 0x00, 0xf0, 0x00, 0x80, 0x00, 0x80, 0x00, 0xf0, 0x20, 0xf0, 
0x00, 0xf0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x0e, 0x7f, 0x3f, 0xff, 0x7f, 0xff, 0x7b, 0xff, 0x77, 0xff, 
0x7f, 0xff, 0x76, 0xff, 0x3a, 0xff, 0x1c, 0x7f, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 03
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x28, 0xfe, 0x74, 0xfe, 0x6c, 0xff, 0x7e, 0xff, 0x6e, 0xff, 
0x76, 0xff, 0x6c, 0xff, 0x7c, 0xfe, 0x38, 0xfe, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 04
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 
0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x3a, 0xff, 0x77, 0xff, 0x7f, 0xff, 0x77, 0xff, 
0x7b, 0xff, 0x77, 0xff, 0x7f, 0xff, 0x3e, 0xff, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 05
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xf0, 
0x20, 0xf0, 0x00, 0xf0, 0x00, 0x80, 0x00, 0x80, 0x00, 0xf0, 0x60, 0xf0, 0x60, 0xf0, 0x00, 0xf0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x1c, 0x7f, 0x3a, 0xff, 0x76, 0xff, 0x7f, 0xff, 
0x77, 0xff, 0x7b, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x0e, 0x7f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM bloob_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xe0, 
0xc0, 0xf0, 0xe0, 0xf0, 0xa0, 0xf0, 0x00, 0xf0, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x07, 0x03, 0x1f, 0x0f, 0x3f, 0x1f, 0x3f, 0x1c, 0x3f, 
0x1d, 0x3f, 0x1b, 0x3f, 0x19, 0x3f, 0x0c, 0x3f, 0x03, 0x1f, 0x01, 0x07, 0x00, 0x03, 0x00, 0x00, 

// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xe0, 0xc0, 0xe0, 0x40, 0xf0, 
0xe0, 0xf8, 0xf0, 0xf8, 0xd0, 0xf8, 0x00, 0xf8, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x0c, 0x1f, 0x0e, 0x1f, 0x07, 0x1f, 0x0f, 0x1f, 0x0e, 0x1f, 
0x0e, 0x1f, 0x0d, 0x1f, 0x0c, 0x1f, 0x06, 0x1f, 0x06, 0x1f, 0x0c, 0x1f, 0x00, 0x1e, 0x00, 0x00, 

// FRAME 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0xe0, 0x40, 0xe0, 0x40, 0xf0, 
0xe0, 0xf8, 0xf0, 0xf8, 0xb0, 0xf8, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x0c, 0x1f, 0x06, 0xff, 0x4f, 0xff, 0x77, 0xff, 0x32, 0xff, 
0x1c, 0x7f, 0x1f, 0x3f, 0x0f, 0x3f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 03
0x00, 0x00, 0x00, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0xf0, 0xa0, 0xf0, 0xe0, 0xf0, 0xc0, 0xf0, 
0x80, 0xe0, 0x80, 0xc0, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0x01, 0x07, 0x03, 0x1f, 0x0c, 0x3f, 0x19, 0x3f, 0x1b, 0x3f, 0x1d, 0x3f, 
0x1c, 0x3f, 0x1f, 0x3f, 0x0f, 0x3f, 0x03, 0x1f, 0x01, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 

// FRAME 04
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0xf8, 0xd0, 0xf8, 0xf0, 0xf8, 0xe0, 0xf8, 
0x40, 0xf0, 0xc0, 0xe0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1e, 0x0c, 0x1f, 0x06, 0x1f, 0x06, 0x1f, 0x0c, 0x1f, 0x0d, 0x1f, 0x0e, 0x1f, 
0x0e, 0x1f, 0x0f, 0x1f, 0x07, 0x1f, 0x0e, 0x1f, 0x0c, 0x1f, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 

// FRAME 05
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xb0, 0xf8, 0xf0, 0xf8, 0xe0, 0xf8, 
0x40, 0xf0, 0x40, 0xe0, 0x80, 0xe0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x0f, 0x3f, 0x1f, 0x3f, 0x1c, 0x7f, 
0x32, 0xff, 0x77, 0xff, 0x4f, 0xff, 0x06, 0xff, 0x0c, 0x1f, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM toque_plus_mask[] =
{
// width, height,
8, 8,
// FRAME 00
0xc0, 0xf8, 0x58, 0xfc, 0x60, 0xff, 0x7d, 0xff, 
0x61, 0xff, 0x7c, 0xff, 0x40, 0xfe, 0xd8, 0xfc,
};




const unsigned char PROGMEM digits_sheet[] =
{
// width, height,
8, 8,
// FRAME 00
0x1e, 0x3f, 0x31, 0x39, 0x2d, 0x3f, 0x1e, 0x00, 
// FRAME 01
0x00, 0x02, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 
// FRAME 02
0x22, 0x33, 0x31, 0x39, 0x3f, 0x2f, 0x26, 0x00, 
// FRAME 03
0x11, 0x31, 0x25, 0x25, 0x3f, 0x3f, 0x1b, 0x00, 
// FRAME 04
0x0c, 0x0f, 0x08, 0x38, 0x3f, 0x3f, 0x08, 0x00, 
// FRAME 05
0x17, 0x37, 0x27, 0x3d, 0x3d, 0x3d, 0x19, 0x00, 
// FRAME 06
0x1e, 0x3f, 0x25, 0x25, 0x3d, 0x3d, 0x19, 0x00, 
// FRAME 07
0x01, 0x01, 0x39, 0x3d, 0x3f, 0x07, 0x03, 0x00, 
// FRAME 08
0x16, 0x3f, 0x29, 0x29, 0x3f, 0x3f, 0x16, 0x00, 
// FRAME 09
0x26, 0x2f, 0x29, 0x29, 0x3f, 0x3f, 0x1e, 0x00, 
// FRAME 10
0x00, 0x1c, 0x3e, 0x32, 0x2f, 0x23, 0x1d, 0x00, 
// FRAME 11
0x00, 0x22, 0x36, 0x1c, 0x36, 0x22, 0x00, 0x00, 
// FRAME 12
0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 
// FRAME 13
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM proj[] =
{
// width, height,
8, 8,
// FRAME 00
0x00, 0x08, 0x00, 0x58, 0x1a, 0x00, 0x10, 0x00,
};

const unsigned char PROGMEM done[] =
{
// width, height,
32, 8,
// FRAME 00
0x00, 0x7e, 0x7e, 0x42, 0x66, 0x7e, 0x3c, 0x00, 0x3c, 0x7e, 0x42, 0x42, 0x7e, 0x3c, 0x00, 0x7e, 0x7e, 0x18, 0x30, 0x7e, 0x7e, 0x00, 0x7e, 0x7e, 0x56, 0x56, 0x46, 0x00, 0x5e, 0x5e, 0x00, 0x00,
};

const uint8_t PROGMEM stage_label[] = {
32, 8,
0x00, 0x4c, 0x5e, 0x5a, 0x7a, 0x32, 0x00, 0x02, 0x7e, 0x7e, 0x02, 0x02, 0x70, 0x7c, 0x26, 0x26, 0x7c, 0x70, 0x00, 0x3c, 0x7e, 0x42, 0x52, 0x76, 0x34, 0x00, 0x7e, 0x7e, 0x4a, 0x4a, 0x42, 0x00, 
};


const uint8_t PROGMEM off_label[] = {
16, 8,
0x00, 0x3c, 0x7e, 0x42, 0x42, 0x7e, 0x3c, 0x00, 0x7c, 0x7e, 0x0a, 0x02, 0x7c, 0x7e, 0x0a, 0x02, 
};

const uint8_t PROGMEM on_label[] = {
16, 8,
0x00, 0x3c, 0x7e, 0x42, 0x42, 0x7e, 0x3c, 0x00, 0x78, 0x78, 0x08, 0x78, 0x70, 0x00, 0x00, 0x00, 
};


const unsigned char PROGMEM balloon_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0, 0xf8, 0xf0, 0xfc, 0xf8, 0xfc, 0x08, 0xfc, 
0x08, 0xfc, 0xf8, 0xfc, 0xf0, 0xfc, 0xe0, 0xf8, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x07, 0x03, 0x0f, 0x07, 0x7f, 0x2d, 0x7f, 
0x2d, 0x7f, 0x07, 0x7f, 0x03, 0x0f, 0x01, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM glasses_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 
0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x80, 0xc0, 0x00, 0xc0, 0x00, 0x80, 
0x00, 0x1f, 0x0e, 0x3f, 0x1e, 0x3f, 0x1f, 0x3f, 0x0e, 0x3f, 0x06, 0x1f, 0x0e, 0x3f, 0x1f, 0x3f, 
0x1e, 0x3f, 0x0e, 0x3f, 0x01, 0x1f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x01, 0x03, 0x00, 0x03, 
};

const unsigned char PROGMEM pop_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0xf0, 0xe0, 0xf0, 0xe0, 0xf0, 
0xe0, 0xf0, 0xe0, 0xf0, 0xc0, 0xf0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x0f, 0x07, 0x0f, 0x07, 0x0f, 
0x07, 0x0f, 0x07, 0x0f, 0x03, 0x0f, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf0, 0xfc, 0xf8, 0xfc, 0xf8, 0xfc, 0x78, 0xfc, 0x38, 0x7c, 
0x38, 0x7c, 0x78, 0xfc, 0xf8, 0xfc, 0xf8, 0xfc, 0xf0, 0xfc, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x0f, 0x3f, 0x1f, 0x3f, 0x1f, 0x3f, 0x1e, 0x3f, 0x1c, 0x3e, 
0x1c, 0x3e, 0x1e, 0x3f, 0x1f, 0x3f, 0x1f, 0x3f, 0x0f, 0x3f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 

// FRAME 02
0x00, 0xe0, 0xc0, 0xee, 0xc4, 0xfe, 0x88, 0xfe, 0x00, 0xdc, 0x00, 0x0f, 0x06, 0x1f, 0x0e, 0x1f, 
0x0e, 0x1f, 0x06, 0x1f, 0x00, 0x0f, 0x00, 0xdc, 0x88, 0xfe, 0xc4, 0xfe, 0xc0, 0xee, 0x00, 0xe0, 
0x00, 0x07, 0x03, 0x77, 0x23, 0x7f, 0x11, 0x7f, 0x00, 0x3b, 0x00, 0xf0, 0x60, 0xf8, 0x70, 0xf8, 
0x70, 0xf8, 0x60, 0xf8, 0x00, 0xf0, 0x00, 0x3b, 0x11, 0x7f, 0x23, 0x7f, 0x03, 0x77, 0x00, 0x07, 

// FRAME 03
0x00, 0xc7, 0x82, 0xc7, 0x00, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x07, 
0x02, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x82, 0xc7, 0x00, 0xc7, 
0x00, 0xe3, 0x41, 0xe3, 0x00, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0xe0, 
0x40, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0x41, 0xe3, 0x00, 0xe3,
};

const unsigned char PROGMEM toquepowerup_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0xf8, 0x50, 0xfc, 0x48, 0xfc, 0x50, 0xfe, 
0x5c, 0xfe, 0x40, 0xff, 0x5b, 0xff, 0x43, 0xff, 0x00, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


const unsigned char PROGMEM oneup_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xe0, 0x40, 0xf0, 0xe0, 0xf8, 0xf0, 0xf8, 0xf0, 0xf8, 
0xf0, 0xf8, 0xe0, 0xf8, 0xc0, 0xf0, 0x00, 0xe0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0x0a, 0x3f, 0x0f, 0x7f, 0x28, 0x7f, 0x20, 0xff, 0x6e, 0xff, 0x68, 0xff, 
0x6e, 0xff, 0x00, 0xff, 0x1e, 0x7f, 0x0a, 0x7f, 0x0e, 0x3f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM toquetext_plus_mask[] =
{
// width, height,
24, 8,
// FRAME 00
0x00, 0x00, 0x00, 0x07, 0x02, 0x7f, 0x3e, 0x7f, 0x02, 0x7f, 0x00, 0x7f, 0x3e, 0x7f, 0x22, 0x7f, 0x3e, 0x7f, 0x00, 0x7f, 0x3e, 0x7f, 0x32, 0xff, 
0x7e, 0xff, 0x40, 0xff, 0x3e, 0xff, 0x20, 0x7f, 0x3e, 0x7f, 0x00, 0x7f, 0x3e, 0x7f, 0x2a, 0x7f, 0x22, 0x7f, 0x00, 0x77, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM flyboy_plus_mask[] =
{
// width, height,
24, 8,
// FRAME 00
0x00, 0x7f, 0x3e, 0x7f, 0x0a, 0x7f, 0x02, 0x1f, 0x00, 0x7f, 0x3e, 0x7f, 0x20, 0x7f, 0x00, 0x7f, 0x0e, 0x7f, 0x38, 0x7f, 0x0e, 0x7f, 0x00, 0x7f, 
0x3e, 0x7f, 0x2a, 0x7f, 0x36, 0x7f, 0x00, 0x7f, 0x3e, 0x7f, 0x22, 0x7f, 0x3e, 0x7f, 0x00, 0x7f, 0x0e, 0x7f, 0x38, 0x7f, 0x0e, 0x7f, 0x00, 0x1f,
};

const unsigned char PROGMEM poletop[] =
{
// width, height,
8, 8,
// FRAME 00
0x00, 0x18, 0x2c, 0x5e, 0x5e, 0x3c, 0x18, 0x00,
};

const unsigned char PROGMEM polemid[] =
{
// width, height,
8, 8,
// FRAME 00
0x00, 0x00, 0x11, 0x33, 0x66, 0x44, 0x00, 0x00,
};