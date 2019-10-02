#ifndef GLSKILL_H_
#define GLSKILL_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "./GLItemDef.h"
#include "./GLCharDefine.h"

#include "../../EngineLib/Common/basestream.h"
#include "../../EngineLib/G-Logic/GLDefine.h"
#include "../../EngineLib/Meshs/DxSkinAniMan.h"
#define SKILLEDIT_VER 0x0106


enum GLSKILL_ATT
{
	SKILLATT_NOTHING	= 0,
	SKILLATT_SWORD		= 1,
	SKILLATT_BLADE		= 2,
	SKILLATT_SWORDBLADE	= 3,
	SKILLATT_DAGGER		= 4,
	SKILLATT_SPEAR		= 5,
	SKILLATT_STICK		= 6,
	SKILLATT_GAUNT		= 7,
	SKILLATT_BOW		= 8,
	SKILLATT_THROW		= 9,

	SKILLATT_GUN		= 10,
	SKILLATT_RAILGUN	= 11,
	SKILLATT_PORTALGUN	= 12,

	SKILLATT_SHOTGUN		= 13,
	SKILLATT_RAILPORTALGUN	= 14,

	SKILLATT_SCYTHE		= 15,
	SKILLATT_DUALSPEAR	= 16,
	SKILLATT_SHURIKEN	= 17,

	SKILLATT_EXTREMEFIST	= 18,

	SKILLATT_WAND	= 19,
	SKILLATT_CUBE	= 20,
	SKILLATT_ROPE	= 21,

	SKILLATT_NOCARE		= 22,
	SKILLATT_EXREMEFIST_BOW = 23,
	SKILLATT_EXREMEFIST_GAUNT = 24,
	SKILLATT_EXREMEFIST_SWORD = 25,
	SKILLATT_EXREMEFIST_SPEAR = 26,
	SKILLATT_EXREMEFIST_GUNS = 27,
	SKILLATT_EXREMEFIST_ASSASSINWEAPS = 28,
	SKILLATT_NSIZE		= 29,

};

namespace SKILL
{
	GLITEM_ATT			GLSKILATT_TO_GLITEMATT( GLSKILL_ATT emSKILLATT );

	enum
	{
		MAX_SZNAME		= 32,
		MAX_SZFILE		= 68,
		MAX_SZCOMMENT	= 128,

		MAX_LEVEL		= 9,
		MAX_EFFECT		= 10,
	};

	enum EMROLE
	{
		EMROLE_NORMAL	= 0,		//	���.
		EMROLE_PASSIVE	= 1,		//	��ú� �迭. ( ����ϴ� ���� �ƴϰ� ������� �ٸ� ���� ���� )
		EMROLE_NSIZE	= 2,
	};

	enum EMAPPLY	//	������ ����� ȿ��.
	{
		EMAPPLY_PHY_SHORT	= 0,	//	���� Ÿ����.
		EMAPPLY_PHY_LONG	= 1,	//	���� �����.
		EMAPPLY_MAGIC		= 2,	//	���� �ۿ���.
	
		EMAPPLY_NSIZE		= 3
	};

	enum EMTYPES
	{
		EMFOR_HP				= 0,	//	ü��ġ ��ȭ.
		EMFOR_MP				= 1,	//	���ġ ��ȭ.
		EMFOR_SP				= 2,	//	�ٷ�ġ ��ȭ.

		EMFOR_VARHP				= 3,	//	ä��ġ ��ȭ��.
		EMFOR_VARMP				= 4,	//	���ġ ��ȭ��.
		EMFOR_VARSP				= 5,	//	�ٷ�ġ ��ȭ��.

		EMFOR_DEFENSE			= 6,	//	���ġ ��ȭ.
		EMFOR_CURE				= 7,	//	�ص�. ( �ص� ���� �ʿ� )

		EMFOR_HITRATE			= 8,	//	������.
		EMFOR_AVOIDRATE			= 9,	//	ȸ����.

		EMFOR_VARAP				= 10,	//	��� (ä��,���,�ٷ�) ��ȭ��.

		EMFOR_VARDAMAGE			= 11,	//	����ġ ��ȭ��.
		EMFOR_VARDEFENSE		= 12,	//	���ġ ��ȭ��.

		EMFOR_PA				= 13,	//	����ġ.
		EMFOR_SA				= 14,	//	���ġ.
		EMFOR_MA				= 15,	//	���ġ.

		EMFOR_HP_RATE			= 16,	//	HP ������.
		EMFOR_MP_RATE			= 17,	//	MP ������.
		EMFOR_SP_RATE			= 18,	//	SP ������.

		EMFOR_PET_GETALLITEMS	= 19,	//	��� ������ �ݱ�	// PetData
		EMFOR_PET_GETRAREITEMS	= 20,	//	���� �����۸� �ݱ�
		EMFOR_PET_GETPOTIONS	= 21,	//	��ǰ�� �����۸� �ݱ�
		EMFOR_PET_GETMONEY		= 22,	//	���� �ݱ�
		EMFOR_PET_GETSTONE		= 23,	//	������ �����۸� �ݱ�
		EMFOR_PET_HEAL			= 24,	//	������ HP ȸ�� �ӵ� ���
		EMFOR_PET_SUPPROT		= 25,	//	������ HP, MP, SP ȸ���� ���
		EMFOR_PET_BACKUP_ATK	= 26,	//	������ ���ݷ�(��) ���
		EMFOR_PET_BACKUP_DEF	= 27,	//	������ ����(��) ���
		EMFOR_PET_AUTOMEDISON	= 28,	//	�ڵ� ��ǰ ���
		EMFOR_PET_PROTECTITEMS	= 29,	//	������ ������ �Ҿ������ �ʵ��� ��ȣ
		EMFOR_RESIST			= 30,	//	���� ��ȭ��
		EMFOR_SUMMONTIME		= 31,
		EMFOR_CP_RATE			= 32,	//add cp
		EMFOR_CP_GAIN			= 33,	//add cp
		FOR_TYPE_SIZE			= 34
	};

	enum EMEFFECTIME
	{
		EMTIME_FIRST		= 0,		//	��ų ���۰� ���ÿ�.
		EMTIME_IMPACT		= 1,		//	��ų Ÿ�� ����.
		EMTIME_TARG_OVR		= 2,		//	��ų Ÿ�� ����Ʈ�� ������ ����.
		EMTIME_PASSIVE		= 3,		//	Ÿ�ٿ� ������ ��ų��.
		EMTIME_REV01		= 4,
		EMTIME_EFFECTACT	= 5,
		EMTIME_NSIZE		= 6,
	};

	enum EMEFFECTPOS
	{
		EMPOS_GROUND			= 0,		//	���� ��ġ.
		EMPOS_STRIKE			= 1,		//	��Ʈ����ũ ��ġ. ( ����, �տ� ������ ������(�߻��ϴ�) ��ġ. )
		EMPOS_NSIZE				= 2,
	};
		
	enum EMSPECIALSKILLTYPE
	{
		EMSSTYPE_NONE		= 0,		//	������
		EMSSTYPE_TRANSFORM	= 1,		//	����
		EMSSTYPE_SUMMON		= 2,
		EMSSTYPE_TRANSCHF	= 3,		//add panther
		EMSSTYPE_NSIZE		= 4,
	};

	enum EMTRANSFORM_PART
	{
		EMTRANSFORM_HEAD	= 0,		    // �۸�
		EMTRANSFORM_UPPER	= 1,			// ��ü
		EMTRANSFORM_LOWER	= 2,			// ��ü
		EMTRANSFORM_HAND	= 3,			// ��
		EMTRANSFORM_LHAND	= 4,			// �޼� ���
		EMTRANSFORM_RHAND	= 5,			// ������ ���
		EMTRANSFORM_FOOT	= 6,			// �ٸ� ���
		EMTRANSFORM_FACE	= 7,			// ��		

		EMTRANSFORM_NSIZE	= 8,				
		
	};

	enum SPEC_STIGMA_TYPE //jdev pending
	{
		EMSTIGMA_NORMAL	= 0,
		EMSTIGMA_SKILL	= 1,
		EMSTIGMA_BUFF	= 2,
		EMSTIGMA_DEBUFF	= 3,
		EMSTIGMA_LIMIT	= 4,
		EMSTIGMA_SIZE	= 5,
	};

	enum SPEC_HALLUCINATE_TYPE //jdev pending
	{
		EMHALLUCINATE_TRANSFORM		= 0,
		EMHALLUCINATE_GESTURE		= 1,
		EMHALLUCINATE_SIZE			= 2,
	};

	enum SPEC_DOMINATE_TYPE //jdev pending
	{
		EMDOMINATE_OWN		= 0,
		EMDOMINATE_CASTER	= 1,
		EMDOMINATE_RANDOM	= 2,
		EMDOMINATE_FIXING	= 3,
		EMDOMINATE_SIZE		= 4,
	};

	enum SPEC_ASIGN_TYPE //jdev pending
	{
		EMASIGN_BEFORE		= 0,
		EMASIGN_AFTER		= 1,
		EMASIGN_SIZE		= 2,
	};

	enum SPEC_INC_TYPE //jdev pending
	{
		EMINC_UP		= 0,
		EMINC_DOWN		= 1,
		EMINC_SIZE		= 2,
	};

	enum SPEC_INVISIBLE_USE_TYPE //jdev pending
	{
		EMINVISIBLE_COMBAT		= 0,
		EMINVISIBLE_SIZE		= 1,
	};

	enum SPEC_INVISIBLE_ANI_TYPE //jdev pending
	{
		EMINVISIBLE_NONE		= 0,
		EMINVISIBLE_WALK		= 1,
		EMINVISIBLE_TELEPORT	= 2,
		EMINVISIBLE_ANI_SIZE	= 3,
	};

