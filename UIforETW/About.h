/*
Copyright 2015 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include "Utility.h"
#include "Version.h"

class CATLAboutDlg final : public ATL::CDialogImpl< CATLAboutDlg >
{
public:
	enum { IDD = IDD_ABOUTBOX };
	BEGIN_MSG_MAP( CATLAboutDlg )
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_HANDLER(IDOK, BN_CLICKED, OnBnClickedOk)
	END_MSG_MAP()
	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&)
	{
		wchar_t buffer[200];
#ifdef VERSION_SUFFIX
		swprintf_s(buffer, L"Version %1.2f%c, build date: %s", kCurrentVersion, VERSION_SUFFIX, GetEXEBuildTime().c_str());
#else
		swprintf_s(buffer, L"Version %1.2f, build date: %s", kCurrentVersion, GetEXEBuildTime().c_str());
#endif
		SetDlgItemText(IDC_BUILDDATE, buffer);
		return 0;
	}
	LRESULT OnBnClickedOk( WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/ )
	{
		EndDialog( 1 );
		return 1;
	}
};
