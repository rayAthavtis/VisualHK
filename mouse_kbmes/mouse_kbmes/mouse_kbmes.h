
// mouse_kbmes.h : mouse_kbmes Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cmouse_kbmesApp:
// �йش����ʵ�֣������ mouse_kbmes.cpp
//

class Cmouse_kbmesApp : public CWinAppEx
{
public:
	Cmouse_kbmesApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cmouse_kbmesApp theApp;
