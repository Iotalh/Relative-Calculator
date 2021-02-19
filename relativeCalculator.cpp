#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;
enum class TitleKey
{
	Father, Mother, OldBrother, YoungBrother, OldSister, YoungSister, Husband, Wife, OldSon, YoungSon, OldDaughter, YoungDaughter, MaleMe, FemaleMe
};
enum class Gender {
	Male, Female
};
enum class Age
{
	Older, Younger
};
class Person
{
public:
	Gender gender;
	Age age;
	Person();
	Person(Age a);
	Person(Gender g);
	Person(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t) = 0;
	virtual string getTitle() = 0;
	void operator=(Person& p);
protected:
	bool IsMale();
	bool IsOlder();
};
Person::Person() {};
Person::Person(Age a)
	:age(a)
{
}
Person::Person(Gender g)
	: gender(g)
{
}
Person::Person(Gender g, Age a)
	: gender(g), age(a)
{
}
Person* Person::getPersonWithRelation(TitleKey t) {
	cout << "getPersonWithRelation\n";
	return this;
};
string Person::getTitle() {
	cout << "getTitle\n";
	return "";
};
void Person::operator=(Person& p) {
	this->age = p.age;
	this->gender = p.gender;
};
bool Person::IsMale() {
	return this->Person::gender == Gender::Male;
};
bool Person::IsOlder() {
	return this->Person::age == Age::Older;
};

class Me :public Person
{
public:
	Me();
	Me(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title = "自己";
	bool haveGender;
};
class Parent :public Person
{
public:
	Parent(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "父親", "母親" };
};
class Sibling :public Person
{
public:
	Sibling(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "哥哥", "弟弟", "姊姊", "妹妹" };
};
class SiblingMate :public Person
{
public:
	SiblingMate(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "嫂嫂", "弟媳", "姊夫", "妹夫" };
};
class SisterChild :public Person
{
public:
	SisterChild(Gender g, bool isBig);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "外甥", "外甥女" };
	bool isBigSister;
};
class BrotherChild :public Person
{
public:
	BrotherChild(Gender g, bool isBig);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "姪子","姪女" };
	bool isBigBrother;
};
class FGrandParent :public Person
{
public:
	FGrandParent(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "祖父","祖母" };
};
class FUncle :public Person
{
public:
	FUncle(Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "伯父","叔父" };
};
class FUncleMate :public Person
{
public:
	FUncleMate(Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "伯母", "嬸嬸" };
};
class FUncleChild :public Person
{
public:
	FUncleChild(Gender g, Age a, bool isBig);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "堂兄", "堂弟", "堂姊", "堂妹" };
	bool isBigUncle;
};
class FAunt :public Person
{
public:
	FAunt();
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title = "姑媽";
};
class FAuntMate :public Person
{
public:
	FAuntMate();
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title = "姑丈";
};
class FAuntChild :public Person
{
public:
	FAuntChild(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "表兄", "表弟", "表姊", "表妹" };
};
class MGrandParent :public Person
{
public:
	MGrandParent(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "外祖父", "外祖母" };
};
class MUncle :public Person
{
public:
	MUncle(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "舅舅", "姨媽" };
};
class MUncleMate :public Person
{
public:
	MUncleMate(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "舅媽", "姨丈" };
};
class MUncleChild :public Person
{
public:
	MUncleChild(Gender g, Age a, bool isMale);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "表兄", "表弟", "表姊", "表妹" };
	bool isMaleUncle;
};
class Child :public Person
{
public:
	Child(Gender g, bool isMale);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "兒子", "女兒" };
	bool isMaleMe;
};
class ChildMate :public Person
{
public:
	ChildMate(Gender g, bool isMale);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "媳婦", "女婿" };
	bool isMaleMe;
};
class SGrandSon :public Person
{
public:
	SGrandSon(Gender g, bool isMale);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "孫子", "孫女" };
	bool isMaleMe;
};
class DGrandSon :public Person
{
public:
	DGrandSon(bool isMale);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title = "外孫";
	bool isMaleMe;
};
class Mate :public Person
{
public:
	Mate(Gender g);
	Mate(Gender g, bool isMale);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "夫", "妻" };
	bool isMaleMe;
};
class HGrandParent :public Person
{
public:
	HGrandParent(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "夫父", "夫母" };
	bool isMaleMe = true;
};
class HSibling :public Person
{
public:
	HSibling(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "夫兄", "夫弟", "夫姊", "夫妹" };
	bool isMaleMe = true;
};
class HSiblingMate :public Person
{
public:
	HSiblingMate(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "夫兄嫂", "夫弟媳", "夫姊夫", "夫妹夫" };
	bool isMaleMe = true;
};
class HSisterChild :public Person
{
public:
	HSisterChild(Gender g, bool isBig);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "外甥", "外甥女" };
	bool isBigSister;
	bool isMaleMe = true;
};
class HBrotherChild :public Person
{
public:
	HBrotherChild(Gender g, bool isBig);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "姪子","姪女" };
	bool isBigBrother;
	bool isMaleMe = true;
};
class WGrandParent :public Person
{
public:
	WGrandParent(Gender g);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "妻父", "妻母" };
	bool isMaleMe = false;
};
class WSibling :public Person
{
public:
	WSibling(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "妻兄", "妻弟", "妻姊", "妻妹" };
	bool isMaleMe = false;
};
class WSiblingMate :public Person
{
public:
	WSiblingMate(Gender g, Age a);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[4] = { "妻兄嫂", "妻弟媳", "妻姊夫", "妻妹夫" };
	bool isMaleMe = false;
};
class WSiblingChild :public Person
{
public:
	WSiblingChild(Gender g, bool isMale, bool isBig);
	virtual Person* getPersonWithRelation(TitleKey t);
	virtual string getTitle();
	string title[2] = { "外甥", "外甥女" };
	bool isMaleSibling;
	bool isBigSibling;
	bool isMaleMe = false;
};

