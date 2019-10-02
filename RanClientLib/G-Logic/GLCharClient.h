#ifndef GLCHARCLIENT_H_
#define GLCHARCLIENT_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

#include "./GLCharDefine.h"
#include "./GLCharData.h"
#include "./GLCopy.h"
#include "./GLogicData.h"
#include "./GLPrivateMarket.h"
#include "../../EngineLib/Meshs/DxSkinChar.h"
#include "../../EngineLib/NaviMesh/Actor.h"
//#include "./GLLandManClient.h"
//#include "s_CSMsgList.h"
#include "./GLVEHICLE.h"
#include "GLogicEx.h"

#ifndef GLLandManClient
	class GLLandManClient;
	class GLClientNode;
	typedef SQUADNODE<GLClientNode> CLIENTQUADNODE;
#endif //GLLandMan

#define _SKILLFACT_DEFAULTTIME		(-1.0f)

class GLCharClient : public GLCHARLOGIC, public GLCOPY
{
protected:
	LPDIRECT3DDEVICEQ	m_pd3dDevice;
	Actor				m_actorMove;
	DxSkinChar*			m_pSkinChar;

	D3DXVECTOR3			m_vDir;
	D3DXVECTOR3			m_vDirOrig;
	D3DXVECTOR3			m_vPos;
	D3DXMATRIX			m_matTrans;

	D3DXVECTOR3			m_vServerPos;

	//	Note : ���� ����.
	//
	float				m_fAge;
	EMACTIONTYPE		m_Action;
	DWORD				m_dwActState;			//	�ൿ ����.
	D3DXVECTOR3			m_vTarPos;

	float				m_fIdleTime;
	STARGETID			m_sTargetID;			//	��ǥ ����.

	float				m_fMoveDelay;			//	�̵� ������.

	DWORD				m_dwANISUBSELECT;
	DWORD				m_dwANISUBGESTURE;

	//	Note : AABB
	//
	D3DXVECTOR3			m_vMaxOrg;
	D3DXVECTOR3			m_vMinOrg;

public:
	D3DXVECTOR3			m_vMax;
	D3DXVECTOR3			m_vMin;
	float				m_fHeight;

	//	Note : ��?E��?E
	//
public:
	std::string			m_strName;
	EMCHARINDEX			m_CHARINDEX;
	DWORD				m_dwGaeaID;				//	���� �޸� �ε���?E( ��?EGLLandMan������ ����ũ�� )
	DWORD				m_dwCeID;				//	�� ID.

	GLLandManClient*		m_pLandManClient;	//	�� �ν��Ͻ� ������.
	SGLNODE<GLCharClient*>*	m_pGlobNode;		//	�� ����Ʈ ?E�E
	CLIENTQUADNODE*			m_pQuadNode;		//	��?EƮ�� ?E�E
	SGLNODE<GLCharClient*>*	m_pCellNode;		//	�� ����Ʈ ?E�E

	DWORD					m_dwSummonGUID;					//  ��ȯ?EID

	void ItemPreviewUpdate(SNATIVEID PrevID);
	void ItemPreviewUpdate_End();

	//	Note : ���� ?E��?
	//
public:
	
	SDROP_CHAR			m_CharData;

protected:
	EMANI_MAINTYPE		m_emANIMAINSKILL;
	EMANI_SUBTYPE		m_emANISUBSKILL;

	EMANI_SUBTYPE		m_emANISUBTYPE;
	DWORD				m_dwRevData;

	SSKILLFACT			m_sSKILLFACT[SKILLFACT_SIZE];	//	��ųȿ��?E

	SLANDEFFECT			m_sLandEffect[EMLANDEFFECT_MULTI];	//  ��?E��?Eȿ��?E

	SSTATEBLOW			m_sSTATEBLOWS[EMBLOW_MULTI];	//	������?E

	DWORD				m_dwTransfromSkill;					//  ���� ��ų ���� �ѹ�

	float				m_fSTATE_MOVE;					//	���� ��?E�̵��ӵ�. ( 1.0f == 100% )
	float				m_fSTATE_DELAY;					//	���� ��?E������. ( 1.0f == 100% ) (+)

