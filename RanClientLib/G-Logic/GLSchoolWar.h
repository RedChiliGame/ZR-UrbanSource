#pragma once

#include "GLDWDefine.h"

class GLSchoolWar
{
public:
	enum 
	{		
		MAX_TIME = 56,
	};

	enum EM_BATTLE_STATE 
	{
		BATTLE_NOSTART		= 0,	//	�������� ����
		BATTLE_READY		= 1,	//	��Ʋ �����
		BATTLE_START		= 2,	//	��Ʋ ��
		BATTLE_END_AWARD	= 3,	//	��Ʋ ������ ���� �ð� ( ��ǰ ���� )
		BATTLE_END			= 4,	//	��Ʋ ������ ƨ��� �ð�
	};

public:
	DWORD				m_dwID;					// ���� ID.
	std::string			m_strName;				// ���� �̸�.
//	std::vector<DWORD>	m_vecMaps;				// ���� ���� ��.

	DWORD				m_dwClubMap;			//	Ŭ�� ��. ( ����� )
	DWORD				m_dwCLubMapGate;		//	Ŭ�� �ʿ� �ִ� ���Ա�.
	DWORD				m_dwClubHallMap;		//	Ŭ�� ��. ( �Ա��� ) 
	DWORD				m_dwClubHallGate;		//	Ŭ�� �� �ⱸ  ( �Ա��� ) 

//	float				m_fItemDropRate;		// ������ ��� Ȯ��.
//	float				m_fDefaultCommissionPer;// �⺻ ��������.

	DWORD				m_dwWinChar;		//	�¸� Ŭ�� ID.
//	float				m_fCommissionPercent;	//	��������.

	DWORD				m_dwBattleTime;
	SDW_TIME			m_sDWTime[MAX_TIME];		//	�����ð�.

	SDW_AWARD_ITEM		m_sDWAwardItem;		
	
	DW_AWARD_CHAR		m_vecDWAwardChar;		//	������ ���� ĳ���� ( �ι��޴°� �����ϱ� ���� )
	DW_RANK_INFO_MAP	m_mapDWScore;			//	cdm ���ھ�
	//SW_RANK_SCHOOL_INFO_MAP	m_mapSWSchoolScore;
//	CDM_RANK_INFO_VEC	m_vecCdmRank;			//	Ŭ����ũ �����

//	bool				m_bNewCommission;		//	�� Ŀ�̼� ���� ����.
//	float				m_fCommissionTimer;		//	�� Ŀ�̼� ���� Ÿ�̸�.
//	float				m_fNewCommissionPercent;//	�� Ŀ�̼�.

	bool				m_bNotifyOneHour;
	bool				m_bNotifyHalfHour;
	bool				m_bNotify10MinHour;

	EM_BATTLE_STATE		m_emBattleState;
	DWORD				m_dwBattleOrder;	
	DWORD				m_dwLastBattleHour;
	float				m_fBattleTimer;

//	DWORD				m_dwCERTIFY_CHARID;
//	DWORD				m_dwCERTIFY_NPCID;
//	float				m_fCERTIFY_TIMER;
//	D3DXVECTOR3			m_vCERTIFY_POS;

	float				m_fCHECK_TIMER;			//	��Ʋ ������ Ÿ�̸ӵ� ( ��ǰ�̶� ���� �ñ涧 ��� ) 
	float				m_fCHECK_TIME;			//

//	bool				m_bBattleEndCheck;		// ������ �������� ����� ������ ��������
//	float				m_fCHECK_TIMER;
//	float				m_fCHECK_TIME;


	float				m_fRankingUpdate;		//	��ŷ Ÿ�̸�

public:
	GLSchoolWar ();

	GLSchoolWar ( const GLSchoolWar &value )
	{
		operator= ( value );
	}

	GLSchoolWar& operator= ( const GLSchoolWar& value );

	bool operator < ( const GLSchoolWar& sDW )
	{
		return m_dwID < sDW.m_dwID;
	}

public:
	bool Load ( std::string strFile );

public:
	void AddDWScore( DWORD dwKillChar, DWORD dwDeathChar );
	//void AddSWSchoolScore( WORD wKillSchool, WORD wDeathSchool );
	SDW_RANK_INFO* GetDWRankInof( DWORD dwCharID );
	//SSW_RANK_SCHOOL_INFO* GetSWRankSchoolInof (WORD wSchool);

public:
//	bool IsCertify()		{ return m_dwCERTIFY_CHARID!=0; }

public:
//	bool IsNewCommission ();
//	bool IsGuidClub ( DWORD dwClubID );

public:
	bool IsBattle () { return ( m_emBattleState == BATTLE_START ); }
	bool IsBattleReady() { return ( m_emBattleState == BATTLE_READY ); }
	bool IsBattleEndAward() { return ( m_emBattleState == BATTLE_END_AWARD ); }
	bool IsBattleEnd() { return ( m_emBattleState == BATTLE_END ); }
	bool IsEnterMap();
	DWORD IsBattleWeekDay ( int nDayOfWeek, int nHour );