Me::Me() :Person()
{
	haveGender = false;
}
Me::Me(Gender g) : Person(g)
{
	haveGender = true;
}
Person* Me::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new Parent(Gender::Male);
	case TitleKey::Mother:
		return new Parent(Gender::Female);
	case TitleKey::OldBrother:
		return new Sibling(Gender::Male, Age::Older);
	case TitleKey::YoungBrother:
		return new Sibling(Gender::Male, Age::Younger);
	case TitleKey::OldSister:
		return new Sibling(Gender::Female, Age::Older);
	case TitleKey::YoungSister:
		return new Sibling(Gender::Female, Age::Younger);
	case TitleKey::Husband:
		if (this->haveGender)
		{
			return new Mate(Gender::Male);
		}
		else {
			return new Mate(Gender::Male, false);
		}

	case TitleKey::Wife:
		return new Mate(Gender::Female);
	case TitleKey::OldSon:
		return new Child(Gender::Male, this->IsMale());
	case TitleKey::YoungSon:
		return new Child(Gender::Male, this->IsMale());
	case TitleKey::OldDaughter:
		return new Child(Gender::Female, this->IsMale());
	case TitleKey::YoungDaughter:
		return new Child(Gender::Female, this->IsMale());
	case TitleKey::MaleMe:
		return new Me(Gender::Male);
	case TitleKey::FemaleMe:
		return new Me(Gender::Female);
	default:
		cout << "broken Me\n";
		break;
	}
}
string Me::getTitle() {
	return this->title;
}

Parent::Parent(Gender g) : Person(g)
{
}
Person* Parent::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		if (this->IsMale()) {
			return new FGrandParent(Gender::Male);
		}
		else {
			return new MGrandParent(Gender::Male);
		}
	case TitleKey::Mother:
		if (this->IsMale()) {
			return new FGrandParent(Gender::Female);
		}
		else {
			return new MGrandParent(Gender::Female);
		}
	case TitleKey::OldBrother:
		if (this->IsMale()) {
			return new FUncle(Age::Older);
		}
		else {
			return new MUncle(Gender::Male);
		}
	case TitleKey::YoungBrother:
		if (this->IsMale()) {
			return new FUncle(Age::Younger);
		}
		else {
			return new MUncle(Gender::Male);
		}
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		if (this->IsMale()) {
			return new FAunt();
		}
		else {
			return new MUncle(Gender::Female);
		}
	case TitleKey::Wife:
		return new Parent(Gender::Female);
	case TitleKey::OldSon:
		return new Sibling(Gender::Male, Age::Older);
	case TitleKey::YoungSon:
		return new Sibling(Gender::Male, Age::Younger);
	case TitleKey::OldDaughter:
		return new Sibling(Gender::Female, Age::Older);
	case TitleKey::YoungDaughter:
		return new Sibling(Gender::Female, Age::Younger);
	default:
		cout << "broken parent\n";
		break;
	}
}
string Parent::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

