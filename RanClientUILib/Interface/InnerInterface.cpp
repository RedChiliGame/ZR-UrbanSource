#include "StdAfx.h"
#include "AdminMessageDisplay.h"
#include "BasicChat.h"
#include "BasicInfoView.h"
#include "BasicQuickSkillSlot.h"
#include "BasicVarTextBox.h"
#include "BasicVarTextBoxEx.h"
#include "BlockProgramAlarm.h"
#include "CommonWeb.h"
#include "DxGlobalStage.h"
#include "DxInputString.h"
#include "GameTextControl.h"
#include "GLGaeaClient.h"
#include "GLPartyClient.h"
#include "InnerInterface.h"
#include "InventoryWindow.h"
#include "ItemShopWindowWeb.h"
#include "MapMoveDisplay.h"
#include "ModalCallerID.h"
#include "ModalWindow.h"
#include "NameDisplayMan.h"
#include "PrivateMarketWindow.h"
#include "QuestAlarm.h"
#include "QuestWindow.h"
#include "RANPARAM.h"
#include "RebirthDialogue.h"
#include "ShopItemSearchWindow.h"
#include "ItemSearchResultWindow.h"
#include "MapRequireCheck.h"
#include "SkillTrayTab.h"
#include "SkillTrayTabNew.h"
#include "InventoryPageWearView.h"

#include "MapWindow/LargeMapWindow.h"

#include "SystemMessageWindow.h"
#include "UILeftTopGroup.h"
#include "UITextControl.h"
#include "s_CHttpPatch.h"
#include "ItemMixWindow.h"
#include "GatherGauge.h"
#include "CdmRankingDisplay.h"
#include "CSwRankingDisplay.h"			//add school war
#include "CSwPRankingDisplay.h"			//add school war
//#include "CharacterWindow.h"
#include "CharacterWindow/CharacterWindow.h"
#include "BasicQuickSkillWindow.h"
#include "BasicQuickSkillWindowNew.h"
#include "../Interface/PKComboDisplay.h" //Add Pk streak by Njd
#include "../Interface/PKComboType.h"
//#include "PartyDisplay.h" //add partydisplay
#include "ItemPreviewWindow/ItemPreviewWindow.h"
#include "BoxItemInfo.h"
#include "CSwRankingDisplay.h"			//add school war
#include "CSwPRankingDisplay.h"			//add school war
#include "CSchoolWarWindow.h" //add schoolwar window - JADev
#include "killTimeDisplay.h"

#include "CRRRankingDisplay.h"			//add rr
#include "CRRPRankingDisplay.h"			//add rr

#include "CrowTargetInfo.h"
#include "CrowTargetInfoNpc.h"
#include "CrowTargetInfoPlayer.h"
#include "PartyDisplay/PartyDisplay.h"
#include "PartyDisplay/PartyDisplayBuff.h"

#include "../EngineUILib/GUInterface/UIKeyCheck.h"


#include "PVPWindow/CPvpWindowDisplay.h"
#include "ForceRebirth.h"
#include "CCtfRankingDisplay.h"
#include "CtfInfoDisplay.h"
#include "CTFRankingDisplay/CTFTopTenRank.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CHAT_MACRO_SIZE	10

CInnerInterface& CInnerInterface::GetInstance()
{
	static CInnerInterface Instance;
	return Instance;
}

const float	CInnerInterface::fMENU_LIFTUP = 90.0f;
const int CInnerInterface::nOUTOFRANGE = -1;

CInnerInterface::CInnerInterface () :
	m_emConflictReqType ( EMCONFT_ONE ),
	m_ConflictReqID ( GAEAID_NULL ),
	m_bPartyStateBack ( FALSE ),
	m_bBlockProgramFound ( false ),
	m_dwEventQuestID ( NATIVEID_NULL().dwID ),
	m_dwEventQuestStep ( UINT_MAX ),
	m_bBlockProgramAlarm ( false ),
	m_bITEM_INFO_EX_DISPLAY_MODE ( false ),
	m_bITEM_INFO_LINK_DISPLAY_MODE ( false ),
	m_bCHANNEL ( false ),
	m_bFirstVNGainSysCall ( true ),
	m_bTabReserve ( false ),
	m_bItemShopLoad ( false ),
	state ( -1 ),
	SkillTabClose ( FALSE ),
	SkillTabOpen ( FALSE )
{
	ResetControl();

	
}

CInnerInterface::~CInnerInterface ()
{
}

void CInnerInterface::ResetControl()
{
	m_pSimpleHP = NULL;
	m_pBusWindow = NULL;
	m_pMiniMap = NULL;
	m_pChat = NULL;
	m_pQuestWindow = NULL;
	m_pQuestAlarm = NULL;	
	m_pFriendWindow = NULL;	
	m_pSkillWindowToTray = NULL;	
	m_pInventoryWindow = NULL;
	m_pPartyWindow = NULL;
	m_pTradeWindow = NULL;	
	m_pPtoPWindow = NULL;
	m_pDamageDisplayMan = NULL;
	m_pTargetInfoDisplay = NULL;
//	m_pTargetBasicInfoDisplay = NULL;
	m_pCharacterViewPropertiesWindow = NULL;//add charinfoview
	m_pNameDisplayMan = NULL;
	m_pDialogueWindow = NULL;
	m_pMarketWindow = NULL;
	m_pStorageWindow = NULL;
	m_pItemMove = NULL;
	m_pBlockProgramAlarm = NULL;
	//m_pItemBankWindow = NULL;
	m_pItemShopWindow = NULL;
	m_pVNGainSysInventory = NULL;
	m_pTradeInventoryWindow = NULL;
	m_pHeadChatDisplayMan = NULL;	
	m_pAdminMessageDisplay = NULL;	
	m_pConftModalWindow = NULL;	
	m_pPartyModalWindow = NULL;
	m_pConftDisplayMan = NULL;
	m_pInfoDisplay = NULL;
	m_pInfoDisplayLink = NULL;
	m_pMapMoveDisplay = NULL;
	m_pWaitServerDisplay = NULL;
	m_pAcademyConftDisplay = NULL;
	m_pLargeMapWindow = NULL;
	m_pStorageChargeCard = NULL;
	m_pRebirthDialogue = NULL;
	m_pPrivateMarketWindow = NULL;
	m_pPrivateMarketMake = NULL;
	m_pPrivateMarketSellWindow = NULL;
	m_pPrivateMarketShowMan = NULL;
	m_pClubWindow = NULL;
	m_pSubMasterSet = NULL;
	m_pClubMake = NULL;
	m_pSystemMessageWindow = NULL;
	m_pQuestionItemDisplay = NULL;
	m_pkillTimeDisplay = NULL;
	m_pPKComboDisplay = NULL; //Add PK Streak By NjD
	m_pInfoDisplayEx = NULL;
	m_pClubStorageWindow = NULL;
	m_pConftConfirm = NULL;
	m_pBasicInfoView = NULL;
	m_pUILeftTopGroup = NULL;
	m_pSkillTrayTab = NULL;
	m_pSkillTrayTabNew = NULL;
	m_pBasicQuickSkillSlot = NULL;
	m_pCountMsgWindow = NULL;
	m_pCountMsgCDWindow = NULL;
	m_pGameMenu = NULL;
	m_pQBoxButton = NULL;
	m_pItemRebuildWindow = NULL;	// ITEMREBUILD_MARK
	//m_pRebuildInventoryWindow = NULL;
	m_pPetRebirthDialogue = NULL; // monster7j
	m_pGambleBox = NULL;
	m_pGambleSelectBox = NULL;
	m_pGambleAgainBox = NULL;
	m_pGambleResultOddBox = NULL;
	m_pGambleResultEvenBox = NULL;
	m_pPetWindow = NULL;
	m_pCharacterWindow = NULL;
	m_pPartyDisplay = NULL;

	m_pPvpWindowDisplay = NULL;
	m_pModalWindow = NULL;

	m_pSystemMessageWindowDummy = NULL;
	m_pMapMoveDisplayDummy = NULL;
	m_pBlockProgramAlarmDummy = NULL;
	m_pLeftTopGroupDummy = NULL;
	m_pBasicInfoViewDummy = NULL;
	m_pBasicPotionTrayDummy = NULL;
	m_pQuestAlarmDummy = NULL;

	m_pKeySettingWindow = NULL;
	m_pChatMacroWindow = NULL;

	m_pBonusTimeGauge = NULL;
	m_pBonusTimeDisplay = NULL;
	m_pQuestHelper = NULL;
	//m_pVehicleWindow = NULL;
	m_pThaiCCafeMark = NULL;
	//add sw buff
	m_pSwBonusMark = NULL;

	m_pItemGarbageWindow = NULL;
	m_pGarbageInventoryWindow = NULL;

	m_pItemShopIconMan = NULL;
	m_pNameDisplayMan = NULL;

	m_pShopItemSearchWindow   = NULL;
	m_pItemSearchResultWindow = NULL;

	m_pAttendanceBookWindow = NULL;
	m_pClubBattleModalWindow = NULL;

	m_pMapRequireCheckWindow = NULL;
	m_pTaxiWindow = NULL;

	m_bFirstVNGainSysCall = true;	

	m_fItemBankDelay = 5.0f;
	m_fItemShopDelay = 5.0f;
	m_pItemMixWindow = NULL;
	m_pItemMixInvenWindow = NULL;
	m_pGatherGauge = NULL;
	m_pCdmRankingDisplay = NULL;
	pButton = NULL;
	m_pBoxInfo = NULL; //BOX INFO
	m_pCrowTargetInfo = NULL; //Add new Interface
	m_pCrowTargetInfoNpc = NULL; //Add new Interface
	m_pCrowTargetInfoPlayer = NULL; //Add new Interface
	m_pPartyDisplay = NULL;
	m_pPartyDisplayBuff = NULL;

	m_pTargetInfoCtfDisplay = NULL;
	m_pForceRebirth = NULL;	
	m_pCtfRankingDisplay = NULL;	
	m_pCtfInfoDisplay = NULL;	
	m_pProgressCtfDisplay = NULL;	
}


