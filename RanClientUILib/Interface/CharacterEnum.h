#pragma	once


enum
{
	SELECT_SCHOOL_STAGE,
	SELECT_SEX_STAGE,
	SELECT_CLASS_STAGE,
	SELECT_STYLE_STAGE
};

enum 
{
	MAX_SELSCHOOL = 3,
	MAX_SEX = 2,
	//added by tobets | 14-7-2012 | add new class
	MAX_CLASS = 7,
};

enum
{
	SUNGMUN_SCHOOL,
	BONGHWANG_SCHOOL,
	HYUNAM_SCHOOL,
};

enum 
{
	GENDER_MAN,
	GENDER_WOMAN,
};

enum 
{
	EXTREME_CLASS,
	FIGHTER_CLASS,
	ARMS_CLASS,
	ARCHER_CLASS,
	SPIRIT_CLASS,
	//added by tobets | 14-7-2012 | add new class
	SCIENCE_CLASS,
	ASSASSIN_CLASS,
};

static const float fFontRate = 0.8f;

static const char szBackImg1[] = { "GUI_01.dds" };
static const char szBackImg2[] = { "GUI_02.dds" };

static const char ClassImg[MAX_SEX][MAX_PATH] = { "class_image_m.dds", 
												  "class_image_w.dds" }; 

static const char jszBackImg1[] = { "SCHOOL_GUI_01.dds" };
static const char jszBackImg2[] = { "SCHOOL_GUI_02.dds" };
static const char jszBackImg3[] = { "SCHOOL_GUI_03.dds" };