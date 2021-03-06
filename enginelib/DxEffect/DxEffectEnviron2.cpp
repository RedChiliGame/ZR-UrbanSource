// DxEffectEnviron2.cpp: implementation of the DxEffectShadowHW class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "DxFrameMesh.h"
#include "DxEffectMan.h"

#include "DxEffectEnviron2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define new DEBUG_NEW


const DWORD DxEffectEnviron2::TYPEID = DEF_EFFECT_ENVIRON2;
const char DxEffectEnviron2::NAME[] = "[3008]_[発井2反引]";

DWORD	DxEffectEnviron2::m_dwEffReflect;

//	Note : 
//
char DxEffectEnviron2::m_strEffReflect[] =
{
	"vs.1.0	;\n" //

	//;transform position
	//;----------------------------------------------------------------------------
	//;	Vertex 研 姿鍵陥.~~~~~せせ
	"m4x4 oPos, v0, c22	;\n"

	//;----------------------------------------------------------------------------
	//;	Vertex 研 World 疎妊稽 戚疑 獣轍陥.

	// 獄努什 疎妊研 World 疎妊稽.
	"m4x3 r0, v0, c10	;\n"
	"mov r0.w, v0.w		;\n"

	//;----------------------------------------------------------------------------
	//		葛菰困斗研 舘是 困斗稽.		---		r9 拭 去系

	// 葛菰困斗研 亜閃紳陥.
	"m3x3 r9, v3, c10	;\n"

	// 舘是 困斗稽 幻級嬢 層陥.
	"dp3 r9.w, r9, r9	\n"	//
	"rsq r9.w, r9.w		\n"	//
	"mul r9, r9, r9.w	\n"	//

	// 朝五虞 採斗 獄努什猿走税 舘是 困斗研 条澗陥.
	"sub r1, r0, c8		\n"	// 暗軒 域至.
	"dp3 r3.w, r1, r1	\n"	// 舘是 困斗 幻級奄 獣拙.
	"rsq r3.w, r3.w		\n"	//
	"mul r5, r1, r3.w	\n"	//

	//;-------------------------------------------------------------------- 
	//;		Diffuse 町虞研 持失

	//; The directional light source.
	"dp3 r4.x, r9, -c0		\n" //

	//	Texture 竺舛.
	//
	"dp3 r4, r5, r9				\n"	// r4 = r3 (鎧旋) 葛菰困斗r9
	"add r4, r4, r4				\n"	// r4 = 2 * r4
	"mad oT0.xyz, r9, -r4, r5	\n"	// r3 - ( r4 ) * r9
	"mov oT0.w, c28.z			\n"	// c1.x = 1.0f
};


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DxEffectEnviron2::DxEffectEnviron2() :
	m_wEnvCase(0x0002),		// 曽嫌 壱献陥.
	m_pCloudTexture(NULL),					// 姥硯 益顕切	// 姥硯 努什団
	m_fTime(0.0f),							// 姥硯 益顕切	// 獣娃
	m_fLoop(0.0f),							// 姥硯 益顕切	// 刊旋掬澗 葵
	m_fLoopAdd(0.0001f),					// 姥硯 益顕切	// 姥硯戚 碑君亜澗 紗亀
	m_fDistance(10000.f),					// 姥硯 益顕切	// 亜稽 掩戚 人 室稽 掩戚
	m_fMultiply(1.0f),						// 姥硯 益顕切	// 維切 収切 ?
	m_pDot3Texture(NULL),	// 鎧旋 鷺兄漁
	m_fDotPower(0.9f),
	m_pDetailTexture(NULL),						// 歯稽 獣拙
	m_fWidth(1.0f),							// 歯稽 獣拙
	m_fHeight(1.0f),						// 歯稽 獣拙
	m_pCubeTexture(NULL),		// 鋼紫
	m_dwBlendAlpha(0x80ffffff)	// 鋼紫	- 0 拭亜猿酔檎 据沙拭 ff拭 亜猿酔檎 鋼紫拭~~!!!
{
	strcpy ( m_szTexture, "cloudcover.bmp" );	// 姥硯 益顕切
	strcpy ( m_szTexDot3, "_Dot_Ripples2_512.tga" );				// 鎧旋 鷺兄漁
	strcpy ( m_szTexDetail, "_Det_1.bmp" );		// 獣拙
	strcpy ( m_szTexture1,"_Env_lobbyxpos.bmp" );	// 鋼紫
	strcpy ( m_szTexture2,"_Env_lobbyxneg.bmp" );	// 鋼紫
	strcpy ( m_szTexture3,"_Env_lobbyypos.bmp" );	// 鋼紫
	strcpy ( m_szTexture4,"_Env_lobbyyneg.bmp" );	// 鋼紫
	strcpy ( m_szTexture5,"_Env_lobbyzpos.bmp" );	// 鋼紫
	strcpy ( m_szTexture6,"_Env_lobbyzneg.bmp" );	// 鋼紫
}