HRESULT CInnerInterface::OneTimeSceneInit ()
{
	switch ( RANPARAM::emSERVICE_TYPE )
	{
	case EMSERVICE_DEFAULT:
	case EMSERVICE_KOREA:
	case EMSERVICE_FEYA:
	case EMSERVICE_MALAYSIA_CN:
	case EMSERVICE_MALAYSIA_EN:
	case EMSERVICE_JAPAN:
	case EMSERVICE_THAILAND:
	case EMSERVICE_CHINA:
	case EMSERVICE_INDONESIA:
	case EMSERVICE_PHILIPPINES:
	case EMSERVICE_VIETNAM:
	case EMSERVICE_GLOBAL:
		m_bCHANNEL = true;
		break;

	default:
		m_bCHANNEL = false;
		break;
	};

	return S_OK;
}

HRESULT CInnerInterface::FrameMove ( LPDIRECT3DDEVICEQ pd3dDevice, float fTime, float fElapsedTime )
{
	GASSERT( pd3dDevice );

	// Ż�� ������ ����
	m_fVehicleDelay += fElapsedTime;

	//	������ �� ���̰� ����.
	//	���ÿ� Update()���� �Ѱ� ����.
	HideGroup ( INFO_DISPLAY );
	HideGroup ( INFO_DISPLAY_EX );
	HideGroup ( INFO_DISPLAY_LINK );

	ResetTargetInfoCrow (); //Add new Interface
	ResetTargetInfoCrowNpc ();
	ResetTargetInfoCrowPlayer ();
	ResetTargetInfo ();		//	Ÿ�� ����â ����
	ResetTargetInfoNpc ();
	ResetTargetInfoPlayer ();
	ResetCharMoveBlock ();	//	ĳ���� ������ ��� Ǯ��	
	ResetSnapItem ();		//	������ ���� ����
	ResetFirstItemSlot ();	//	�����۽��� �ٱ� ����

	ResetTargetCtfInfo();

	m_bUSING_INFO_DISPLAY = false;
	m_bITEM_INFO_LINK_DISPLAY_MODE = false;

	{
		HideGroup ( PARTY_DISPLAY );
		HideGroup ( PARTY_DISPLAY_BUFF );
	}

	// ������ ��ũâ ������ ����
	if( !IsVisibleGroup( /*ITEMBANK_WINDOW*/INVENTORY_WINDOW ) && m_fItemBankDelay < 5.0f )
	{
		m_fItemBankDelay += fElapsedTime;
	}

	if( !IsVisibleGroup( ITEMSHOP_WINDOW ) && m_fItemShopDelay < 5.0f )
	{
		m_fItemShopDelay += fElapsedTime;
	}

	bool bKEYBOARD_BLOCK = false;
	if( IsVisibleGroup ( MODAL_WINDOW ) ||
		IsVisibleGroup ( REBIRTH_DIALOGUE ) ||
		//IsVisibleGroup ( HELP_WINDOW ) ||	// �� ��������, ���� ��� ���� ( ���� )
		IsVisibleGroup ( ITEMSHOP_WINDOW ) ||
		DXInputString::GetInstance().IsOn () )
	{
		bKEYBOARD_BLOCK = true;
	}

	// WebBrowser�� �������� �������� �����Ƿ�
	// �ʿ��� ��Ȳ������ HELP_WINDOW�� �ݴ´� ( ���� )
	if( CCommonWeb::Get()->GetCreate() )
	{
		if( IsVisibleGroup ( MODAL_WINDOW ) ||
			IsVisibleGroup ( REBIRTH_DIALOGUE ) ||
			IsVisibleGroup( ESC_MENU ) )
		{
			HideGroup( HELP_WINDOW );
			HideGroup( ITEMSHOP_WINDOW );
		}
	}

	if ( !bKEYBOARD_BLOCK ) UpdateShortcutBefore ();

	if ( m_sItemInfoLinkTemp.sNativeID != NATIVEID_NULL() )
	{
		SHOW_ITEM_INFO_LINK( m_sItemInfoLinkTemp );
	}

	HRESULT hr = S_OK;
	hr = CUIMan::FrameMove ( pd3dDevice, fTime, fElapsedTime );
	if ( FAILED ( hr ) ) return hr;

	if ( IsVisibleGroup ( INFO_DISPLAY_LINK ) )
	{
		UIRECT rcGlobalPos1 = GetChat()->GetGlobalPos();
		UIRECT rcGlobalPos2 = m_pInfoDisplayLink->GetGlobalPos();

		float x = rcGlobalPos1.right + 2.0f;
		float y = rcGlobalPos1.bottom - rcGlobalPos2.sizeY;

		m_pInfoDisplayLink->SetGlobalPos(D3DXVECTOR2(x,y));
	}

	if( IsOpenWindowToMoveBlock() )
	{
		SetCharMoveBlock ();
	}

	UpdateStatus ();

	if ( !m_bUSING_INFO_DISPLAY ) RESET_INFO ();
	if ( !bKEYBOARD_BLOCK )	UpdateShortcutAfter ();

	if ( IsExclusiveControl() ) SetCharMoveBlock ();

	int LB = (int)DxInputDevice::GetInstance().GetMouseState(DXMOUSE_LEFT);
	if ( (LB & DXKEY_UP) || (LB & DXKEY_DUP) )
	{
		ResetExclusiveControl();
	}

	MoveBasicInfoWindow ();

	if ( SkillTabClose )
	{
		UIRECT rcGlobalPos = m_pSkillTrayTab->GetGlobalPos();
		m_pBasicQuickSkillWindow->SetGlobalPos( D3DXVECTOR2( rcGlobalPos.left , rcGlobalPos.top ) );
	}

	if ( SkillTabOpen )
	{
		UIRECT rcGlobalPos = m_pBasicQuickSkillWindow->GetGlobalPos();
		m_pSkillTrayTab->SetGlobalPos( D3DXVECTOR2( rcGlobalPos.left , rcGlobalPos.top ) );
	}

	if ( SkillTabCloseNew )
	{
		UIRECT rcGlobalPos = m_pSkillTrayTabNew->GetGlobalPos();
		m_pBasicQuickSkillWindowNew->SetGlobalPos( D3DXVECTOR2( rcGlobalPos.left , rcGlobalPos.top ) );
	}

	if ( SkillTabOpenNew )
	{
		UIRECT rcGlobalPos = m_pBasicQuickSkillWindowNew->GetGlobalPos();
		m_pSkillTrayTabNew->SetGlobalPos( D3DXVECTOR2( rcGlobalPos.left , rcGlobalPos.top ) );
	}

	if ( RotateSkillTab )
	{
		UIRECT rcGlobalPos = m_pSkillTrayTab->GetGlobalPos();
		m_pSkillTrayTabNew->SetGlobalPos( D3DXVECTOR2( rcGlobalPos.left , rcGlobalPos.top ) );
	}

	if ( RotateSkillTabNew )
	{
		UIRECT rcGlobalPos = m_pSkillTrayTabNew->GetGlobalPos();
		m_pSkillTrayTab->SetGlobalPos( D3DXVECTOR2( rcGlobalPos.left , rcGlobalPos.top ) );
	}

	CUIFocusContainer::UICONTROL_FOCUSLIST focus_list = GetFocusList()->GetFocusList();
	CUIFocusContainer::UICONTROL_FOCUSLIST_RITER riter = focus_list.rbegin ();
	CUIFocusContainer::UICONTROL_FOCUSLIST_RITER riter_end = focus_list.rend ();

	bool bBasicChatBoxShow = false;
	for ( ; riter != riter_end; ++riter )
	{
		UIGUID cID = riter->cID;
		if ( BASIC_INFO_VIEW == cID )
		{
			if ( bBasicChatBoxShow )
			{
				if ( !GetChat()->IsCHAT_BEGIN() )
				{
					GetFocusList()->InsertAfter ( BASIC_CHAT_BOX, BASIC_INFO_VIEW, riter->pUIControl );
				}
			}
			break;
		}
		else if ( BASIC_CHAT_BOX == cID )
		{
			bBasicChatBoxShow = true;
		}
	}

	{
		GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter ();
		Actor& actor = pCharacter->GetActorMove ();
		if ( actor.PathIsActive () ) m_vCharDir = actor.Movement ();
	}

	{
		if ( IsVisibleGroup ( INFO_DISPLAY_EX ) )
		{
			UIRECT rcGlobalPos = m_pInfoDisplay->GetGlobalPos();
			UIRECT rcGlobalPosEx = m_pInfoDisplayEx->GetGlobalPos();
			float x = rcGlobalPos.right + 2.0f;
			float y = min(rcGlobalPos.top,rcGlobalPosEx.top);

			const long lResolution = GetResolution ();
			WORD X_RES = HIWORD ( lResolution );
			WORD Y_RES = LOWORD ( lResolution );

			if ( X_RES < x + rcGlobalPosEx.sizeX )
			{
				x = X_RES - rcGlobalPosEx.sizeX;

				m_pInfoDisplay->SetGlobalPos(D3DXVECTOR2(x-2.0f-rcGlobalPos.sizeX,y));
				m_pInfoDisplayEx->SetGlobalPos(D3DXVECTOR2(x,y));
			}
			else
			{
				m_pInfoDisplay->SetGlobalPos(D3DXVECTOR2(rcGlobalPos.left,y));
				m_pInfoDisplayEx->SetGlobalPos(D3DXVECTOR2(x,y));
			}
		}
	}

#ifdef _RELEASED // ��ȯ�� ���ο����� �ǰ� ����
	{
		if( IsVisibleGroup ( SUMMON_POSION_DISPLAY ) )
		{
			GLSummonClient *pMySummon = GLGaeaClient::GetInstance().GetSummonClient();
			if( !pMySummon || !pMySummon->IsVALID() )
			{
				HideGroup ( SUMMON_POSION_DISPLAY );
			}
		}
	}
#endif

	return hr;
}

