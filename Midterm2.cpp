#include <iostream>
#include <vector>
class Human{
	std::string name;
	int age;
	char sex;
	Human() {};
protected:
	Human(std::string n, int a, char s){
		name = n;
		age = a;
		sex = s;
	}
	virtual ~Human() {};
public:
	void setName(std::string n){
		name = n;
	}
	void setAge(int a){
		age = a;
	}
	void setSex(char s){
		sex = s;
	}
	std::string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	char getSex(){
		return sex;
	}

};

class Child : public Human{
	std::string momName;
	std::string dadName;
	int allowance;
	//Child() {};
public:
	Child(std::string m, std::string d, std::string n, int a, char s) : Human(n, a, s), allowance(0){
		momName = m;
		dadName = d;
	}
	virtual ~Child(){};
	friend class Parent;
	int getAllowance() const{
		return allowance;
	}
	void printParent(){
		std::cout << "Mom: " << momName << std::endl;
		std::cout << "Dad: " << dadName << std::endl;
	}
};

class Parent : public Human{
	std::vector <std::string> children;
	//Parent() {};
public:
	Parent(std::string n, int a, char s) : Human(n, a, s){

	}
	virtual ~Parent(){};
	void printChild(std::vector <std::string> & c){
		for(int i = 0; i < c.size(); i++){
			std::cout << c.at(i) << " ";
		}
	}
	void setChild(Child & c){
		children.push_back(c.getName().c_str());
	}
	void setChildAllowance(int a, Child &c){
		c.allowance = a;

	}
};

void printInfo(Human &h){
	std::cout << "Name: " << h.getName() << std::endl;
	std::cout << "Age: " << h.getAge() << std::endl;
	std::cout << "Sex: " << h.getSex() << std::endl;
}
int main(){
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Child Lisa("March", "Homer", "Lisa", 12, 'F');
	Child Bart("March", "Homer", "Bart", 10, 'F');
	Child Maggie("March", "Homer", "Maggie", 3, 'F');

	Homer.setChild(Lisa);
	Homer.setChild(Bart);
	Homer.setChild(Maggie);
	March.setChild(Lisa);
	March.setChild(Bart);
	March.setChild(Maggie);

	std::cout << "Bart's allowance: $" << Bart.getAllowance() << std::endl;
	Homer.setChildAllowance(5, Bart);
	std::cout << "Bart's allowance: $" << Bart.getAllowance() << std::endl;
	Bart.printParent();
	printInfo(March);
	printInfo(Lisa);

}