	enum SPEC_SWAPPOS_DIR_TYPE //jdev pending
	{
		EMSWAPPOS_DIR_ALL		= 0,
		EMSWAPPOS_DIR_SELF		= 1,
		EMSWAPPOS_DIR_TARGET	= 2,
		EMSWAPPOS_DIR_SIZE	= 3,
	};

	struct SSTATE_BLOW
	{
		float			fRATE;		//	�߻� Ȯ��.
		float			fVAR1;		//	���� �� 1.
		float			fVAR2;		//	���� �� 2.

		SSTATE_BLOW () :
			fRATE(0.0f),
			fVAR1(0.0f),
			fVAR2(0.0f)
		{
		}
	};

	struct SSPEC_100
	{
		float	fVAR1;
		float	fVAR2;
		DWORD	dwFLAG;
		
		SSPEC_100 () :
			fVAR1(0.0f),
			fVAR2(0.0f),
			dwFLAG(NULL)
		{
		}

	};

	struct SSPEC
	{
		float		fVAR1;
		float		fVAR2;
		DWORD		dwFLAG;
		SNATIVEID	dwNativeID;
		
		SSPEC () :
			fVAR1(0.0f),
			fVAR2(0.0f),
			dwFLAG(NULL),
			dwNativeID(NATIVEID_NULL())
		{
		}

		void Assign( SSPEC_100 &sOldData )
		{
			fVAR1 = sOldData.fVAR1;
			fVAR2 = sOldData.fVAR2;
			dwFLAG = sOldData.dwFLAG;
		}
	};

	struct CDATA_LVL_100
	{
		float			fDELAYTIME;			//	������ Ÿ��.

		float			fLIFE;				//	���ӽð�.
		WORD			wAPPLYRANGE;		//	���� ����.
		WORD			wAPPLYNUM;			//	���� ����.
		WORD			wAPPLYANGLE;		//	���� ����.
		WORD			wPIERCENUM;			//	���� ����.

		float			fBASIC_VAR;			//	��ȭ��.

		//	���� �Ҹ�-����. ( ������� )
		WORD			wUSE_ARROWNUM;		//	�Ҹ� ȭ�� ����.

		WORD			wUSE_HP;			//	���� HP ������.
		WORD			wUSE_MP;			//	���� MP ������.
		WORD			wUSE_SP;			//	���� SP ������.

		WORD			wUSE_HP_PTY;		//	���� HP ��Ƽ�� ������.
		WORD			wUSE_MP_PTY;		//	���� MP ��Ƽ�� ������.
		WORD			wUSE_SP_PTY;		//	���� SP ��Ƽ�� ������.
	};

	struct CDATA_LVL_101
	{
		float			fDELAYTIME;			//	������ Ÿ��.

		float			fLIFE;				//	���ӽð�.
		WORD			wAPPLYRANGE;		//	���� ����.
		WORD			wAPPLYNUM;			//	���� ����.
		WORD			wAPPLYANGLE;		//	���� ����.
		WORD			wPIERCENUM;			//	���� ����.
		WORD			wTARNUM;			//	Ÿ�� ����.

		float			fBASIC_VAR;			//	��ȭ��.

		//	���� �Ҹ�-����. ( ������� )
		WORD			wUSE_ARROWNUM;		//	�Ҹ� ȭ�� ����.
		WORD			wUSE_CHARMNUM;		//	�Ҹ� ���� ����.

		WORD			wUSE_EXP;			//	���� EXP ������.
		WORD			wUSE_HP;			//	���� HP ������.
		WORD			wUSE_MP;			//	���� MP ������.
		WORD			wUSE_SP;			//	���� SP ������.

		WORD			wUSE_HP_PTY;		//	���� HP ��Ƽ�� ������.
		WORD			wUSE_MP_PTY;		//	���� MP ��Ƽ�� ������.
		WORD			wUSE_SP_PTY;		//	���� SP ��Ƽ�� ������.
	};

	//	���� �� ���뺰 ����.
	struct CDATA_LVL
	{
		float			fDELAYTIME;			//	������ Ÿ��.

		float			fLIFE;				//	���ӽð�.
		WORD			wAPPLYRANGE;		//	���� ����.
		WORD			wAPPLYNUM;			//	���� ����.
		WORD			wAPPLYANGLE;		//	���� ����.
		WORD			wPIERCENUM;			//	���� ����.
		WORD			wTARNUM;			//	Ÿ�� ����.

		float			fBASIC_VAR;			//	��ȭ��.

		//	���� �Ҹ�-����. ( ������� )
		WORD			wUSE_ARROWNUM;		//	�Ҹ� ȭ�� ����.
		WORD			wUSE_CHARMNUM;		//	�Ҹ� ���� ����.

		WORD			wUSE_EXP;			//	���� EXP ������.
		WORD			wUSE_HP;			//	���� HP ������.
		WORD			wUSE_MP;			//	���� MP ������.
		WORD			wUSE_SP;			//	���� SP ������.

		WORD			wUSE_HP_PTY;		//	���� HP ��Ƽ�� ������.
		WORD			wUSE_MP_PTY;		//	���� MP ��Ƽ�� ������.
		WORD			wUSE_SP_PTY;		//	���� SP ��Ƽ�� ������.

		WORD			wUSE_CP;
		WORD			wUSE_BULLET;
		WORD			wUSE_EXTRA;

		void Assign ( CDATA_LVL_100 &sOldData );
		void Assign ( CDATA_LVL_101 &sOldData );

		void LOAD_GS_110 ( basestream &SFile );

		CDATA_LVL (void) :
			fDELAYTIME(0.0f),

			fLIFE(0.0f),
			wAPPLYRANGE(0),
			wAPPLYNUM(1),
			wAPPLYANGLE(0),
			wPIERCENUM(1),
			wTARNUM(1),

			fBASIC_VAR(0.0f),

			wUSE_ARROWNUM(0),
			wUSE_CHARMNUM(0),

			wUSE_EXP(0),
			wUSE_HP(0),
			wUSE_MP(0),
			wUSE_SP(0),

			wUSE_HP_PTY(0),
			wUSE_MP_PTY(0),
			wUSE_SP_PTY(0),

			wUSE_CP(0),
			wUSE_BULLET(0),
			wUSE_EXTRA(0)
		{
		}
	};

	struct SBASIC_100
	{
		SNATIVEID			sNATIVEID;					//	���� ID. ( ���� �����ÿ� �ο��Ǵ� ���� ID )

		char				szNAME[MAX_SZNAME];			//	��ų�� �̸�.
		DWORD				dwGRADE;					//	���.

		EMROLE				emROLE;						//	��ų ���� Ư��. ( ���, ����, ��ú� )
		EMAPPLY				emAPPLY;					//	��ų ����. ( ��������, ��������, ���� ���� )

		//	Skill �� ���� �޴� ��ǥ.
		EMIMPACT_TAR		emIMPACT_TAR;				//	Ÿ��. ( �ڽ�, ���, ��ġ ) &&
		EMIMPACT_REALM		emIMPACT_REALM;				//	����. ( Ÿ��, Ÿ�ٰ� �� ����, �� ���� ) &&
		EMIMPACT_SIDE		emIMPACT_SIDE;				//	"��" ( �� ������ �ڱ���, �� ������ ����� )
		
		WORD				wTARRANGE;					//	��ǥ ���� �Ÿ�.

		glold::GLITEM_ATT_102	emUSE_LITEM;			//	��밡�� �޼� ���� �Ӽ�.
		glold::GLITEM_ATT_102	emUSE_RITEM;			//	��밡�� ������ ���� �Ӽ�.
	};

	struct SBASIC_101
	{
		SNATIVEID			sNATIVEID;					//	���� ID. ( ���� �����ÿ� �ο��Ǵ� ���� ID )

		char				szNAME[MAX_SZNAME];			//	��ų�� �̸�.
		DWORD				dwGRADE;					//	���.

		EMROLE				emROLE;						//	��ų ���� Ư��. ( ���, ����, ��ú� )
		EMAPPLY				emAPPLY;					//	��ų ����. ( ��������, ��������, ���� ���� )

		//	Skill �� ���� �޴� ��ǥ.
		EMIMPACT_TAR		emIMPACT_TAR;				//	Ÿ��. ( �ڽ�, ���, ��ġ ) &&
		EMIMPACT_REALM		emIMPACT_REALM;				//	����. ( Ÿ��, Ÿ�ٰ� �� ����, �� ���� ) &&
		EMIMPACT_SIDE		emIMPACT_SIDE;				//	"��" ( �� ������ �ڱ���, �� ������ ����� )
		
		WORD				wTARRANGE;					//	��ǥ ���� �Ÿ�.

		glold::GLITEM_ATT_102	emUSE_LITEM;			//	��밡�� �޼� ���� �Ӽ�.
		glold::GLITEM_ATT_102	emUSE_RITEM;			//	��밡�� ������ ���� �Ӽ�.
	};

	struct SBASIC_102
	{
		SNATIVEID			sNATIVEID;					//	���� ID. ( ���� �����ÿ� �ο��Ǵ� ���� ID )

		char				szNAME[MAX_SZNAME];			//	��ų�� �̸�.
		DWORD				dwGRADE;					//	���.

		EMROLE				emROLE;						//	��ų ���� Ư��. ( ���, ����, ��ú� )
		EMAPPLY				emAPPLY;					//	��ų ����. ( ��������, ��������, ���� ���� )