void CInnerInterface::UpdateShortcutBefore ()
{	
	{
		if ( !m_pNameDisplayMan ) return ;		

		if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_LMENU, DXKEY_PRESSED ) )
		{
			for (int i= 0; i < CHAT_MACRO_SIZE; ++i){
				if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_1+i, DXKEY_DOWN ) )
				{			
					AddChatMacro(i);
					break;
				}
			}
		}



		if( RANPARAM::bNAME_DISPLAY )
		{
			if( IsVisibleGroup( NAME_DISPLAY_MAN ) )
			{
				if( m_pNameDisplayMan->GetNameType() != NAME_DISPLAY_MOBCHAR )
				{
					HideGroup( NAME_DISPLAY_MAN );
					m_pNameDisplayMan->SetNameType( NAME_DISPLAY_MOBCHAR );
					ShowGroupBottom( NAME_DISPLAY_MAN );
				}
			}
			else
			{
				m_pNameDisplayMan->SetNameType( NAME_DISPLAY_MOBCHAR );
				ShowGroupBottom( NAME_DISPLAY_MAN );
			}

			return ;
		}

		HideGroup ( NAME_DISPLAY_MAN );		
		if ( UIKeyCheck::GetInstance()->Check ( DIK_LMENU, DXKEY_PRESSED ) )
		{
			m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_ITEMMONEY );
			ShowGroupBottom ( NAME_DISPLAY_MAN );
		}
		else if ( UIKeyCheck::GetInstance()->Check ( DIK_LCONTROL, DXKEY_PRESSED ) )
		{
			m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_MOBCHAR );
			ShowGroupBottom ( NAME_DISPLAY_MAN );
		}
		else if ( UIKeyCheck::GetInstance()->Check ( DIK_LSHIFT, DXKEY_PRESSED ) )
		{
			m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_ALL );
			ShowGroupBottom ( NAME_DISPLAY_MAN );
		}
		else
		{
			//	BEGIN : CLUB CONFT SETTING
			const EMCONFT_TYPE emTYPE = GLGaeaClient::GetInstance().GetCharacter()->GetConfting().emTYPE;
			if ( emTYPE == EMCONFT_GUILD )
			{
				m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_CLUB_CONFT );
				ShowGroupBottom ( NAME_DISPLAY_MAN );                
				return ;
			}

			//	��Ƽ
			GLPARTY_CLIENT *pMaster = GLPartyClient::GetInstance().GetMaster();	//	������
			if ( pMaster )
			{
				GLCharacter *pMyCharacter = GLGaeaClient::GetInstance().GetCharacter();			

				if ( pMyCharacter->GetConfting().IsCONFRONTING() )	//	��Ƽ ��� ���ΰ�?
				{
					m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_PARTY_CONFT );			
				}
				else	//	��Ƽ ���� �� ���
				{
					m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_PARTY );		
				}
				ShowGroupBottom ( NAME_DISPLAY_MAN );
			}
			else
			{
				//	������ �Ѹ�
				m_pNameDisplayMan->SetNameType ( NAME_DISPLAY_DEFAULT );
				ShowGroupBottom ( NAME_DISPLAY_MAN );
			}
		}
	}	
}

void CInnerInterface::UpdateShortcutAfter ()
{
/*	if( cID == ITEM_REBUILD_WINDOW || cID == REBUILDINVENTORY_WINDOW )
	{
		( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_INVEN], DXKEY_DOWN ))
		{
			HideGroup ( INVENTORY_WINDOW );
		}
	}*/
	if ( UIKeyCheck::GetInstance()->Check ( DIK_ESCAPE, DXKEY_DOWN ) )
	{
		bool bALLHIDE = true;
		
		//HideGroup ( DIALOGUE_WINDOW );
		//HideGroup ( MARKET_WINDOW );
		//CloseItemViewWindow();


		//	NOTE
		//		���ÿ� �� ������ FocusList��
		//		������ ���ɼ��� ���ٴ� ������ �־�� �Ѵ�.
		//		�����ϱ� ��.��
		CUIFocusContainer::UICONTROL_FOCUSLIST list = GetFocusList()->GetFocusList ();
		CUIFocusContainer::UICONTROL_FOCUSLIST_RITER riter = list.rbegin ();
		CUIFocusContainer::UICONTROL_FOCUSLIST_RITER riter_end = list.rend ();
		for ( ; riter != riter_end; ++riter )
		{
			bool bAnotherProcess = false;
			UIGUID cID = riter->cID;

			if ( IsVisibleGroup ( cID ) && 
				cID != BASIC_CHAT_BOX && 
				cID != BASIC_INFO_VIEW &&
				cID != QUICK_SKILL_TRAY_TAB_WINDOW &&
				cID != QUICK_SKILL_TRAY_TAB_NEW_WINDOW &&
				cID != BASIC_QUICK_SKILL_WINDOW &&
				cID != BASIC_QUICK_SKILL_NEW_WINDOW &&
				cID != PRIVATE_MARKET_SHOW_MAN && 
				cID != MINIMAP && 
				cID != KILL_TIME_DISPLAY &&
				cID != INFO_CTF_DISPLAY &&
				cID != REBIRTH_FORCE
)
			{
				if ( cID == INVENTORY_WINDOW || cID == MARKET_WINDOW ||
					cID == STORAGE_WINDOW || cID == CLUB_STORAGE_WINDOW ||
					cID == DIALOGUE_WINDOW)
				{
					SetMarketWindowClose ();
					SetStorageWindowClose ();
					SetClubStorageWindowClose ();
				}
				else if ( cID == TRADEINVENTORY_WINDOW )
				{
					if ( IsVisibleGroup ( TRADE_WINDOW ) )
					{
						SetTradeWindowCloseReq ();
					}
					else if ( IsVisibleGroup ( PRIVATE_MARKET_WINDOW ) )
					{
						if ( m_pPrivateMarketWindow->IsOPENER () )
						{
							DoModal ( ID2GAMEINTEXT("PRIVATE_MARKET_QUIT"), MODAL_QUESTION, YESNO, MODAL_PRIVATE_MARKET_QUIT );
						}
						else
						{
							SetPrivateMarketClose ();
						}
						bAnotherProcess = true;
					}
				}
				else if ( cID == TRADE_WINDOW )
				{							
					SetTradeWindowCloseReq ();
				}
				else if ( cID == ITEMPREVIEW_WINDOW )
				{							
					HideGroup ( ITEMPREVIEW_WINDOW );
				}
				else if ( cID == QUEST_WINDOW )
				{							
					HideGroup ( QUEST_WINDOW );
					ShowGroupBottom ( QUEST_ALARM );
				}
				else if ( cID == VIEW_PROPERTIES_WINDOW )
				{
					CloseItemViewWindow();
				}
				else if ( cID == MINIPARTY_WINDOW )
				{
					ShowGroupBottom ( MINIPARTY_OPEN );
// #ifdef CH_PARAM // �߱� �������̽� ����
//					UpdatePotionTrayPosition();
// #endif
				}
				else if ( cID == PRIVATE_MARKET_WINDOW )
				{
					if ( m_pPrivateMarketWindow->IsOPENER () )
					{
						DoModal ( ID2GAMEINTEXT("PRIVATE_MARKET_QUIT"), MODAL_QUESTION, YESNO, MODAL_PRIVATE_MARKET_QUIT );
					}
					else
					{
						SetPrivateMarketClose ();
					}
					bAnotherProcess = true;					
				}
				else if( cID == ITEM_REBUILD_WINDOW || cID == REBUILDINVENTORY_WINDOW )	// ITEMREBUILD_MARK
				{
					CloseItemRebuildWindow();
				}
				else if( cID == ITEM_GARBAGE_WINDOW || cID == GARBAGEINVENTORY_WINDOW )	// ������
				{
					CloseItemGarbageWindow();
				}
				else if( cID == ITEM_MIX_WINDOW || cID == ITEM_MIX_INVEN_WINDOW )	// ������ ����
				{
					CloseItemMixWindow();
				}
				else if( cID == GAMBLE_DIALOGUE || cID == GAMBLE_SELECT_DIALOGUE || 
						cID == GAMBLE_AGAIN_DIALOGUE || cID == GAMBLE_ANIMATION_DIALOGUE || 
						cID == GAMBLE_RESULT_EVEN_DIALOGUE || cID == GAMBLE_RESULT_ODD_DIALOGUE  )
				{
					HideGroup( INVENTORY_WINDOW );
					GLCharacter* pCharacter = GLGaeaClient::GetInstance().GetCharacter();
					if( pCharacter )
					{
						pCharacter->ReqMGameOddEvenCancel();
					}
				}
				else if ( cID == QUEST_WINDOW )
				{
					m_pQuestWindow->SET_SHOW_PAGE ( CQuestWindow::QUEST_LIST );
					bAnotherProcess = true;
					/*int nPage = m_pQuestWindow->GET_SHOW_PAGE ();
					switch ( nPage )
					{
					case CQuestWindow::QUEST_STEP:
						{							
							m_pQuestWindow->SET_SHOW_PAGE ( CQuestWindow::QUEST_MAIN );
							bAnotherProcess = true;
						}
						break;

					case CQuestWindow::QUEST_MAIN:
						{												
							m_pQuestWindow->SET_SHOW_PAGE ( CQuestWindow::QUEST_LIST );
							bAnotherProcess = true;
						}
						break;
					}*/					
				}
				else if ( cID == SCHOOL_WARS_WINDOW )
				{
					HideGroup ( SCHOOL_WARS_WINDOW );
				}
				else if ( cID == ROYAL_RUMBLE_WINDOW )
				{
					HideGroup ( ROYAL_RUMBLE_WINDOW );
				}
				else if ( cID == CHARACTER_WINDOW )
				{
					HideGroup ( CHARACTER_WINDOW );
				}
				else if ( cID == WAITSERVER_DISPLAY || cID == REBIRTH_DIALOGUE || cID == MAP_REQUIRE_CHECK )
				{
					bAnotherProcess = true;
				}
				else if ( (MODAL_WINDOW + 1) <= cID )
				{
					//					CLOSE_MODAL ( cID, false );
					bAnotherProcess = true;
				}
				else if( cID == INFO_DISPLAY_LINK )
				{
					CLEAR_INFO_LINK ();
				}

				if ( !bAnotherProcess )	
				{
					HideGroup ( cID );
				}

				bALLHIDE = false;
				break;
			}
		}

		if ( bALLHIDE )
		{
			if ( !IsVisibleGroup ( ESC_MENU ) )
				ShowGroupFocus ( ESC_MENU );
		}
	}

	// Tab Key �������̶��
	if ( m_bTabReserve ) 
	{
		if ( !GLGaeaClient::GetInstance().GetCharacter()->IsACTION(GLAT_SKILL) )
		{
			GLGaeaClient::GetInstance().GetCharacter()->ReqSlotChange();
			m_bTabReserve = false;
		}
	}	
	else 
	{
		if ( UIKeyCheck::GetInstance()->Check( DIK_TAB, DXKEY_DOWN ) )
		{
			EMCHARCLASS emClass = GLGaeaClient::GetInstance().GetCharacter()->m_emClass;

			if ( emClass&GLCC_EXTREME_M || emClass&GLCC_EXTREME_W )
			{
				 //��ų ��������� �����ϸ� Tab Key ����
				if ( E_FAIL == GLGaeaClient::GetInstance().GetCharacter()->ReqSlotChange() )
					m_bTabReserve = true;
			}
				
		}
	}



	if ( IsVisibleGroup ( ESC_MENU ) )				return ;
	if ( IsVisibleGroup ( HELP_WINDOW ) )			return ;
	if ( IsVisibleGroup ( ITEMSHOP_WINDOW ) )		return ;
	if ( IsVisibleGroup ( KEY_SETTING_WINDOW ) )	return ;

	if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_V, DXKEY_DOWN ) )
	{
		if ( GLTradeClient::GetInstance().Valid() ) return;
		GLCharacter* const pCharacter = GLGaeaClient::GetInstance().GetCharacter ();

		if ( pCharacter->m_sVehicle.IsActiveValue() && m_fVehicleDelay < 1.0f )	
		{
			PrintMsgText ( NS_UITEXTCOLOR::NEGATIVE, ID2GAMEINTEXT("VEHICLE_SET_FB_DELAY") );
			return;
		}

		pCharacter->ReqSetVehicle( !pCharacter->m_bVehicle ); // Ȱ�� ��Ȱ��
		m_fVehicleDelay = 0.0f;
	}

	if ( UIKeyCheck::GetInstance()->CheckSimple ( RANPARAM::MenuShotcut[SHOTCUT_ITEMSHOP], DXKEY_DOWN ) )
	{
		if ( GLTradeClient::GetInstance().Valid() ) return;
		GLCharacter* const pCharacter = GLGaeaClient::GetInstance().GetCharacter ();

		if ( IsVisibleGroup ( ITEMSHOP_WINDOW ) )	HideGroup ( ITEMSHOP_WINDOW );
		else										SetItemShopWindowOpen ();

	}


	if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_LMENU, DXKEY_PRESSED ) )
	{
		for (int i= 0; i < CHAT_MACRO_SIZE; ++i){
			if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_1+i, DXKEY_DOWN ) )
			{			
				return ;
			}
		}
	}

	GLCharacter* const pCharacter = GLGaeaClient::GetInstance().GetCharacter ();
	if ( pCharacter )
	{
		//	�� ��ų
		for( int i = 0; i < QUICK_SKILL_SLOT_MAX; ++i)
		{
            if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::SkillSlot[i], DXKEY_DOWN ) )
			{
				INT nIndex = m_pSkillTrayTabNew->GetTabIndex() * QUICK_SKILL_SLOT_MAX + i;
				pCharacter->ReqSkillRunSet( nIndex );
			}
		}
	}
	
	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_INVEN], DXKEY_DOWN ) )
	{		
		if ( !IsVisibleGroup ( INVENTORY_WINDOW ) && !IsVisibleGroup ( TRADEINVENTORY_WINDOW ) /*&& state == -1*/ )
		{
			ShowGroupFocus( INVENTORY_WINDOW );
			m_pInventoryWindow->INVENTORY();
			state = 0;
		}
		else
		{
			if ( state == 0) // Current inventory
			{
				HideGroup ( INVENTORY_WINDOW );
				state = -1;
			}
			else if ( state == 1) // Current itembank
			{
				m_pInventoryWindow->INVENTORY();
				state = 0;
			}
		}
	}