Sibling::Sibling(Gender g, Age a) :Person(g, a)
{
}
Person* Sibling::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new Parent(Gender::Male);
	case TitleKey::Mother:
		return new Parent(Gender::Female);
	case TitleKey::OldBrother:
		return new Sibling(Gender::Male, Age::Older);
	case TitleKey::YoungBrother:
		return new Sibling(Gender::Male, Age::Younger);
	case TitleKey::OldSister:
		return new Sibling(Gender::Female, Age::Older);
	case TitleKey::YoungSister:
		return new Sibling(Gender::Female, Age::Younger);
	case TitleKey::Husband:
		if (!this->IsMale())
			return new SiblingMate(Gender::Male, this->age);
	case TitleKey::Wife:
		if (this->IsMale())
			return new SiblingMate(Gender::Female, this->age);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		if (this->IsMale()) {
			return new BrotherChild(Gender::Male, this->IsOlder());
		}
		else {
			return new SisterChild(Gender::Male, this->IsOlder());
		}
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		if (this->IsMale()) {
			return new BrotherChild(Gender::Female, this->IsOlder());
		}
		else {
			return new SisterChild(Gender::Female, this->IsOlder());
		}
	default:
		cout << "broken sibling\n";
		break;
	}
}
string Sibling::getTitle() {
	if (this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

SiblingMate::SiblingMate(Gender g, Age a) : Person(g, a)
{
}
Person* SiblingMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new Sibling(Gender::Male, this->age);
	case TitleKey::Wife:
		return new Sibling(Gender::Female, this->age);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		if (this->IsMale()) {
			return new BrotherChild(Gender::Male, this->IsOlder());
		}
		else {
			return new SisterChild(Gender::Male, this->IsOlder());
		}
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		if (this->IsMale()) {
			return new BrotherChild(Gender::Female, this->IsOlder());
		}
		else {
			return new SisterChild(Gender::Female, this->IsOlder());
		}
	default:
		cout << "broken SiblingMate\n";
		break;
	}
}
string SiblingMate::getTitle() {
	if (!this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

SisterChild::SisterChild(Gender g, bool isBig) :Person(g)
{
	this->isBigSister = isBig;
}
Person* SisterChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new SiblingMate(Gender::Male, (isBigSister) ? Age::Older : Age::Younger);
	case TitleKey::Mother:
		return new Sibling(Gender::Female, (isBigSister) ? Age::Older : Age::Younger);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new SisterChild(Gender::Male, this->isBigSister);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new SisterChild(Gender::Female, this->isBigSister);
	default:
		cout << "broken SisterChild\n";
		break;
	}
}
string SisterChild::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

BrotherChild::BrotherChild(Gender g, bool isBig) :Person(g)
{
	this->isBigBrother = isBig;
}
Person* BrotherChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new Sibling(Gender::Male, (isBigBrother) ? Age::Older : Age::Younger);
	case TitleKey::Mother:
		return new SiblingMate(Gender::Female, (isBigBrother) ? Age::Older : Age::Younger);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new BrotherChild(Gender::Male, isBigBrother);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new BrotherChild(Gender::Female, isBigBrother);
	default:
		cout << "broken BrotherChild\n";
		break;
	}
}
string BrotherChild::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

FGrandParent::FGrandParent(Gender g) :Person(g)
{
}
Person* FGrandParent::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new FGrandParent(Gender::Male);
	case TitleKey::Wife:
		return new FGrandParent(Gender::Female);
	case TitleKey::OldSon:
		return new FUncle(Age::Older);
	case TitleKey::YoungSon:
		return new FUncle(Age::Younger);
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		return new FAunt();
	default:
		cout << "broken FGrandParent\n";
		break;
	}
}
string FGrandParent::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

FUncle::FUncle(Age a) :Person(a)
{
}
Person* FUncle::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new FGrandParent(Gender::Male);
	case TitleKey::Mother:
		return new FGrandParent(Gender::Female);
	case TitleKey::OldBrother:
		return new FUncle(Age::Older);
	case TitleKey::YoungBrother:
		return new FUncle(Age::Younger);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new FAunt();
	case TitleKey::Wife:
		if (this->IsOlder())
		{
			return new FUncleMate(Age::Older);
		}
		else {
			return new FUncleMate(Age::Younger);
		}
	case TitleKey::OldSon:
		return new FUncleChild(Gender::Male, Age::Older, this->IsOlder());
	case TitleKey::YoungSon:
		return new FUncleChild(Gender::Male, Age::Younger, this->IsOlder());
	case TitleKey::OldDaughter:
		return new FUncleChild(Gender::Female, Age::Older, this->IsOlder());
	case TitleKey::YoungDaughter:
		return new FUncleChild(Gender::Female, Age::Younger, this->IsOlder());
	default:
		cout << "broken FUncle\n";
		break;
	}
}
string FUncle::getTitle() {
	return (this->IsOlder()) ? title[0] : title[1];
}