		//	Skill �� ���� �޴� ��ǥ.
		EMIMPACT_TAR		emIMPACT_TAR;				//	Ÿ��. ( �ڽ�, ���, ��ġ ) &&
		EMIMPACT_REALM		emIMPACT_REALM;				//	����. ( Ÿ��, Ÿ�ٰ� �� ����, �� ���� ) &&
		EMIMPACT_SIDE		emIMPACT_SIDE;				//	"��" ( �� ������ �ڱ���, �� ������ ����� )
		
		WORD				wTARRANGE;					//	��ǥ ���� �Ÿ�.

		glold_103::GLITEM_ATT_103	emUSE_LITEM;			//	��밡�� �޼� ���� �Ӽ�.
		glold_103::GLITEM_ATT_103	emUSE_RITEM;			//	��밡�� ������ ���� �Ӽ�.
	};

	struct SBASIC_103
	{
		SNATIVEID			sNATIVEID;					//	���� ID. ( ���� �����ÿ� �ο��Ǵ� ���� ID )

		char				szNAME[MAX_SZNAME];			//	��ų�� �̸�.
		DWORD				dwGRADE;					//	���.

		EMROLE				emROLE;						//	��ų ���� Ư��. ( ���, ����, ��ú� )
		EMAPPLY				emAPPLY;					//	��ų ����. ( ��������, ��������, ���� ���� )

		//	Skill �� ���� �޴� ��ǥ.
		EMIMPACT_TAR		emIMPACT_TAR;				//	Ÿ��. ( �ڽ�, ���, ��ġ ) &&
		EMIMPACT_REALM		emIMPACT_REALM;				//	����. ( Ÿ��, Ÿ�ٰ� �� ����, �� ���� ) &&
		EMIMPACT_SIDE		emIMPACT_SIDE;				//	"��" ( �� ������ �ڱ���, �� ������ ����� )
		
		WORD				wTARRANGE;					//	��ǥ ���� �Ÿ�.

		GLITEM_ATT			emUSE_LITEM;				//	��밡�� �޼� ���� �Ӽ�.
		GLITEM_ATT			emUSE_RITEM;				//	��밡�� ������ ���� �Ӽ�.
	};

	struct SBASIC_105
	{
		enum { VERSION = SKILLEDIT_VER, };

		SNATIVEID			sNATIVEID;					//	���� ID. ( ���� �����ÿ� �ο��Ǵ� ���� ID )

		char				szNAME[MAX_SZNAME];			//	��ų�� �̸�.
		DWORD				dwGRADE;					//	���.
		DWORD				dwMAXLEVEL;					//	�ִ� ����.

		EMROLE				emROLE;						//	��ų ���� Ư��. ( ���, ����, ��ú� )
		EMAPPLY				emAPPLY;					//	��ų ����. ( ��������, ��������, ���� ���� )

		//	Skill �� ���� �޴� ��ǥ.
		EMIMPACT_TAR		emIMPACT_TAR;				//	Ÿ��. ( �ڽ�, ���, ��ġ ) &&
		EMIMPACT_REALM		emIMPACT_REALM;				//	����. ( Ÿ��, Ÿ�ٰ� �� ����, �� ���� ) &&
		EMIMPACT_SIDE		emIMPACT_SIDE;				//	"��" ( �� ������ �ڱ���, �� ������ ����� )

		WORD				wTARRANGE;					//	��ǥ ���� �Ÿ�.

		GLITEM_ATT			emUSE_LITEM;				//	��밡�� �޼� ���� �Ӽ�.
		GLITEM_ATT			emUSE_RITEM;				//	��밡�� ������ ���� �Ӽ�.
	};


	struct SBASIC
	{
		enum { VERSION = SKILLEDIT_VER, };

		SNATIVEID			sNATIVEID;					//	���� ID. ( ���� �����ÿ� �ο��Ǵ� ���� ID )

		char				szNAME[MAX_SZNAME];			//	��ų�� �̸�.
		DWORD				dwGRADE;					//	���.
		DWORD				dwMAXLEVEL;					//	�ִ� ����.

		EMROLE				emROLE;						//	��ų ���� Ư��. ( ���, ����, ��ú� )
		EMAPPLY				emAPPLY;					//	��ų ����. ( ��������, ��������, ���� ���� )

		//	Skill �� ���� �޴� ��ǥ.
		EMIMPACT_TAR		emIMPACT_TAR;				//	Ÿ��. ( �ڽ�, ���, ��ġ ) &&
		EMIMPACT_REALM		emIMPACT_REALM;				//	����. ( Ÿ��, Ÿ�ٰ� �� ����, �� ���� ) &&
		EMIMPACT_SIDE		emIMPACT_SIDE;				//	"��" ( �� ������ �ڱ���, �� ������ ����� )
		
		WORD				wTARRANGE;					//	��ǥ ���� �Ÿ�.

		GLITEM_ATT			emUSE_LITEM;				//	��밡�� �޼� ���� �Ӽ�.
		GLITEM_ATT			emUSE_RITEM;				//	��밡�� ������ ���� �Ӽ�.

		bool				bLearnView;					//  GM�� ���̴� ��ų

		SBASIC (void) :
			dwGRADE(0),
			dwMAXLEVEL(9),

			emROLE(EMROLE_NORMAL),
			emAPPLY(EMAPPLY_MAGIC),

			emIMPACT_TAR(TAR_SPEC),
			emIMPACT_REALM(REALM_SELF),
			emIMPACT_SIDE(SIDE_ENERMY),

			wTARRANGE(50),

			emUSE_LITEM(ITEMATT_NOCARE),
			emUSE_RITEM(ITEMATT_NOCARE),
			bLearnView(FALSE)
		{
			SecureZeroMemory ( szNAME, sizeof(char)*MAX_SZNAME );
		}

		void Assign ( SBASIC_100 &sOldData );
		void Assign ( SBASIC_101 &sOldData );
		void Assign ( SBASIC_102 &sOldData );
		void Assign ( SBASIC_103 &sOldData );
		void Assign ( SBASIC_105 &sOldData );
		bool LOAD_GS_0112 ( basestream &SFile );
		bool LOAD_GS_0113 ( basestream &SFile );

		static VOID SaveCsvHead ( std::fstream &SFile );
		static VOID SaveCsvHead_old ( std::fstream &SFile );
		VOID SaveCsv ( std::fstream &SFile );
		VOID SaveCsv_old ( std::fstream &SFile );
		VOID LoadCsv ( CStringArray &StrArray );
		VOID LoadCsv_106 ( CStringArray &StrArray );
		VOID LoadCsv_old ( CStringArray &StrArray );
		VOID LoadCsv_oldj ( CStringArray &StrArray );
	};

	struct SAPPLY_100
	{
		//	�⺻ ���밪 ����.
		SKILL::EMTYPES		emBASIC_TYPE;				//	���밪 Ÿ��.
		EMELEMENT			emELEMENT;					//	( ��, ��, ȭ, ��, ���� ) �Ӽ�.
		DWORD				dwCUREFLAG;					//	�ص� ����.
		SKILL::CDATA_LVL_100 sDATA_LVL[MAX_LEVEL];		//	������ ���� ��.

		//	�ΰ� ȿ�� ����.
		EMIMPACT_ADDON		emADDON;					//	�ΰ�ȿ�� ����.
		float				fADDON_VAR[MAX_LEVEL];		//	��ȭ ��ġ.

		//	�����̻� ����.
		EMSTATE_BLOW		emSTATE_BLOW;				//	���� �̻� ���� Ÿ��.
		SKILL::SSTATE_BLOW	sSTATE_BLOW[MAX_LEVEL];		//	���� �̻� ��ġ��.

		//	Ư����� ����.
		EMSPEC_ADDON		emSPEC;						//	Ư��.
		SKILL::SSPEC_100	sSPEC[MAX_LEVEL];			//	Ư�� ��� ������.
	};

	struct SAPPLY_101
	{
		//	�⺻ ���밪 ����.
		SKILL::EMTYPES		emBASIC_TYPE;				//	���밪 Ÿ��.
		EMELEMENT			emELEMENT;					//	( ��, ��, ȭ, ��, ���� ) �Ӽ�.
		DWORD				dwCUREFLAG;					//	�ص� ����.
		SKILL::CDATA_LVL_101	sDATA_LVL[MAX_LEVEL];		//	������ ���� ��.

		//	�ΰ� ȿ�� ����.
		EMIMPACT_ADDON		emADDON;					//	�ΰ�ȿ�� ����.
		float				fADDON_VAR[MAX_LEVEL];		//	��ȭ ��ġ.

		//	�����̻� ����.
		EMSTATE_BLOW		emSTATE_BLOW;				//	���� �̻� ���� Ÿ��.
		SKILL::SSTATE_BLOW	sSTATE_BLOW[MAX_LEVEL];		//	���� �̻� ��ġ��.

		//	Ư����� ����.
		EMSPEC_ADDON		emSPEC;						//	Ư��.
		SKILL::SSPEC_100	sSPEC[MAX_LEVEL];			//	Ư�� ��� ������.
	};

	struct SAPPLY_102
	{
		//	�⺻ ���밪 ����.
		SKILL::EMTYPES		emBASIC_TYPE;				//	���밪 Ÿ��.
		EMELEMENT			emELEMENT;					//	( ��, ��, ȭ, ��, ���� ) �Ӽ�.
		DWORD				dwCUREFLAG;					//	�ص� ����.
		SKILL::CDATA_LVL_101	sDATA_LVL[MAX_LEVEL];		//	������ ���� ��.

		//	�ΰ� ȿ�� ����.
		EMIMPACT_ADDON		emADDON;					//	�ΰ�ȿ�� ����.
		float				fADDON_VAR[MAX_LEVEL];		//	��ȭ ��ġ.

