// WMI_ProcessMon.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include "eventsink.h"
#include "ProcessMon.h"

// CProcessMon�� ��ӹ޾� �����ؼ� ����ϴ� Ŭ���� 
class CStartMon : public CProcessMon
{
	void Log(char* sMsg)
    {
        SYSTEMTIME LocalTime; 
        GetLocalTime(&LocalTime); 
 
        char szDate[1024];
        ZeroMemory(szDate, 1024);
 
        sprintf(szDate, "[%04d-%02d-%02d %02d:%02d:%02d]",  
                LocalTime.wYear, LocalTime.wMonth,
                LocalTime.wDay, LocalTime.wHour,
                LocalTime.wMinute, LocalTime.wSecond); 
 
        printf("%s %s\n", szDate, sMsg);
        
    }

	void OnCreate()
	{
		char szMSG[1024];
        ZeroMemory(szMSG, 1024);
		sprintf(szMSG, "[%s] ���� �Ǿ����ϴ�!!", this->m_szProcessName);

        Log(szMSG);
	};

	void OnDelete()
	{
        char szMSG[1024];
        ZeroMemory(szMSG, 1024);
		sprintf(szMSG, "[%s] ���� �Ǿ����ϴ�!!", this->m_szProcessName);

		Log(szMSG);

	};
};


int main(int iArgCnt, char ** argv)
{
	
	CStartMon c;
	
	printf("cmd.exe�� ����͸� �մϴ�. �ƹ�Ű�� ������ �������� �Ѿ�ϴ�.\n");
	if (c.StartWatching("cmd.exe")) 
		printf("WMI ������ �����߽��ϴ�.");
	
	getchar();

	c.StopWatching();
	printf("python.exe�� ����͸� �մϴ�. �ƹ�Ű�� ������ �����մϴ�.\n");
	if (c.StartWatching("python.exe")) 
		printf("WMI ������ �����߽��ϴ�.");
	
	getchar();
}