FUncleMate::FUncleMate(Age a) : Person(Gender::Female, a)
{
}
Person* FUncleMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		if (this->IsOlder())
		{
			return new FUncle(Age::Older);
		}
		else {
			return new FUncle(Age::Younger);
		}
	case TitleKey::OldSon:
		return new FUncleChild(Gender::Male, Age::Older, this->IsOlder());
	case TitleKey::YoungSon:
		return new FUncleChild(Gender::Male, Age::Younger, this->IsOlder());
	case TitleKey::OldDaughter:
		return new FUncleChild(Gender::Female, Age::Older, this->IsOlder());
	case TitleKey::YoungDaughter:
		return new FUncleChild(Gender::Female, Age::Younger, this->IsOlder());
	default:
		cout << "broken FUncleMate\n";
		break;
	}
}
string FUncleMate::getTitle() {
	return (this->IsOlder()) ? title[0] : title[1];
}

FUncleChild::FUncleChild(Gender g, Age a, bool isBig) : Person(g, a)
{
	this->isBigUncle = isBig;
}
Person* FUncleChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new FUncle((this->isBigUncle) ? Age::Older : Age::Younger);
	case TitleKey::Mother:
		return new FUncleMate((this->isBigUncle) ? Age::Older : Age::Younger);
	case TitleKey::OldBrother:
		return new FUncleChild(Gender::Male, Age::Older, this->IsOlder());
	case TitleKey::YoungBrother:
		return new FUncleChild(Gender::Male, Age::Younger, this->IsOlder());
	case TitleKey::OldSister:
		return new FUncleChild(Gender::Female, Age::Older, this->IsOlder());
	case TitleKey::YoungSister:
		return new FUncleChild(Gender::Female, Age::Younger, this->IsOlder());
	default:
		cout << "broken FUncleSibling\n";
		break;
	}
}
string FUncleChild::getTitle() {
	if (this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

FAunt::FAunt() :Person(Gender::Female)
{
}
Person* FAunt::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new FGrandParent(Gender::Male);
	case TitleKey::Mother:
		return new FGrandParent(Gender::Female);
	case TitleKey::OldBrother:
		return new FUncle(Age::Older);
	case TitleKey::YoungBrother:
		return new FUncle(Age::Younger);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new FAunt();
	case TitleKey::Husband:
		return new FAuntMate();
	case TitleKey::OldSon:
		return new FAuntChild(Gender::Male, Age::Older);
	case TitleKey::YoungSon:
		return new FAuntChild(Gender::Male, Age::Younger);
	case TitleKey::OldDaughter:
		return new FAuntChild(Gender::Female, Age::Older);
	case TitleKey::YoungDaughter:
		return new FAuntChild(Gender::Female, Age::Younger);
	default:
		cout << "broken FAunt\n";
		break;
	}
}
string FAunt::getTitle() {
	return title;
}

FAuntMate::FAuntMate() : Person(Gender::Male)
{
}
Person* FAuntMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Wife:
		return new FAunt();
	case TitleKey::OldSon:
		return new FAuntChild(Gender::Male, Age::Older);
	case TitleKey::YoungSon:
		return new FAuntChild(Gender::Male, Age::Younger);
	case TitleKey::OldDaughter:
		return new FAuntChild(Gender::Female, Age::Older);
	case TitleKey::YoungDaughter:
		return new FAuntChild(Gender::Female, Age::Younger);
	default:
		cout << "broken FAuntMate\n";
		break;
	}
}
string FAuntMate::getTitle() {
	return title;
}

FAuntChild::FAuntChild(Gender g, Age a) : Person(g, a)
{
}
Person* FAuntChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new FAuntMate();
	case TitleKey::Mother:
		return new FAunt();
	case TitleKey::OldBrother:
		return new FAuntChild(Gender::Male, Age::Older);
	case TitleKey::YoungBrother:
		return new FAuntChild(Gender::Male, Age::Younger);
	case TitleKey::OldSister:
		return new FAuntChild(Gender::Female, Age::Older);
	case TitleKey::YoungSister:
		return new FAuntChild(Gender::Female, Age::Younger);
	default:
		cout << "broken FAuntSibling\n";
		break;
	}
}
string FAuntChild::getTitle() {
	if (this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

MGrandParent::MGrandParent(Gender g) :Person(g)
{
}
Person* MGrandParent::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new MGrandParent(Gender::Male);
	case TitleKey::Wife:
		return new MGrandParent(Gender::Female);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		return new MUncle(Gender::Male);
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		return new MUncle(Gender::Female);
	default:
		cout << "broken FGrandParent\n";
		break;
	}
}
string MGrandParent::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

