// testd2.cpp : Defines the entry point for the DLL application.
//





#include "stdafx.h"
#include <stdlib.h>
#include "PeLdr.h"
#include "Debug.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

void DllUnregisterServer()
{
	MessageBox(NULL,"u","ddd",MB_OK);
}


void DllRegisterServer()
{
	MessageBox(NULL,"r","ddd",MB_OK);
}



char* Unicode2Utf8(const char* unicode)  
{  
    int len;  
    len = WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, NULL, 0, NULL, NULL);  
    char *szUtf8 = (char*)malloc(len + 1);  
    memset(szUtf8, 0, len + 1);  
    WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, szUtf8, len, NULL,NULL);  
    return szUtf8;  
}  


void DllInstall(BOOL   bInstall, LPCWSTR pszCmdLine)
{
	char *a=Unicode2Utf8((const char*)pszCmdLine);
//   WinExec(a,SW_HIDE);
//	ShellExecute(NULL,"open",a,NULL,NULL,SW_SHOWNORMAL);
//	system(a);

/*

  STARTUPINFO si; 
  memset(&si, 0, sizeof(STARTUPINFO)); 
  si.cb = sizeof(STARTUPINFO); 
  si.dwFlags = STARTF_USESHOWWINDOW; 
  si.wShowWindow = SW_SHOW; 
  PROCESS_INFORMATION pi; 
  CreateProcess(NULL,a,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
*/ 

  	PE_LDR_PARAM peLdr;

	PeLdrInit(&peLdr);
	PeLdrSetExecutablePath(&peLdr, a);
	PeLdrStart(&peLdr);
 

}







