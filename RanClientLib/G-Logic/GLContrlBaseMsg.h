#pragma once

#include "s_NetGlobal.h"
#include "GLCharData.h"
#include "GLCrowData.h"
#include "GLItem.h"
#include "GLMoney.h"
#include "GLParty.h"
#include "GLPeriod.h"
#include "GLAutoLevel.h"
#include "GLClubMan.h"
#include "GLCDMDefine.h"
//add schoolwars
#include "GLSWDefine.h"
#include "GLSWPDefine.h"
#include "GLRoyalRumbleDefine.h" //Add RoyalRumble Player Define- JADev
#include "GLTowerWarsDefine.h"

//	#include "GLContrlMsg.h"
//	�޼���E������ ũ�⸦ (NET_DATA_BUFSIZE) byte �̳��� ���� �Ͽ� ����E
//
#define NET_DELAY		(0.2f)
#define NET_MSGDELAY	(0.3f)

#define MAX_SEARCH_RESULT 10

inline float APPLY_MSGDELAY ( float &fDelay )
{
	fDelay -= NET_MSGDELAY;
	if ( fDelay < 0.0f )	fDelay = 0.0f;
	return fDelay;
}

enum EMGLMSG
{
	EMGLMSG_SKILLMAX	= 100,
	EMGLMSG_COOLTIMEMAX	= 30,
};

enum EMREQUEST_MSG
{
	EMREQMSG_OBJ_DROP	= 0,
};

enum EMTAKE_FB
{
	EMTAKE_FB_OFF				= 0,	//	�������� �����E�濁E
	EMTAKE_FB_RESERVED			= 1,	//	����E�����ڰ� �����Ǿ�E���� �濁E
	EMTAKE_FB_INVEN_ERROR		= 2,	//	�κ��丮�� ������E����.
	EMTAKE_FB_TOO_EVENT_ITEM	= 3,	//	�̹� �̺�Ʈ �������� ������E�ֽ��ϴ�.
	EMTAKE_FB_DISTANCE			= 4,	//	�Ÿ��� �ʹ� �ٴϴ�.
};

enum EMHOLD_FB
{
	EMHOLD_FB_OFF				= 0,	//	������ �������� ��������E�ʽ��ϴ�.
	EMHOLD_FB_OK				= 1,	//	�������� HOLD�մϴ�.
	EMHOLD_FB_NONKEEPSTORAGE	= 2,	//	��Ŀ�� ��ǰ�� ���� ��E����.
};

enum EMCHAR_JOIN_FB
{
	EMCJOIN_FB_ERROR		= 0,
	EMCJOIN_FB_NOWLOGIN		= 1,	//	���� �������� ���¶� ������ �ȵ˴ϴ�.
	EMCJOIN_FB_PKPOINT		= 2,	//	pk ������ ���Ƽ� �ش�Eä�ο� ���� �Ұ�.
};

enum EMDROP_OUT_FORCED
{
	EMDROPOUT_ERROR			= 0,	//	������ ���� ���� ����E
	EMDROPOUT_REQLOGIN		= 1,	//	���� ������ ���� �õ��� ���� ���� ����E
};

enum EMCHAR_GATEOUT_FB
{
	EMCHAR_GATEOUT_OK		= 0,
	EMCHAR_GATEOUT_FAIL		= 1,
	EMCHAR_GATEOUT_MAPID	= 2,
	EMCHAR_GATEOUT_GATEID	= 3,
	EMCHAR_GATEOUT_TARMAPID	= 4,
	EMCHAR_GATEOUT_TARGATEID= 5,
	EMCHAR_GATEOUT_FIELDSVR	= 6,
	EMCHAR_GATEOUT_HOLD		= 7,
	EMCHAR_GATEOUT_CONDITION = 8,
	EMCHAR_GATEOUT_CLUBBATTLE = 9,		//	�������ʽ� Ŭ����Ʋ
	EMCHAR_GATEOUT_CLUBBATTLE2 = 10,	//	CDM�ʽ� Ŭ����Ʋ
	EMCHAR_GATEOUT_NOPARTY = 11,		//	Add remove party first before entering the map - JADev (JeanArt)
};


