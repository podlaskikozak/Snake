#pragma once
#include <stdint.h>
#include <string>
//////////////////////
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef std::string text;
/////////////////////


/*GameVARIABLES*/
struct GameVariables
{
	u16		SCREEN_WIDTH = 1200;
	u16		SCREEN_HEIGHT = 840;
	u8		FPS_LIMIT = 60;
	text	TITLE = "Testin";
};
