// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

extern HWND hWnd;		// ������ �ڵ�
//�츮�� �߰��Ұ� 
#pragma comment(lib,"Msimg32.lib")  //���� ������� �Լ� �߰��ϱ� ���� ����׸� ���̺귯�� �߰�
#pragma comment(lib,"vfw32.lib")	// .mp4 Ȯ���ڸ� ����ϱ� ���� ����׸� ���̺귯�� �߰�
#pragma comment(lib,"winmm.lib")

#include <strsafe.h>//DrawScore 
#include "g_Defines.h"
#include <mmsystem.h>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>
using namespace std;
