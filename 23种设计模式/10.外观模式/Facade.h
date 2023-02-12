//在这个事例中，新生入学系统就是一个复杂的系统；新生是客户端；接待人员可以看做入学系统的外观。
#include <iostream>
#include <string>
using namespace std;
class AdmissionSystem
{
public:
	AdmissionSystem() {}
	virtual ~AdmissionSystem() {}
 
	void GetStudentID()
	{
		cout << "领取学生证" << endl;
	}
 
	void ConfirmDormitory()
	{
		cout << "确认宿舍+床位号" << endl;
	}
 
	void GetTextBook()
	{
		cout << "领取教材" << endl;
	}
 
	virtual void ConfirmClass() = 0;
};
//理学院入学系统
class FacultyOfScience : public AdmissionSystem
{
public:
	void ConfirmClass()
	{
		cout << "进入理学院：确认学生班级" << endl;
	}
};
 
//工学院入学系统
class FacultyOfEngineering : public AdmissionSystem
{
public:
	void ConfirmClass()
	{
		cout << "进入工学院：确认学生班级" << endl;
	}
 
	void GetComputer()
	{
		cout << "领取电脑" << endl;
	}
};
 
//艺术学院入学系统
class FacultyOfArt : public AdmissionSystem
{
public:
	void ConfirmClass()
	{
		cout << "进入艺术学院：确认学生班级" << endl;
	}
 
	void ConfirmActivityRoom()
	{
		cout << "确认学生活动室" << endl;
	}
};
//接待人员
class AdmissionSystemHandlers
{
public:
	AdmissionSystemHandlers()
	{
		_scienceHandler = new FacultyOfScience();
		_engineerHandler = new FacultyOfEngineering();
		_artHandler = new FacultyOfArt();
	}
 
	~AdmissionSystemHandlers()
	{
		delete _scienceHandler;
		delete _engineerHandler;
		delete _artHandler;
 
		_scienceHandler = nullptr;
		_engineerHandler = nullptr;
		_artHandler = nullptr;
	}
 
	//入学理学院
	void ScienceAdmission()
	{
		if (nullptr == _scienceHandler)
		{
			cout << "不存在接待人员" << endl;
			return;
		}
 
		_scienceHandler->GetStudentID();
		_scienceHandler->ConfirmClass();
		_scienceHandler->ConfirmDormitory();
		_scienceHandler->GetTextBook();
	}
 
	//入学工学院
	void EngineerAdmission()
	{
		if (nullptr == _engineerHandler)
		{
			cout << "不存在接待人员" << endl;
			return;
		}
 
		_engineerHandler->GetStudentID();
		_engineerHandler->ConfirmClass();
		_engineerHandler->ConfirmDormitory();
		_engineerHandler->GetTextBook();
		_engineerHandler->GetComputer();
	}
 
	//入学艺术学院
	void ArtAdmission()
	{
		if (nullptr == _artHandler)
		{
			cout << "不存在接待人员" << endl;
			return;
		}
 
		_artHandler->GetStudentID();
		_artHandler->ConfirmClass();
		_artHandler->ConfirmDormitory();
		_artHandler->GetTextBook();
		_artHandler->ConfirmActivityRoom();
	}
 
private:
	FacultyOfScience* _scienceHandler;
	FacultyOfEngineering* _engineerHandler;
	FacultyOfArt* _artHandler;
};