DxEffectEnviron2::~DxEffectEnviron2()
{
}

HRESULT DxEffectEnviron2::CreateDevice ( LPDIRECT3DDEVICE8 pd3dDevice )
{
	HRESULT hr;
	LPD3DXBUFFER pCode = NULL; 

	DWORD dwDecl[] =
	{
		D3DVSD_STREAM(0),
		D3DVSD_REG(0, D3DVSDT_FLOAT3 ),			//D3DVSDE_POSITION,  0  
		D3DVSD_REG(3, D3DVSDT_FLOAT3 ),		//D3DVSDE_DIFFUSE,   5  
		D3DVSD_REG(7, D3DVSDT_FLOAT2 ),		//D3DVSDE_
		D3DVSD_END()
	};

	//	Note : 鋼紫
	//
	hr = D3DXAssembleShader( m_strEffReflect, (UINT)strlen( m_strEffReflect ), 0, NULL, &pCode, NULL );
	if( FAILED(hr) )	return E_FAIL;

	hr = pd3dDevice->CreateVertexShader ( dwDecl, (DWORD*)pCode->GetBufferPointer(), &m_dwEffReflect, 
												DxEffectMan::Instance.GetUseSwShader() );
	if( FAILED(hr) )	return E_FAIL;

	SAFE_RELEASE ( pCode );

	return S_OK;
}

HRESULT DxEffectEnviron2::ReleaseDevice ( LPDIRECT3DDEVICE8 pd3dDevice )
{
	pd3dDevice->DeleteVertexShader ( m_dwEffReflect );

	return S_OK;
}

HRESULT DxEffectEnviron2::AdaptToDxFrame ( DxFrame *pFrame, LPDIRECT3DDEVICE8 pd3dDevice )
{
	if ( !pFrame ) return S_OK;

	this->pLocalFrameEffNext = pFrame->pEffectNext;
	pFrame->pEffectNext = this;

	if ( pFrame->szName )
	{
		SAFE_DELETE_ARRAY(m_szAdaptFrame);
		m_szAdaptFrame = new char[strlen(pFrame->szName)+1];

		strcpy ( m_szAdaptFrame, pFrame->szName );
	}

	return S_OK;
}


