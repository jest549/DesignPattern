#include<iostream>
#include <string>
#include <map>

using namespace std;

class Member;
//抽象中介者类AbstractChatroom（抽象聊天室类） 
class AbstractChatroom {
public:
	virtual void registerMember(Member* member) = 0;
	virtual void sendText(string from, string to, string message) = 0;
	virtual void sendImage(string from, string to, string image) = 0;
};
//抽象同事类Member（抽象会员类）
class Member
{

protected:
	AbstractChatroom *chatroom;
	string name;
public:
	Member(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setName(string name) {
		this->name = name;
	}

	AbstractChatroom* getChatroom() {
		return chatroom;
	}

	void setChatroom(AbstractChatroom* chatroom) {
		this->chatroom = chatroom;
	}

	virtual void sendText(string to, string message) = 0;
	virtual void sendImage(string to, string image) = 0;

	void receiveText(string from, string message) {
		cout << from << "发送文本给" << this->name << ",内容为:" << message << endl;
	}

	void receiveImage(string from, string image) {
		cout << from << "发送图片给" << this->name << ",内容为:" << image << endl;
	}

};
//具体中介者类Chatgroup（具体聊天室类） 
class ChatGroup : public AbstractChatroom {
public:
	void registerMember(Member* member) {
		if (!members.count(member->getName())) {
			members.insert(make_pair(member->getName(), member));
			member->setChatroom(this);
		}
	}

	void sendText(string from, string to, string message) {
		Member *member = members[to];
		member->receiveText(from, message);
	}

	void sendImage(string from, string to, string image) {
		Member *member = members[to];
		if (image.length() > 5) {
			cout << "图片太大，发送失败！" << endl;
		}
		else {
			member->receiveImage(from, image);
		}

	}
private:
	map<string, Member*> members;
};

//具体同事类CommonMember（普通会员类）
class CommonMember : public Member {
public:
	CommonMember(string name) : Member(name) {

	}

	void sendText(string to, string message) {
		cout << "普通会员发送信息:" << endl;
		chatroom->sendText(name, to, message);
	}

	void sendImage(string to, string image) {
		cout << "普通会员不能发送图片!" << endl;
	}
};
//具体同事类DiamondMember（钻石会员类）
class DiamondMember : public Member {
public:
	DiamondMember(string name) : Member(name) {

	}

	void sendText(string to, string message) {
		cout << "钻石会员发送信息:" << endl;
		chatroom->sendText(name, to, message);
	}

	void sendImage(string to, string image) {
		cout << "钻石会员发送图片:" << endl;
		chatroom->sendImage(name, to, image);
	}
};
int main(int argc, char* argv[])
{

	//创建聊天室 
	ChatGroup happyChat;

	//创建成员
	CommonMember member1("张三");
	DiamondMember member2("李四");

	//注册 
	happyChat.registerMember(&member1);
	happyChat.registerMember(&member2);

	//发送信息
	member1.sendText("李四", "李四，你好！");
	member2.sendText("张三", "张三，你好！");
	member1.sendText("李四", "今天天气很不错");
	member1.sendImage("李四", "好天气");
	member2.sendImage("张三", "一个很大的太阳");
	member2.sendImage("张三", "太阳");
}