	bool				m_bSTATE_PANT;					//	������?E�涱��.
	bool				m_bSTATE_STUN;					//	������?E����.
	bool				m_bINVISIBLE;					//	��?E
	bool				m_bSimplifySet;

	float				m_fSKILL_MOVE;					//	��ų �̵� �ӵ�.
	float				m_fATTVELO;						//	��ų ���ݼӵ� ��ȭ.
	float				m_fITEM_MOVE_R;					//  ������ �̵� �ӵ� ����	
	float				m_fITEMATTVELO_R;				//  ������ ���ݼӵ� ����
	float				m_fITEM_MOVE;					//  ������ �̵� �ӵ� ��?E?
	float				m_fITEMATTVELO;				//  ������ ���ݼӵ� ��?E?

	WORD				m_wTARNUM;
	D3DXVECTOR3			m_vTARPOS;
	STARID				m_sTARIDS[EMTARGET_NET];

	WORD				m_wACTIVESKILL_LEVEL;
	SNATIVEID			m_idACTIVESKILL;

protected:
	float				m_fattTIMER;
	int					m_nattSTEP;

public:
	GLPrivateMarket		m_sPMarket;						//	���� ����.
	BOOL				m_bVehicle;
	GLVEHICLE			m_sVehicle;
    BOOL                m_bFist;
	bool				m_bItemShopOpen;
	bool				m_bSafeZone;

public:
	virtual WORD GetBodyRadius ();

public:
	virtual EMCROW GetCrow () const			{ return CROW_PC; }
	virtual DWORD GetCtrlID () const		{ return m_dwGaeaID; }
	virtual DWORD GetCharID () const		{ return m_CharData.dwCharID; }
	virtual const char* GetName () const	{ return m_strName.c_str(); }
	virtual GLPWDATA GetHp () const			{ return m_CharData.sHP; }  //original gldwdata
	virtual GLPWDATA GetDmg () const			{ return m_CharData.m_gdDAMAGE_PHYSIC;; }  //original gldwdata
	

	virtual GLPWDATA GetHpSg () const			{ return m_CharData.sHP; }
	virtual GLPWDATA GetHpMp () const			{ return m_CharData.sHP; }
	virtual GLPWDATA GetHpPhx () const			{ return m_CharData.sHP; }
	virtual WORD GetSchool() const			{ return m_CharData.wSchool; }

	//�s�W����k�U
	virtual DWORD GetCharClubID () const	{ return m_CharData.dwGuild; }
	virtual DWORD GetCharPayalName () const	{ return m_CharData.dwParty; }
	virtual DWORD GetCharHPMAX () const	{ return m_CharData.sHP.dwMax; }
	virtual DWORD GetCharHPNOW () const	{ return  m_CharData.sHP.dwNow; }	
	virtual WORD GetCharLevel () const		{ return m_CharData.wLevel; }
//	virtual DWORD GetCharReborn () const		{ return m_CharData.m_dwReborn; }
	virtual EMCHARCLASS GetCharClass () const		{ return m_CharData.emClass; }
	virtual WORD GetCharShool () const		{ return m_CharData.wSchool; }
	virtual const char* GetCharClubName () const	{ return m_CharData.szClubName; }
	virtual WORD GetLevel()							{ return m_CharData.wLevel; }
//	virtual DWORD GetReborn()						{ return m_CharData.dwReborn; }
	virtual WORD GetSchool()						{ return m_CharData.wSchool; }
	virtual const EMCHARCLASS GetClass()			{ return m_CharData.emClass; }

	virtual void ReceiveDamage ( DWORD wDamage, DWORD dwDamageFlag , STARGETID sACTOR );
	virtual void ReceiveAVoid ();
	virtual void ReceiveSwing ();
	virtual bool IsSafeZone () const		{ return m_bSafeZone; }

	const SITEMCLIENT& GET_SLOT_ITEM ( EMSLOT _slot )				{ return m_CharData.m_PutOnItems[_slot]; }
	BOOL VALID_SLOT_ITEM ( EMSLOT _slot );

