//LIBRARIES
#include <iostream>

//CLASSES


class Address{
	private:
		//Address Informations
		unsigned int streetnumber;
		std::string streetname, zipcode, city, country;

	public:
		//Constructor
		Address(unsigned int _streetnumber, std::string _streetname, std::string _zipcode, std::string _city, std::string _country){
			streetnumber = _streetnumber;
			streetname = _streetname;
			zipcode = _zipcode;
			city = _city;
			country = _country;
		}
	
		//Destructor
		~Address(){}
	
		//GET & SET

};

class Person{
	private:
		//Person Informations
		std::string firstname, name;
		unsigned int age;
		Address address = Address(0,"","","","");
		std::string email;
		unsigned int phone;
			
	
		//Person Counters
		unsigned int count=0;
		
	
	public:
		//Constructor
		Person(std::string _firstname, std::string _name, unsigned int _age, unsigned int _streetnumber, std::string _streetname, std::string _zipcode, std::string _city, std::string _country, std::string _email, unsigned int _phone){
			firstname = _firstname;
			name = _name;
			age = _age;
			address = Address(_streetnumber, _streetname, _zipcode, _city, _country);
			email = _email;
			phone = _phone;

			count++;
		}
	
		//Destructor
		~Person(){count--;}
	
		//GET & SET
			void setFirstName(std::string val){firstname = val;}
			std::string getFirstname(){return firstname;}
			
			void setName(std::string val){name = val;}
			std::string getName(){return name;}
	
		//PRINT
			void printFirstName(){std::cout << firstname << std::endl;}
			void printName(){std::cout << 	name << std::endl;}
			void printAge(){std::cout << 	age << std::endl;}
			//void printAddress(){std::cout << address;}
			void printEmail(){std::cout << 	email << std::endl;}
			void printPhone(){std::cout << 	phone << std::endl;}

			
			void printPerson(){
				printFirstName();
				printName();
				printAge();
				printEmail();
				printPhone();
			};
		
};

//PROGRAM
int main(){
	
	Person first = Person("Henri", "Respaud", 21, 4,"Allée Jacques Brel", "93160", "Noisy-le-Grand", "France", "henri@gmail.com", 3352602695);

	first.printPerson();
	
	return 0;
}