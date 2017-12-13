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
	int index;
public:
	Person();
	void setName(std::string nameIn);
	std::string getName();
	void setStatus(bool statusIn);
	bool getStatus();
	void setIndex(int indexIn);
	int getIndex();
};

class Man : public Person {
private:
	std::vector<Woman> prefList;
	std::vector<Woman> messageBox;
	Woman *fiance;
public:
	Man();
	void setPrefList(Woman wIn);
	std::vector<Woman> getPrefList();
	void setMessageBox(Woman wIn);
	std::vector<Woman> getMessageBox();
	void setFiance(Woman *fianceIn);
	Woman* getFiance();
	bool operator ==(Man manIn)
	{
		bool r = false;
		std::string name1 = this->getName();
		std::string name2 = manIn.getName();
		if (name1 == name2)
		{
			r = true;
		}
		return r;
	}
};

class Woman : public Person {
private:
	std::vector<Man> prefList;
	size_t round;
	Man fiance;
public:
	Woman();
	void setPrefList(Man mIn);
	std::vector<Man> getPrefList();
	void setRound(size_t roundIn);
	size_t getRound();
	void setFiance(Man fianceIn);
	Man getFiance();
	bool operator ==(Woman womanIn)
	{
		bool r = false;
		std::string name1 = this->getName();
		std::string name2 = womanIn.getName();
		if (name1 == name2)
		{
			r = true;
		}
		return r;
	}
};



Person::Person() {
	name = "undeclared";
	maritalStatus = false;
	index = 0;
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

void Person::setIndex(int indexIn) {
	index = indexIn;
}

int Person::getIndex() {
	return index;
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

void Man::setFiance(Woman *fianceIn) {
	fiance = fianceIn;
}

Woman* Man::getFiance() {
	return fiance;
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

void Woman::setFiance(Man fianceIn) {
	fiance = fianceIn;
}

Man Woman::getFiance() {
	return fiance;
}