	SITEM* GET_SLOT_ITEMDATA ( EMSLOT _slot );

	EMELEMENT GET_ITEM_ELMT ();

	SSKILLFACT* GET_SKILLFACT ( int nINDEX )						{ if ( nINDEX >=SKILLFACT_SIZE ) return NULL; return &m_sSKILLFACT[nINDEX]; }

	DWORD GETCLUBID ()												{ return m_CharData.dwGuild; }
	EMCROW GETCROW()												{ return CROW_PC; }
	DWORD GETPARTYID()												{ return m_CharData.dwParty; }
	DWORD GETALLIANCEID()											{ return m_CharData.dwAlliance; }

public:
	D3DXMATRIX GetMatrix ()											{ return m_matTrans; }

public:
	BOOL IsSTATE ( DWORD dwState )					{ return m_dwActState&dwState; }
	virtual BOOL IsACTION ( EMACTIONTYPE emCur )	{ return m_Action == emCur; }
	
	virtual BOOL IsPartyMem ()						{ return m_CharData.dwParty!=GAEAID_NULL; }
	virtual BOOL IsPartyMaster ()					{ return m_CharData.dwPMasterID==m_CharData.dwGaeaID; }
	virtual BOOL IsClubMaster ()					{ return m_CharData.dwGuildMaster==m_CharData.dwCharID; }
	virtual BOOL IsAllianceMasterClub()				{ return m_CharData.dwGuild == m_CharData.dwAlliance ; }
	virtual BOOL IsAllianceMaster()					{ return IsClubMaster() && IsAllianceMasterClub(); }
	virtual const char* GetClubName()				{ return m_CharData.szClubName; }
	virtual const char* GetName()					{ return m_CharData.szName; }
//	virtual WORD GetLevel()							{ return m_CharData.wLevel; }
//	virtual WORD GetSchool()						{ return m_CharData.wSchool; }
	virtual int GetReborn()							{ return m_CharData.nChaReborn; }
//	virtual const EMCHARCLASS GetClass()			{ return m_CharData.emClass; }

	BOOL IsCDCertify ()								{ return m_CharData.dwFLAGS&SDROP_CHAR::CLUB_CD; }

	BOOL IsValidBody ();
	BOOL IsDie ();

	BOOL IsVisibleDetect ();
	BOOL IsVisibleDetectParty ();

	void UpdateCharacterSimplify();//Character Simplify recoded <3 - AnFire16 (7/23/2017)

protected:
	void SetSTATE ( DWORD dwState )			{ m_dwActState |= dwState; }
	void ReSetSTATE ( DWORD dwState )		{ m_dwActState &= ~dwState; }

protected:
	float GetMoveVelo ();
	void TurnAction ( EMACTIONTYPE toAction );

public:
	void SetPosition ( const D3DXVECTOR3 &vPos );
	
	const D3DXVECTOR3 &GetPosition ()	{ return m_vPos; }
	float GetDirection ();

	WORD GETBODYRADIUS ()				{ return GLCONST_CHAR::wBODYRADIUS; }
	SDROP_CHAR& GetCharData ()			{ return m_CharData; }
	DxSkinChar* GetCharSkin ()			{ return m_pSkinChar; }

	virtual float GetBodyHeight()			{ return m_fHeight; }
	//added by   | 18-7-2012 | add mouse effect code
	virtual float GetScale()			{ return ( GetCharSkin() != NULL ) ? GetCharSkin()->GetScale() : 0.f; }
	virtual DxSkinChar* GetSkinCharF() { return GetCharSkin(); }
	virtual D3DXVECTOR3 GetPosBodyHeight ();
	virtual D3DXVECTOR3 GetDir () { return m_vDir; }
	virtual D3DXVECTOR3 GetDirOrig () { return m_vDirOrig; };

	void SetUseArmSub( BOOL bSub )		{ m_CharData.m_bUseArmSub = bSub; }
	BOOL IsUseArmSub() const			{ return m_CharData.m_bUseArmSub; }