		//	�����̻� ����.
		EMSTATE_BLOW		emSTATE_BLOW;				//	���� �̻� ���� Ÿ��.
		SKILL::SSTATE_BLOW	sSTATE_BLOW[MAX_LEVEL];		//	���� �̻� ��ġ��.

		//	Ư����� ����.
		EMSPEC_ADDON		emSPEC;						//	Ư��.
		SKILL::SSPEC_100	sSPEC[MAX_LEVEL];			//	Ư�� ��� ������.
	};

	struct SAPPLY_103
	{
		//	�⺻ ���밪 ����.
		SKILL::EMTYPES		emBASIC_TYPE;				//	���밪 Ÿ��.
		EMELEMENT			emELEMENT;					//	( ��, ��, ȭ, ��, ���� ) �Ӽ�.
		DWORD				dwCUREFLAG;					//	�ص� ����.
		SKILL::CDATA_LVL_101	sDATA_LVL[MAX_LEVEL];		//	������ ���� ��.

		//	�ΰ� ȿ�� ����.
		EMIMPACT_ADDON		emADDON;					//	�ΰ�ȿ�� ����.
		float				fADDON_VAR[MAX_LEVEL];		//	��ȭ ��ġ.

		//	�����̻� ����.
		EMSTATE_BLOW		emSTATE_BLOW;				//	���� �̻� ���� Ÿ��.
		SKILL::SSTATE_BLOW	sSTATE_BLOW[MAX_LEVEL];		//	���� �̻� ��ġ��.

		//	Ư����� ����.
		EMSPEC_ADDON		emSPEC;						//	Ư��.
		SKILL::SSPEC		sSPEC[MAX_LEVEL];			//	Ư�� ��� ������.
	};

	struct SAPPLY_104
	{
		SKILL::EMTYPES		emBASIC_TYPE;				//	���밪 Ÿ��.
		EMELEMENT			emELEMENT;					//	( ��, ��, ȭ, ��, ���� ) �Ӽ�.
		DWORD				dwCUREFLAG;					//	�ص� ����.
		SKILL::CDATA_LVL	sDATA_LVL[MAX_LEVEL];		//	������ ���� ��.

		//	�ΰ� ȿ�� ����.
		EMIMPACT_ADDON		emADDON;					//	�ΰ�ȿ�� ����.
		float				fADDON_VAR[MAX_LEVEL];		//	��ȭ ��ġ.

		//	�����̻� ����.
		EMSTATE_BLOW		emSTATE_BLOW;				//	���� �̻� ���� Ÿ��.
		SKILL::SSTATE_BLOW	sSTATE_BLOW[MAX_LEVEL];		//	���� �̻� ��ġ��.

		//	Ư����� ����.
		EMSPEC_ADDON		emSPEC;						//	Ư��.
		SKILL::SSPEC		sSPEC[MAX_LEVEL];			//	Ư�� ��� ������.
	};

	struct SADDONS
	{
		EMIMPACT_ADDON		emADDON;
		float				fADDON_VAR[MAX_LEVEL];
	};

	struct SSPECS
	{
		EMSPEC_ADDON		emSPEC;
		SKILL::SSPEC		sSPEC[MAX_LEVEL];
	};

	struct SSPEC_DESCRIPTOR {
		EMSPEC_ADDON		emSPEC;
		SKILL::SSPEC		sSPEC[MAX_LEVEL];

		SSPEC_DESCRIPTOR()
			: emSPEC(EMSPECA_NULL)
		{}
	};

	//dmk14 | 11-13-16 | SIMPACT_DESCRIPTOR
	struct SIMPACT_DESCRIPTOR
	{
		EMIMPACT_ADDON		emADDON;
		float				fADDON_VAR[MAX_LEVEL];
		float				fADDON_VAR2[MAX_LEVEL];

		SIMPACT_DESCRIPTOR() :
			emADDON(EMIMPACTA_NONE)
		{
			for( int i=0; i<MAX_LEVEL ; ++i)
			{
				fADDON_VAR[i]	=0.0f;
				fADDON_VAR2[i]	=0.0f;
			}
		}
	};

	struct SAPPLY
	{
		enum { VERSION = 0x0105, };
		enum { MAX_DESCRIPTOR = 10 };	// increase version when changing this

		//	�⺻ ���밪 ����.
		SKILL::EMTYPES		emBASIC_TYPE;				//	���밪 Ÿ��.
		EMELEMENT			emELEMENT;					//	( ��, ��, ȭ, ��, ���� ) �Ӽ�.
		DWORD				dwCUREFLAG;					//	�ص� ����.
		SKILL::CDATA_LVL	sDATA_LVL[MAX_LEVEL];		//	������ ���� ��.

		//dmk14 | 11-13-16 | SIMPACT_DESCRIPTOR
		SIMPACT_DESCRIPTOR	sadon[MAX_DESCRIPTOR];

		//	�����̻� ����.
		EMSTATE_BLOW		emSTATE_BLOW;				//	���� �̻� ���� Ÿ��.
		SKILL::SSTATE_BLOW	sSTATE_BLOW[MAX_LEVEL];		//	���� �̻� ��ġ��.

		SSPEC_DESCRIPTOR	spec[MAX_DESCRIPTOR];

		void Assign ( SAPPLY_100 &sOldData );
		void Assign ( SAPPLY_101 &sOldData );
		void Assign ( SAPPLY_102 &sOldData );
		void Assign ( SAPPLY_103 &sOldData );
		void Assign ( SAPPLY_104 &sOldData );

		BOOL LOAD_GS_110 ( basestream &SFile );
		BOOL LOAD_GS_111 ( basestream &SFile );

		SAPPLY (void) :
			emBASIC_TYPE(EMFOR_HP),
			emELEMENT(EMELEMENT_SPIRIT),
			dwCUREFLAG(NULL),

			emSTATE_BLOW(EMBLOW_NONE)
		{
			//for ( int i=0; i<MAX_LEVEL; ++i )	fADDON_VAR[i] = 0;
		}

		//dmk14 | 11-13-16 | SIMPACT_DESCRIPTOR
		const SSPEC_DESCRIPTOR *GetSpec( EMSPEC_ADDON emSPEC ) const;
		const SIMPACT_DESCRIPTOR *GetImpact( EMIMPACT_ADDON emADDON ) const;

		static VOID SaveCsvHead ( std::fstream &SFile );
		static VOID SaveCsvHead_old ( std::fstream &SFile );
		static VOID SaveCsvHead_oldj ( std::fstream &SFile );
		VOID SaveCsv ( std::fstream &SFile );
		VOID SaveCsv_old ( std::fstream &SFile );
		VOID SaveCsv_oldj ( std::fstream &SFile );
		VOID LoadCsv ( CStringArray &StrArray );
		VOID LoadCsv_106 ( CStringArray &StrArray );
		VOID LoadCsv_old ( CStringArray &StrArray );
		VOID LoadCsv_oldj ( CStringArray &StrArray );
	};

	//	���� �� ���� ����.
	struct SLEARN_LVL_100
	{
		DWORD		dwSKP;					//	�䱸 ��ų ����Ʈ.
		DWORD		dwLEVEL;				//	�䱸 Level.
		//SCHARSTATS			sSTATS;					//	�䱸 Stats.
		WORD		wPow;
		WORD		wStr;
		WORD		wSpi;
		WORD		wDex;
		WORD		wInt;
		WORD		wSta;

		DWORD		dwSKILL_LVL;			//	�䱸 ������ų ����.
	};
	struct SLEARN_LVL_101
	{
		DWORD		dwSKP;					//	�䱸 ��ų ����Ʈ.
		DWORD		dwLEVEL;				//	�䱸 Level.
		//SCHARSTATS			sSTATS;					//	�䱸 Stats.
		WORD		wPow;
		WORD		wStr;
		WORD		wSpi;
		WORD		wDex;
		WORD		wInt;
		WORD		wSta;

		DWORD		dwSKILL_LVL;			//	�䱸 ������ų ����.
		int		nREBORN;	
	};

	struct SLEARN_LVL_102
	{
		DWORD				dwSKP;					//	�䱸 ��ų ����Ʈ.
		DWORD				dwLEVEL;				//	�䱸 Level.
		//SCHARSTATS			sSTATS;					//	�䱸 Stats.
		DWORD		dwPow;
		DWORD		dwStr;
		DWORD		dwSpi;
		DWORD		dwDex;
		DWORD		dwInt;
		DWORD		dwSta;

		DWORD				dwSKILL_LVL;			//	�䱸 ������ų ����.
		int				nREBORN;	
	};

	struct SLEARN_LVL_103
	{
		DWORD				dwSKP;					//	�䱸 ��ų ����Ʈ.
		DWORD				dwLEVEL;				//	�䱸 Level.
		SCHARSTATS			sSTATS;					//	�䱸 Stats.

		DWORD				dwSKILL_LVL;			//	�䱸 ������ų ����.
		int				nREBORN;	
	};

	struct SLEARN_LVL_PH_100
	{
		DWORD		dwLEVEL;
		WORD		wPow;
		WORD		wStr;
		WORD		wSpi;
		WORD		wDex;
		WORD		wInt;
		WORD		wSta;

		DWORD		dwSKP;
		DWORD		dwSKILL_LVL;

		SLEARN_LVL_PH_100 (void) :
		dwSKP(1),
			dwLEVEL(1),
			dwSKILL_LVL(0)
		{
		}
	};

