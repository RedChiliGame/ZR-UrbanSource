#include "StdAfx.h"
#include ".\skilltraytab.h"
#include ".\skilltraytabNew.h"
#include "BasicQuickSkillSlot.h"
#include "BasicQuickSkillWindow.h"
#include "BasicQuickSkillWindowNew.h"
#include "d3dfont.h"
#include "../EngineUILib/GUInterface/BasicButton.h"
#include "GameTextControl.h"
#include "InnerInterface.h"
#include "../EngineUILib/GUInterface/UIKeyCheck.h"


CBasicQuickSkillWindow::CBasicQuickSkillWindow(void)
	: TabLock ( TRUE )
{
}

CBasicQuickSkillWindow::~CBasicQuickSkillWindow(void)
{
}

void CBasicQuickSkillWindow::CreateSubControl()
{
	m_pBasicQuickSkillSlot = new CBasicQuickSkillSlot;
	m_pBasicQuickSkillSlot->CreateSub ( this, "BASIC_QUICK_SKILL_SLOT" );
	m_pBasicQuickSkillSlot->CreateSubControl ();
	m_pBasicQuickSkillSlot->SetUseSkillImageTwinkle( false ); // ��ų ����� �����̴� �׼��� ������� �ʽ��ϴ�.
	RegisterControl ( m_pBasicQuickSkillSlot );

	CUIControl* pSlotEnd = new CUIControl;
	pSlotEnd->CreateSub ( this, "BASIC_QUICK_SKILL_TRAY_SLOT_END_CLOSE" );
	pSlotEnd->SetControlNameEx ( "���� ����" );
    RegisterControl ( pSlotEnd );

	CBasicButton * pButton = new CBasicButton;
	pButton->CreateSub( this, "QUICK_SKILL_TRAY_OPEN_BUTTON_CLOSE", UI_FLAG_DEFAULT, QUICK_SKILL_TRAY_OPEN_BUTTON_CLOSE );
	pButton->CreateFlip( "QUICK_SKILL_TRAY_OPEN_BUTTON_CLOSE_F", CBasicButton::MOUSEIN_FLIP );
	pButton->SetUseGlobalAction ( TRUE );	
	RegisterControl( pButton );

	pButtonLock = new CBasicButton;
	pButtonLock->CreateSub( this, "QUICK_SKILL_TRAY_LOCK_BUTTON_CLOSE", UI_FLAG_DEFAULT, QUICK_SKILL_TRAY_LOCK_BUTTON_CLOSE );
	pButtonLock->CreateFlip( "QUICK_SKILL_TRAY_LOCK_BUTTON_CLOSE_F", CBasicButton::MOUSEIN_FLIP );
	pButtonLock->SetUseGlobalAction ( TRUE );
	pButtonLock->SetVisibleSingle ( FALSE );
	RegisterControl ( pButtonLock );
	SetFoldGroup( pButtonLock, TABBUTTON_FOLDGROUP_ID );

	pButtonUnLock = new CBasicButton;
	pButtonUnLock->CreateSub( this, "QUICK_SKILL_TRAY_UNLOCK_BUTTON_CLOSE", UI_FLAG_DEFAULT, QUICK_SKILL_TRAY_UNLOCK_BUTTON_CLOSE );
	pButtonUnLock->CreateFlip( "QUICK_SKILL_TRAY_UNLOCK_BUTTON_CLOSE_F", CBasicButton::MOUSEIN_FLIP );
	pButtonUnLock->SetUseGlobalAction ( TRUE );
	pButtonUnLock->SetVisibleSingle ( TRUE );
	RegisterControl ( pButtonUnLock );
	SetFoldGroup( pButtonUnLock, TABBUTTON_FOLDGROUP_ID );
}

