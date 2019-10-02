#include "StdAfx.h"
#include "ItemImage.h"
#include "GLGaeaClient.h"
#include "GLItemMan.h"
#include "SkillFunc.h"
#include "../EngineUILib/GUInterface/BasicProgressBar.h"
#include "d3dfont.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//	����¡ �÷�
const DWORD	RECHARGECOLOR = D3DCOLOR_ARGB(150,0,0,0);

CItemImage::CItemImage () 
	: m_pItemImage ( NULL )
	, m_pItemImageUnUse ( NULL )
	, m_pd3dDevice ( NULL )
	, m_sICONINDEX ( NATIVEID_NULL () )
	, m_TotElapsedTime(0.0f)
	, m_bItemUsed(false)
	, m_bItemEnd(false)
	, m_bTwinkle(true)
	, m_pItemProcess( NULL )
	, m_sNativeID(false)
	, m_pTextBox(NULL)
{
}

CItemImage::~CItemImage ()
{
}

HRESULT CItemImage::InitDeviceObjects ( LPDIRECT3DDEVICEQ pd3dDevice )
{
	HRESULT hr = S_OK;
	hr = CUIGroup::InitDeviceObjects ( pd3dDevice );
	if ( FAILED ( hr ) ) return hr;

	m_pd3dDevice = pd3dDevice;

	return S_OK;
}

void	CItemImage::CreateSubControl ()
{
	CD3DFontPar* pFont8 = DxFontMan::GetInstance().LoadDxFont ( _DEFAULT_FONT, 9, TRUE, D3DFONT_SHADOW | D3DFONT_ASCII );

	m_pItemImage = new CUIControl;
	m_pItemImage->CreateSub ( this, "ITEM_IMAGE" );	
	m_pItemImage->SetUseRender ( TRUE );
	m_pItemImage->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pItemImage );

	m_pItemImageUnUse = new CUIControl;
	m_pItemImageUnUse->CreateSub ( this, "ITEM_IMAGE_UNUSE" );	
	m_pItemImageUnUse->SetUseRender ( TRUE );
	m_pItemImageUnUse->SetVisibleSingle ( FALSE );
	RegisterControl ( m_pItemImageUnUse );

	CBasicProgressBar* pItemProcess = new CBasicProgressBar;
	pItemProcess->CreateSub ( this, "ITEM_IMAGE_PROGRESS" );
	pItemProcess->CreateOverImage ( "ITEM_IMAGE_PROGRESS_OVER" );
	pItemProcess->SetType ( CBasicProgressBar::VERTICAL );
	pItemProcess->SetOverImageUseRender ( TRUE );
	pItemProcess->SetOverImageDiffuse ( RECHARGECOLOR );
	pItemProcess->SetControlNameEx ( "���α׷�����" );	
	RegisterControl ( pItemProcess );
	m_pItemProcess = pItemProcess;

	m_pTextBox = new CBasicTextBox;
	m_pTextBox->CreateSub ( this, "ITEM_NUMBER0" );
	m_pTextBox->SetFont ( pFont8 );
	m_pTextBox->SetTextAlign ( TEXT_ALIGN_RIGHT );
	RegisterControl ( m_pTextBox );

}

void CItemImage::Update( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl )
{
	CUIGroup::Update ( x, y, LB, MB, RB, nScroll, fElapsedTime, bFirstControl );

	if( m_bItemUsed && m_bItemEnd )
	{
		m_TotElapsedTime += fElapsedTime;

		if( m_TotElapsedTime < 0.3f )		m_pItemProcess->SetPercent(0);
		else if( m_TotElapsedTime < 0.6f )	m_pItemProcess->SetPercent(1);
		else if( m_TotElapsedTime < 0.9f )	m_pItemProcess->SetPercent(0);
		else if( m_TotElapsedTime < 1.2f )	m_pItemProcess->SetPercent(1);
		else
		{
			m_pItemProcess->SetPercent(0);
			m_TotElapsedTime = 0.0f;
			m_bItemEnd = false;
			m_bItemUsed = false;
		}
	}

	//	��Ÿ�� ǥ��
    if ( !m_pItemProcess )
	{
		GASSERT ( 0 && "���α׷����ٰ� ��������� �ʾҽ��ϴ�." );
		return ;
	}

	SITEM* pItem = GLItemMan::GetInstance().GetItem( m_sNativeID );
	if ( !pItem )	return ;

	if ( !GLGaeaClient::GetInstance().GetCharacter()->IsCoolTime( m_sNativeID ) )
	{
		m_bItemEnd = true;
		return;
	}	

	ITEM_COOLTIME* pItemCoolTime = GLGaeaClient::GetInstance().GetCharacter()->GetCoolTime( m_sNativeID );
	if ( !pItemCoolTime )
	{
		m_bItemEnd = true;
		return;
	}

	m_bItemEnd = false;

	__time64_t tCurTime = GLGaeaClient::GetInstance().GetCurrentTime().GetTime();
	__time64_t tUseTime = pItemCoolTime->tUseTime;
	__time64_t tCoolTime = pItemCoolTime->tCoolTime;

	float fCoolTime = tCoolTime - tUseTime;
	float fCurTime = fCoolTime - ( tCurTime - tUseTime );
	
	if ( fCoolTime == 0.0f )
	{
		fCoolTime = 1.0f;
	}

	const float fPercent = fCurTime / fCoolTime;
	m_pItemProcess->SetPercent ( fPercent );
	m_bItemUsed = true;
}