	struct SLEARN_LVL
	{
		DWORD				dwSKP;					//	�䱸 ��ų ����Ʈ.
		DWORD				dwLEVEL;				//	�䱸 Level.
		SCHARSTATS			sSTATS;					//	�䱸 Stats.

		DWORD				dwSKILL_LVL;			//	�䱸 ������ų ����.
		int				nREBORN;

		DWORD				dwMoneyReq;
		DWORD				dwPremPoint;
		DWORD				dwVotePoint;

		SLEARN_LVL (void) :
			dwSKP(1),
			dwLEVEL(1),

			dwSKILL_LVL(0),
			nREBORN(0),

			dwMoneyReq(0),
			dwPremPoint(0),
			dwVotePoint(0)

		{
		}

		void Assign( SLEARN_LVL_100 &sOldData )
		{
			dwSKP = sOldData.dwSKP;
			dwLEVEL = sOldData.dwLEVEL;
			//sSTATS = sOldData.sSTATS;
			sSTATS.dwPow		= 	sOldData.wPow;
			sSTATS.dwStr		= 	sOldData.wStr;
			sSTATS.dwSpi		= 	sOldData.wSpi;
			sSTATS.dwDex		= 	sOldData.wDex;
			sSTATS.dwInt		= 	sOldData.wInt;
			sSTATS.dwSta		= 	sOldData.wSta;

			dwSKILL_LVL			= sOldData.dwSKILL_LVL;
			nREBORN			= 0;

			dwMoneyReq			= 0;
			dwPremPoint			= 0;
			dwVotePoint			= 0;
		}

		void Assign( SLEARN_LVL_101 &sOldData )
		{
			dwSKP = sOldData.dwSKP;
			dwLEVEL = sOldData.dwLEVEL;
			//sSTATS = sOldData.sSTATS;
			sSTATS.dwPow		= 	sOldData.wPow;
			sSTATS.dwStr		= 	sOldData.wStr;
			sSTATS.dwSpi		= 	sOldData.wSpi;
			sSTATS.dwDex		= 	sOldData.wDex;
			sSTATS.dwInt		= 	sOldData.wInt;
			sSTATS.dwSta		= 	sOldData.wSta;

			dwSKILL_LVL			= sOldData.dwSKILL_LVL;
			nREBORN			= sOldData.nREBORN;

			dwMoneyReq			= 0;
			dwPremPoint			= 0;
			dwVotePoint			= 0;
		}

		void Assign( SLEARN_LVL_102 &sOldData )
		{
			dwSKP = sOldData.dwSKP;
			dwLEVEL = sOldData.dwLEVEL;
			//sSTATS = sOldData.sSTATS;
			sSTATS.dwPow		= 	sOldData.dwPow;
			sSTATS.dwStr		= 	sOldData.dwStr;
			sSTATS.dwSpi		= 	sOldData.dwSpi;
			sSTATS.dwDex		= 	sOldData.dwDex;
			sSTATS.dwInt		= 	sOldData.dwInt;
			sSTATS.dwSta		= 	sOldData.dwSta;
			
			dwSKILL_LVL = sOldData.dwSKILL_LVL;
			nREBORN = sOldData.nREBORN;

			dwMoneyReq			= 0;
			dwPremPoint			= 0;
			dwVotePoint			= 0;
		}

		void Assign( SLEARN_LVL_103 &sOldData )
		{
			dwSKP = sOldData.dwSKP;
			dwLEVEL = sOldData.dwLEVEL;
			sSTATS = sOldData.sSTATS;
			
			dwSKILL_LVL = sOldData.dwSKILL_LVL;
			nREBORN = sOldData.nREBORN;

			dwMoneyReq			= 0;
			dwPremPoint			= 0;
			dwVotePoint			= 0;
		}
	};

	struct SLEARN_100
	{
		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL_100			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.
	};

	struct SLEARN_101
	{
		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL_100			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.
	};

	struct SLEARN_102
	{
		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL_101			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.
	};

	struct SLEARN_103
	{
		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL_102			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.
	};

	struct SLEARN_104
	{
		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL_103			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.
	};

	struct SLEARN_PH_102
	{
		DWORD				dwCLASS;
		EMBRIGHT			emBRIGHT;
		SNATIVEID			sSKILL;	
		SLEARN_LVL_PH_100		sLVL_STEP[MAX_LEVEL];
	};

	struct SLEARN_GS_104
	{
		DWORD				dwCLASS;
		EMBRIGHT			emBRIGHT;
		SNATIVEID			sSKILL;	
		SLEARN_LVL_PH_100	sLVL_STEP[MAX_LEVEL];
		DWORD				dwMoneyReq;
		SNATIVEID			sWeapon;
		DWORD				dwPremPoint;
	};

	struct SLEARN_105
	{
		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL_103			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.
	};

	

	struct SLEARN
	{
		enum { VERSION = 0x0106, };

		EMBRIGHT			emBRIGHT;					//	�Ӽ�.
		DWORD				dwCLASS;					//	����.
		SNATIVEID			sSKILL;						//	�䱸 ������ų.

		SLEARN_LVL			sLVL_STEP[MAX_LEVEL];		//	���� �� �䱸 ��ġ.

		DWORD				dwMoneyReq;
		SNATIVEID			sWEAPON;
		DWORD				dwPremPoint;

		SLEARN (void) :
			emBRIGHT(BRIGHT_BOTH),
			dwCLASS(GLCC_NONE),
			sSKILL(NATIVEID_NULL()),
			dwMoneyReq(0),
			sWEAPON(NATIVEID_NULL()),
			dwPremPoint(0)
		{
		}