void CBasicQuickSkillWindow::CheckMouseState ()
{
	const DWORD dwMsg = GetMessageEx ();
	if ( CHECK_MOUSE_IN ( dwMsg ) )
	{	
		if( UIMSG_LB_DUP & dwMsg )
		{
			// �����츦 ����Ʈ ���������� �̵�
			AddMessageEx( UIMSG_BASIC_LBDUP_WINDOW );
			return ;
		}
		
		if ( dwMsg & UIMSG_LB_DOWN )
		{
			CInnerInterface::GetInstance().SkillTabClose = FALSE;

			//	�ܵ� ��Ʈ�ѷ� ����ϰ�,
			SetExclusiveControl();	

			//	���� ������ ���� ����Ѵ�.
			if ( !m_bFirstGap )
			{
				UIRECT rcPos = GetGlobalPos ();
				m_vGap.x = m_PosX - rcPos.left;
				m_vGap.y = m_PosY - rcPos.top;
				m_bFirstGap = TRUE;
			}
		}
		else if ( CHECK_LB_UP_LIKE ( dwMsg ) )
		{
			//	�ܵ� ��Ʈ���� �����ϰ�
			ResetExclusiveControl();
			//	���� �����ǰ��� �����Ѵ�.
			m_bFirstGap = FALSE;				
		}
	}
	//	��Ʈ�� �����ۿ��� ��ư�� ���� ��찡 �߻��ϴ���
	else if ( CHECK_LB_UP_LIKE ( dwMsg ) )		
	{								
		//	�ܵ� ��Ʈ���� �����ϰ�,
		ResetExclusiveControl();
		//	���� �����ǰ��� �����Ѵ�.
		m_bFirstGap = FALSE;					
	}
}
void CBasicQuickSkillWindow::Update( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl )
{
	if ( TabLock )
	{
		m_bCHECK_MOUSE_STATE = false;
	}
	m_PosX = x;
	m_PosY = y;

	CUIGroup::Update ( x, y, LB, MB, RB, nScroll, fElapsedTime, bFirstControl );

	if ( IsExclusiveSelfControl() )
	{
		SetGlobalPos ( D3DXVECTOR2 ( x - m_vGap.x, y - m_vGap.y ) );
	}
}
void CBasicQuickSkillWindow::TranslateUIMessage ( UIGUID ControlID, DWORD dwMsg )
{
	if ( !m_bCHECK_MOUSE_STATE )
	{
		CheckMouseState ();
		m_bCHECK_MOUSE_STATE = true;
	}

	switch ( ControlID )
	{
	case QUICK_SKILL_TRAY_OPEN_BUTTON_CLOSE:
		{
			if ( CHECK_MOUSE_IN ( dwMsg ) )
			{
				if ( CHECK_LB_UP_LIKE ( dwMsg ) )
				{					
					CInnerInterface::GetInstance().HideGroup ( GetWndID () );
					CInnerInterface::GetInstance().SkillTabOpen = TRUE;
					CInnerInterface::GetInstance().ShowGroupFocus ( QUICK_SKILL_TRAY_TAB_WINDOW, true );
				}
			}
		}
		break;
	case QUICK_SKILL_TRAY_LOCK_BUTTON_CLOSE:
	case QUICK_SKILL_TRAY_UNLOCK_BUTTON_CLOSE:
		{
			if ( CHECK_MOUSE_IN ( dwMsg ) )
			{
				if ( CHECK_LB_UP_LIKE( dwMsg ) )
				{
					if ( pButtonLock->IsVisible() )
					{
						pButtonLock->SetVisibleSingle ( FALSE );
						pButtonUnLock->SetVisibleSingle ( TRUE );
						CInnerInterface::GetInstance().GetSkillTrayTab()->SetUnlock();
						CInnerInterface::GetInstance().GetSkillTrayTabNew()->SetUnlock();
						CInnerInterface::GetInstance().GetBasicQuickSkillWindowNew()->SetUnlock();
						TabLock = TRUE;
					}else
					{
						pButtonLock->SetVisibleSingle ( TRUE );
						pButtonUnLock->SetVisibleSingle ( FALSE );
						CInnerInterface::GetInstance().GetSkillTrayTab()->SetLock();
						CInnerInterface::GetInstance().GetSkillTrayTabNew()->SetLock();
						CInnerInterface::GetInstance().GetBasicQuickSkillWindowNew()->SetLock();
						TabLock = FALSE;
					}
				}
			}
		}
		break;
	}
}
void CBasicQuickSkillWindow::SetLock()
{
	pButtonLock->SetVisibleSingle ( TRUE );
	pButtonUnLock->SetVisibleSingle ( FALSE );
	TabLock = FALSE;
}
void CBasicQuickSkillWindow::SetUnlock()
{
	pButtonLock->SetVisibleSingle ( FALSE );
	pButtonUnLock->SetVisibleSingle ( TRUE );
	TabLock = TRUE;
}