enum EMSKILL_LEARNCHECK
{
	EMSKILL_LEARN_OK		= 0,	//	�迁E�E����E
	EMSKILL_LEARN_MAX		= 1,	//	��E�̻�E������ �� ��E����.
	EMSKILL_LEARN_NOTTERM	= 2,	//	�䱸 ������ ��������E�ʾƼ� ������ �Ҽ�E����.
	EMSKILL_LEARN_NOTCLASS	= 3,	//	�μ��� Ʋ���� �迁E�E�����ϴ�.
	EMSKILL_LEARN_NOTBRIGHT	= 4,	//	��E�� ������ ��������E�ʽ��ϴ�.
	EMSKILL_LEARN_ALREADY	= 5,	//	�̹� �迁E��ų�Դϴ�.

	EMSKILL_LEARN_UNKNOWN	= 999
};

enum EMPARTY_LURE_FB
{
	EMPARTY_LURE_OK			= 0,	//	��Ƽ ������ ����E
	EMPARTY_LURE_REFUSE		= 1,	//	��Ƽ ������ �ź�.
	
	EMPARTY_LURE_FULL		= 2,	//	��Ƽ�� �������� ���̻�E������E����.
	EMPARTY_LURE_OTHER		= 3,	//	�ٸ� ��Ƽ�� ���ԵǾ�E�־�ح ������.
	EMPARTY_LURE_OPT		= 4,	//	��Ƽ �ɼ� ����E
	EMPARTY_LURE_OTHERSCHOOL= 5,	//	�ٸ� �п������� ��Ƽ �Ұ���.
	EMPARTY_LURE_CLUBBATTLE	= 6,	//	Ŭ����Ʋ ���϶��� ��Ƽ �Ұ�
	EMPARTY_LURE_ROYAL_MAP	= 7,//add battle royale
	EMPARTY_LURE_NO_TARGET	= 8,//
};

enum EMTRADE_ANS
{
	EMTRADE_OK				= 0,
	EMTRADE_CANCEL			= 1,
};

enum EMTRADE_AGREE_FB
{
	EMTRADE_AGREE_OK		= 0,
	EMTRADE_AGREE_CANCEL	= 1,
	EMTRADE_AGREE_TIME		= 2,
};

enum EMTRADE_CANCEL_TAR
{
	EMTRADE_CANCEL_NORMAL	= 0,	//	�Ϲ����� ÁE�.
	EMTRADE_CANCEL_OTHER	= 1,	//	��E��� ÁE���.
	EMTRADE_CANCEL_MYINVEN	= 2,	//	���� ���� �ι�E����.
	EMTRADE_CANCEL_TARINVEN	= 3,	//	���� ���� �ι�E����.
};

enum EMGRINDING_FB
{
	EMGRINDING_FAIL			= 0,
	EMGRINDING_SUCCEED		= 1
};

enum EMGRINDING_RESIST_FB
{
	EMGRINDING_RESIST_FAIL			= 0,
	EMGRINDING_RESIST_SUCCEED		= 1
};
enum EMGRINDING_PERFECT_FB
{
	EMGRINDING_PERFECT_FAIL			= 0,
	EMGRINDING_PERFECT_SUCCEED		= 1
};

enum EMREGEN_GATE_FB
{
	EMREGEN_GATE_FAIL		= 0,
	EMREGEN_GATE_SUCCEED	= 1,
};

enum EMREGEN_CURE_FB
{
	EMREGEN_CURE_FAIL		= 0,
	EMREGEN_CURE_SUCCEED	= 1,
};

enum EMREGEN_CHARRESET_FB
{
	EMREGEN_CHARRESET_SUCCEED	= 0,
	EMREGEN_CHARRESET_FAIL		= 1,
	EMREGEN_CHARRESET_ITEM_FAIL	= 2,
};

enum EMNPC_ITEM_TRADE_FB
{
	EMNPC_ITEM_TRADE_SUCCEED		= 0,
	EMNPC_ITEM_TRADE_FAIL			= 1,
	EMNPC_ITEM_TRADE_ITEM_FAIL		= 2,
	EMNPC_ITEM_TRADE_INSERT_FAIL	= 3,
};