#ifdef _RELEASED // ��ȯ�� ���ο����� �ǰ� ����
	if ( UIKeyCheck::GetInstance()->CheckSimple( DIK_SLASH, DXKEY_DOWN ) )
	{
		GLGaeaClient::GetInstance().ReqUseSummon(SNATIVEID(2,2));
	}
#endif


	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_SKILL], DXKEY_DOWN ) )
	{		
		if ( !IsVisibleGroup ( SKILL_WINDOW ) )
			ShowGroupFocus ( SKILL_WINDOW );
		else
			HideGroup ( SKILL_WINDOW );
	}

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_PARTY], DXKEY_DOWN ) )
	{		
		if ( !IsVisibleGroup ( PARTY_WINDOW ) )
			ShowGroupFocus ( PARTY_WINDOW );
		else
			HideGroup ( PARTY_WINDOW );
	}

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_CHAR], DXKEY_DOWN ) )
	{		
		//if ( !IsVisibleGroup ( CHARACTER_WINDOW ) )
		//	ShowGroupFocus ( CHARACTER_WINDOW );
		//else
		///	HideGroup ( CHARACTER_WINDOW );
		OpenCharacterPage();
	}

	if ( UIKeyCheck::GetInstance()->CheckSimple ( RANPARAM::MenuShotcut[SHOTCUT_MAP], DXKEY_DOWN ) )
	{
		if ( !IsVisibleGroup ( LARGEMAP_WINDOW ) )
			ShowGroupFocus ( LARGEMAP_WINDOW );
		else
			HideGroup ( LARGEMAP_WINDOW );
	}

	if ( UIKeyCheck::GetInstance()->CheckSimple ( RANPARAM::MenuShotcut[SHOTCUT_CLUB], DXKEY_DOWN ) )
	{
		if ( !IsVisibleGroup ( CLUB_WINDOW ) )
			ShowGroupFocus ( CLUB_WINDOW );
		else
			HideGroup ( CLUB_WINDOW );
	}

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_QUEST], DXKEY_DOWN ) )
	{
		if ( !IsVisibleGroup ( QUEST_WINDOW ) )
		{			
			if ( NATIVEID_NULL().dwID == m_dwEventQuestID )
			{
				ShowGroupFocus ( QUEST_WINDOW );
				REFRESH_QUEST_WINDOW ();				
			}
			else
			{
				SetQuestWindowOpen ( m_dwEventQuestID );
			}
		}
		else
		{
			HideGroup ( QUEST_WINDOW );
		}
	}
//#if defined ( CH_PARAM ) || defined ( TH_PARAM ) || defined( PH_PARAM ) || defined ( JP_PARAM ) || defined( _RELEASED )
	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_HELP], DXKEY_DOWN) )
	{
		if ( !IsVisibleGroup ( HELP_WINDOW ) )
		{
			HideGroup ( ITEMSHOP_WINDOW );
			ShowGroupFocus ( HELP_WINDOW );
		}
		else
		{
			HideGroup ( HELP_WINDOW );
		}
	}

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_ITEMSHOP], DXKEY_DOWN  ) )
	{
		if ( !GLGaeaClient::GetInstance().m_vecCtfRankAll.empty() )
		{
			ShowGroupFocus( TOWER_RANKING_DISPLAY );
			RefreshCTFRanking();
		}
		
		/*if( GLGaeaClient::GetInstance().GetActiveMap()->m_bTowerWars )
		{
			GLGaeaClient::GetInstance().ReqTowerWarsCTFInfo();
		}*/
	}

//#if defined ( CH_PARAM ) || defined ( TH_PARAM ) || defined( PH_PARAM ) || defined ( JP_PARAM ) || defined( _RELEASED ) // �ʸ��� �����ۼ�
	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_ITEMSHOP], DXKEY_DOWN) )
	{
		//if ( !IsVisibleGroup ( ITEMSHOP_WINDOW ) )
		//{
		//	//	ItemShopAuth
		//	if ( ItemShopAuth() )
		//	{
		//		ShowGroupFocus ( ITEMSHOP_WINDOW );
		//	}

		//	HideGroup ( HELP_WINDOW );
		//}
		//else
		//{
		//	HideGroup ( ITEMSHOP_WINDOW );
		//}
	}
	
	//	ItemShopAuth	
	ItemShopVisible();