HRESULT DxEffectEnviron2::InitDeviceObjects ( LPDIRECT3DDEVICE8 pd3dDevice )
{
	//	Note : 努什団税 石奄 神嫌澗 巷獣廃陥.
	//
	TextureManager::LoadTexture ( m_szTexture, pd3dDevice, m_pCloudTexture, 0, 0 );

	if ( !m_pCloudTexture )
	{
		char szMsg[256];
		sprintf ( szMsg, "戚耕走 督析 '%s' 石奄拭 叔鳶", m_szTexture );
		MessageBox ( NULL, szMsg, "ERROR", MB_OK );
	}

	//	Note : 努什団税 石奄 神嫌澗 巷獣廃陥.
	//
	TextureManager::LoadTexture ( m_szTexDot3, pd3dDevice, m_pDot3Texture, 0, 0 );

	if ( !m_pDot3Texture )
	{
		char szMsg[256];
		sprintf ( szMsg, "戚耕走 督析 '%s' 石奄拭 叔鳶", m_szTexDot3 );
		MessageBox ( NULL, szMsg, "ERROR", MB_OK );
	}

	//	Note : 努什団税 石奄 神嫌澗 巷獣廃陥.
	//
	TextureManager::LoadTexture ( m_szTexDetail, pd3dDevice, m_pDetailTexture, 0, 0 );

	if ( !m_pDetailTexture )
	{
		char szMsg[256];
		sprintf ( szMsg, "戚耕走 督析 '%s' 石奄拭 叔鳶", m_szTexDetail );
		MessageBox ( NULL, szMsg, "ERROR", MB_OK );
	}



	//	Note : 
	//
	// Note	: Shader 拭辞 床戚澗 Cube Texture 幻級奄
	//
	TCHAR* szSkyTex[6] =
	{
		m_szTexture1, m_szTexture2, m_szTexture3,
		m_szTexture4, m_szTexture5, m_szTexture6
	};

	LPDIRECT3DTEXTURE8	m_pSkyTex[6];

	//	Note : 
	//
	for(UINT i = 0; i < 6; i++)
	{
		TextureManager::LoadTexture ( szSkyTex[i], pd3dDevice, m_pSkyTex[i], 0, 0 );
	}

	if(SUCCEEDED(D3DXCreateCubeTexture(pd3dDevice, 128, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, &m_pCubeTexture)))
	{
		for(UINT i = 0; i < 6; i++)
		{
			if(m_pSkyTex[i])
			{
				IDirect3DSurface8 *pSrc;
				IDirect3DSurface8 *pDest;

				m_pSkyTex[i]->GetSurfaceLevel(0, &pSrc);
				m_pCubeTexture->GetCubeMapSurface((D3DCUBEMAP_FACES) i, 0, &pDest);

				if(pSrc && pDest)
					D3DXLoadSurfaceFromSurface(pDest, NULL, NULL, pSrc, NULL, NULL, D3DX_DEFAULT, 0);

				SAFE_RELEASE(pDest);
				SAFE_RELEASE(pSrc);

				//	Note : 走趨 層陥.
				//
				TextureManager::ReleaseTexture ( m_pSkyTex[i] );
				m_pSkyTex[i] = NULL;
			}
		}

		D3DXFilterCubeTexture( m_pCubeTexture, NULL, 0, D3DX_DEFAULT);
	}

	return S_OK;
}

HRESULT DxEffectEnviron2::DeleteDeviceObjects ()
{
	//	Note : 戚穿 努什団亜 稽球鞠嬢 赤聖 井酔 薦暗.
	//
	if ( m_pCloudTexture )
		TextureManager::ReleaseTexture ( m_pCloudTexture );
	m_pCloudTexture = NULL;

	//	Note : 戚穿 努什団亜 稽球鞠嬢 赤聖 井酔 薦暗.
	//
	if ( m_pDot3Texture )
		TextureManager::ReleaseTexture ( m_pDot3Texture );
	m_pDot3Texture = NULL;

	//	Note : 戚穿 努什団亜 稽球鞠嬢 赤聖 井酔 薦暗.
	//
	if ( m_pDetailTexture )
		TextureManager::ReleaseTexture ( m_pDetailTexture );
	m_pDetailTexture = NULL;

	//	Note : 戚穿 努什団亜 稽球鞠嬢 赤聖 井酔 薦暗.
	//
	if ( m_pCubeTexture )
		m_pCubeTexture->Release ();
	m_pCubeTexture = NULL;

	return S_OK;
}

HRESULT DxEffectEnviron2::FrameMove ( float fTime, float fElapsedTime )
{
	m_fTime += fElapsedTime;

	return S_OK;
}

