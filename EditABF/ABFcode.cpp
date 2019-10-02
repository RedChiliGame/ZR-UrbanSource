#include "stdafx.h"

#include "ABFcode.h"
#include "../G-Logic/GLogic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CAbfCode::CAbfCode(void):
	m_dwRef(0),

	m_bWorldObj(FALSE),
	m_fScale(1.0f),
	m_vMax(7.f,20.f,7.f),
	m_vMin(-7.f,0.f,-7.f),
	m_fHeight(20.f),
	m_fRadius(7.f),
	m_dwBONE(0)
{
	for ( DWORD n=0; n<MAX_BONE; ++n )
	{
		m_fBONE1[n] = 0.0f;
		m_fBONE2[n] = 0.0f;
		m_fBONE3[n] = 0.0f;
		m_strBONE[n] = "";
	}
}

CAbfCode::~CAbfCode(void)
{
}

BOOL CAbfCode::SaveFile ( const char* szFile )
{
	char szPathName[MAX_PATH] = "";
	StringCchCopy( szPathName, MAX_PATH, DxSkinPieceDataContainer::GetInstance().GetPath() );
	StringCchCat( szPathName, MAX_PATH, szFile );

	CSerialFile SFile;
	if ( !SFile.OpenFile ( FOT_WRITE, szPathName ) )		return FALSE;

	SFile << VERSION;

	SFile << PIECE_SIZE;
	for ( int i=0; i<PIECE_SIZE; ++i )
	{
		SFile << BOOL (!m_strPIECE[i].empty()); //bStatus;
		if ( m_strPIECE[i].empty() )	continue;

		//std::string strPieceFile = m_pPieceArray[i]->m_szFileName;
		SFile << m_strPIECE[i];
	}

	SFile << m_strSkeleton;

	//	Note :���ϸ��̼� ����.
	//
	SFile << (DWORD)m_vecANIFILE.size();
	for ( size_t n=0; n<m_vecANIFILE.size(); ++n )
	{
		std::string strNAME = m_vecANIFILE[n].c_str();
		SFile << strNAME;
	}

	SFile << m_fScale;

	// Note : �߰�.
	SFile << (BOOL)TRUE;
	SFile << m_fHeight;
	SFile << m_fRadius;

	SFile << m_dwBONE;

	if ( m_dwBONE > MAX_BONE ) return FALSE;

	for ( i=0; i < m_dwBONE ; ++i )
	{
		SFile << m_fBONE1[i];
		SFile << m_fBONE2[i];
		SFile << m_fBONE3[i];
		SFile << m_strBONE[i];
	}

	//	Note : ��� �ڽ� ���.
	//
	SFile << (BOOL) TRUE;
	//CalculateBoundingBox ( pd3dDevice, m_vMax, m_vMin );

	SFile << m_vMax;
	SFile << m_vMin;

	// Note : �߰�.
	SFile << (BOOL)TRUE;
	SFile << m_bWorldObj;

	//	Note : ����Ʈ�� �ٸ� �߰� ��ü�� �� ���� ����ؼ� ���� ����Ʈ�� ���� �Ǹ�
	//		TRUE ���� �����ϰ� �ȴ�.
	//
	SFile << (BOOL)FALSE;

	//	Note : ��Ų �ɸ��� �̸� ����.

	return TRUE;
}

BOOL CAbfCode::LOAD_Ver100 ( basestream &SFile )
{
	DWORD dwPieceSize;

	//SFile >> m_fScale;
	SFile >> dwPieceSize;
	if ( dwPieceSize > PIECE_SIZE )		return FALSE;

	//	Note : ������ �ε�.
	//
	BOOL bExit;
	for ( DWORD i=0; i<dwPieceSize; ++i )
	{
		SFile >> bExit;
		if ( !bExit )
		{
			m_strPIECE[i].clear();
			continue;
		}

		SFile >> m_strPIECE[i];
	}

	//	Note : ������ �б�.
	//
	SFile >> m_strSkeleton;

	//	Note :���ϸ��̼� �б�.
	//
	DWORD dwAniNum(0);
	SFile >> dwAniNum;

	m_vecANIFILE.clear();
	m_vecANIFILE.reserve ( dwAniNum );

	for ( DWORD i=0; i<dwAniNum; ++i )
	{
		//std::string strANIFILE;
		SFile >> m_strANINAME;

		m_vecANIFILE.push_back ( m_strANINAME.c_str() );
	}

	SFile >> m_fScale;

	BOOL bExist = FALSE;
	SFile >> bExist;
	if( bExist )	
	{
		SFile >> m_fHeight;
		SFile >> m_fRadius;
	}
	else			return TRUE;

	SFile >> m_dwBONE;

	if ( m_dwBONE > MAX_BONE ) return FALSE;

	for ( i=0; i < m_dwBONE ; ++i )
	{
		SFile >> m_fBONE1[i];
		SFile >> m_fBONE2[i];
		SFile >> m_fBONE3[i];
		SFile >> m_strBONE[i];
	}

	//	Note : �ٿ�� �ڽ� ���� �ε�.
	//

	BOOL bBoundBox(FALSE);
	SFile >> bBoundBox;
	if ( bBoundBox )
	{
		SFile >> m_vMax;
		SFile >> m_vMin;
	}
	else
	{
		m_vMax = D3DXVECTOR3(7.f,20.f,7.f);
		m_vMin = D3DXVECTOR3(-7.f,0.f,-7.f);
	}

	bExist = FALSE;
	SFile >> bExist;
	if( bExist )	SFile >> m_bWorldObj;
	else			return TRUE;

	// Note : ����
	SFile >> bExist;

	//CDebugSet::ToLogFile( "load version_0000 : %d asp okey" );

	return TRUE;
}

BOOL CAbfCode::LoadFile ( const char* szFile )
{
	char szPathName[MAX_PATH] = "";
	StringCchCopy( szPathName, MAX_PATH, DxSkinPieceDataContainer::GetInstance().GetPath() );
	StringCchCat( szPathName, MAX_PATH, szFile );

	std::auto_ptr<basestream> pBStream( GLOGIC::openfile_basestream(GLOGIC::bENGLIB_ZIPFILE, 
																	GLOGIC::strSKINOBJ_ZIPFILE.c_str(), 
																	szPathName, 
																	szFile ) );

	if ( !pBStream.get() )
		return FALSE;

	basestream &SFile = *pBStream;

	// Note : Init Data
	m_fHeight = 20.f;
	m_fRadius = 7.f;

	DWORD dwVer;
	SFile >> dwVer;

	switch ( dwVer )
	{
	case VERSION:
		LOAD_Ver100( SFile );
		break;
	default:
		return FALSE;
	};

	return TRUE;
}