enum EMCONFRONT_FB
{
	EMCONFRONT_FAIL			= 0,	//	�Ϲ� ����E
	EMCONFRONT_AGREE		= 1,	//	��E� ����E	(ans��E
	EMCONFRONT_REFUSE		= 2,	//	��E� �ź�.
	EMCONFRONT_OPTION		= 3,	//	�ɼ� ����E
	EMCONFRONT_PEACE		= 4,	//	��ȭ ���� ��E� �Ұ�.
	EMCONFRONT_MAX			= 5,	//	n ��E�̻�E���� ��E����� time ���� ��E� ����.
	EMCONFRONT_ELAP			= 6,	//	����E��E��� time ���� ��E� ����.
	EMCONFRONT_ALREADY_ME	= 7,	//	�ڽ��� �̹� ��E���.
	EMCONFRONT_ALREADY_TAR	= 8,	//	��E��� �̹� ��E���.
	EMCONFRONT_PARTY		= 9,	//	���� ��Ƽ��E������ ��E� �Ұ�.
	EMCONFRONT_DIE_YOU		= 10,	//	��Eĳ���Ͱ� �׾��־�ح ��E� �Ұ�.
	EMCONFRONT_DIE_ME		= 11,	//	�ڽ��� ĳ���Ͱ� �׾��־�ح ��E� �Ұ�.

	EMCONFRONT_MENOTPARTY	= 12,	//	��Ƽ���� �ƴϿ��� ��Ƽ ��E��� �Ұ���.
	EMCONFRONT_MENOTMASTER	= 13,	//	��Ƽ���� �ƴϿ��� '��Ƽ��E�'�� ��û�ϽǼ�E�����ϴ�.
	EMCONFRONT_TARMASTER	= 14,	//	��Ƽ���� �ƴϿ��� '��Ƽ��E�'�� ��û�ϽǼ�E�����ϴ�.

	//EMCONFRONT_NO_BET		= 15, //add duel bet
	//EMCONFRONT_CANT_BET		= 16, //add duel bet

	//EMCONFRONT_CANT_BET_MONEY		= 17, //add duel bet
};

enum EMCONFRONT_END
{
	EMCONFRONT_END_FAIL		= 0,	//	�Ϲ� ����E
	EMCONFRONT_END_WIN		= 1,	//	�¸�.
	EMCONFRONT_END_LOSS		= 2,	//	�й�E
	EMCONFRONT_END_TIME		= 3,	//	�ð� �ʰ�E
	EMCONFRONT_END_MOVEMAP	= 4,	//	�� �̵�.
	EMCONFRONT_END_DISWIN	= 5,	//	�Ÿ��� �ʹ� ����݁E
	EMCONFRONT_END_DISLOSS	= 6,	//	�Ÿ��� �ʹ� ����݁E

	EMCONFRONT_END_PARTY	= 7,	//	��E� ���� ���� ��Ƽ���� �Ǿ�ح �����.

	EMCONFRONT_END_NOTWIN	= 10,	//	�¸��� �⿩����E����.
	EMCONFRONT_END_PWIN		= 11,	//	��Ƽ��Eÿ� �¸�.
	EMCONFRONT_END_PLOSS	= 12,	//	��Ƽ��Eÿ� �й�E
	EMCONFRONT_END_PTIME	= 13,	//	��Ƽ��E� �ð��ʰ�E

	EMCONFRONT_END_CWIN		= 14,	//	Ŭ����Eÿ� �¸�.
	EMCONFRONT_END_CLOSS	= 15,	//	Ŭ����Eÿ� �й�E
	EMCONFRONT_END_CTIME	= 16,	//	Ŭ����E� �ð��ʰ�E
};

enum EMANTIDISAPPEAR
{
	EMANTIDISAPPEAR_OFF	= 0,		// �ҹ��� ����
	EMANTIDISAPPEAR_ON	= 1,		// �ҹ��� ����E
	EMANTIDISAPPEAR_USE	= 2,		// �ҹ��� �翁E
};

// ĳ���� �κ�E���÷��̿�E������
struct SCHARINFO_LOBBY
{
	DWORD				m_dwCharID;

	char				m_szName[CHAR_SZNAME];		// �̸�. (��ݤ)
	EMCHARCLASS			m_emClass;					// ����E (��ݤ)
	WORD				m_wSchool;					// �п�E
	WORD				m_wHair;					// ǁE�ٺŸ��
	WORD				m_wFace;					// �󱼸�E
	WORD                m_wSex;                     // ���� (�߰�:2005-12-29 Jgkim)
	WORD                m_wHairColor;               // �Ӹ� ����E(�߰�:2005-12-29 Jgkim)

	//added by   | 21-6-2012 | Bypass HP+MP+SP
	GLPADATA			m_sHP;						//	����Ӯ. ( ����/�ִ�E� )					//	����Ӯ. ( ����/�ִ�E� )
	GLLLDATA			m_sExperience;				//	����ġ. ( ����/��������E��ް� )
	int					m_nBright;					//	�Ӽ�.

	WORD				m_wLevel;					//	����.
	SCHARSTATS			m_sStats;					//	Stats.