// Aunt is Female Uncle
MUncle::MUncle(Gender g) :Person(g)
{
}
Person* MUncle::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new MGrandParent(Gender::Male);
	case TitleKey::Mother:
		return new MGrandParent(Gender::Female);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new MUncle(Gender::Male);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new MUncle(Gender::Female);
	case TitleKey::Husband:
		return new MUncleMate(Gender::Male);
	case TitleKey::Wife:
		return new MUncleMate(Gender::Female);
	case TitleKey::OldSon:
		return new MUncleChild(Gender::Male, Age::Older, this->IsMale());
	case TitleKey::YoungSon:
		return new MUncleChild(Gender::Male, Age::Younger, this->IsMale());
	case TitleKey::OldDaughter:
		return new MUncleChild(Gender::Female, Age::Older, this->IsMale());
	case TitleKey::YoungDaughter:
		return new MUncleChild(Gender::Female, Age::Younger, this->IsMale());
	default:
		cout << "broken MUncle\n";
		break;
	}
}
string MUncle::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

MUncleMate::MUncleMate(Gender g) : Person(g)
{
}
Person* MUncleMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new MUncle(Gender::Male);
	case TitleKey::Wife:
		return new MUncle(Gender::Female);
	case TitleKey::OldSon:
		return new MUncleChild(Gender::Male, Age::Older, !(this->IsMale()));
	case TitleKey::YoungSon:
		return new MUncleChild(Gender::Male, Age::Younger, !(this->IsMale()));
	case TitleKey::OldDaughter:
		return new MUncleChild(Gender::Female, Age::Older, !(this->IsMale()));
	case TitleKey::YoungDaughter:
		return new MUncleChild(Gender::Female, Age::Younger, !(this->IsMale()));
	default:
		cout << "broken MUncleMate\n";
		break;
	}
}
string MUncleMate::getTitle() {
	return (!this->IsMale()) ? title[0] : title[1];
}

MUncleChild::MUncleChild(Gender g, Age a, bool isMale) :Person(g, a)
{
	this->isMaleUncle = isMale;
}
Person* MUncleChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		if (isMaleUncle)
		{
			return new MUncle(Gender::Male);
		}
		else {
			return new MUncleMate(Gender::Male);
		}
	case TitleKey::Mother:
		if (isMaleUncle)
		{
			return new MUncleMate(Gender::Female);
		}
		else {
			return new MUncle(Gender::Female);
		}
	case TitleKey::OldBrother:
		return new MUncleChild(Gender::Male, Age::Older, this->IsMale());
	case TitleKey::YoungBrother:
		return new MUncleChild(Gender::Male, Age::Younger, this->IsMale());
	case TitleKey::OldSister:
		return new MUncleChild(Gender::Female, Age::Older, this->IsMale());
	case TitleKey::YoungSister:
		return new MUncleChild(Gender::Female, Age::Younger, this->IsMale());
	default:
		cout << "broken MUncleChild\n";
		break;
	}
}
string MUncleChild::getTitle() {
	if (this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

Child::Child(Gender g, bool isMale) :Person(g)
{
	this->isMaleMe = isMale;
}
Person* Child::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		if (isMaleMe) {
			return new Me(Gender::Male);
		}
		else {
			return new Mate(Gender::Male);
		}
	case TitleKey::Mother:
		if (isMaleMe) {
			return new Mate(Gender::Female);
		}
		else {
			return new Me(Gender::Female);
		}
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new Child(Gender::Male, this->isMaleMe);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new Child(Gender::Female, this->isMaleMe);
	case TitleKey::Husband:
		return new ChildMate(Gender::Male, this->isMaleMe);
	case TitleKey::Wife:
		return new ChildMate(Gender::Female, this->isMaleMe);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		if (this->IsMale()) {
			return new SGrandSon(Gender::Male, this->isMaleMe);
		}
		else {
			return new DGrandSon(this->isMaleMe);
		}
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		if (this->IsMale()) {
			return new SGrandSon(Gender::Female, this->isMaleMe);
		}
		else {
			return new DGrandSon(this->isMaleMe);
		}
	default:
		cout << "broken Child\n";
		break;
	}
}
string Child::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

ChildMate::ChildMate(Gender g, bool isMale) :Person(g)
{
	this->isMaleMe = isMale;
}
Person* ChildMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
	case TitleKey::Wife:
		return new Child((!this->IsMale()) ? Gender::Male : Gender::Female, this->isMaleMe);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		return new SGrandSon(Gender::Male, this->isMaleMe);
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		return new SGrandSon(Gender::Female, this->isMaleMe);
	default:
		cout << "broken ChildMate\n";
		break;
	}
}
string ChildMate::getTitle() {
	return (!this->IsMale()) ? title[0] : title[1];
}