		void Assign ( SLEARN_100 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				//sLVL_STEP[i].dwSKP = 1;
				sLVL_STEP[i].Assign ( OldData.sLVL_STEP[i] );
			}
		}
		void Assign ( SLEARN_101 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				//sLVL_STEP[i].dwSKP = 1;
				sLVL_STEP[i].Assign ( OldData.sLVL_STEP[i] );
			}
		}

		void Assign ( SLEARN_102 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				//sLVL_STEP[i].dwSKP = 1;
				sLVL_STEP[i].Assign ( OldData.sLVL_STEP[i] );
			}
		}

		void Assign ( SLEARN_103 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				//sLVL_STEP[i].dwSKP = 1;
				sLVL_STEP[i].Assign ( OldData.sLVL_STEP[i] );
			}
		}

		void Assign ( SLEARN_104 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				//sLVL_STEP[i].dwSKP = 1;
				sLVL_STEP[i].Assign ( OldData.sLVL_STEP[i] );
			}
		}

		void Assign ( SLEARN_PH_102 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				sLVL_STEP[i].dwSKP = OldData.sLVL_STEP[i].dwSKP;
				sLVL_STEP[i].dwLEVEL = OldData.sLVL_STEP[i].dwLEVEL;
				sLVL_STEP[i].dwSKILL_LVL = OldData.sLVL_STEP[i].dwSKILL_LVL;
				sLVL_STEP[i].sSTATS.dwPow =  OldData.sLVL_STEP[i].wPow;
				sLVL_STEP[i].sSTATS.dwDex =  OldData.sLVL_STEP[i].wDex;
				sLVL_STEP[i].sSTATS.dwInt =  OldData.sLVL_STEP[i].wInt;
				sLVL_STEP[i].sSTATS.dwSpi =  OldData.sLVL_STEP[i].wSpi;
				sLVL_STEP[i].sSTATS.dwSta =  OldData.sLVL_STEP[i].wSta;
				sLVL_STEP[i].sSTATS.dwStr =  OldData.sLVL_STEP[i].wStr;
			}

			emBRIGHT = OldData.emBRIGHT;
			dwCLASS = OldData.dwCLASS;
			sSKILL = OldData.sSKILL;
		}

		void Assign( SLEARN_GS_104 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				sLVL_STEP[i].dwSKP = OldData.sLVL_STEP[i].dwSKP;
				sLVL_STEP[i].dwLEVEL = OldData.sLVL_STEP[i].dwLEVEL;
				sLVL_STEP[i].dwSKILL_LVL = OldData.sLVL_STEP[i].dwSKILL_LVL;
				sLVL_STEP[i].sSTATS.dwPow =  OldData.sLVL_STEP[i].wPow;
				sLVL_STEP[i].sSTATS.dwDex =  OldData.sLVL_STEP[i].wDex;
				sLVL_STEP[i].sSTATS.dwInt =  OldData.sLVL_STEP[i].wInt;
				sLVL_STEP[i].sSTATS.dwSpi =  OldData.sLVL_STEP[i].wSpi;
				sLVL_STEP[i].sSTATS.dwSta =  OldData.sLVL_STEP[i].wSta;
				sLVL_STEP[i].sSTATS.dwStr =  OldData.sLVL_STEP[i].wStr;
			}

			emBRIGHT = OldData.emBRIGHT;
			dwCLASS = OldData.dwCLASS;
			sSKILL = OldData.sSKILL;

			dwMoneyReq = OldData.dwMoneyReq;
			sWEAPON = OldData.sWeapon;
			dwPremPoint  = OldData.dwMoneyReq;
		}

		// o di ba haha
		void Assign ( SLEARN_105 &OldData )
		{
			for ( int i=0; i<MAX_LEVEL; ++i )
			{
				//sLVL_STEP[i].dwSKP = 1;
				sLVL_STEP[i].Assign ( OldData.sLVL_STEP[i] );
			}
		}

		


		static VOID SaveCsvHead ( std::fstream &SFile );
		static VOID SaveCsvHead_old ( std::fstream &SFile );
		VOID SaveCsv ( std::fstream &SFile );
		VOID SaveCsv_old ( std::fstream &SFile );
		VOID LoadCsv ( CStringArray &StrArray );
		VOID LoadCsv_106 ( CStringArray &StrArray );
		VOID LoadCsv_old ( CStringArray &StrArray );
		VOID LoadCsv_oldj ( CStringArray &StrArray );
	};

	struct SEXT_DATA_100
	{
		EMANI_MAINTYPE		emANIMTYPE;						//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;						//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		EMEFFECTIME			emTARG;
		char				szTARG[MAX_SZFILE];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		char				szSELFZONE01[MAX_SZFILE];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		char				szTARGZONE01[MAX_SZFILE];		//	��ǥ ��ġ ����Ʈ.
		EMEFFECTIME			emTARGZONE02;
		char				szTARGZONE02[MAX_SZFILE];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		char				szSELFBODY[MAX_SZFILE];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.
		EMEFFECTIME			emTARGBODY01;
		char				szTARGBODY01[MAX_SZFILE];		//	��ǥ ������ ���� �״� ����Ʈ.
		EMEFFECTIME			emTARGBODY02;
		char				szTARGBODY02[MAX_SZFILE];		//	��ǥ ������ ���� �״� ����Ʈ.

		SNATIVEID			sICONINDEX;						//	������ �ε���.
		char				szICONFILE[MAX_SZFILE];			//	������ �ؽ��� ���� �̸�.
		
		char				szCOMMENTS[MAX_SZCOMMENT];		//	��ų�� ���� ������ ����.
	};

	struct SEXT_DATA_101
	{
		EMANI_MAINTYPE		emANIMTYPE;						//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;						//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		EMEFFECTIME			emTARG;
		char				szTARG[MAX_SZFILE];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		char				szSELFZONE01[MAX_SZFILE];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		char				szSELFZONE02[MAX_SZFILE];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		char				szTARGZONE01[MAX_SZFILE];		//	��ǥ ��ġ ����Ʈ.
		
		EMEFFECTIME			emTARGZONE02;
		char				szTARGZONE02[MAX_SZFILE];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		char				szSELFBODY[MAX_SZFILE];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.
		EMEFFECTIME			emTARGBODY01;
		char				szTARGBODY01[MAX_SZFILE];		//	��ǥ ������ ���� �״� ����Ʈ.
		EMEFFECTIME			emTARGBODY02;
		char				szTARGBODY02[MAX_SZFILE];		//	��ǥ ������ ���� �״� ����Ʈ.

		SNATIVEID			sICONINDEX;						//	������ �ε���.
		char				szICONFILE[MAX_SZFILE];			//	������ �ؽ��� ���� �̸�.
		
		char				szCOMMENTS[MAX_SZCOMMENT];		//	��ų�� ���� ������ ����.
	};

	struct SEXT_DATA_102
	{
		EMANI_MAINTYPE		emANIMTYPE;						//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;						//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		EMEFFECTIME			emTARG;
		EMEFFECTPOS			emTARG_POSA;
		EMEFFECTPOS			emTARG_POSB;
		char				szTARG[MAX_SZFILE];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		EMEFFECTPOS			emSELFZONE01_POS;
		char				szSELFZONE01[MAX_SZFILE];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		EMEFFECTPOS			emSELFZONE02_POS;
		char				szSELFZONE02[MAX_SZFILE];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		EMEFFECTPOS			emTARGZONE01_POS;
		char				szTARGZONE01[MAX_SZFILE];		//	��ǥ ��ġ ����Ʈ.
		
		EMEFFECTIME			emTARGZONE02;
		EMEFFECTPOS			emTARGZONE02_POS;
		char				szTARGZONE02[MAX_SZFILE];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		char				szSELFBODY[MAX_SZFILE];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.
		EMEFFECTIME			emTARGBODY01;
		char				szTARGBODY01[MAX_SZFILE];		//	��ǥ ������ ���� �״� ����Ʈ.
		EMEFFECTIME			emTARGBODY02;
		char				szTARGBODY02[MAX_SZFILE];		//	��ǥ ������ ���� �״� ����Ʈ.

		SNATIVEID			sICONINDEX;						//	������ �ε���.
		char				szICONFILE[MAX_SZFILE];			//	������ �ؽ��� ���� �̸�.
		
		char				szCOMMENTS[MAX_SZCOMMENT];		//	��ų�� ���� ������ ����.
	};

	struct SEXT_DATA_103
	{
		EMANI_MAINTYPE		emANIMTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		EMEFFECTIME			emTARG;
		EMEFFECTPOS			emTARG_POSA;
		EMEFFECTPOS			emTARG_POSB;
		std::string			strTARG[EMELEMENT_OLDMAX];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		EMEFFECTPOS			emSELFZONE01_POS;
		std::string			strSELFZONE01[EMELEMENT_OLDMAX];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		EMEFFECTPOS			emSELFZONE02_POS;
		std::string			strSELFZONE02[EMELEMENT_OLDMAX];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		EMEFFECTPOS			emTARGZONE01_POS;
		std::string			strTARGZONE01[EMELEMENT_OLDMAX];		//	��ǥ ��ġ ����Ʈ.
			
		EMEFFECTIME			emTARGZONE02;
		EMEFFECTPOS			emTARGZONE02_POS;
		std::string			strTARGZONE02[EMELEMENT_OLDMAX];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		std::string			strSELFBODY[EMELEMENT_OLDMAX];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY01;
		std::string			strTARGBODY01[EMELEMENT_OLDMAX];		//	��ǥ ������ ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY02;
		std::string			strTARGBODY02[EMELEMENT_OLDMAX];		//	��ǥ ������ ���� �״� ����Ʈ.

		std::string			strHOLDOUT;								//	��� ����Ʈ.

		SNATIVEID			sICONINDEX;								//	������ �ε���.
		std::string			strICONFILE;							//	������ �ؽ��� ���� �̸�.
		
		std::string			strCOMMENTS;							//	��ų�� ���� ������ ����.

		BOOL LOAD ( basestream &SFile );
	};

	struct SEXT_DATA_104
	{
		EMANI_MAINTYPE		emANIMTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		float				fDELAY4DAMAGE;							//	����� �߻� ������.
		EMEFFECTIME			emTARG;
		EMEFFECTPOS			emTARG_POSA;
		EMEFFECTPOS			emTARG_POSB;
		std::string			strTARG[EMELEMENT_OLDMAX];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		EMEFFECTPOS			emSELFZONE01_POS;
		std::string			strSELFZONE01[EMELEMENT_OLDMAX];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		EMEFFECTPOS			emSELFZONE02_POS;
		std::string			strSELFZONE02[EMELEMENT_OLDMAX];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		EMEFFECTPOS			emTARGZONE01_POS;
		std::string			strTARGZONE01[EMELEMENT_OLDMAX];		//	��ǥ ��ġ ����Ʈ.
			
		EMEFFECTIME			emTARGZONE02;
		EMEFFECTPOS			emTARGZONE02_POS;
		std::string			strTARGZONE02[EMELEMENT_OLDMAX];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		std::string			strSELFBODY[EMELEMENT_OLDMAX];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY01;
		std::string			strTARGBODY01[EMELEMENT_OLDMAX];		//	��ǥ ������ ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY02;
		std::string			strTARGBODY02[EMELEMENT_OLDMAX];		//	��ǥ ������ ���� �״� ����Ʈ.

		std::string			strHOLDOUT;								//	��� ����Ʈ.

		SNATIVEID			sICONINDEX;								//	������ �ε���.
		std::string			strICONFILE;							//	������ �ؽ��� ���� �̸�.
		
		std::string			strCOMMENTS;							//	��ų�� ���� ������ ����.

		BOOL LOAD ( basestream &SFile );
	};

	struct SEXT_DATA_105
	{
		EMANI_MAINTYPE		emANIMTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		float				fDELAY4DAMAGE;							//	����� �߻� ������.
		EMEFFECTIME			emTARG;
		EMEFFECTPOS			emTARG_POSA;
		EMEFFECTPOS			emTARG_POSB;
		bool				bTARG_ONE;								//	��ǥ ���� ����Ʈ ���� ����.
		std::string			strTARG[EMELEMENT_OLDMAX];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		EMEFFECTPOS			emSELFZONE01_POS;
		std::string			strSELFZONE01[EMELEMENT_OLDMAX];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		EMEFFECTPOS			emSELFZONE02_POS;
		std::string			strSELFZONE02[EMELEMENT_OLDMAX];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		EMEFFECTPOS			emTARGZONE01_POS;
		std::string			strTARGZONE01[EMELEMENT_OLDMAX];		//	��ǥ ��ġ ����Ʈ.
			
		EMEFFECTIME			emTARGZONE02;
		EMEFFECTPOS			emTARGZONE02_POS;
		std::string			strTARGZONE02[EMELEMENT_OLDMAX];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		std::string			strSELFBODY[EMELEMENT_OLDMAX];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY01;
		std::string			strTARGBODY01[EMELEMENT_OLDMAX];		//	��ǥ ������ ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY02;
		std::string			strTARGBODY02[EMELEMENT_OLDMAX];		//	��ǥ ������ ���� �״� ����Ʈ.

		std::string			strHOLDOUT;								//	��� ����Ʈ.

		SNATIVEID			sICONINDEX;								//	������ �ε���.
		std::string			strICONFILE;							//	������ �ؽ��� ���� �̸�.
		
		std::string			strCOMMENTS;							//	��ų�� ���� ������ ����.

		BOOL LOAD ( basestream &SFile );

	};

	struct SEXT_DATA_106
	{
		EMANI_MAINTYPE		emANIMTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		float				fDELAY4DAMAGE;							//	����� �߻� ������.
		EMEFFECTIME			emTARG;
		EMEFFECTPOS			emTARG_POSA;
		EMEFFECTPOS			emTARG_POSB;
		bool				bTARG_ONE;								//	��ǥ ���� ����Ʈ ���� ����.
		std::string			strTARG[EMELEMENT_MAXNUM];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		EMEFFECTPOS			emSELFZONE01_POS;
		std::string			strSELFZONE01[EMELEMENT_MAXNUM];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		EMEFFECTPOS			emSELFZONE02_POS;
		std::string			strSELFZONE02[EMELEMENT_MAXNUM];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		EMEFFECTPOS			emTARGZONE01_POS;
		std::string			strTARGZONE01[EMELEMENT_MAXNUM];		//	��ǥ ��ġ ����Ʈ.
			
		EMEFFECTIME			emTARGZONE02;
		EMEFFECTPOS			emTARGZONE02_POS;
		std::string			strTARGZONE02[EMELEMENT_MAXNUM];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emSELFBODY;
		std::string			strSELFBODY[EMELEMENT_MAXNUM];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY01;
		std::string			strTARGBODY01[EMELEMENT_MAXNUM];		//	��ǥ ������ ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY02;
		std::string			strTARGBODY02[EMELEMENT_MAXNUM];		//	��ǥ ������ ���� �״� ����Ʈ.

		std::string			strHOLDOUT;								//	��� ����Ʈ.

		SNATIVEID			sICONINDEX;								//	������ �ε���.
		std::string			strICONFILE;							//	������ �ؽ��� ���� �̸�.
		
		std::string			strCOMMENTS;							//	��ų�� ���� ������ ����.

		BOOL LOAD ( basestream &SFile );

	};
	
	struct SEXT_DATA
	{
		enum { VERSION = 0x0107, };

		EMANI_MAINTYPE		emANIMTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		
		EMANI_SUBTYPE		emANISTYPE;								//	��ų ���� ĳ������ ���ϸ��̼� ����.		

		float				fDELAY4DAMAGE;							//	����� �߻� ������.
		EMEFFECTIME			emTARG;
		EMEFFECTPOS			emTARG_POSA;
		EMEFFECTPOS			emTARG_POSB;
		bool				bTARG_ONE;								//	��ǥ ���� ����Ʈ ���� ����.
		std::string			strTARG[EMELEMENT_MAXNUM];				//	��ǥ ���� ����Ʈ.
		
		EMEFFECTIME			emSELFZONE01;
		EMEFFECTPOS			emSELFZONE01_POS;
		std::string			strSELFZONE01[EMELEMENT_MAXNUM];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE02;
		EMEFFECTPOS			emSELFZONE02_POS;
		std::string			strSELFZONE02[EMELEMENT_MAXNUM];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emSELFZONE03;
		EMEFFECTPOS			emSELFZONE03_POS;
		std::string			strSELFZONE03[EMELEMENT_MAXNUM];		//	�ڱ� ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE01;
		EMEFFECTPOS			emTARGZONE01_POS;
		std::string			strTARGZONE01[EMELEMENT_MAXNUM];		//	��ǥ ��ġ ����Ʈ.
			
		EMEFFECTIME			emTARGZONE02;
		EMEFFECTPOS			emTARGZONE02_POS;
		std::string			strTARGZONE02[EMELEMENT_MAXNUM];		//	��ǥ ��ġ ����Ʈ.

		EMEFFECTIME			emTARGZONE03;
		EMEFFECTPOS			emTARGZONE03_POS;
		std::string			strTARGZONE03[EMELEMENT_MAXNUM];		//	��ǥ ��ġ ����Ʈ.


		EMEFFECTIME			emSELFBODY;
		std::string			strSELFBODY[EMELEMENT_MAXNUM];			//	�ڱ� �ڽ��� ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY01;
		std::string			strTARGBODY01[EMELEMENT_MAXNUM];		//	��ǥ ������ ���� �״� ����Ʈ.

		EMEFFECTIME			emTARGBODY02;
		std::string			strTARGBODY02[EMELEMENT_MAXNUM];		//	��ǥ ������ ���� �״� ����Ʈ.

		std::string			strHOLDOUT;								//	��� ����Ʈ.

		SNATIVEID			sICONINDEX;								//	������ �ε���.
		std::string			strICONFILE;							//	������ �ؽ��� ���� �̸�.
		
		std::string			strCOMMENTS;							//	��ų�� ���� ������ ����.

		inline void LIMIT ( EMELEMENT &emElement )
		{
			GASSERT(emElement<EMELEMENT_MAXNUM2);
			if (emElement==EMELEMENT_MAXNUM) emElement=EMELEMENT_SPIRIT;
		}

		bool VALIDTARG ( EMELEMENT emElement )					{  LIMIT(emElement); return strTARG[emElement].length()!=0; }

		const char* GETTARG ( EMELEMENT emElement )				{  LIMIT(emElement); return strTARG[emElement].c_str(); }
		const char* GETSELFZONE01 ( EMELEMENT emElement )		{  LIMIT(emElement); return strSELFZONE01[emElement].c_str(); }
		const char* GETSELFZONE02 ( EMELEMENT emElement )		{  LIMIT(emElement); return strSELFZONE02[emElement].c_str(); }
		const char* GETSELFZONE03 ( EMELEMENT emElement )		{  LIMIT(emElement); return strSELFZONE03[emElement].c_str(); }

		const char* GETTARGZONE01 ( EMELEMENT emElement )		{  LIMIT(emElement); return strTARGZONE01[emElement].c_str(); }
		const char* GETTARGZONE02 ( EMELEMENT emElement )		{  LIMIT(emElement); return strTARGZONE02[emElement].c_str(); }
		const char* GETTARGZONE03 ( EMELEMENT emElement )		{  LIMIT(emElement); return strTARGZONE03[emElement].c_str(); }

		const char* GETSELFBODY ( EMELEMENT emElement )			{  LIMIT(emElement); return strSELFBODY[emElement].c_str(); }

		const char* GETTARGBODY01 ( EMELEMENT emElement )		{  LIMIT(emElement); return strTARGBODY01[emElement].c_str(); }
		const char* GETTARGBODY02 ( EMELEMENT emElement )		{  LIMIT(emElement); return strTARGBODY02[emElement].c_str(); }

		SEXT_DATA (void) :
			emANIMTYPE(AN_SKILL),
			emANISTYPE(AN_SUB_00),

			fDELAY4DAMAGE(0.0f),

			emTARG_POSA(EMPOS_GROUND),
			emTARG_POSB(EMPOS_GROUND),
			bTARG_ONE(false),

			emSELFZONE01_POS(EMPOS_GROUND),
			emSELFZONE02_POS(EMPOS_GROUND),
			emSELFZONE03_POS(EMPOS_GROUND),
			emTARGZONE01_POS(EMPOS_GROUND),
			emTARGZONE02_POS(EMPOS_GROUND),
			emTARGZONE03_POS(EMPOS_GROUND),

			emTARG(EMTIME_IMPACT),
			emSELFZONE01(EMTIME_FIRST),
			emSELFZONE02(EMTIME_IMPACT),
			emSELFZONE03(EMTIME_IMPACT),
			emTARGZONE01(EMTIME_TARG_OVR),
			emTARGZONE02(EMTIME_PASSIVE),
			emTARGZONE03(EMTIME_PASSIVE),

			emSELFBODY(EMTIME_FIRST),
			emTARGBODY01(EMTIME_TARG_OVR),
			emTARGBODY02(EMTIME_PASSIVE),

			sICONINDEX(0,0)
		{
		}

		void Assign ( const SEXT_DATA_100 &OldData );
		void Assign ( const SEXT_DATA_101 &OldData );
		void Assign ( const SEXT_DATA_102 &OldData );
		void Assign ( const SEXT_DATA_103 &OldData );
		void Assign ( const SEXT_DATA_104 &OldData );
		void Assign ( const SEXT_DATA_105 &OldData );
		void Assign ( const SEXT_DATA_106 &OldData );

		BOOL SAVE ( CSerialFile &SFile );
		BOOL LOAD ( basestream &SFile );
		BOOL LOAD_GS_0110 ( basestream &SFile );

		static VOID SaveCsvHead ( std::fstream &SFile );
		static VOID SaveCsvHead_old ( std::fstream &SFile );
		VOID SaveCsv ( std::fstream &SFile );
		VOID SaveCsv_old ( std::fstream &SFile );
		VOID LoadCsv ( CStringArray &StrArray );
		VOID LoadCsv_106 ( CStringArray &StrArray );
		VOID LoadCsv_old ( CStringArray &StrArray );
		VOID LoadCsv_oldj ( CStringArray &StrArray );

		SEXT_DATA& operator= ( const SEXT_DATA &value );
	};

	struct SSPECIAL_SKILL_100
	{
		EMSPECIALSKILLTYPE	emSSTYPE;					//  Ư�� ��ų Ÿ��
		std::string			strEffectName;				//  ������ ��ų �̸�
		DWORD				dwRemainSecond;				//  ���� ��

		std::string			strTransform_Man[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�
		std::string			strTransform_Woman[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�
	};

	struct SSPECIAL_SKILL_101
	{
		EMSPECIALSKILLTYPE	emSSTYPE;					//  Ư�� ��ų Ÿ��
		std::string			strEffectName;				//  ������ ��ų �̸�
		DWORD				dwRemainSecond;				//  ���� ��

		SNATIVEID			sSummonID; //add summon
		DWORD				dwSummonTime;	//add summon

		std::string			strTransform_Man[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�
		std::string			strTransform_Woman[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�

		std::string			strTransform_Chf; //add panther
	};

	struct SSPECIAL_SKILL_102
	{
		EMSPECIALSKILLTYPE	emSSTYPE;					//  Ư�� ��ų Ÿ��
		std::string			strEffectName;				//  ������ ��ų �̸�
		DWORD				dwRemainSecond;				//  ���� ��

		SNATIVEID			sSummonID; //add summon
		DWORD				dwSummonTime;	//add summon

		std::string			strTransform_Man[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�
		std::string			strTransform_Woman[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�

		std::string			strTransform_Chf; //add panther
	};

	struct SSUMMON_DATA
	{
		//for dummy data
		SNATIVEID sSummon;
		DWORD	dwSummon;
		float	fSummon;
		BOOL	bSummon;
		WORD	wSummon;

		SSUMMON_DATA() :
			sSummon(NATIVEID_NULL()),
			dwSummon(0),
			fSummon(0.0f),
			bSummon( FALSE ),
			wSummon(0)
		{
		}
	};

	struct SSPECIAL_SKILL
	{
		enum { VERSION = 0x0103, };

		EMSPECIALSKILLTYPE	emSSTYPE;					//  Ư�� ��ų Ÿ��
		std::string			strEffectName;				//  ������ ��ų �̸�
		DWORD				dwRemainSecond;				//  ���� ��

		//SNATIVEID			sSummonID; //add summon
		//DWORD				dwSummonTime;	//add summon
		SSUMMON_DATA		sSummon[MAX_LEVEL];

		std::string			strTransform_Man[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�
		std::string			strTransform_Woman[EMTRANSFORM_NSIZE];	//	���Ž� ����ϴ� �����̸�

		std::string			strTransform_Chf; //add panther

		SSPECIAL_SKILL() :
			emSSTYPE(EMSSTYPE_NONE),
			dwRemainSecond(0)//,
			//sSummonID(NATIVEID_NULL()),//add summon
			//dwSummonTime(0)//add summon
			{
			}

		void ResetAll()
		{
			strEffectName.clear();
			dwRemainSecond = 0;
			strTransform_Chf.clear(); //add panther
			for( BYTE i = 0; i < SKILL::EMTRANSFORM_NSIZE; i++ )
			{
				strTransform_Man[i].clear();
				strTransform_Woman[i].clear();
			}
		}

		BOOL SAVE ( CSerialFile &SFile );
		BOOL LOAD_100 ( basestream &SFile );
		BOOL LOAD_101 ( basestream &SFile );
		BOOL LOAD_102 ( basestream &SFile );
		BOOL LOAD ( basestream &SFile );

		BOOL LOAD_GS_101 ( basestream &SFile );
		BOOL LOAD_GS_103 ( basestream &SFile );

		static VOID SaveCsvHead ( std::fstream &SFile );
		static VOID SaveCsvHead_old ( std::fstream &SFile );
		VOID SaveCsv ( std::fstream &SFile );
		VOID SaveCsv_old ( std::fstream &SFile );
		VOID LoadCsv ( CStringArray &StrArray );
		VOID LoadCsv_106 ( CStringArray &StrArray );
		VOID LoadCsv_old ( CStringArray &StrArray );
		VOID LoadCsv_oldj ( CStringArray &StrArray );

		SSPECIAL_SKILL & operator= ( const SSPECIAL_SKILL  &value );

	};

};


struct GLSKILL
{
	enum
	{
		VERSION			= 0x0100,

		FILE_SBASIC			= 1,
		FILE_SAPPLY			= 2,
		FILE_SLEARN			= 3,
		FILE_SEXT_DATA		= 4,
		FILE_SPECIAL_SKILL = 5,

		FILE_END_DATA	= 0xEDEDEDED,
	};

	SKILL::SBASIC		  m_sBASIC;
	SKILL::SAPPLY		  m_sAPPLY;
	SKILL::SLEARN		  m_sLEARN;
	SKILL::SEXT_DATA	  m_sEXT_DATA;
	SKILL::SSPECIAL_SKILL m_sSPECIAL_SKILL;

	GLSKILL ()
	{
	}

	BOOL SaveFile ( CSerialFile &SFile );
	BOOL LoadFile ( basestream &SFile, bool bPastLoad, bool bGS = FALSE );

	static VOID SaveCsvHead ( std::fstream &SFile );
	static VOID SaveCsvHead_old ( std::fstream &SFile );
	static VOID SaveCsvHead_oldj ( std::fstream &SFile );
	VOID SaveCsv ( std::fstream &SFile );
	VOID SaveCsv_old ( std::fstream &SFile );
	VOID SaveCsv_oldj ( std::fstream &SFile );
	VOID LoadCsv ( CStringArray &StrArray, int iLine );
	VOID LoadCsv_106 ( CStringArray &StrArray, int iLine );
	VOID LoadCsv_old ( CStringArray &StrArray, int iLine );
	VOID LoadCsv_oldj ( CStringArray &StrArray, int iLine );

	GLSKILL& operator= ( GLSKILL &value )
	{
		m_sBASIC		 = value.m_sBASIC;
		m_sAPPLY		 = value.m_sAPPLY;
		m_sLEARN		 = value.m_sLEARN;
		m_sEXT_DATA		 = value.m_sEXT_DATA;
		m_sSPECIAL_SKILL = value.m_sSPECIAL_SKILL;

		return *this;
	}

	bool	IsSkillFact ();		//	���Ӽ� ��ų
	const char* GetName();
	const char* GetDesc();
};
typedef GLSKILL* PGLSKILL;

class GLSkillMan
{
public:
	enum
	{
		ENCODE_VER = 0x0101,

		VERSION = 0x0101,
		MAX_CLASSSKILL = 99,
	};

	static const char* _FILEHEAD;
	static const char* _LOGFILE;
	static const char* _STRINGTABLE;

protected:
	char				m_szFileName[MAX_PATH];
	
	bool				m_bModify;
	PGLSKILL			m_pSkills[EMSKILLCLASS_NSIZE][MAX_CLASSSKILL];

	LPDIRECT3DDEVICEQ	m_pd3dDevice;

public:
	PGLSKILL GetData ( const WORD wClass, const WORD Index );
	PGLSKILL GetData ( const SNATIVEID &sID )	{ return GetData(sID.wMainID,sID.wSubID); }

	void	SetData ( WORD wClass, WORD Index, const PGLSKILL SkillData, bool binner=false );

public:
	WORD	FindFreeSkillIndex ( WORD wClass );
	BOOL	DeleteSkill ( WORD wClass, WORD Index );
	void	GetMaxSkill ( WORD& wClass, WORD& rIndex );	

public:
	bool	ValidData ();

public:
	bool	IsModify ()							{ return m_bModify; }

public:
	HRESULT OneTimeSceneInit ();
	HRESULT InitDeviceObjects ( LPDIRECT3DDEVICEQ pd3dDevice );
	HRESULT DeleteDeviceObjects ();
	HRESULT FinalCleanup ();

public:
	HRESULT LoadFile ( const char* szFile, bool bPastLoad, bool bGS = FALSE );
	HRESULT SaveFile ( const char* szFile );

public:
	HRESULT	SyncStringTable();
	HRESULT SyncUpdateData ();

public:
	HRESULT SaveCsvFile( CWnd* pWnd );
	HRESULT SaveCsvFile_old( CWnd* pWnd );
	HRESULT SaveCsvFile_oldj( CWnd* pWnd );
	HRESULT LoadCsvFile( CWnd* pWnd );
	HRESULT LoadCsvFile_106( CWnd* pWnd );
	HRESULT LoadCsvFile_old( CWnd* pWnd );
	HRESULT LoadCsvFile_oldj( CWnd* pWnd );

public:
	GLSkillMan ();

public:
	~GLSkillMan ();

public:
	static GLSkillMan& GetInstance();
};

namespace COMMENT
{
	enum { SKILL_ICON_SIZE=256 };

	extern std::string SKILL_ROLE[SKILL::EMROLE_NSIZE];
	extern std::string SKILL_APPLY[SKILL::EMAPPLY_NSIZE];

	extern std::string SKILL_TYPES[SKILL::FOR_TYPE_SIZE];
	extern float SKILL_TYPES_SCALE[SKILL::FOR_TYPE_SIZE];
	inline bool IsSKILL_PER ( SKILL::EMTYPES emTYPE )			{ return SKILL_TYPES_SCALE[emTYPE]==100.0f; }

	extern std::string SKILL_LEVEL[SKILL::MAX_LEVEL];

	extern std::string SKILL_EFFTIME[SKILL::EMTIME_NSIZE];
	extern std::string SKILL_EFFPOS[SKILL::EMPOS_NSIZE];
	extern std::string SPECIAL_SKILL_TYPE[SKILL::EMSSTYPE_NSIZE];

	extern std::string SPEC_STIGMA_TYPE[SKILL::EMSTIGMA_SIZE];
	extern std::string SPEC_HALLUCINATE_TYPE[SKILL::EMHALLUCINATE_SIZE];
	extern std::string SPEC_DOMINATE_TYPE[SKILL::EMDOMINATE_SIZE];
	extern std::string SPEC_ASIGN_TYPE[SKILL::EMASIGN_SIZE];
	extern std::string SPEC_INC_TYPE[SKILL::EMINC_SIZE];
	extern std::string SPEC_INVISIBLE_USE_TYPE[SKILL::EMINVISIBLE_SIZE];
	extern std::string SPEC_INVISIBLE_ANI_TYPE[SKILL::EMINVISIBLE_ANI_SIZE];
	extern std::string SPEC_SWAPPOS_DIR_TYPE[SKILL::EMSWAPPOS_DIR_SIZE];
};

#endif // GLSKILL_H_