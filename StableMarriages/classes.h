#pragma once

#include <iostream>
#include <string>
#include <vector>

class Person;
class Man;
class Woman;

class Person {
private:
	std::string name;
	bool maritalStatus;
public:
	Person();
	void setName(std::string nameIn);
	std::string getName();
	void setStatus(bool statusIn);
	bool getStatus();
};

class Man : public Person {
private:
	std::vector<Woman> prefList;
	std::vector<Woman> messageBox;
public:
	Man();
	void setPrefList(Woman wIn);
	std::vector<Woman> getPrefList();
	void setMessageBox(Woman wIn);
	std::vector<Woman> getMessageBox();
};

class Woman : public Person {
private:
	std::vector<Man> prefList;
	size_t round;
public:
	Woman();
	void setPrefList(Man mIn);
	std::vector<Man> getPrefList();
	void setRound(size_t roundIn);
	size_t getRound();
};



Person::Person() {
	name = "undeclared";
	maritalStatus = false;
}

void Person::setName(std::string nameIn) {
	name = nameIn;
}

std::string Person::getName() {
	return name;
}

void Person::setStatus(bool statusIn) {
	maritalStatus = statusIn;
}

bool Person::getStatus() {
	return maritalStatus;
}



Man::Man() {

}

void Man::setPrefList(Woman wIn) {
	prefList.push_back(wIn);
}

std::vector<Woman> Man::getPrefList() {
	return prefList;
}

void Man::setMessageBox(Woman wIn) {
	messageBox.push_back(wIn);
}



Woman::Woman() {

}

std::vector<Woman> Man::getMessageBox() {
	return messageBox;
}

void Woman::setPrefList(Man mIn) {
	prefList.push_back(mIn);
}

std::vector<Man> Woman::getPrefList() {
	return prefList;
}

void Woman::setRound(size_t roundIn) {
	round = roundIn;
}

size_t Woman::getRound() {
	return round;
}