HRESULT DxEffectEnviron2::Render ( DxFrame *pframeCur, LPDIRECT3DDEVICE8 pd3dDevice )
{
	HRESULT hr = S_OK;
	DxMeshes *pmsMeshs;
	DxFrame *pframeChild;

	//	Note : Render 
	//
	if ( pframeCur->pmsMeshs != NULL )
	{
		//	Note : 五習 益軒奄.
		//
		pmsMeshs = pframeCur->pmsMeshs;
		while ( pmsMeshs != NULL )
		{
			if ( pmsMeshs->m_pLocalMesh )
			{
				DWORD dwFVFSize;
				DWORD dwVerts, dwFaces;
				LPDIRECT3DINDEXBUFFER8 pIB;
				LPDIRECT3DVERTEXBUFFER8 pVB;
				
				pmsMeshs->m_pLocalMesh->GetIndexBuffer ( &pIB );
				pmsMeshs->m_pLocalMesh->GetVertexBuffer ( &pVB );
				
				dwFVFSize = pmsMeshs->m_pLocalMesh->GetFVF ();
				dwFVFSize = D3DXGetFVFVertexSize ( dwFVFSize );

				dwVerts = pmsMeshs->m_pLocalMesh->GetNumVertices();
				dwFaces = pmsMeshs->m_pLocalMesh->GetNumFaces();


				//	Note : SetVertexShader拭 World人 WorldViewProjection 楳慶 増嬢 隔奄
				//
				D3DXMATRIX	matWorld, matView, matProj, matWVP;

				matView = DxViewPort::Instance.GetMatView();
				matProj = DxViewPort::Instance.GetMatProj();

				D3DXMatrixTranspose( &matWorld, &(pframeCur->matCombined) );
				pd3dDevice->SetVertexShaderConstant ( VSC_MATWORLD,			&matWorld,	4 );

				D3DXMatrixMultiply ( &matWVP, &(pframeCur->matCombined), &matView );
				D3DXMatrixMultiply ( &matWVP, &matWVP, &matProj );
				D3DXMatrixTranspose( &matWVP, &matWVP );
				pd3dDevice->SetVertexShaderConstant ( VSC_MATWORLDVIEWPROJ, &matWVP,	4 );



				//	Note : SetRenderState() 識情
				//
				pd3dDevice->SetRenderState ( D3DRS_TEXTUREFACTOR, 0xffffffff );//m_dwBlendAlpha );	// 硝督葵... せせせ発井己 硝督.


				//	Note : SetTextureStageState() 識情
				//
				pd3dDevice->SetTextureStageState ( 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR );
				pd3dDevice->SetTextureStageState ( 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR );
				pd3dDevice->SetTextureStageState ( 0, D3DTSS_MIPFILTER, D3DTEXF_LINEAR );				

				pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
		//		pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLORARG2, D3DTA_TFACTOR );
				pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_BLENDFACTORALPHA );

				



				switch ( m_wEnvCase )
				{
				case 0x0001:	// 鎧旋 鷺兄漁
					pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, TRUE );
					pd3dDevice->SetRenderState ( D3DRS_SRCBLEND,	D3DBLEND_ZERO );
					pd3dDevice->SetRenderState ( D3DRS_DESTBLEND,	D3DBLEND_SRCCOLOR );

					pd3dDevice->SetTexture ( 0, m_pDot3Texture );
			//		pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLORARG2, D3DTA_TFACTOR );
					pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_DOTPRODUCT3 );

					break;

				case 0x0002:	// 巨砺析 己

					pd3dDevice->SetTexture ( 0, m_pDetailTexture );

					pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, TRUE );
					pd3dDevice->SetRenderState ( D3DRS_SRCBLEND,	D3DBLEND_DESTCOLOR );
					pd3dDevice->SetRenderState ( D3DRS_DESTBLEND,	D3DBLEND_SRCCOLOR );

			//		pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_SELECTARG1 );

					break;

				case 0x0003:	// 鋼紫
					pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, TRUE );
					pd3dDevice->SetRenderState ( D3DRS_SRCBLEND,	D3DBLEND_DESTCOLOR );
					pd3dDevice->SetRenderState ( D3DRS_DESTBLEND,	D3DBLEND_SRCCOLOR );