SGrandSon::SGrandSon(Gender g, bool isMale) :Person(g)
{
	this->isMaleMe = isMale;
}
Person* SGrandSon::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new Child(Gender::Male, true);
	case TitleKey::Mother:
		return new ChildMate(Gender::Female, this->isMaleMe);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new SGrandSon(Gender::Male, this->isMaleMe);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new SGrandSon(Gender::Female, this->isMaleMe);
	default:
		cout << "broken SGrandSon\n";
		break;
	}
}
string SGrandSon::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

DGrandSon::DGrandSon(bool isMale) :Person()
{
	this->isMaleMe = isMale;
}
Person* DGrandSon::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new ChildMate(Gender::Male, this->isMaleMe);
	case TitleKey::Mother:
		return new Child(Gender::Female, false);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new DGrandSon(this->isMaleMe);
	default:
		cout << "broken DGrandSon\n";
		break;
	}
}
string DGrandSon::getTitle() {
	return this->title;
}

Mate::Mate(Gender g) :Person(g)
{
}
Mate::Mate(Gender g, bool isMale) : Person(g)
{
	this->isMaleMe = isMale;
}
Person* Mate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		if (this->IsMale()) {
			return new HGrandParent(Gender::Male);
		}
		else {
			return new WGrandParent(Gender::Male);
		}
	case TitleKey::Mother:
		if (this->IsMale()) {
			return new HGrandParent(Gender::Female);
		}
		else {
			return new WGrandParent(Gender::Female);
		}
	case TitleKey::OldBrother:
		if (this->IsMale()) {
			return new HSibling(Gender::Male, Age::Older);
		}
		else {
			return new WSibling(Gender::Male, Age::Older);
		}
	case TitleKey::YoungBrother:
		if (this->IsMale()) {
			return new HSibling(Gender::Male, Age::Younger);
		}
		else {
			return new WSibling(Gender::Male, Age::Younger);
		}
	case TitleKey::OldSister:
		if (this->IsMale()) {
			return new HSibling(Gender::Female, Age::Older);
		}
		else {
			return new WSibling(Gender::Female, Age::Older);
		}
	case TitleKey::YoungSister:
		if (this->IsMale()) {
			return new HSibling(Gender::Female, Age::Younger);
		}
		else {
			return new WSibling(Gender::Female, Age::Younger);
		}
	case TitleKey::Husband:
		return new Me(Gender::Male);
	case TitleKey::Wife:
		return new Me(Gender::Female);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		return new Child(Gender::Male, !(this->IsMale()));
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		return new Child(Gender::Female, !(this->IsMale()));
	default:
		cout << "broken Mate\n";
		break;
	}
}
string Mate::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

HGrandParent::HGrandParent(Gender g) :Person(g)
{
}
Person* HGrandParent::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new HGrandParent(Gender::Male);
	case TitleKey::Wife:
		return new HGrandParent(Gender::Female);
	case TitleKey::OldSon:
		return new HSibling(Gender::Male, Age::Older);
	case TitleKey::YoungSon:
		return new HSibling(Gender::Male, Age::Younger);
	case TitleKey::OldDaughter:
		return new HSibling(Gender::Female, Age::Older);
	case TitleKey::YoungDaughter:
		return new HSibling(Gender::Female, Age::Younger);
	default:
		cout << "broken HGrandParent\n";
		break;
	}
}
string HGrandParent::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

HSibling::HSibling(Gender g, Age a) :Person(g, a)
{
}
Person* HSibling::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new HGrandParent(Gender::Male);
	case TitleKey::Mother:
		return new HGrandParent(Gender::Female);
	case TitleKey::OldBrother:
		return new HSibling(Gender::Male, Age::Older);
	case TitleKey::YoungBrother:
		return new HSibling(Gender::Male, Age::Younger);
	case TitleKey::OldSister:
		return new HSibling(Gender::Female, Age::Older);
	case TitleKey::YoungSister:
		return new HSibling(Gender::Female, Age::Younger);
	case TitleKey::Husband:
		return new HSiblingMate(Gender::Male, (this->IsOlder()) ? Age::Older : Age::Younger);
	case TitleKey::Wife:
		return new HSiblingMate(Gender::Female, (this->IsOlder()) ? Age::Older : Age::Younger);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		if (this->IsMale()) {
			return new HBrotherChild(Gender::Male, this->IsOlder());
		}
		else {
			return new HSisterChild(Gender::Male, this->IsOlder());
		}
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		if (this->IsMale()) {
			return new HBrotherChild(Gender::Female, this->IsOlder());
		}
		else {
			return new HSisterChild(Gender::Female, this->IsOlder());
		}
	default:
		cout << "broken HSibling\n";
		break;
	}
}
string HSibling::getTitle() {
	if (this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

HSiblingMate::HSiblingMate(Gender g, Age a) :Person(g, a)
{
}
Person* HSiblingMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new HSibling(Gender::Male, this->age);
	case TitleKey::Wife:
		return new HSibling(Gender::Female, this->age);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		if (this->IsMale()) {
			return new HSisterChild(Gender::Male, this->IsOlder());
		}
		else {
			return new HBrotherChild(Gender::Male, this->IsOlder());
		}
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		if (this->IsMale()) {
			return new HSisterChild(Gender::Female, this->IsOlder());
		}
		else {
			return new HBrotherChild(Gender::Female, this->IsOlder());
		}
	default:
		cout << "broken HSiblingMate\n";
		break;
	}
}
string HSiblingMate::getTitle() {
	if (!this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

HSisterChild::HSisterChild(Gender g, bool isBig) :Person(g)
{
	this->isBigSister = isBig;
}
Person* HSisterChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new HSiblingMate(Gender::Male, (isBigSister) ? Age::Older : Age::Younger);
	case TitleKey::Mother:
		return new HSibling(Gender::Female, (isBigSister) ? Age::Older : Age::Younger);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new HSisterChild(Gender::Male, this->isBigSister);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new HSisterChild(Gender::Female, this->isBigSister);
	default:
		cout << "broken SisterChild\n";
		break;
	}
}
string HSisterChild::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

