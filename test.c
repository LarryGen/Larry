#include <stdio.h>
#include <windows.h>
//#include "...\lib.h"
//#pragma comment(lib,"...\\Lib.lib")  //指定与静态库一起连接

int main(int argc, char *argv[])
{
	HINSTANCE hDll; //DLL句柄 
	hDll = LoadLibrary("E:\\1提上日程\\1项目\\DLL\\Debug\\DLL.dll");
	printf("DLL is Loaded\n");
	typedef int ( *PROCSUM)(int, int);  
  PROCSUM procSum;    // 指定DLL模块中导出模块的地址 
	if ( NULL!= hDll)
	{
		procSum = (PROCSUM) GetProcAddress(hDll, "addD"); // 获取dll导出函数的地址 
	
		if (NULL!=procSum)
		{
			printf("addD:%d\n",procSum(1, 12));
		}
		else{  
			printf("GetProcAddress() failed, error %d\n", GetLastError());  
		}  
		FreeLibrary(hDll);
	}
	else{  
		printf("LoadLibrary() failed, error %d\n", GetLastError());  
	}  
	
	printf("\n");
	return 0;
}