//#endif	
	//RankingWindow
	PLANDMANCLIENT pLand = GLGaeaClient::GetInstance().GetActiveMap();
	if( UIKeyCheck::GetInstance()->Check( DIK_F5, DXKEY_DOWN ) )	
	{
		if ( pLand->m_bSchoolWars )
		{
			if ( IsVisibleGroup ( SCHOOL_WARS_WINDOW ) )		
				HideGroup ( SCHOOL_WARS_WINDOW );
			else										
				ShowGroupFocus ( SCHOOL_WARS_WINDOW );
		}
	}

	if ( pLand->m_bSchoolWars )
	{																
		ShowGroupBottom ( SW_RANKING_DISPLAY );
	}

	
	//RankingWindow for RoyalRumble
	if( UIKeyCheck::GetInstance()->Check( DIK_F6, DXKEY_DOWN ) )	
	{
		if ( pLand->m_bRoyalRumble )
		{
			if ( IsVisibleGroup ( ROYAL_RUMBLE_WINDOW ) )		
				HideGroup ( ROYAL_RUMBLE_WINDOW );
			else										
				ShowGroupFocus ( ROYAL_RUMBLE_WINDOW );
		}
	}

	if ( pLand->m_bRoyalRumble )
		{																
				ShowGroupBottom ( RRP_RANKING_DISPLAY );
		}

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_FRIEND], DXKEY_DOWN ) )
	{
		if ( IsVisibleGroup ( FRIEND_WINDOW ) )		HideGroup ( FRIEND_WINDOW );			
		else										ShowGroupFocus ( FRIEND_WINDOW );
	}

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_ITEMBANK], DXKEY_DOWN ) )
	{
		if ( !IsVisibleGroup ( INVENTORY_WINDOW ) /*&& state == -1*/)
		{
			SetItemBankWindowOpen ();
		}
		else
		{
			if (state == 0) // Current inventory
			{
				m_pInventoryWindow->INVENTORY_BANK();
				m_pInventoryWindow->InitItemBank();
				//state = 1;
			}
			else if (state == 1) //Current itembank
			{
				HideGroup ( INVENTORY_WINDOW );
			//	state = -1;
			}
		}
	}

	/*if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_VIETNAMGAINSYS], DXKEY_DOWN ) )
	{
		if ( IsVisibleGroup ( VNGAINSYS_WINDOW ) )	HideGroup ( VNGAINSYS_WINDOW );
		else										SetVNGainSysWindowOpen();
	}*/

	if ( UIKeyCheck::GetInstance()->Check ( RANPARAM::MenuShotcut[SHOTCUT_CHATMACRO], DXKEY_DOWN ) )
	{
		if ( IsVisibleGroup ( CHATMACRO_WINDOW ) )
		{
			HideGroup ( CHATMACRO_WINDOW );
		}
		else
		{
			GetChatMacro();
			ShowGroupFocus ( CHATMACRO_WINDOW );
		}
	}



	if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_LMENU, DXKEY_PRESSED ) )
	{
		if ( UIKeyCheck::GetInstance()->CheckSimple ( DIK_F4, DXKEY_DOWN ) )
		{			
			DoModal ( ID2GAMEINTEXT("MODAL_ESC_MENU_CLOSE"), MODAL_QUESTION, YESNO, MODAL_CLOSEGAME );
		}
	}

//#ifndef CH_PARAM // �߱� �������̽� ����
	/*if( UIKeyCheck::GetInstance()->Check ( DIK_GRAVE, DXKEY_DOWN ) ||
		UIKeyCheck::GetInstance()->Check ( DIK_Y, DXKEY_DOWN ) )
	{
		
			HideGroup ( QUICK_SKILL_TRAY_TAB_WINDOW );
			ShowGroupFocus ( QUICK_SKILL_TRAY_OPEN_BUTTON , true );
		}
	}*/
//#endif

	if( UIKeyCheck::GetInstance()->Check( DIK_F1, DXKEY_DOWN ) )	
	{
		m_pSkillTrayTab->SetTabIndex( 0 );
		m_pSkillTrayTab->SetTabTextIndex( 0 );
		m_pSkillTrayTabNew->SetTabIndex( 0 );
		m_pSkillTrayTabNew->SetTabTextIndex( 0 );
	}
	if( UIKeyCheck::GetInstance()->Check( DIK_F2, DXKEY_DOWN ) )
	{
		m_pSkillTrayTab->SetTabIndex( 1 );
		m_pSkillTrayTab->SetTabTextIndex( 1 );
		m_pSkillTrayTabNew->SetTabIndex( 1 );
		m_pSkillTrayTabNew->SetTabTextIndex( 1 );;
	}
	if( UIKeyCheck::GetInstance()->Check( DIK_F3, DXKEY_DOWN ) )
	{
		m_pSkillTrayTab->SetTabIndex( 2 );
		m_pSkillTrayTab->SetTabTextIndex( 2 );
		m_pSkillTrayTabNew->SetTabIndex( 2 );
		m_pSkillTrayTabNew->SetTabTextIndex( 2 );
	}
	if( UIKeyCheck::GetInstance()->Check( DIK_F4, DXKEY_DOWN ) )
	{
		m_pSkillTrayTab->SetTabIndex( 3 );
		m_pSkillTrayTab->SetTabTextIndex( 3 );
		m_pSkillTrayTabNew->SetTabIndex( 3 );
		m_pSkillTrayTabNew->SetTabTextIndex( 3 );
		
	}

	if( UIKeyCheck::GetInstance()->Check( RANPARAM::MenuShotcut[SHOTCUT_PET], DXKEY_DOWN ) )
	{
		if( GLGaeaClient::GetInstance().GetPetClient()->IsVALID() )
		{
			if ( GLTradeClient::GetInstance().Valid() ) return;
			
			if ( IsVisibleGroup( PET_WINDOW ) )		HideGroup ( PET_WINDOW );
			else									ShowGroupFocus( PET_WINDOW );

			
		}
	}


#ifdef _RELEASED // ��ȯ�� ���ο����� �ǰ� ����
	if( UIKeyCheck::GetInstance()->Check( RANPARAM::MenuShotcut[SHOTCUT_SUMMON], DXKEY_DOWN ) )
	{
		if( GLGaeaClient::GetInstance().GetSummonClient()->IsVALID() )
		{
			if ( GLTradeClient::GetInstance().Valid() ) return;

			if ( IsVisibleGroup( SUMMON_WINDOW ) )		HideGroup ( SUMMON_WINDOW );
			else									ShowGroupFocus( SUMMON_WINDOW );


		}
	}
#endif

	

	if( UIKeyCheck::GetInstance()->Check( DIK_N, DXKEY_DOWN ) )
	{
		//if( GLGaeaClient::GetInstance().GetCharacter()->m_sVehicle.IsActiveValue() )
		//{
		//	if ( GLTradeClient::GetInstance().Valid() ) return;
			
		//	if ( IsVisibleGroup( VEHICLE_WINDOW ) )	HideGroup ( VEHICLE_WINDOW );
		//	else									ShowGroupFocus( VEHICLE_WINDOW );

			//if ( IsVisibleGroup( INVENTORY_WINDOW ) )		HideGroup ( INVENTORY_WINDOW );
			//else									ShowGroupFocus( INVENTORY_WINDOW );
			//m_pInventoryWindow->SetVisiblePage (2)	;		
		//}

		OpenVehiclePage();
	}
}
void CInnerInterface::SetInventoryPage()
{
	m_pInventoryWindow->INVENTORY();
	state = 0;
}
void CInnerInterface::UpdateStatus ()
{
	GLCharacter* const pCharacter = GLGaeaClient::GetInstance().GetCharacter();

	if ( IsVisibleGroup ( SYSTEM_MESSAGE_WINDOW ) )
	{
		UIRECT rcGlobalPos = m_pSystemMessageWindowDummy->GetGlobalPos ();
		//rcGlobalPos.top += fMENU_LIFTUP;
		m_pSystemMessageWindow->SetGlobalPos ( rcGlobalPos );
	}

	/*if ( IsBlockProgramAlarm () )
	{		
		if ( !IsVisibleGroup ( BLOCK_PROGRAM_ALARM ) )
		{
			UIRECT rcGlobalPos = m_pBlockProgramAlarmDummy->GetGlobalPos ();
			rcGlobalPos.top += float((rand()%200) - 100);
			rcGlobalPos.left += float((rand()%200) - 100);
			m_pBlockProgramAlarm->SetGlobalPos ( rcGlobalPos );

			GetPositionKeeper()->SetPosition ( BLOCK_PROGRAM_ALARM, rcGlobalPos );

			ShowGroupFocus ( BLOCK_PROGRAM_ALARM );
		}
	}
	else
	{
		HideGroup ( BLOCK_PROGRAM_ALARM );
	}*/
	
	
	//	ĳ���� ���� ���� Ȯ��
	if ( pCharacter->IsDie () )
	{
		PLANDMANCLIENT pLand = GLGaeaClient::GetInstance().GetActiveMap();
		if( pLand && ( pLand->m_bTowerWars || pLand->m_bTowerWars /*|| pLand->m_bRoyalRamble*/ ) )
		{
			if ( !IsVisibleGroup ( REBIRTH_FORCE ) )
			{
				m_pForceRebirth->SetCallerID ( MODAL_REBIRTH );
				m_pForceRebirth->DoForceRebirth();
				ShowGroupFocus ( REBIRTH_FORCE, true );
				ShowGroupFocus ( BASIC_CHAT_BOX, true );
			}
		}
		else
		{
			if ( !IsVisibleGroup ( REBIRTH_DIALOGUE ) )
			{
				bool bItemRebirth = (pCharacter->ISREVIVE ())?true:false;
				bool bAutoRebirth = false;
				bool bCantUseRebirth = FALSE;

				//	��ȥ�� �� Ÿ�� üũ
				if ( bItemRebirth ) 
				{
					SITEM* pITEM = pCharacter->GET_SLOT_ITEMDATA(SLOT_NECK);
					if ( pITEM && pCharacter->IsCoolTime( pITEM->sBasicOp.sNativeID ) )
					{
						bItemRebirth = FALSE;
					}
				}

				if( pCharacter->IsRestartPossible() == FALSE )
				{
					bItemRebirth = FALSE;
					bCantUseRebirth = TRUE;
				}

				if ( bItemRebirth )
				{
					// �Ҹ� ��ȥ���̸� �ڵ� ��ȥ�� ���
					SITEM* pITEM = pCharacter->GET_SLOT_ITEMDATA(SLOT_NECK);
					if ( pITEM && !pITEM->ISINSTANCE() ) bAutoRebirth = true;
				}
				
				m_pRebirthDialogue->SET_ITEMREBIRTH ( bItemRebirth, bAutoRebirth, bCantUseRebirth );
				m_pRebirthDialogue->SetCallerID ( MODAL_REBIRTH );
				ShowGroupFocus ( REBIRTH_DIALOGUE, true );
				ShowGroupFocus ( BASIC_CHAT_BOX, true );
			}
		}		
	}
	else
	{
		HideGroup ( REBIRTH_DIALOGUE, true );
		HideGroup ( REBIRTH_FORCE, true );

		if ( IsGateOpen () )
		{
			//	���� �� �̸��� ���ٸ�, �̵��� �� ����.
			if ( m_pMapMoveDisplay )
			{
				CString strMapName = pCharacter->DetectGateToMapName();
				m_pMapMoveDisplay->SetMapName ( strMapName + ID2GAMEINTEXT ( "MAPMOVE_MESSAGE" ) );

				UIRECT rcGlobalPos = m_pMapMoveDisplayDummy->GetGlobalPos ();
				rcGlobalPos.top -= fMENU_LIFTUP;
				m_pMapMoveDisplay->SetGlobalPos ( rcGlobalPos );

				if ( strMapName.GetLength () )	ShowGroupFocus ( MAPMOVE_DISPLAY );
				else							HideGroup ( MAPMOVE_DISPLAY );
			}		
		}
		else
		{
			HideGroup ( MAPMOVE_DISPLAY );
		}
	}

	//	����, ���� ���μ��� üũ
	/*if ( IsBlockProgramFound () )
	{
		if ( !IsVisibleGroup ( WAITSERVER_DISPLAY ) )
			DoModal ( ID2GAMEINTEXT("BLOCK_PROGRAM_FOUND"), MODAL_INFOMATION, OK, MODAL_CLOSEGAME );
	}*/

	if ( !DxGlobalStage::GetInstance().IsEmulator() )		//��Ʈ��ũ ������ ������ ���
	{
		if ( !DxGlobalStage::GetInstance().IsSTATE( DxGlobalStage::EM_CHANGE ) )
		{
			if ( !DxGlobalStage::GetInstance().GetNetClient()->IsOnline() )
			{
				if ( !IsVisibleGroup ( WAITSERVER_DISPLAY ) )
					DoModal ( ID2GAMEINTEXT("PLAYINTERFACE_5"), MODAL_INFOMATION, OK, MODAL_CLOSEGAME );				
			}
		}
	}

	if ( m_pAdminMessageDisplay )
	{
		if ( IsVisibleGroup ( ADMIN_MESSAGE_DISPLAY ) )
		{
			if ( m_pAdminMessageDisplay->GetLifeTime () < 0.0f )
			{
				HideGroup ( ADMIN_MESSAGE_DISPLAY );			
			}
		}
	}

	//if ( m_pSimpleMessageMan )
	//{
	//if ( IsVisibleGroup ( SIMPLE_MESSAGE_MAN ) )
	//{
	//	if ( m_pSimpleMessageMan->GetLifeTime () < 0.0f )
	//	{
	//		HideGroup ( SIMPLE_MESSAGE_MAN );			
	//	}
	//}
	//	}

	BOOL bPartyState = FALSE;
	GLPARTY_CLIENT *pMaster = GLPartyClient::GetInstance().GetMaster();	//	������
	if ( pMaster )
	{
		bPartyState = TRUE;
	}

	if ( bPartyState != m_bPartyStateBack )
	{
		if ( GLPARTY_CLIENT *pMaster = GLPartyClient::GetInstance().GetMaster() )
		{
			ShowGroupFocus ( MINIPARTY_WINDOW );
			HideGroup ( MINIPARTY_OPEN );
		}
		else
		{
			ShowGroupBottom ( MINIPARTY_OPEN );
			HideGroup ( MINIPARTY_WINDOW );
		}
		m_bPartyStateBack = bPartyState;

// #ifdef CH_PARAM // �߱� �������̽� ����
//		UpdatePotionTrayPosition();
// #endif
	}

	UpdateStateQuestAlarm ();
	UpdateStateSimpleHP ();	

	if ( IsVisibleGroup ( ACADEMY_CONFT_DISPLAY ) || IsVisibleGroup ( SYSTEM_MESSAGE_WINDOW ) )
	{
		HideGroup ( SIMPLE_MESSAGE_MAN );
	}
	else
	{
		if ( RANPARAM::bSHOW_TIP )
		{
			ShowGroupBottom ( SIMPLE_MESSAGE_MAN, true );
		}
		else
		{
			HideGroup ( SIMPLE_MESSAGE_MAN, true );
		}
	}
}

