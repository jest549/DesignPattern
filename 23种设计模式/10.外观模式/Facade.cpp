#include "Facade.h"

int main(int argc, char *argv[])
{
	AdmissionSystemHandlers hander;
	//学生甲：入学理学院
	cout << "学生甲申请入学理学院" << endl;
	hander.ScienceAdmission();
	cout << endl;
	//学生乙：入学艺术学院
	cout << "学生乙申请入学艺术学院" << endl;
	hander.ArtAdmission();
	return 0;
}