HBrotherChild::HBrotherChild(Gender g, bool isBig) :Person(g)
{
	this->isBigBrother = isBig;
}
Person* HBrotherChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new HSibling(Gender::Male, (isBigBrother) ? Age::Older : Age::Younger);
	case TitleKey::Mother:
		return new HSiblingMate(Gender::Female, (isBigBrother) ? Age::Older : Age::Younger);
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new HBrotherChild(Gender::Male, isBigBrother);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new HBrotherChild(Gender::Female, isBigBrother);
	default:
		cout << "broken BrotherChild\n";
		break;
	}
}
string HBrotherChild::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

WGrandParent::WGrandParent(Gender g) :Person(g)
{
}
Person* WGrandParent::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new WGrandParent(Gender::Male);
	case TitleKey::Wife:
		return new WGrandParent(Gender::Female);
	case TitleKey::OldSon:
		return new WSibling(Gender::Male, Age::Older);
	case TitleKey::YoungSon:
		return new WSibling(Gender::Male, Age::Younger);
	case TitleKey::OldDaughter:
		return new WSibling(Gender::Female, Age::Older);
	case TitleKey::YoungDaughter:
		return new WSibling(Gender::Female, Age::Younger);
	default:
		cout << "broken WGrandParent\n";
		break;
	}
}
string WGrandParent::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}

WSibling::WSibling(Gender g, Age a) :Person(g, a)
{
}
Person* WSibling::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		return new WGrandParent(Gender::Male);
	case TitleKey::Mother:
		return new WGrandParent(Gender::Female);
	case TitleKey::OldBrother:
		return new WSibling(Gender::Male, Age::Older);
	case TitleKey::YoungBrother:
		return new WSibling(Gender::Male, Age::Younger);
	case TitleKey::OldSister:
		return new WSibling(Gender::Female, Age::Older);
	case TitleKey::YoungSister:
		return new WSibling(Gender::Female, Age::Younger);
	case TitleKey::Husband:
		return new WSiblingMate(Gender::Male, this->age);
	case TitleKey::Wife:
		return new WSiblingMate(Gender::Female, this->age);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		return new WSiblingChild(Gender::Male, this->IsMale(), this->IsOlder());
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		return new WSiblingChild(Gender::Female, this->IsMale(), this->IsOlder());
	default:
		cout << "broken WSibling\n";
		break;
	}
}
string WSibling::getTitle() {
	if (this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

WSiblingMate::WSiblingMate(Gender g, Age a) :Person(g, a)
{
}
Person* WSiblingMate::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Husband:
		return new WSibling(Gender::Male, this->age);
	case TitleKey::Wife:
		return new WSibling(Gender::Female, this->age);
	case TitleKey::OldSon:
	case TitleKey::YoungSon:
		return new WSiblingChild(Gender::Male, !this->IsMale(), this->IsOlder());
	case TitleKey::OldDaughter:
	case TitleKey::YoungDaughter:
		return new WSiblingChild(Gender::Female, !this->IsMale(), this->IsOlder());
	default:
		cout << "broken WSiblingMate\n";
		break;
	}
}
string WSiblingMate::getTitle() {
	if (!this->IsMale()) {
		return (this->IsOlder()) ? title[0] : title[1];
	}
	else {
		return (this->IsOlder()) ? title[2] : title[3];
	}
}