void CItemImage::SetItem ( SNATIVEID sICONINDEX, const char* szTexture, SNATIVEID sNativeID )
{	
	if ( !m_pItemImage )	return;

	//	NOTE
	//		���� �����Ӱ� ������ ID�� ����,
	//		�ؽ��İ� �����ϴٸ� ���� �̹��� �̹Ƿ�,
	//		�� �̻� �۾��� ������ �ʿ䰡 ����.

	if( m_sNativeID == sNativeID && sNativeID != NATIVEID_NULL() )	return;

	if ( (sICONINDEX == m_sICONINDEX) && (szTexture == m_pItemImage->GetTextureName ()) )	return ;


	ResetItem ();
	SetItemProcess( sNativeID );

	if ( m_pItemImage )
	{
		m_pItemImage->SetTexturePos ( NS_SKILL::GetIconTexurePos ( sICONINDEX ) );
		m_pItemImage->SetTextureName ( szTexture );	

		if ( m_pd3dDevice )
		{	
			m_pItemImage->InitDeviceObjects ( m_pd3dDevice );
			m_pItemImage->SetVisibleSingle ( TRUE );

			m_sICONINDEX = sICONINDEX;
			m_strTextureName = szTexture;
		}
	}
}
void CItemImage::SetItem2 ( SNATIVEID sICONINDEX, const char* szTexture, int nGrind, SNATIVEID sNativeID /*= false*/ )//Added by Cle Art Palconit - Item image with ups
{	
	if ( !m_pItemImage )	return;

	//	NOTE
	//		���� �����Ӱ� ������ ID�� ����,
	//		�ؽ��İ� �����ϴٸ� ���� �̹��� �̹Ƿ�,
	//		�� �̻� �۾��� ������ �ʿ䰡 ����.

	if( m_sNativeID == sNativeID && sNativeID != NATIVEID_NULL() )	return;

	if ( (sICONINDEX == m_sICONINDEX) && (szTexture == m_pItemImage->GetTextureName ()) )	return ;


	ResetItem ();
	SetItemProcess( sNativeID );

	if ( m_pItemImage )
	{
		m_pItemImage->SetTexturePos ( NS_SKILL::GetIconTexurePos ( sICONINDEX ) );
		m_pItemImage->SetTextureName ( szTexture );	

		if ( m_pd3dDevice )
		{	
			m_pItemImage->InitDeviceObjects ( m_pd3dDevice );
			m_pItemImage->SetVisibleSingle ( TRUE );

			m_sICONINDEX = sICONINDEX;
			m_strTextureName = szTexture;
		}
	}

	if ( m_pTextBox && nGrind > 0 )
	{
		//FIXME
		//change text color to upgrade color
		CString strGrind;
		strGrind.Format( "+%d", nGrind );
		m_pTextBox->AddText( strGrind.GetString() );
	}
}

SNATIVEID	 CItemImage::GetItem ()
{
	return m_sICONINDEX;
}

void CItemImage::ResetItem ()
{
	/*if ( m_pItemImage )
	{
		//if ( m_sICONINDEX != NATIVEID_NULL () )
		//{
			m_pItemImage->DeleteDeviceObjects ();
			m_pItemImage->SetTextureName ( NULL );
			m_pItemImage->SetVisibleSingle ( FALSE );
			m_pItemImageUnUse->SetVisibleSingle ( FALSE );
			m_sICONINDEX = NATIVEID_NULL ();
			ReSetItemProcess();
			m_strTextureName.Empty ();
		//}		
	}*/
	if ( m_pItemImage )
	{
		if ( m_sICONINDEX != NATIVEID_NULL () )
		{
			m_pItemImage->DeleteDeviceObjects ();
			m_pItemImage->SetTextureName ( NULL );
			m_pItemImage->SetVisibleSingle ( FALSE );

			m_sICONINDEX = NATIVEID_NULL ();

			ReSetItemProcess();

			m_strTextureName.Empty ();
		}		
	}

	if ( m_pTextBox )
	{
		m_pTextBox->ClearText();
	}
}
void CItemImage::SetUse()
{
	if ( m_pItemImage )
	{
		if ( m_sICONINDEX != NATIVEID_NULL () )
		{
			BOOL IsUse = m_pItemImageUnUse->IsVisible();
			if ( IsUse )
			{
				m_pItemImageUnUse->SetVisibleSingle ( FALSE );
			}
		}		
	}
}
void CItemImage::SetUnUse()
{
	if ( m_pItemImage )
	{
		if ( m_sICONINDEX != NATIVEID_NULL () )
		{
			m_pItemImageUnUse->SetVisibleSingle ( TRUE );
			m_sICONINDEX = NATIVEID_NULL ();
		}		
	}
}

const CString&	CItemImage::GetItemTextureName () const
{
	return m_strTextureName;
}

void CItemImage::SetItemProcess( SNATIVEID sNativeID )
{
	m_bItemUsed = false;	
	m_sNativeID = sNativeID;

	if ( sNativeID == NATIVEID_NULL() )
	{
		m_pItemProcess->SetVisibleSingle( FALSE );
	}
	else
	{
		m_pItemProcess->SetVisibleSingle( TRUE );
	}

	return;
}

void CItemImage::ReSetItemProcess()
{
	m_bItemUsed = false;
	m_sNativeID = NATIVEID_NULL();
	m_pItemProcess->SetVisibleSingle( FALSE );
	m_pItemProcess->SetPercent( 0.0f );
	
	return;
}

void CItemImage::SetDiffuse(D3DCOLOR _diffuse)
{
	CUIGroup::SetDiffuse( _diffuse );

	m_pItemProcess->SetOverImageDiffuse ( RECHARGECOLOR );
}