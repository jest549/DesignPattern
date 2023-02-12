

#include <iostream>
#include <string>
#include "component.h"
using namespace component;
int main()
{

	//(1)创建各种目录，文件对象
	FileSystem* pdir1 = new Dir("root");
	//----
	FileSystem* pfile1 = new  File("common.mk");
	FileSystem* pfile2 = new  File("config.mk");
	FileSystem* pfile3 = new  File("makefile");
	//-----
	FileSystem* pdir2 = new Dir("app");
	FileSystem* pfile4 = new  File("nginx.c");
	FileSystem* pfile5 = new  File("ngx_conf.c");
	//-----
	FileSystem* pdir3 = new Dir("signal");
	FileSystem* pfile6 = new  File("ngx_signal.c");
	//-----
	FileSystem* pdir4 = new Dir("_include");
	FileSystem* pfile7 = new  File("ngx_func.h");
	FileSystem* pfile8 = new  File("ngx_signal.h");

	//(2)构造树形目录结构
	pdir1->Add(pfile1);
	pdir1->Add(pfile2);
	pdir1->Add(pfile3);
	//----
	pdir1->Add(pdir2);
	pdir2->Add(pfile4);
	pdir2->Add(pfile5);
	//----
	pdir1->Add(pdir3);
	pdir3->Add(pfile6);
	//----
	pdir1->Add(pdir4);
	pdir4->Add(pfile7);
	pdir4->Add(pfile8);


	//(3)输出整个目录结构，只要通过根目录的ShowName方法即可，每个子目录都有自己的ShowName方法负责自己旗下的文件和目录显示。
	pdir1->ShowName(0); //缩进字符刚开始可以为空
	//pdir2->ShowName("");

	//(4)释放资源
	delete pfile8;
	delete pfile7;
	delete pdir4;
	//----
	delete pfile6;
	delete pdir3;
	//----
	delete pfile5;
	delete pfile4;
	delete pdir2;
	//----
	delete pfile3;
	delete pfile2;
	delete pfile1;
	delete pdir1;

	return 0;
}