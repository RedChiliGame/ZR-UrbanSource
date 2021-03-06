#pragma	once

#include "UIWindowEx.h"
#include "GLFriendClient.h"

class	CBasicTextBoxEx;
class	CBasicScrollBarEx;
class	CBasicTextButton;
class	CUIEditBox;
class	CBasicButtonText;

class	CFriendWindowNormalPage : public CUIGroup
{
private:
static	const int nLIMIT_CHAR;

private:
	enum
	{
		FRIEND_LIST_TEXTBOX = NO_ID + 1,
		FRIEND_LIST_SCROLLBAR,
		FRIEND_LIST_ADDBUTTON,
		FRIEND_LIST_DELBUTTON,
		FRIEND_LIST_BLOCKBUTTON,
		FRIEND_LIST_MOVEBUTTON,
		FRIEND_LIST_PARTYBUTTON,	//added by : tobets | 08-03-2012 | add party button in friend window
		//FRIEND_LIST_NOTEBUTTON,
		FRIEND_EDITBOX
	};

	enum
	{
		ONLINE = 0,
		OFFLINE
	};

public:
	CFriendWindowNormalPage ();
	virtual ~CFriendWindowNormalPage ();

public:
	void	CreateSubControl ();
	CBasicTextButton*	CreateTextButton24 ( const char* szButton, UIGUID ControlID, const char* szText );
	CBasicButtonText*	CreateButtonBlue ( char* szButton, char* szTextBox, CD3DFontPar* pFont, int nAlign, UIGUID ControlID, CString strText );

public:
	//added by : tobets | 20-03-2012 | added party for friend window
	DWORD	GetFriendID() { return m_nCharID; }
	BOOL IsSelectedIndex();
	void	LoadFriendList ();
	void	EDIT_END ();
	void	EDIT_BEGIN ( const CString& strName = "" );

public:
	void	ADD_FRIEND ( const CString& strName );
	void	DEL_FRIEND ( const CString& strName );
	void	ADD_BLOCK ( const CString& strName );
	void	MOVETO_FRIEND ( const CString& strName );
	void	PARTY_FRIEND ( const CString& strName );	//added by : tobets | 08-03-2012 | add party button in friend window
	const CString& GET_FRIEND_NAME () const						{ return m_strSelectName; }
	CString		GetNameSelected(){ return m_strSelectName.GetString(); }

private:
	BOOL	GetFriend ( const int nCharID, CString & strName );

public:
	void	ADD_FRIEND_NAME_TO_EDITBOX ( const CString& strName );

public:
	virtual	void SetVisibleSingle ( BOOL bVisible );

public:
	virtual HRESULT InitDeviceObjects ( LPDIRECT3DDEVICEQ pd3dDevice );
	virtual	void	Update ( int x, int y, BYTE LB, BYTE MB, BYTE RB, int nScroll, float fElapsedTime, BOOL bFirstControl );
	virtual	void	TranslateUIMessage ( UIGUID cID, DWORD dwMsg );

private:
	void	LoadFriend ( const SFRIEND& sFriend );

private:
	int		m_nSelectIndex;
	CString	m_strSelectName;

private:
	CBasicTextBoxEx*	m_pListText;
	CBasicScrollBarEx*	m_pListScrollBar;

	CBasicButtonText*	m_pADD;
	CBasicButtonText*	m_pDEL;
	CBasicButtonText*	m_pBLOCK;
	CBasicButtonText*	m_pMOVE;
	CBasicButtonText*	m_pPARTY;	//added by : tobets | 08-03-2012 | add party button in friend window
	DWORD				m_nCharID;
	//CBasicTextButton*	m_pNote;

	CUIEditBox*			m_pEditBox;

	BOOL				m_bINIT;

	SFRIEND				m_sFriend;

protected:
	BOOL SetFriendInfo( const int nCharID );

public:
	SFRIEND & GetFriendInfo() { return m_sFriend; }
};
