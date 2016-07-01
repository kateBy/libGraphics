#ifndef BASICS_H
#define BASICS_H

#ifndef WIN32
#include <stdint.h>
#endif
#include <string>
using std::string;

#ifndef BITS

#define BITS

#define BIT1 1
#define BIT2 2
#define BIT3 4
#define BIT4 8
#define BIT5 16
#define BIT6 32
#define BIT7 64
#define BIT8 128
#define BIT9 256
#define BIT10 512
#define BIT11 1024
#define BIT12 2048
#define BIT13 4096
#define BIT14 8192
#define BIT15 16384
#define BIT16 32768
#define BIT17 65536UL
#define BIT18 131072UL
#define BIT19 262144UL
#define BIT20 524288UL
#define BIT21 1048576UL
#define BIT22 2097152UL
#define BIT23 4194304UL
#define BIT24 8388608UL
#define BIT25 16777216UL
#define BIT26 33554432UL
#define BIT27 67108864UL
#define BIT28 134217728UL
#define BIT29 268435456UL
#define BIT30 536870912UL
#define BIT31 1073741824UL
#define BIT32 2147483648UL

#endif

void gamelog_string(const string &str);
void errorlog_string(const string &str);
void errorlog_string(const char *ptr);

bool grab_token_string(string &dest,string &source,char compc=':');
bool grab_token_string(string &dest,string &source,int32_t &pos,char compc=':');
bool grab_token_string_pos(string &dest,string &source,int32_t pos,char compc=':');
void replace_token_string(string &token,string &str,int32_t pos,char compc,string &nw,char repc);
bool grab_token_list_as_string(string &dest,string &source,int32_t &pos,char compc=':');
bool grab_token_expression(string &dest,string &source,int32_t &pos,char compc=':');
char grab_variable_token(string &str,string &token,char sec_comp,int32_t &pos,int32_t i_pos);

int32_t convert_string_to_long(string &str);
uint32_t convert_string_to_ulong(string &str);
void add_long_to_string(int32_t n,string &str);
void convert_long_to_string(int32_t n,string &str);
void convert_ulong_to_string(uint32_t n,string &str);

void lower_case_string(string &str);
void upper_case_string(string &str);
void simplify_string(string &str);
void capitalize_string_words(string &str);
void capitalize_string_first_word(string &str);
void abbreviate_string(string &str,int32_t len);

void get_number(int32_t number,string &str);
void get_ordinal(int32_t number,string &str,bool shorten);

enum GameMode
{
	GAMEMODE_DWARF,
	GAMEMODE_ADVENTURE,
	GAMEMODENUM,
	GAMEMODE_NONE
};

enum GameType
{
	GAMETYPE_DWARF_MAIN,
	GAMETYPE_ADVENTURE_MAIN,
	GAMETYPE_VIEW_LEGENDS,
	GAMETYPE_DWARF_RECLAIM,
	GAMETYPE_DWARF_ARENA,
	GAMETYPE_ADVENTURE_ARENA,
	GAMETYPE_ADVENTURE_DUNGEON,
	GAMETYPE_DWARF_TUTORIAL,
	GAMETYPE_DWARF_UNRETIRE,
	GAMETYPE_ADVENTURE_WORLD_DEBUG,
	GAMETYPENUM,
	GAMETYPE_NONE
};

enum Song
{
	SONG_TITLE,
	SONG_GAME,
	SONGNUM
};


enum justification : unsigned char {
  justify_left, justify_center, justify_right,
    justify_cont,
    not_truetype
};

extern int charmap[256];