WSiblingChild::WSiblingChild(Gender g, bool isMale, bool isBig) :Person(g)
{
	this->isMaleSibling = isMale;
	this->isBigSibling = isBig;
}
Person* WSiblingChild::getPersonWithRelation(TitleKey t) {
	switch (t)
	{
	case TitleKey::Father:
		if (isMaleSibling)
		{
			return new WSibling(Gender::Male, (isBigSibling) ? Age::Older : Age::Younger);
		}
		else {
			return new WSiblingMate(Gender::Male, (isBigSibling) ? Age::Older : Age::Younger);
		}
	case TitleKey::Mother:
		if (isMaleSibling)
		{
			return new WSiblingMate(Gender::Female, (isBigSibling) ? Age::Older : Age::Younger);
		}
		else {
			return new WSibling(Gender::Female, (isBigSibling) ? Age::Older : Age::Younger);
		}
	case TitleKey::OldBrother:
	case TitleKey::YoungBrother:
		return new WSiblingChild(Gender::Male, this->isMaleSibling, this->isBigSibling);
	case TitleKey::OldSister:
	case TitleKey::YoungSister:
		return new WSiblingChild(Gender::Female, this->isMaleSibling, this->isBigSibling);
	default:
		cout << "broken WSiblingChild\n";
		break;
	}
}
string WSiblingChild::getTitle() {
	return (this->IsMale()) ? title[0] : title[1];
}


class QueryParser
{
public:
	static vector<TitleKey> parse(vector<wstring> raw) {
		vector<TitleKey> keys;
		for (auto& e : raw)
		{
			if (e == L"爸爸")
			{
				keys.push_back(TitleKey::Father);
			}
			else if (e == L"媽媽") {
				keys.push_back(TitleKey::Mother);
			}
			else if (e == L"哥哥")
			{
				keys.push_back(TitleKey::OldBrother);
			}
			else if (e == L"弟弟")
			{
				keys.push_back(TitleKey::YoungBrother);
			}
			else if (e == L"姊姊")
			{
				keys.push_back(TitleKey::OldSister);
			}
			else if (e == L"妹妹")
			{
				keys.push_back(TitleKey::YoungSister);
			}
			else if (e == L"丈夫")
			{
				keys.push_back(TitleKey::Husband);
			}
			else if (e == L"妻子")
			{
				keys.push_back(TitleKey::Wife);
			}
			else if (e == L"兒子")
			{
				keys.push_back(TitleKey::OldSon);
			}
			else if (e == L"兒子(較年長)")
			{
				keys.push_back(TitleKey::OldSon);
			}
			else if (e == L"兒子(較年輕)")
			{
				keys.push_back(TitleKey::YoungSon);
			}
			else if (e == L"女兒")
			{
				keys.push_back(TitleKey::OldDaughter);
			}
			else if (e == L"女兒(較年長)")
			{
				keys.push_back(TitleKey::OldDaughter);
			}
			else if (e == L"女兒(較年輕)")
			{
				keys.push_back(TitleKey::YoungDaughter);
			}
			else if (e == L"我")
			{
				keys.push_back(TitleKey::MaleMe);
			}
			else if (e == L"我(男)")
			{
				keys.push_back(TitleKey::MaleMe);
			}
			else if (e == L"我(女)")
			{
				keys.push_back(TitleKey::FemaleMe);
			}
		}
		return keys;
	}
};
class QuerySolver
{
public:
	static void solve(vector<TitleKey> query) {
		Person* self = new Me();
		for (auto& e : query) {
			self = self->getPersonWithRelation(e);
		}
		cout << self->getTitle() << '\n';
	}
};
class FileReader {
private:
	static inline void rtrim(wstring& s) {
		s.erase(find_if(s.rbegin(), s.rend(), [](wchar_t ch) { return !(ch == L'\r'); }).base(), s.end());
	}
public:
	static vector<wstring> Read(wifstream& file) {
		// locale ch(std::locale(), new codecvt_utf8<wchar_t>);
		locale ch("zh_TW");
		wcin.imbue(ch);
		wcout.imbue(ch);
		wchar_t wc = L'的';
		wstring str;
		wstring sub;
		vector<wstring> data;

		if (getline(file, str, L'\n'))
		{
			rtrim(str);
			wstringstream ss(str);
			while (getline(ss, sub, wc))
				data.push_back(sub);
		}
		return data;
	}
};
int main(int argc, char* argv[])
{
	wifstream fin;
	//locale loc(std::locale(), new codecvt_utf8<wchar_t>);
	//fin.imbue(loc);
	fin.imbue(locale("zh_TW"));
	fin.open(argv[1], std::ifstream::binary);
	while (true)
	{
		vector<wstring> raw = FileReader::Read(fin);
		if (raw.empty()) break;
		vector<TitleKey> keys = QueryParser::parse(raw);
		QuerySolver::solve(keys);

	}
}