	EMSLOT GetCurRHand();
	EMSLOT GetCurLHand();

	BOOL IsCurUseArm( EMSLOT emSlot );

public:
	void DISABLESKEFF ( int i )					{ m_sSKILLFACT[i].sNATIVEID = NATIVEID_NULL(); }
	void DISABLEBLOW ( int i )					{ m_sSTATEBLOWS[i].emBLOW = EMBLOW_NONE; }
	void UPDATE_DATA ( float fTime, float fElapsedTime, BOOL bClient=FALSE );
	void UPDATE_ITEM ( );
	void DISABLEALLLANDEFF();
	void ADDLANDEFF( SLANDEFFECT landEffect, int iNum );

	// ��?Eȿ?E������Ʈ
	void UpdateLandEffect();

public:
	float GETATTVELO ();
	float GETMOVEVELO ();
	float GETATT_ITEM();
	float GETMOVE_ITEM();

public:
	HRESULT Create ( GLLandManClient* pLandManClient, SDROP_CHAR* pCharData, LPDIRECT3DDEVICEQ pd3dDevice );
	HRESULT UpdateSuit ();

	BOOL RECEIVE_SKILLFACT ( const SNATIVEID skill_id, const WORD wlevel, const DWORD dwSELECT, float fAge = _SKILLFACT_DEFAULTTIME );

protected:
	void ReSelectAnimation ();
	HRESULT UpateAnimation ( float fTime, float fElapsedTime );

protected:
	void StartAttackProc ();
	BOOL AttackProc ( float fElapsedTime );
	void AttackEffect ( const SANIMSTRIKE &sStrikeEff );

protected:
	void StartSkillProc ();
	BOOL SkillProc ( float fElapsedTime );

	void SKT_EFF_HOLDOUT ( STARGETID sTarget, DWORD dwDamageFlag );

	void SK_EFF_TARG ( const PGLSKILL pSkill, const SANIMSTRIKE &sStrikeEff, const STARGETID &sTarget );
	void SK_EFF_SELFZONE ( const SANIMSTRIKE &sStrikeEff, const SKILL::EMEFFECTPOS emPOS, const char* const szZONE_EFF, STARGETID *pTarget=NULL );
	void SK_EFF_TARZONE ( const STARGETID &sTarget, const SKILL::EMEFFECTPOS emPOS, const char* const szZONE_EFF );
	void SkillEffect ( const SANIMSTRIKE &sStrikeEff );

public:
		DWORD GET_PK_COLOR ();

public:
	BOOL IsCollisionVolume ();
	HRESULT FrameMove ( float fTime, float fElapsedTime );

	HRESULT RenderShadow ( LPDIRECT3DDEVICEQ pd3dDevice, CLIPVOLUME &cv );
	HRESULT Render ( LPDIRECT3DDEVICEQ pd3dDevice, CLIPVOLUME &cv, BOOL bRendAABB );

	void	DisableSkillFact();

public:
	HRESULT RestoreDeviceObjects ( LPDIRECT3DDEVICEQ pd3dDevice );
	HRESULT InvalidateDeviceObjects ();

public:
	HRESULT MsgMoveState ( NET_MSG_GENERIC* nmg );
	HRESULT MsgGoto ( NET_MSG_GENERIC* nmg );

public:
	virtual void MsgProcess ( NET_MSG_GENERIC* nmg );

public:
	D3DXVECTOR3 CollisionForward( D3DXVECTOR3 vPOSITION, D3DXVECTOR3 vDIRECTION );
	D3DXVECTOR3 CollisionBackward( D3DXVECTOR3 vPOSITION, D3DXVECTOR3 vDIRECTION );

public:
	GLCharClient(void);
	~GLCharClient(void);
};

typedef GLCharClient* PGLCHARCLIENT;

typedef CGLLIST<PGLCHARCLIENT>	GLCHARCLIENTLIST;
typedef SGLNODE<PGLCHARCLIENT>	GLCHARCLIENTNODE;

#endif // GLCHARCLIENT_H_