//1-19
const char zero[] = {237, 238, 235, 252, 0};//ноль
const char one[] = {238, 228, 232, 237, 0};//один
const char two[] = {228, 226, 224, 0};//два
const char three[] = {242, 240, 232, 0};//три
const char four[] = {247, 229, 242, 251, 240, 229, 0};//четыре
const char five[] = {239, 255, 242, 252, 0};//пять
const char six[] = {248, 229, 241, 242, 252, 0};//шесть
const char seven[] = {241, 229, 236, 252, 0};//семь
const char eight[] = {226, 238, 241, 229, 236, 252, 0};//восемь
const char nine[] = {228, 229, 226, 255, 242, 252, 0};//девять
const char ten[] = {228, 229, 241, 255, 242, 252, 0};//десять
const char eleven[] = {238, 228, 232, 237, 224, 228, 246, 224, 242, 252, 0};//одинадцать
const char twelve[] = {228, 226, 229, 237, 224, 228, 246, 224, 242, 252, 0};//двенадцать
const char thirteen[] = {242, 240, 232, 237, 224, 228, 246, 224, 242, 252, 0};//тринадцать
const char fourteen[] = {247, 229, 242, 251, 240, 237, 224, 228, 246, 224, 242, 252, 0};//четырнадцать
const char fifteen[] = {239, 255, 242, 237, 224, 228, 246, 224, 242, 252, 0};//пятнадцать
const char sixteen[] = {248, 229, 241, 242, 237, 224, 228, 246, 224, 242, 252, 0};//шестнадцать
const char seventeen[] = {241, 229, 236, 237, 224, 228, 246, 224, 242, 252, 0};//семнадцать
const char eighteen[] = {226, 238, 241, 229, 236, 237, 224, 228, 246, 224, 242, 252, 0};//восемнадцать
const char nineteen[] = {228, 229, 226, 255, 242, 237, 224, 228, 246, 224, 242, 252, 0};//девятнадцать
const char negative[] = {236, 232, 237, 243, 241, 0};//минус
//20-90
const char twenty[] = {228, 226, 224, 228, 246, 224, 242, 252, 0};//двадцать
const char thirty[] = {242, 240, 232, 228, 246, 224, 242, 252, 0};//тридцать
const char forty[] = {241, 238, 240, 238, 234, 0};//сорок
const char fifty[] = {239, 255, 242, 252, 228, 229, 241, 255, 242, 0};//пятьдесят
const char sixty[] = {248, 229, 241, 242, 252, 228, 229, 241, 255, 242, 0};//шестьдесят
const char seventy[] = {241, 229, 236, 228, 229, 241, 255, 242, 0};//семдесят
const char eighty[] = {226, 238, 241, 229, 236, 228, 229, 241, 255, 242, 0};//восемдесят
const char ninety[] = {228, 229, 226, 255, 237, 238, 241, 242, 238, 0};//девяносто
//10^3 - 10^9
const char billion[] = {32, 236, 232, 235, 235, 232, 224, 240, 228, 0};// миллиард
const char hundred[] = {32, 241, 242, 238, 0};// сто
const char thousand[] = {32, 242, 251, 241, 255, 247, 224, 0};// тысяча
const char million[] = {32, 236, 232, 235, 235, 232, 238, 237, 0};// миллион
//1st-19th
const char Zeroth[] = {205, 243, 235, 229, 226, 238, 233, 0};//Нулевой
const char First[] = {207, 229, 240, 226, 251, 233, 0};//Первый
const char Second[] = {194, 242, 238, 240, 238, 233, 0};//Второй
const char Third[] = {210, 240, 229, 242, 232, 233, 0};//Третий
const char Fourth[] = {215, 229, 242, 226, 184, 240, 242, 251, 233, 0};//Четвёртый
const char Fifth[] = {207, 255, 242, 251, 233, 0};//Пятый
const char Sixth[] = {216, 229, 241, 242, 238, 233, 0};//Шестой
const char Seventh[] = {209, 229, 228, 252, 236, 238, 233, 0};//Седьмой
const char Eighth[] = {194, 238, 241, 252, 236, 238, 233, 0};//Восьмой
const char Ninth[] = {196, 229, 226, 255, 242, 251, 233, 0};//Девятый
const char Tenth[] = {196, 229, 241, 255, 242, 251, 233, 0};//Десятый
const char Eleventh[] = {206, 228, 232, 237, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Одиннадцатый
const char Twelfth[] = {196, 226, 229, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Двенадцатый
const char Thirteenth[] = {210, 240, 232, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Тринадцатый
const char Fourteenth[] = {215, 229, 242, 251, 240, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Четырнадцатый
const char Fifteenth[] = {207, 255, 242, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Пятнадцатый
const char Sixteenth[] = {216, 229, 241, 242, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Шестнадцатый
const char Seventeenth[] = {209, 229, 236, 237, 228, 246, 224, 242, 251, 233, 0};//Семндцатый
const char Eighteenth[] = {194, 238, 241, 229, 236, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Восемнадцатый
const char Nineteenth[] = {196, 229, 226, 255, 242, 237, 224, 228, 246, 224, 242, 251, 233, 0};//Девятнадцатый
const char Negative [] = {204, 232, 237, 243, 241, 0};//Минус

const char ord_th[] = {45, 227, 238, 0};//-го

#endif
