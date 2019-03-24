#include <cstdio>

#include <string>

class PersonData{
private:
	std::string _lastName;
	std::string _firstName;
	std::string _address;
	std::string _city;
	std::string _state;
	int _zip;
	std::string _phone;
	PersonData() {};

protected:
	PersonData(const std::string & l, const std::string & f, const std::string & add,
		const std::string & c, const std::string & s, const int & z, const std::string & p)
		: _lastName(l), _firstName(f), _address(add), _city(c), _state(s), _zip(z), _phone(p) {

	}

public:
	void display() const;
	const std::string & lastName() const { return _lastName; }
	const std::string & firstName() const{ return _firstName; }
	const std::string & address() const { return _address; }
	const std::string & city() const { return _city; }
	const std::string & state() const { return _state; }
	const int & zip() const { return _zip; }
	const std::string & phone() const { return _phone; }

};

void PersonData::display() const{
	printf("Name: %s, %s\nAddress: %s, %s, %s, %d\nPhone Number: %s\n", _lastName.c_str(), _firstName.c_str(), _address.c_str(),
			_city.c_str(), _state.c_str(), zip(), _phone.c_str());
}

class CustomerData : public PersonData {
	int customerNumber;
	bool mailingList;

public:
	CustomerData(std::string l, std::string f) : PersonData(l, f, "3801 W Temple Ave", "Pomona", "CA", 91768, "909-869-7659"),  customerNumber(0), mailingList(true) {

	};
	int number(){
		return ++customerNumber;
	}
	std::string mail(){
		std::string list;
		if((mailingList = false)){
			list = "No";
		}else{
			list = "Yes";
		}
		return list;
	}
};

int main(){
	CustomerData c("Hong", "Jaewon");
	c.display();

	printf("Customer number is: %d\n", c.number());
	printf("Mailing List: %s", c.mail().c_str());

}