	void SetBattle( EM_BATTLE_STATE emBattleState )	{ m_emBattleState = emBattleState; }
	
	// ����Ŭ�� ���۽ð��ΰ�?
	bool IsBattleHour ( DWORD dwORDER, int nHour );

public:
	// ���������� ����Ŭ���������� �Ͼ ���� �����Ѵ�.
	void UpdateBattleDay ( int nDay );
	// ����Ŭ�� ������ ���� �ð��� Ŭ���̾�Ʈ���� �˸���.
	void UpdateNotifyBattle ( DWORD dwORDER, int nHour, int nMinute );
//	void UpdateCommission ( float fElaps );

	//	���� Ŭ���� ����ǰ� ���� ������ ƨ����.
	void CheckExtraGuild ( float fElaps );
	bool IsCheckExtraGuild() { return true; }

	void CheckAwardClub( float fElaps );	//	���� ����
	void CheckExtraClub( float fElaps );	//	���� �������� 

public:
	// ����Ŭ�� �������� �����Ѵ�.
	void DoBattleStart ( DWORD dwORDER, int nDay );
	void DoBattleEnd();

//	void DoCertifyEnd();

public:
//	bool ChangeGuidClub ( DWORD dwClubID );
//	bool ChangeCommission ( float fRate );
};

class GLSchoolWarMan
{
public:
	typedef std::vector<GLSchoolWar>			DW_VEC;
	typedef DW_VEC::iterator					DW_VEC_ITER;
	typedef std::pair<DW_VEC_ITER,DW_VEC_ITER>	DW_VEC_PAIR;

protected:
	DW_VEC											m_vecDW;

public:
	bool Load ( std::vector<std::string> &vecFiles );
//	bool SetState ( VECGUID_DB &vecGUID );

public:
	GLSchoolWar* Find ( DWORD dwID );
	bool IsBattle ();
//	bool IsCheckExtraGuild ();

public:
	GLSchoolWarMan ()
	{
	}

public:
	//static GLGuidanceMan& GetInstance();
};

class GLSchoolWarAgentMan : public GLSchoolWarMan
{
protected:
	float m_fRemainTimer, m_fTimer;

public:
//	bool ChangeGuidClub ( DWORD dwID, DWORD dwClubID );
//	bool ChangeCommission ( DWORD dwID, float fRate );

public:
//	GLSchoolWar* FindByClubID ( DWORD dwClubID );

public:
	bool SetMapState ();

public:
//	DWORD GetGuidID ( DWORD dwClubID );
	DWORD GetRemainTime () { return (DWORD)m_fRemainTimer; }

public:
	bool FrameMove ( float fElapsedAppTime );

public:
	GLSchoolWarAgentMan ()
		: m_fRemainTimer(0)
		, m_fTimer(0)
	{
	}

public:
	static GLSchoolWarAgentMan& GetInstance();
};

class GLSchoolWarFieldMan : public GLSchoolWarMan
{
public:
	bool SetMapState ();

public:
	bool ReadyBattle( DWORD dwID );
	bool BeginBattle ( DWORD dwID );
	bool EndBattle ( DWORD dwID );

public:
//	bool ChangeGuidClub ( DWORD dwID, DWORD dwClubID );
//	bool ChangeCommission ( DWORD dwID, float fRate );

//	bool DoCertify ( DWORD dwID, DWORD dwCHARID, DWORD dwNPCID, const D3DXVECTOR3 &vPOS );

public:
	DWORD GetWinCharID ( DWORD dwCharID );
//	EMCHECKCERTIFY CheckCertify ( DWORD dwID, DWORD dwCHARID );
	const std::string GetName ( DWORD dwID );

//	void CheckExtraGuild ( float fElaps );

	void UpdateDWRanking( DWORD dwID );
	void DWAwardItem( DWORD dwID );

public:
	bool FrameMove ( float fElaps );

protected:
	GLSchoolWarFieldMan ()
	{
	}

public:
	static GLSchoolWarFieldMan& GetInstance();
};