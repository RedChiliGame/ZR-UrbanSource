#include "StdAfx.h"
#include "GamePlayOption.h"
#include "../EngineUILib/GUInterface/BasicButton.h"
#include "../EngineUILib/GUInterface/BasicTextBox.h"
#include "GameTextControl.h"
#include "UITextControl.h"
#include "../EngineLib/DxCommon/DxFontMan.h"
#include "../EngineUILib/GUInterface/UIMan.h"
#include "DxGlobalStage.h"

#include "DxParamSet.h"
#include "RANPARAM.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CBasicGamePlayOption::CBasicGamePlayOption () :
	m_pFont ( NULL ),
	m_pConftButton ( NULL ),
	m_pTradeButton ( NULL ),
	m_pPartyButton ( NULL ),
	m_pSimpleHPButton ( NULL ),
	m_pFriendButton ( NULL ),
	m_pMovableOnChatButton ( NULL ),
	m_pShowTipButton ( NULL ),
	m_pCharacterSimplifyButton ( NULL ),
	m_pIdleAnimButton ( NULL )
{
}

CBasicGamePlayOption::~CBasicGamePlayOption ()
{
}

void CBasicGamePlayOption::CreateSubControl ()
{
	m_pFont = DxFontMan::GetInstance().LoadDxFont ( _DEFAULT_FONT, 9, _DEFAULT_FONT_FLAG );

	CBasicTextBox* pTextBox = NULL;

	{	//	�⺻ �ؽ�Ʈ		
		DWORD dwFontColor = NS_UITEXTCOLOR::DEFAULT;
		int nAlign = TEXT_ALIGN_LEFT;

		//	�ڵ� ��� �ź�
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_CONFT_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 0 ) );

		//	�ڵ� �ŷ� �ź�
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_TRADE_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 1 ) );

		//	�ڵ� ��Ƽ �ź�
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_PARTY_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 2 ) );

		//	�̴� HP ǥ��
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_SIMPLEHP_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 3 ) );

		//	�ڵ� ģ�� �ź�
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_FRIEND_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 4 ) );

		//	����â �⺻ ��ġ��
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_DEFAULTPOS_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 5 ) );

		//  ä��â �ձ�
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_MOVABLE_ON_CHAT_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 6 ) );

		//  �� ����
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_SHOW_TIP_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 7 ) );

		//  ���� ����
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_FORCED_ATTACK_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 8 ) );

		//  �̸� �׻� ǥ��
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_NAME_DISPLAY_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 9 ) );

		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_CHARACTER_SIMPLIFY_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 12 ) );

		//  ��Ȱ ��ų ����
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_REVIVAL_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 10 ) );

		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_IDLE_ANIM_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 11 ) );

		//  ��Ȱ ��ų ����
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_FPSLATENCY_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 13 ) );

		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_AUTOTARGET_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 14 ) );
		pTextBox = CreateStaticControl ( "HWOPTION_GAMEPLAY_SKILLEFFECTS_STATIC", m_pFont, dwFontColor, nAlign );
		pTextBox->SetOneLineText ( ID2GAMEWORD ( "HWOPTION_GAMEPLAY_OPTION", 15 ) );
	}

	{	//	���
		//	��ư
		m_pConftButton = CreateFlipButton( "HWOPTION_GAMEPLAY_CONFT_BUTTON", "HWOPTION_GAMEPLAY_CONFT_BUTTON_F", HWOPTION_GAMEPLAY_CONFT_BUTTON );
		m_pTradeButton = CreateFlipButton( "HWOPTION_GAMEPLAY_TRADE_BUTTON", "HWOPTION_GAMEPLAY_TRADE_BUTTON_F", HWOPTION_GAMEPLAY_TRADE_BUTTON );
		m_pPartyButton = CreateFlipButton( "HWOPTION_GAMEPLAY_PARTY_BUTTON", "HWOPTION_GAMEPLAY_PARTY_BUTTON_F", HWOPTION_GAMEPLAY_PARTY_BUTTON );
		m_pSimpleHPButton = CreateFlipButton( "HWOPTION_GAMEPLAY_SIMPLEHP_BUTTON", "HWOPTION_GAMEPLAY_SIMPLEHP_BUTTON_F", HWOPTION_GAMEPLAY_SIMPLEHP_BUTTON );
		m_pFriendButton = CreateFlipButton( "HWOPTION_GAMEPLAY_FRIEND_BUTTON", "HWOPTION_GAMEPLAY_FRIEND_BUTTON_F", HWOPTION_GAMEPLAY_FRIEND_BUTTON );
		m_pMovableOnChatButton = CreateFlipButton( "HWOPTION_GAMEPLAY_MOVABLE_ON_CHAT_BUTTON", "HWOPTION_GAMEPLAY_MOVABLE_ON_CHAT_BUTTON_F", HWOPTION_GAMEPLAY_MOVABLE_ON_CHAT_BUTTON );
		m_pShowTipButton = CreateFlipButton( "HWOPTION_GAMEPLAY_SHOW_TIP_BUTTON", "HWOPTION_GAMEPLAY_SHOW_TIP_BUTTON_F", HWOPTION_GAMEPLAY_SHOW_TIP_BUTTON );
		m_pForcedAttackButton = CreateFlipButton( "HWOPTION_GAMEPLAY_FORCED_ATTACK_BUTTON", "HWOPTION_GAMEPLAY_FORCED_ATTACK_BUTTON_F", HWOPTION_GAMEPLAY_FORCED_ATTACK_BUTTON );
		m_pNameDisplayButton = CreateFlipButton( "HWOPTION_GAMEPLAY_NAME_DISPLAY_BUTTON", "HWOPTION_GAMEPLAY_NAME_DISPLAY_BUTTON_F", HWOPTION_GAMEPLAY_NAME_DISPLAY_BUTTON );
		m_pCharacterSimplifyButton = CreateFlipButton( "HWOPTION_GAMEPLAY_CHARACTER_SIMPLIFY_BUTTON", "HWOPTION_GAMEPLAY_CHARACTER_SIMPLIFY_BUTTON_F", HWOPTION_GAMEPLAY_CHARACTER_SIMPLIFY_BUTTON );
		m_pRevivalButton = CreateFlipButton( "HWOPTION_GAMEPLAY_REVIVAL_BUTTON", "HWOPTION_GAMEPLAY_REVIVAL_BUTTON_F", HWOPTION_GAMEPLAY_REVIVAL_BUTTON );
		m_pIdleAnimButton = CreateFlipButton( "HWOPTION_GAMEPLAY_IDLE_ANIM_BUTTON", "HWOPTION_GAMEPLAY_IDLE_ANIM_BUTTON_F", HWOPTION_GAMEPLAY_IDLE_ANIM_BUTTON );
		m_bFpsLatencyButton = CreateFlipButton( "HWOPTION_GAMEPLAY_FPSLATENCY_BUTTON", "HWOPTION_GAMEPLAY_FPSLATENCY_BUTTON_F", HWOPTION_GAMEPLAY_FPSLATENCY_BUTTON );
		m_bAutoTargetButton = CreateFlipButton( "HWOPTION_GAMEPLAY_AUTOTARGET_BUTTON", "HWOPTION_GAMEPLAY_AUTOTARGET_BUTTON_F", HWOPTION_GAMEPLAY_AUTOTARGET_BUTTON );
		m_bSkillEffectsButton = CreateFlipButton( "HWOPTION_GAMEPLAY_SKILLEFFECTS_BUTTON", "HWOPTION_GAMEPLAY_SKILLEFFECTS_BUTTON_F", HWOPTION_GAMEPLAY_SKILLEFFECTS_BUTTON );

		{
			CBasicButton* pButton = new CBasicButton;
			pButton->CreateSub ( this, "HWOPTION_GAMEPLAY_DEFAULTPOS_BUTTON", UI_FLAG_DEFAULT, HWOPTION_GAMEPLAY_DEFAULTPOS_BUTTON );
			pButton->CreateFlip ( "HWOPTION_GAMEPLAY_DEFAULTPOS_BUTTON_F", CBasicButton::CLICK_FLIP );				
			RegisterControl ( pButton );
		}
	}
}

