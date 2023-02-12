#include <iostream>
#include <string>
#include <list>
using namespace std;
namespace component
{
	//抽象父类FileSystem（抽象接口）
	class FileSystem
	{
	public:
		virtual void ShowName(int level) = 0; //显示名字，参数level用于表示显示的层次，用于显示对齐
		virtual int Add(FileSystem* pfilesys) = 0; //向当前目录中增加文件或者子目录
		virtual int Remove(FileSystem* pfilesys) = 0; //从当前目录中移除文件或者子目录
		virtual ~FileSystem() {} //做父类时析构函数应该为虚函数
	};

	//文件相关类
	class File :public FileSystem
	{
	public:
		//构造函数
		File(string name) :m_sname(name) {}
		//显示名
		virtual void ShowName(int level)
		{
			for (int i = 0; i < level; ++i)
			{
				cout << "    "; //显示若干个空格用于对齐
			}
			cout << "|-" << m_sname << endl;
		}
		virtual int Add(FileSystem* pfilesys)
		{
			return -1;
		}
		virtual int Remove(FileSystem* pfilesys)
		{
			return -1;
		}

	private:
		string m_sname; //文件名
	};

	//目录相关类
	class Dir :public FileSystem
	{
	public:
		//构造函数
		Dir(string name) :m_sname(name) {}

		//显示名字
		virtual void ShowName(int level)
		{
			//（1）显示若干个空格用于对齐
			for (int i = 0; i < level; ++i) { cout << "    "; }
			//（2）输出本目录名
			cout << "+" << m_sname << endl;
			//（3）显示的层级向下走一级
			level++;
			//（4）输出所包含的子内容（可能是文件，也可能是目录）
			//遍历目录中的文件和子目录
			for (auto iter = m_child.begin(); iter != m_child.end(); ++iter)
			{
				(*iter)->ShowName(level);
			}
		}

		virtual int Add(FileSystem* pfilesys)
		{
			m_child.push_back(pfilesys);
			return 0;
		}

		virtual int Remove(FileSystem* pfilesys)
		{
			m_child.remove(pfilesys);
			return 0;
		}

	private:
		string m_sname; //文件名
		list<FileSystem*> m_child; //目录中包含的文件或者其他目录列表
	};
}