#include <iostream>
#include <string>

// 00. Interface

class iSubscriber {
public:
	iSubscriber();
	~iSubscriber();

	void onEmit();
	virtual void iSub() = 0;

};

// 01. View

class View : public iSubscriber {
public:
	View();
	~View();
	void onInput();
	virtual void View() = 0;
	viewObserver observer;
private:
	int value_ = 0;


};

// 02. Input

class Input : public View {
public:
	Input();
	~Input();
	void onInput();
private:
	int value_ = 0;

};

// 03. TextArea

class textArea : public Input {
public:
	textArea();
	~textArea();
	void onInput();
private:
	string value = "";

};

// 04. UrlInput

class urlInput : public Input {
public:
	urlInput();
	~urlInput();
	void onInput();
private:
	string value = "";

};

// 05. Button

class Button : public View {
public:
	Button();
	~Button();
private:

};

// 06. SaveButton

class saveButton : public Button {
public:
	saveButton();
	~saveButton();
	void onClick();
private:
};

// 07. OpenButton

class openButton : public Button {
public:
	openButton();
	~openButton();
	void onClick();
private:
};

// 08. Observer

class Observer {
public:
	Observer();
	~Observer();
	void subscribe(iSubscriber subscriber);
	void publish(std::string payload);
	virtual void Observer() = 0;
private:
};

// 09. viewObserver

class viewObserver : public Observer {
public:
	viewObserver();
	~viewObserver();
private:
};

// 10. modelObserver

class modelObserver : public Observer {
public:
	modelObserver();
	~modelObserver();
private:
};

// 11. Model

class Model : public modelObserver {
public:
	Model();
	~Model();
	void setData(string data);
	string getData() const {
		return data;

private:
	string data = "";
};

// 12. Contoller

class Controller : public Model {
public:
	Controller();
	~Controller();
	Model model;
private:
};

using namespace std;

int main() {

	View iView;
	iView.setData("Hello, subscriber!");
	string Hello = subscriber.getData;
	std::cout << Hello << endl;

	return 0;
}