CBasicButton* CBasicGamePlayOption::CreateFlipButton ( char* szButton, char* szButtonFlip, UIGUID ControlID )
{
	CBasicButton* pButton = new CBasicButton;
	pButton->CreateSub ( this, szButton, UI_FLAG_DEFAULT, ControlID );
	pButton->CreateFlip ( szButtonFlip, CBasicButton::RADIO_FLIP );
	pButton->SetControlNameEx ( szButton );
	RegisterControl ( pButton );
	return pButton;
}

CBasicTextBox* CBasicGamePlayOption::CreateStaticControl ( char* szControlKeyword, CD3DFontPar* pFont, D3DCOLOR dwColor, int nAlign )
{
	CBasicTextBox* pStaticText = new CBasicTextBox;
	pStaticText->CreateSub ( this, szControlKeyword );
	pStaticText->SetFont ( pFont );
	pStaticText->SetTextAlign ( nAlign );	
	RegisterControl ( pStaticText );
	return pStaticText;
}

void CBasicGamePlayOption::LoadConft ()
{
	m_bConft = DXPARAMSET::GetInstance().m_bDIS_CONFT;
	m_pConftButton->SetFlip ( m_bConft );
}

void CBasicGamePlayOption::LoadTrade ()
{
	m_bTrade = DXPARAMSET::GetInstance().m_bDIS_TRADE;
	m_pTradeButton->SetFlip ( m_bTrade );
}