void CInnerInterface::MoveBasicInfoWindow ()
{
	CUIControl * pControl(NULL);

//#ifdef CH_PARAM // �߱� �������̽� ����
//	pControl = m_pBasicQuickSkillSlot;
//#else
	pControl = m_pUILeftTopGroup;
//#endif

	if ( !pControl ) return;

	const UIRECT& rcBasicInfoViewDummy = m_pBasicInfoViewDummy->GetGlobalPos ();
	const UIRECT& rcLeftTopGroupDummy = m_pLeftTopGroupDummy->GetGlobalPos ();
	const UIRECT& rcBasicInfoView = m_pBasicInfoView->GetGlobalPos ();
	const UIRECT& rcLeftTopGroup = pControl->GetGlobalPos ();

	const D3DXVECTOR2 vLeftTopGroup ( rcLeftTopGroup.left, rcLeftTopGroup.top );
	const D3DXVECTOR2 vLeftTopGroupDummy ( rcLeftTopGroupDummy.left, rcLeftTopGroupDummy.top );

	const D3DXVECTOR2 vBasicInfoViewDummy (rcBasicInfoViewDummy.left,rcBasicInfoViewDummy.top);
	const D3DXVECTOR2 vBasicInfoView (rcBasicInfoView.left,rcBasicInfoView.top);
	const D3DXVECTOR2 vDist = vBasicInfoViewDummy - vBasicInfoView;
	const float fDist = D3DXVec2LengthSq ( &vDist );

	if ( fDist > 900.0f )	//	��Ʈ���� ��������?
	{	
		if ( vBasicInfoViewDummy != vLeftTopGroup ) pControl->SetGlobalPos ( vBasicInfoViewDummy );
	}
	else
	{
		if ( vLeftTopGroupDummy != vLeftTopGroup )		pControl->SetGlobalPos ( vLeftTopGroupDummy );
		if ( vBasicInfoViewDummy != vBasicInfoView )	m_pBasicInfoView->SetGlobalPos( vBasicInfoViewDummy );
	}
}

void CInnerInterface::BasicInfoViewDoubleClick()
{
	CUIControl * pControl(NULL);

//#ifdef CH_PARAM // �߱� �������̽� ����
//	pControl = m_pBasicQuickSkillSlot;
//#else
	pControl = m_pUILeftTopGroup;
//#endif

	const UIRECT& rcBasicInfoViewDummy = m_pBasicInfoViewDummy->GetGlobalPos ();
	const UIRECT& rcLeftTopGroupDummy = m_pLeftTopGroupDummy->GetGlobalPos ();

	const D3DXVECTOR2 vLeftTopGroupDummy ( rcLeftTopGroupDummy.left, rcLeftTopGroupDummy.top );
	const D3DXVECTOR2 vBasicInfoViewDummy (rcBasicInfoViewDummy.left,rcBasicInfoViewDummy.top);

	pControl->SetGlobalPos ( vLeftTopGroupDummy );
	m_pBasicInfoView->SetGlobalPos( vBasicInfoViewDummy );
}