//
					pd3dDevice->SetRenderState ( D3DRS_TEXTUREFACTOR, m_dwBlendAlpha );
					
		//			pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_SELECTARG1 );

					pd3dDevice->SetTexture ( 0, m_pCubeTexture );

					break;

				case 0x0010:	// 姥硯 益顕切

					pd3dDevice->SetTexture ( 0, m_pCloudTexture );

			//		pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_SELECTARG1 );

					if( m_fTime > 0.05f )
					{
						m_fTime = 0.0f;

						m_fLoop += m_fLoopAdd;
						if( m_fLoop > 1.0f )
							m_fLoop = 0.0f;

						struct VERTEX { D3DXVECTOR3 p,n;  D3DXVECTOR2 t; };
						VERTEX* pVertices;

						D3DXVECTOR4	vLightDirect;
						pd3dDevice->GetVertexShaderConstant ( VSC_LIGHTDIRECT01, &vLightDirect, 1 );

						D3DXVECTOR4	vCameraPos;
						pd3dDevice->GetVertexShaderConstant ( VSC_CAMERAPOSITION, &vCameraPos, 1 );



						pmsMeshs->m_pLocalMesh->LockVertexBuffer ( 0L, (BYTE**)&pVertices );

						for( DWORD j=0; j<dwVerts; j++ )
						{
							float X = pVertices->p.x * pframeCur->matCombined._11 + pVertices->p.y * pframeCur->matCombined._21 +
										pVertices->p.z * pframeCur->matCombined._31 + pframeCur->matCombined._41;

							float Y = pVertices->p.x * pframeCur->matCombined._12 + pVertices->p.y * pframeCur->matCombined._22 +
										pVertices->p.z * pframeCur->matCombined._32 + pframeCur->matCombined._42;

							float Z = pVertices->p.x * pframeCur->matCombined._13 + pVertices->p.y * pframeCur->matCombined._23 +
										pVertices->p.z * pframeCur->matCombined._33 + pframeCur->matCombined._43;

							//	Note : 格搾亜 (m_fDistance) 昔 姥硯聖 幻窮 陥製
							//			U,V 葵聖 (m_fLoop)崇送食辞 競拭 益顕切亜 球軒酔澗 反引研 浬陥.
							//		 是帖		株戚人 笹 唖亀 叫獣.			穿端滴奄鋼		穿端滴奄	崇送昔陥
							float u = (X + (vLightDirect.x/vLightDirect.y)*Y - m_fDistance/2) / m_fDistance - m_fLoop;// + DistX/1000;
							float v = (Z + (vLightDirect.z/vLightDirect.y)*Y - m_fDistance/2) / m_fDistance - m_fLoop;// + DistZ/1000;

							pVertices->t.x = u*m_fMultiply;
							pVertices->t.y = v*m_fMultiply;

							pVertices++;
						}
						pmsMeshs->m_pLocalMesh->UnlockVertexBuffer ();
					}

					pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, TRUE );
					pd3dDevice->SetRenderState ( D3DRS_SRCBLEND,	D3DBLEND_DESTCOLOR );
					pd3dDevice->SetRenderState ( D3DRS_DESTBLEND,	D3DBLEND_SRCCOLOR );

					break;

				case 0x0011:	// 姥硯 益顕切 + 鎧旋 鷺兄漁

					pd3dDevice->SetTexture ( 0, m_pDot3Texture );
					pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLORARG2, D3DTA_TFACTOR );
					pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_DOTPRODUCT3 );

					break;

				case 0x0012:	// 姥硯 益顕切 + 

					break;

				case 0x0013:	// 姥硯 益顕切 + 鋼紫

					if( m_fTime > 0.05f )
					{
						m_fTime = 0.0f;

						m_fLoop += m_fLoopAdd;
						if( m_fLoop > 1.0f )
							m_fLoop = 0.0f;
					}
					//	Note : Shader 雌呪 識情
					//
					pd3dDevice->SetVertexShaderConstant ( VSC_CUSTOM+5,	&D3DXVECTOR4( m_fDistance , m_fLoop, m_fMultiply, 0.0f ),	1 );



					pd3dDevice->SetTexture ( 0, m_pCloudTexture );

					pd3dDevice->SetTextureStageState ( 0, D3DTSS_ADDRESSU, D3DTADDRESS_MIRROR );
					pd3dDevice->SetTextureStageState ( 0, D3DTSS_ADDRESSV, D3DTADDRESS_MIRROR );

					pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_SELECTARG1 );

					//	Note : SetRenderState() 識情
					//
					pd3dDevice->SetRenderState ( D3DRS_TEXTUREFACTOR, m_dwBlendAlpha );	// 硝督葵... せせせ発井己 硝督.

					pd3dDevice->SetTexture ( 1, m_pCubeTexture );

					pd3dDevice->SetTextureStageState ( 1, D3DTSS_COLOROP,	D3DTOP_BLENDFACTORALPHA );

					pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, TRUE );
					pd3dDevice->SetRenderState ( D3DRS_SRCBLEND,	D3DBLEND_ZERO );
					pd3dDevice->SetRenderState ( D3DRS_DESTBLEND,	D3DBLEND_SRCCOLOR );
					//pd3dDevice->SetRenderState ( D3DRS_DESTBLEND,	D3DBLEND_ONE );

				//	pd3dDevice->SetVertexShader ( m_dwEffCloudReflect );
					pd3dDevice->DrawIndexedPrimitive ( D3DPT_TRIANGLELIST, 0, dwVerts, 0, dwFaces );

					pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, FALSE );
					
					break;

				default:
					return S_OK;

					break;

				}






				DWORD					AttribTableSize = 0;
				LPD3DXATTRIBUTERANGE	pSrcAttribTable = NULL;

				pmsMeshs->m_pLocalMesh->GetAttributeTable ( NULL, &AttribTableSize );
				
				LPD3DXATTRIBUTERANGE pAttribTable;
				pAttribTable = new D3DXATTRIBUTERANGE [ AttribTableSize ];
				pmsMeshs->m_pLocalMesh->GetAttributeTable( pAttribTable, &AttribTableSize );

				//	Note : 災燈誤 五習 球稽跡.
				//		pmsMeshs->cMaterials --> AttribTableSize
				//
				for ( DWORD i=0; i<AttribTableSize; i++ )
				{












				pd3dDevice->SetVertexShaderConstant ( VSC_MATRIAL, &( pmsMeshs->rgMaterials[0].Diffuse ), 1 );


				//	Note : 社覗闘裾嬢 獄努什 覗稽室縮
				//
				if ( DxEffectMan::Instance.GetUseSwShader() )
					pd3dDevice->SetRenderState( D3DRS_SOFTWAREVERTEXPROCESSING, TRUE );		

				pd3dDevice->SetIndices ( pIB, 0 );
				pd3dDevice->SetStreamSource ( 0, pVB, dwFVFSize );

				switch ( m_wEnvCase )
				{
				case 0x0003:	// 鋼紫
					pd3dDevice->SetVertexShader ( m_dwEffReflect );
					break;
				case 0x0013:	// 姥硯 益顕切 + 鋼紫
		//			pd3dDevice->SetVertexShader ( m_dwEffCloudReflect );
					break;
				default:
					pd3dDevice->SetTransform ( D3DTS_WORLD, &(pframeCur->matCombined) );
					pd3dDevice->SetVertexShader ( pmsMeshs->m_pLocalMesh->GetFVF () );
					break;
				}

				pd3dDevice->DrawIndexedPrimitive
				(
					D3DPT_TRIANGLELIST,
					pAttribTable[i].VertexStart,
					pAttribTable[i].VertexCount,
					pAttribTable[i].FaceStart * 3,
					pAttribTable[i].FaceCount
				);




				//	Note : 社覗闘裾嬢 獄努什 覗稽室縮
				//
				if ( DxEffectMan::Instance.GetUseSwShader() )
					pd3dDevice->SetRenderState( D3DRS_SOFTWAREVERTEXPROCESSING, FALSE );

				pd3dDevice->SetIndices ( NULL, 0 );
				pd3dDevice->SetStreamSource ( 0, NULL, 0 );








				}

				SAFE_DELETE(pAttribTable);






				
				pd3dDevice->SetTexture(0, NULL);
				pd3dDevice->SetTexture(1, NULL);

				pd3dDevice->SetRenderState ( D3DRS_ALPHABLENDENABLE, FALSE );

				pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE );
				pd3dDevice->SetTextureStageState ( 0, D3DTSS_COLOROP,	D3DTOP_MODULATE );

				pd3dDevice->SetTextureStageState ( 1, D3DTSS_COLORARG2,	D3DTA_DIFFUSE );
				pd3dDevice->SetTextureStageState ( 1, D3DTSS_COLOROP,	D3DTOP_DISABLE );

				pd3dDevice->SetTextureStageState ( 0, D3DTSS_ADDRESSU, D3DTADDRESS_WRAP );
				pd3dDevice->SetTextureStageState ( 0, D3DTSS_ADDRESSV, D3DTADDRESS_WRAP );

				pd3dDevice->SetTextureStageState ( 1, D3DTSS_ADDRESSU, D3DTADDRESS_WRAP );
				pd3dDevice->SetTextureStageState ( 1, D3DTSS_ADDRESSV, D3DTADDRESS_WRAP );

				pd3dDevice->SetTextureStageState ( 0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );
				pd3dDevice->SetTextureStageState ( 1, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE );
			}

			pmsMeshs = pmsMeshs->pMeshNext;
		}
	}

	//	Note : 切縦 覗傾績 益軒奄.
	//
	pframeChild = pframeCur->pframeFirstChild;
	while ( pframeChild != NULL )
	{
		hr = Render ( pframeChild, pd3dDevice );
		if (FAILED(hr))
			return hr;

		pframeChild = pframeChild->pframeSibling;
	}


	return S_OK;
}