void CBasicGamePlayOption::LoadParty ()
{
	m_bParty = DXPARAMSET::GetInstance().m_bDIS_PARTY;
	m_pPartyButton->SetFlip ( m_bParty );
}

void CBasicGamePlayOption::LoadSimpleHP ()
{
	m_bSimpleHP = DXPARAMSET::GetInstance().m_bSHOW_SIMPLEHP;
	m_pSimpleHPButton->SetFlip ( m_bSimpleHP );
}

void CBasicGamePlayOption::LoadFriend ()
{
	m_bFriend = RANPARAM::bDIS_FRIEND;
	m_pFriendButton->SetFlip ( m_bFriend );
}

void CBasicGamePlayOption::LoadMovableOnChat ()
{
	m_bMovableOnChat = RANPARAM::bMOVABLE_ON_CHAT;
	m_pMovableOnChatButton->SetFlip ( m_bMovableOnChat );
}

void CBasicGamePlayOption::LoadShowTip ()
{
	m_bShowTip = RANPARAM::bSHOW_TIP;
	m_pShowTipButton->SetFlip ( m_bShowTip );
}

void CBasicGamePlayOption::LoadForcedAttack ()
{
	m_bForcedAttack = RANPARAM::bFORCED_ATTACK;
	m_pForcedAttackButton->SetFlip ( m_bForcedAttack );
}

void CBasicGamePlayOption::LoadNameDisplay ()
{
	m_bNameDisplay = RANPARAM::bNAME_DISPLAY;
	m_pNameDisplayButton->SetFlip ( m_bNameDisplay );
}
void CBasicGamePlayOption::LoadCharacterSimplify ()
{
	m_bCharacterSimplify = DXPARAMSET::GetInstance().m_bCHARACTER_SIMPLIFY;
	m_pCharacterSimplifyButton->SetFlip ( m_bCharacterSimplify );
}

void CBasicGamePlayOption::LoadRevival()
{
	m_bNon_Rebirth = RANPARAM::bNON_Rebirth;
	m_pRevivalButton->SetFlip ( m_bNon_Rebirth );
}
void CBasicGamePlayOption::LoadIdleAnim()
{
	m_bIdleAnim = RANPARAM::bIdleAnim;
	m_pIdleAnimButton->SetFlip ( m_bIdleAnim );
}

void CBasicGamePlayOption::LoadFpsLatency()
{
	m_bFpsLatency = RANPARAM::bFPSLATENCY;
	m_bFpsLatencyButton->SetFlip ( m_bFpsLatency );
}
void CBasicGamePlayOption::LoadAutoTarget()
{
	m_bAutoTarget = RANPARAM::bAutoTarget;
	m_bAutoTargetButton->SetFlip ( m_bAutoTarget );
}
void CBasicGamePlayOption::LoadSkillEffects()
{
	m_bSkillEffects = RANPARAM::bSkillEffects;
	m_bSkillEffectsButton->SetFlip ( m_bSkillEffects );
}
void CBasicGamePlayOption::LoadCurrentOption()
{
	LoadConft();
	LoadTrade();
	LoadParty();
	LoadSimpleHP();
	LoadFriend();
	LoadMovableOnChat();
	LoadShowTip();
	LoadForcedAttack();
	LoadNameDisplay();
	LoadCharacterSimplify();
	LoadRevival();
	LoadIdleAnim();
	LoadFpsLatency();
	LoadAutoTarget();
	LoadSkillEffects();

	CD3DApplication* const pD3DApp = DxGlobalStage::GetInstance().GetD3DApp ();
	if ( !pD3DApp )
	{
		GASSERT ( pD3DApp && "����̽��� �������� �ʾҽ��ϴ�." );
		return ;
	}
	D3DDeviceInfo* const pDeviceInfo = pD3DApp->GetCurDeviceInfo();
}

void CBasicGamePlayOption::SetVisibleSingle( BOOL bVisible )
{
	CUIGroup::SetVisibleSingle ( bVisible );

	if( bVisible )
	{
		LoadCurrentOption();
	}
}