//************************************
// Method:    IsOpenWindowToMoveBlock
// FullName:  CInnerInterface::IsOpenWindowToMoveBlock
// Access:    public 
// Returns:   BOOL
// Qualifier: 
//************************************
BOOL CInnerInterface::IsOpenWindowToMoveBlock()
{
	// ���⿡ �߰��Ǵ� ��Ʈ���� �ݵ��� InitDeviceObjects���� ������ SetVisibleSingle( FALSE )�� ����� �Ѵ�.
	if( IsVisibleGroup( TRADE_WINDOW ) || 
		IsVisibleGroup( TRADEINVENTORY_WINDOW ) || 
		IsVisibleGroup( MARKET_WINDOW ) || 
		IsVisibleGroup( STORAGE_WINDOW ) || 
		//IsVisibleGroup( ITEMBANK_WINDOW ) || 
		IsVisibleGroup( MAP_REQUIRE_CHECK ) ||
		IsVisibleGroup( REBIRTH_DIALOGUE ) ||
		IsVisibleGroup( REBIRTH_FORCE ) ||
		IsVisibleGroup( DIALOGUE_WINDOW ) || 
		IsVisibleGroup( CLUB_STORAGE_WINDOW ) || 
		IsVisibleGroup( PRIVATE_MARKET_MAKE ) || 
		IsVisibleGroup( GAMBLE_DIALOGUE ) || 
		IsVisibleGroup( GAMBLE_SELECT_DIALOGUE ) || 
		IsVisibleGroup( GAMBLE_AGAIN_DIALOGUE ) ||
		IsVisibleGroup( GAMBLE_ANIMATION_DIALOGUE ) || 
		IsVisibleGroup( GAMBLE_RESULT_EVEN_DIALOGUE ) ||
		IsVisibleGroup( GAMBLE_RESULT_ODD_DIALOGUE ) ||
		IsVisibleGroup( ITEM_REBUILD_WINDOW ) || 
		IsVisibleGroup( REBUILDINVENTORY_WINDOW ) ||	// ITEMREBUILD_MARK
		IsVisibleGroup( ITEM_GARBAGE_WINDOW ) || 
		IsVisibleGroup( GARBAGEINVENTORY_WINDOW ) ||	// ������
		IsVisibleGroup( ITEMSHOP_WINDOW ) ||
		IsVisibleGroup( ITEM_SHOP_SEARCH_WINDOW ) ||
		IsVisibleGroup( ITEM_SEARCH_RESULT_WINDOW ) || // ������ �˻� â
		IsVisibleGroup( PETSKIN_MIX_IMAGE_WINDOW ) ||
		IsVisibleGroup( ITEM_MIX_WINDOW ) ||
		IsVisibleGroup( ITEM_MIX_INVEN_WINDOW ) )

	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
#ifdef CH_PARAM // �߱� �������̽� ����
void CInnerInterface::UpdatePotionTrayPosition()
{
	m_pUILeftTopGroup->SetGlobalPos( m_pBasicPotionTrayDummy->GetGlobalPos() );
	m_pQuestAlarm->SetGlobalPos( m_pQuestAlarmDummy->GetGlobalPos() );

	BOOL bVisibleQuest = IsVisibleGroup( QUEST_ALARM);
	BOOL bVisibleMini = IsVisibleGroup( MINIPARTY_OPEN );

	if( bVisibleQuest && bVisibleMini ) return;

	UIRECT rcDummy = m_pUILeftTopGroup->GetGlobalPos();
	rcDummy.left += 41; // ����Ʈ, �̴���Ƽ ��ư�� ���� ũ�Ⱑ 41
	rcDummy.right = rcDummy.left + rcDummy.sizeX;
	m_pUILeftTopGroup->SetGlobalPos( rcDummy );

	CUIControl * pUIControl(NULL);

	if( !bVisibleQuest && !bVisibleMini )
	{
		pUIControl = m_pUILeftTopGroup;
	}
	else if( !bVisibleMini )
	{
		pUIControl = m_pQuestAlarm;
	}

	if( pUIControl != NULL )
	{
		rcDummy = pUIControl->GetGlobalPos();
		rcDummy.left += 41;
		rcDummy.right = rcDummy.left + rcDummy.sizeX;
		pUIControl->SetGlobalPos( rcDummy );
	}
}
#endif
*/
void CInnerInterface::SetArmSwap( BOOL bSwap )
{
	m_pCharacterWindow->SetArmSwapTabButton( bSwap );
}

bool CInnerInterface::ItemShopAuth ()
{

//	ItemShopAuth
#if defined ( JP_PARAM ) //|| defined ( KR_PARAM ) || defined ( KRT_PARAM )
	if ( m_bItemShopLoad )	return false;

	GLCharacter* pChar = GLGaeaClient::GetInstance().GetCharacter();
	if ( !pChar ) return false;

	CString strData = "";
	strData.Format( "%s?id=%s& uuid=%s", RANPARAM::ItemShopAddress, pChar->m_szUID, RANPARAM::GETJAPANUUID() );

	CCommonWeb::Get()->Navigate( CCommonWeb::ITEMSHOP_ID, strData, true );
	CCommonWeb::Get()->ReSetCompleteLoad( CCommonWeb::ITEMSHOP_ID );

	m_bItemShopLoad = true;

	// �ε� �Ϸ� �޼����� �ö����� ��ٸ���.
	return false;
#endif	
	return true;
}

void CInnerInterface::ItemShopVisible()
{

//	ItemShopAuths
#if defined ( JP_PARAM ) || defined ( KR_PARAM ) || defined ( KRT_PARAM )
	if ( m_bItemShopLoad )
	{
		if ( CCommonWeb::Get()->IsCompleteLoad( CCommonWeb::ITEMSHOP_ID ) )
		{
			ShowGroupFocus ( ITEMSHOP_WINDOW );			
			HideGroup ( HELP_WINDOW );
			m_bItemShopLoad = false;
		}
	}
#endif
	return;
}

void CInnerInterface::SetItemMixResult( CString strMsg, bool bSuccess, bool bFail )
{
	m_pItemMixWindow->SetItemMixResult( strMsg, bSuccess, bFail );
}

void CInnerInterface::SET_GATHER_GAUGE( DWORD dwGaeaID, float fTime )
{
	m_pGatherGauge->SetTime( fTime );
	m_pGatherGauge->SetMaterial ( dwGaeaID );
}

void CInnerInterface::VisibleCDMRanking( bool bVisible )
{
	if ( bVisible )
	{
		HideGroup( QUEST_HELPER_DISPLAY );
		ShowGroupBottom ( CDM_RANKING_DISPLAY );
	}
	else
	{
		HideGroup( CDM_RANKING_DISPLAY );
		ShowGroupBottom ( QUEST_HELPER_DISPLAY );
	}
}

void CInnerInterface::RefreashCDMRanking()
{
	if ( m_pCdmRankingDisplay && m_pCdmRankingDisplay->IsVisible() )
		m_pCdmRankingDisplay->RefreashCdmRanking();
}

void CInnerInterface::VisibleCTFRanking( bool bVisible )
{
	if ( bVisible )
	{
		ShowGroupFocus ( TOWER_RANKING_DISPLAY );
	}
	else
	{
		HideGroup( TOWER_RANKING_DISPLAY );
	}
}

void CInnerInterface::VisibleCtfInfoDisplay( bool bVisible )
{
	if ( bVisible && !IsVisibleGroup ( INFO_CTF_DISPLAY ) )
	{
		ShowGroupFocus ( INFO_CTF_DISPLAY );
	}
	else if( !bVisible && IsVisibleGroup ( INFO_CTF_DISPLAY ) )
	{
		HideGroup( INFO_CTF_DISPLAY );
	}
}
void CInnerInterface::RefreshCTFRanking()
{
	if ( m_pCtfRankingDisplay && m_pCtfRankingDisplay->IsVisible() )
		m_pCtfRankingDisplay->RefreshSwPRanking();
}

void CInnerInterface::RefreshCtfIcon( bool bEmpty )
{
	if ( m_pCtfInfoDisplay ){
		if( bEmpty )	
			m_pCtfInfoDisplay->ResetIcon();
		else
			m_pCtfInfoDisplay->UpdateIcon();
	}
}

void CInnerInterface::OpenCharacterPage()
{
	if ( !m_pCharacterWindow )	return;
	if ( GLTradeClient::GetInstance().Valid() ) return;

	if ( m_pCharacterWindow->IsVisible() && m_pCharacterWindow->GetActivePage() != CHARPAGE_CHARACTER )
	{
		m_pCharacterWindow->OpenPage( CHARPAGE_CHARACTER );
	}
	else if ( m_pCharacterWindow->IsVisible() && m_pCharacterWindow->GetActivePage() == CHARPAGE_CHARACTER ) 
	{
		CInnerInterface::GetInstance().HideGroup ( CHARACTER_WINDOW );
	}
	else
	{
		CInnerInterface::GetInstance().ShowGroupFocus( CHARACTER_WINDOW );
		m_pCharacterWindow->OpenPage( CHARPAGE_CHARACTER );
	}
}

void CInnerInterface::OpenVehiclePage()
{
	if ( !m_pCharacterWindow )	return;
	if ( GLTradeClient::GetInstance().Valid() ) return;

	if ( m_pCharacterWindow->IsVisible() && m_pCharacterWindow->GetActivePage() != CHARPAGE_VEHICLE ) {
		m_pCharacterWindow->OpenPage( CHARPAGE_VEHICLE );
	}else if ( m_pCharacterWindow->IsVisible() && m_pCharacterWindow->GetActivePage() == CHARPAGE_VEHICLE )	{
		CInnerInterface::GetInstance().HideGroup ( CHARACTER_WINDOW );
	}else{
		CInnerInterface::GetInstance().ShowGroupFocus( CHARACTER_WINDOW );
		m_pCharacterWindow->OpenPage( CHARPAGE_VEHICLE );
	}
}

void CInnerInterface::RefreshVehiclePage()
{
	if ( !m_pCharacterWindow )	return;
	m_pCharacterWindow->RefreshVehiclePage();
}
void CInnerInterface::UpdateSchoolWarNextBattle( float fProgress, float fNextBattleStart, float fNextBattleEnd, float fPreviousBattleStart, float fPreviousBattleEnd )
{
	if ( m_pPvpWindowDisplay )
	{
		m_pPvpWindowDisplay->SetProgressTime(fProgress);
		m_pPvpWindowDisplay->SetNextBattleTime(fNextBattleStart,fNextBattleEnd);
		m_pPvpWindowDisplay->SetBattleRecord(fPreviousBattleStart,fPreviousBattleEnd);
	}
}

bool CInnerInterface::PreviewCheckSimple( SNATIVEID sID )
{
	SITEM* pItem = GLItemMan::GetInstance().GetItem( sID );
	if ( !pItem )	return false;

	if ( pItem->sBasicOp.emItemType == ITEM_SUIT )
	{
		return PreviewCheckWear( sID );
	}
	else if ( pItem->sBasicOp.emItemType == ITEM_BOX )
	{
		for ( int i=0; i<ITEM::SBOX::ITEM_SIZE; ++i )
		{
			SNATIVEID sNativeID = pItem->sBox.sITEMS[i].nidITEM;
			SITEM* pItemBox = GLItemMan::GetInstance().GetItem( sNativeID );
			if( pItemBox )
			{
				bool bCan = PreviewCheckWear( sNativeID );
				if ( bCan )	return true;
			}
		}
	}

	return false;
}

bool CInnerInterface::PreviewCheckWear( SNATIVEID sID )
{
	SITEM* pItem = GLItemMan::GetInstance().GetItem( sID );
	if ( !pItem )	return false;

	EMCHARCLASS	emClass = GLGaeaClient::GetInstance().GetCharacter()->m_emClass;
	WORD wSchool = GLGaeaClient::GetInstance().GetCharacter()->m_wSchool;
	EMCHARINDEX emIndex = CharClassToIndex( emClass );

	if ( !(pItem->sBasicOp.dwReqCharClass&emClass) )			return false;
	if ( !(pItem->sBasicOp.dwReqSchool&index2school(wSchool)) ) return false;

	if ( pItem->sBasicOp.emItemType == ITEM_SUIT )
	{
		if ( pItem->sSuitOp.emSuit > SUIT_HANDHELD )	return false;

		std::string strWearFile = pItem->GetWearingFile( emIndex );

		EMCHARCLASS emSex = CharClassGetSex( emIndex );
		EMCPSINDEX	emLeft = CPSIND_NULL;
		EMCPSINDEX	emRight = CPSIND_NULL;

		if ( emSex == GLCC_MAN )
		{
			emLeft = CPSIND_M_LEFT;
			emRight = CPSIND_M_RIGHT;
		}else{
			emLeft = CPSIND_W_LEFT;
			emRight = CPSIND_W_RIGHT;
		}

		std::string strR = pItem->GetCpsFile(emRight);
		std::string strL = pItem->GetCpsFile(emLeft);

		if ( strWearFile.size() > 0 || strR.size() > 0 || strL.size() > 0 )	return true;
	}

	return false;
}

void CInnerInterface::PreviewItem( SITEMCUSTOM sItem )
{
	if ( !PreviewCheckSimple( sItem.sNativeID ) )	return;
	if ( !m_pItemPreviewWindow )	return;

	m_pItemPreviewWindow ->StartPreview( sItem );

	ShowGroupFocus( ITEMPREVIEW_WINDOW );
}

void CInnerInterface::ADDITEM_RENDER ( SNATIVEID sICONINDEX, const char* szTexture, SITEMCUSTOM sCustom ) 
{ 
    if ( m_bITEM_INFO_EX_DISPLAY_MODE ){ 
        m_pInfoDisplayEx->SetItemRender ( sICONINDEX, szTexture, sCustom );
    }
	else if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	{ 
        m_pInfoDisplayLink->SetItemRender ( sICONINDEX, szTexture, sCustom );
    }else{ 
        m_pInfoDisplay->SetItemRender ( sICONINDEX, szTexture, sCustom );
    } 
} 
void CInnerInterface::RESETITEM_RENDER(SITEMCUSTOM sCustom) 
{ 
    if ( m_bITEM_INFO_EX_DISPLAY_MODE ){ 
        m_pInfoDisplayEx->ResetItemRender (sCustom); 
    }
	else if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	{ 
        m_pInfoDisplayLink->ResetItemRender (sCustom); 
    }else{ 
        m_pInfoDisplay->ResetItemRender (sCustom); 
    } 
}
void CInnerInterface::SETRESIICON ()
{
	if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	{
		m_pInfoDisplayLink->SetResiIcon();
	}
	else if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	{
		m_pInfoDisplayEx->SetResiIcon();
	}
	else
	{
		m_pInfoDisplay->SetResiIcon();
	}
}

void CInnerInterface::RESETRESIICON ()
{
	if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	{
		m_pInfoDisplayLink->HideResiIcon ();
	}
	else if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	{
		m_pInfoDisplayEx->HideResiIcon ();
	}
	else
	{
		m_pInfoDisplay->HideResiIcon ();
	}
}

int CInnerInterface::ADDTEXT( const CString& strText, const D3DCOLOR& dwColor )
{
	if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	{
		if ( m_pInfoDisplayLink ) return m_pInfoDisplayLink->AddText ( strText, dwColor );
	}
	else if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	{
		if ( m_pInfoDisplayEx ) return m_pInfoDisplayEx->AddText ( strText, dwColor );
	}
	else
	{
		if ( m_pInfoDisplay ) return m_pInfoDisplay->AddText ( strText, dwColor );
	}
	//return -1;
}

void CInnerInterface::ADDSTRING ( int nIndex, const CString& strText, const D3DCOLOR& dwColor )
{
	if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	{
		m_pInfoDisplayLink->RePosControl(0,0);
		m_pInfoDisplayLink->AddString ( nIndex, strText, dwColor );
		m_pInfoDisplayLink->RePosControl(0,0);
	}
	else if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	{
		m_pInfoDisplayEx->RePosControl(0,0);
		m_pInfoDisplayEx->AddString ( nIndex, strText, dwColor );
		m_pInfoDisplayEx->RePosControl(0,0);
	}
	else
	{
		m_pInfoDisplay->RePosControl(0,0);
		m_pInfoDisplay->AddString ( nIndex, strText, dwColor );
		m_pInfoDisplay->RePosControl(0,0);
	}
}

void CInnerInterface::ADDITEMBOX_RENDER( SNATIVEID sICONINDEX, const char* szTexture, int nIndex )
{
	  if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	  { 
        m_pInfoDisplayEx->SetItemBoxRender ( sICONINDEX, szTexture, nIndex );
	  }
	   else if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	  {
		m_pInfoDisplayLink->SetItemBoxRender ( sICONINDEX, szTexture, nIndex );
	  }
	  else
	  {
		m_pInfoDisplay->SetItemBoxRender ( sICONINDEX, szTexture, nIndex );
	  }
}

void CInnerInterface::RESETITEMBOX_RENDER()
{
	 if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	  {
		m_pInfoDisplayEx->ResetItemBoxRender ();
	  }
	   else if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	  {
		m_pInfoDisplayLink->ResetItemBoxRender ();
	  }
	 else
	  {
		m_pInfoDisplay->ResetItemBoxRender ();
	  }
}

void CInnerInterface::ADDNAME_RENDER( const CString& strText, const D3DCOLOR& dwColor )
{
	if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	  {
		m_pInfoDisplayEx->AddTextNoSplitBig ( strText, dwColor );
	  }
	   else if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	  {
		m_pInfoDisplayLink->AddTextNoSplitBig ( strText, dwColor );
	  }
	 else
	 {
		m_pInfoDisplay->AddTextNoSplitBig ( strText, dwColor );
	 }
}

int CInnerInterface::ADDTEXT_NOSPLIT_BIG( const CString& strText, const D3DCOLOR& dwColor )
{
	 if ( m_bITEM_INFO_EX_DISPLAY_MODE )
	  {
		m_pInfoDisplayEx->AddTextNoSplitBig ( strText, dwColor );
	  }
	 else if ( m_bITEM_INFO_LINK_DISPLAY_MODE )
	  {
		m_pInfoDisplayLink->AddTextNoSplitBig ( strText, dwColor );
	  }
	 else
	 {
		m_pInfoDisplay->AddTextNoSplitBig ( strText, dwColor );
	 }
	 return -1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Box Item Image Render by NjD
void CInnerInterface::ADDNAME_RENDER_BOXINFO ( const CString& strText, const D3DCOLOR& dwColor )
{
	m_pBoxInfo->AddTextNoSplitBig ( strText, dwColor );
}
void CInnerInterface::ADDITEM_RENDER_BOXINFO ( SNATIVEID sICONINDEX, const char* szTexture )
{
	m_pBoxInfo->SetItemRender ( sICONINDEX, szTexture );
}
void CInnerInterface::RESETITEM_RENDER_BOXINFO ()
{
	m_pBoxInfo->ResetItemRender ();
}
void CInnerInterface::ADDITEMBOX_RENDER_BOXINFO ( SNATIVEID sICONINDEX, const char* szTexture, int nIndex )
{
	m_pBoxInfo->SetItemBoxRender ( sICONINDEX, szTexture, nIndex );
}
void CInnerInterface::RESETITEMBOX_RENDER_BOXINFO ()
{
	m_pBoxInfo->ResetItemBoxRender ();
}
void CInnerInterface::SETRESIICON_BOXINFO ()
{
	m_pBoxInfo->SetResiIcon();
}
void CInnerInterface::RESETRESIICON_BOXINFO ()
{
	m_pBoxInfo->HideResiIcon ();
}
void CInnerInterface::ADDITEMBOXRANDOM_RENDER_BOXINFO ( SNATIVEID sICONINDEX, const char* szTexture, int nIndex )
{
	m_pBoxInfo->SetItemBoxRandomRender ( sICONINDEX, szTexture, nIndex );
}
void CInnerInterface::RESETITEMBOXRANDOM_RENDER_BOXINFO ()
{
	m_pBoxInfo->ResetItemBoxRandomRender ();
}
void CInnerInterface::ADDTEXT_LONGESTLINE_SPLIT_BOXINFO ( const CString& strText, const D3DCOLOR& dwColor )
{
	m_pBoxInfo->AddTextLongestLineSplit ( strText, dwColor );
}
void CInnerInterface::ADDTEXT_NOSPLIT_BOXINFO ( const CString& strText, const D3DCOLOR& dwColor )
{
	m_pBoxInfo->AddTextNoSplit ( strText, dwColor );
}
//End of Box Item Image Render by NjD
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CInnerInterface::ADDTEXT_MULTICOLOR_SPLIT (int nIndex, const CString& strText, const D3DCOLOR& dwColor )
{
	{
		int nIndex = m_pInfoDisplay->AddText ( strText, NS_UITEXTCOLOR::PRIVATE );
		m_pInfoDisplay->AddString ( nIndex, strText, dwColor );
	}
}
//add school wars
void CInnerInterface::VisibleSWRanking( bool bVisible )
{
	if ( bVisible )
	{
		HideGroup( QUEST_HELPER_DISPLAY );
		ShowGroupBottom ( SW_RANKING_DISPLAY );
	}
	else
	{
		HideGroup( SW_RANKING_DISPLAY );
		ShowGroupBottom ( QUEST_HELPER_DISPLAY );
	}
}

void CInnerInterface::VisibleSWPRanking( bool bVisible )
{
	if ( bVisible )
	{
		HideGroup( QUEST_HELPER_DISPLAY );
		ShowGroupBottom ( SWP_RANKING_DISPLAY );
	}
	else
	{
		HideGroup( SWP_RANKING_DISPLAY );
		ShowGroupBottom ( QUEST_HELPER_DISPLAY );
	}
}

void CInnerInterface::RefreshSWRanking()
{
	//if ( m_pSwRankingDisplay && m_pSwRankingDisplay->IsVisible() )
}

void CInnerInterface::RefreshSWPRanking()
{
	if ( m_pSwPRankingDisplay && m_pSwPRankingDisplay->IsVisible() )
		m_pSwPRankingDisplay->RefreshSwPRanking();
}
void CInnerInterface::VisibleRRPRanking( bool bVisible )
{
	if ( bVisible )
	{
		HideGroup( QUEST_HELPER_DISPLAY );
		ShowGroupBottom ( RRP_RANKING_DISPLAY );
	}
	else
	{
		HideGroup( RRP_RANKING_DISPLAY );
		ShowGroupBottom ( QUEST_HELPER_DISPLAY );
	}
}

void CInnerInterface::RefreshRRPRanking()
{
	if ( m_pRrPRankingDisplay && m_pRrPRankingDisplay->IsVisible() )
		m_pRrPRankingDisplay->RefreshRrPRanking();
}
void CInnerInterface::LinkItem( SITEMCUSTOM* pItem )
{
	if ( GetChat() && pItem )
	{
		GetChat()->AddItemLink( pItem );
	}
}

void CInnerInterface::LinkItemGlobalGrind( SITEMCUSTOM* pItem )
{
	if ( GetChat() && pItem )
	{
		GetChat()->AddItemLinkGlobalGrind( pItem );
	}
}