	//add reborn
	int					m_nChaReborn;

	SITEM_LOBY			m_PutOnItems[SLOT_TSIZE];	//	ǁE�E����.

	SNATIVEID			m_sSaveMapID;				//	����E��.

	SCHARINFO_LOBBY () 
		: m_dwCharID(0)
		, m_emClass(GLCC_ARMS_M)
		, m_wLevel(1)
		, m_nChaReborn(0)
		, m_wSchool(0)
		, m_wHair(0)
		, m_wFace(0)
		, m_wSex(0)
		, m_wHairColor(0)
		, m_nBright(0)
	{
		memset(m_szName, 0, sizeof(char) * CHAR_SZNAME);		
	}
};

namespace GLMSG
{
	#pragma pack(1)

	struct SNETPC_BROAD
	{
		NET_MSG_GENERIC		nmg;
		DWORD				dwGaeaID;

		SNETPC_BROAD () 
			: dwGaeaID(0)
		{
		}
	};
	
	struct SNETPK_BROAD
	{
		NET_MSG_GENERIC		nmg;
		DWORD				dwGaeaID;

		SNETPK_BROAD () 
			: dwGaeaID(0)
		{
		}
	};


	struct SNETCROW_BROAD
	{
		NET_MSG_GENERIC		nmg;
		EMCROW				emCrow;
		DWORD				dwID;

		SNETCROW_BROAD () 
			: emCrow(CROW_PC)
			, dwID(0)
		{
		}
	};

	struct SNETPET_BROAD
	{
		NET_MSG_GENERIC		nmg;
		DWORD				dwGUID;

		SNETPET_BROAD () :
			dwGUID(UINT_MAX)
		{
		}
	};

	struct SNET_COMBINE
	{
		enum
		{
			//				�ִ�E�E۷�    - ( �޽���EǁE�E )
			EMHEAD_SIZE = ( sizeof(NET_MSG_GENERIC) + sizeof(WORD)*2 ),
			EMMAX_SIZE = NET_DATA_BUFSIZE - EMHEAD_SIZE,
		};

		NET_MSG_GENERIC		nmg;
		WORD				wMSG_SIZE;
		WORD				wMSG_CUR;

		BYTE				arrayMSG[EMMAX_SIZE];

		SNET_COMBINE () 
			: wMSG_SIZE(0)
			, wMSG_CUR(0)
		{
			nmg.dwSize = sizeof(SNET_COMBINE);
			nmg.nType = NET_MSG_COMBINE;
			GASSERT(nmg.dwSize<=NET_DATA_BUFSIZE);

			memset(arrayMSG, 0, sizeof(BYTE) * EMMAX_SIZE);
		}

		bool IsVALID ()
		{
			return wMSG_SIZE!=0;
		}

		void RESET ()
		{
			wMSG_SIZE = 0;
			wMSG_CUR = 0;
			memset(arrayMSG, 0, sizeof(BYTE) * EMMAX_SIZE);
		}

		void RESET_CUR ()
		{
			wMSG_CUR = 0;
		}

		bool ADDMSG ( LPVOID _pMsg )
		{
			NET_MSG_GENERIC* pMsg = (NET_MSG_GENERIC*)_pMsg;
			
			//	Note : ����E���̥ ������ �ִ���E����.
			//
			WORD wSIZE = (WORD) pMsg->dwSize;
			if ( (wSIZE+wMSG_SIZE) >= EMMAX_SIZE )
			{
				return false;
			}
			else
			{
				//	Note : �޽����� �ڿ� �ִ´�.
				//
				memcpy ( arrayMSG+wMSG_SIZE, _pMsg, wSIZE );
				//	Note : �޽����� ������ ������ �軁E
				//
				wMSG_SIZE += wSIZE;
				//	�޽���E������E��E����.
				nmg.dwSize = EMHEAD_SIZE + wMSG_SIZE;	
				return true;
			}
		}

		bool POPMSG ( LPNET_MSG_GENERIC &pMsg )
		{
			if ( wMSG_SIZE<=wMSG_CUR )	return false;

			pMsg = (NET_MSG_GENERIC*) ( arrayMSG + (wMSG_CUR) );
			wMSG_CUR += (WORD) pMsg->dwSize;

			GASSERT(wMSG_SIZE>=wMSG_CUR);
			if ( wMSG_SIZE<wMSG_CUR )	return false;

			return true;
		}
	};

	// Revert to default structure packing
	#pragma pack()
};
