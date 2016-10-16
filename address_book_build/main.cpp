//LIBRARIES
#include <iostream>
#include <cstdio>
#include <vector>


//CLASSES
class Menu{
	private :

	public :

	static void welcomeMessage(){
		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << "| Welcome to the Address Book Program made by Henri Respaud-Bouny |" << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
	}

	static int goodbyeMessage(int *loop){
		*loop = 0;
		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << "|   Thank you for using my Address Book program! See you soon!    |                |" << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
		return *loop;
	}

	static void displayMainMenu(){
		std::cout << "MAIN MENU" << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << "1) Show Contacts  	2) Search Contacts" << std::endl;
		std::cout << "3) Add Contact  	4) Remove Contact" << std::endl;
		std::cout << "5) Edit Contact  	6) Export" << std::endl;
		std::cout << "7) Exit" << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
	}

	static int actionMainMenu(){
		int answer;
		std::cout << "Type the figure corresponding to the action you want to make :";
		std::cin >> answer; 
		return answer;
	}
};

class Address{
	private:
		//Address Informations
		unsigned int streetnumber;
		std::string streetname, zipcode, city, country;

	public:
		//Constructor
		Address(unsigned int _streetnumber, 
				std::string _streetname, 
				std::string _zipcode, 
				std::string _city, 
				std::string _country)
		{
			streetnumber = _streetnumber;
			streetname = _streetname;
			zipcode = _zipcode;
			city = _city;
			country = _country;
		}
	
		//Destructor
		~Address(){}
	
		//GET & SET
		void setStreetnumber(unsigned int val){streetnumber = val;}
		unsigned int getStreetnumber(){return streetnumber;}

		void setStreetname(std::string val){streetname = val;}
		std::string getStreetname(){return streetname;}

		void setZipcode(std::string val){zipcode = val;}
		std::string getZipcode(){return zipcode;}

		void setCity(std::string val){city = val;}
		std::string getCity(){return city;}

		void setCountry(std::string val){country = val;}
		std::string getCountry(){return country;}

		//PRINT
		void printStreetnumber(){std::cout << streetnumber << std::endl;}
		void printStreetname(){std::cout << streetname << std::endl;}
		void printZipcode(){std::cout << zipcode << std::endl;}
		void printCity(){std::cout << city << std::endl;}
		void printCountry(){std::cout << country << std::endl;}

			
		void printAddress(){
			printStreetnumber();
			printStreetname();
			printZipcode();
			printCity();
			printCountry();
		}


		// ADD
		static Address addAddress(){
				Address new_address = Address(0,"","","","");
				std::string answer;

				std::cout << "Enter Street number :";
				getline(std::cin, answer);
				new_address.streetnumber = std::stoi(answer, 0, 10);
				std::cout << std::endl;

				std::cout << "Enter Street name :";
				getline(std::cin, answer);
				new_address.streetname = answer;
				std::cout << std::endl;

				std::cout << "Enter ZipCode :";
				getline(std::cin, answer);
				new_address.zipcode = answer;
				std::cout << std::endl;

				std::cout << "Enter City :";
				getline(std::cin, answer);
				new_address.city = answer;
				std::cout << std::endl;

				std::cout << "Enter Country :";
				getline(std::cin, answer);
				new_address.country = answer;
				std::cout << std::endl;


				return new_address;
		}

};

class Person{
	private:
		//Person Informations
		std::string firstname, name, email, phone;
		unsigned int age;
		Address address = Address(0,"","","","");
			
	
		//Person Counters
		unsigned int count=0;
		
	
	public:
		//Constructor
		Person(	std::string _firstname, 
				std::string _name, 
				unsigned int _age, 
				unsigned int _streetnumber, 
				std::string _streetname, 
				std::string _zipcode, 
				std::string _city, 
				std::string _country, 
				std::string _email, 
				std::string _phone)
		{
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

			void setAge(unsigned int val){age = val;}
			unsigned int getAge(){return age;}

			Address getAddress(){return address;}

			void setEmail(std::string val){email = val;}
			std::string getEmail(){return email;}

			void setPhone(std::string val){phone = val;}
			std::string getPhone(){return phone;}


	
		//PRINT
			void printFirstName(){std::cout << firstname << std::endl;}
			void printName(){std::cout << 	   name << std::endl;}
			void printAge(){std::cout << 	   age << std::endl;}
			void printEmail(){std::cout << 	   email << std::endl;}
			void printPhone(){std::cout << 	   phone << std::endl;}

			
			void printPerson(Person contact){
				contact.printFirstName();
				contact.printName();
				contact.printAge();
				contact.address.Address::printAddress();
				contact.printEmail();
				contact.printPhone();
			};

			
			//ADD
			static void addContact(std::vector<Person> &contact_list){
				Person new_contact = Person("","",0,0,"","","","","","");
				std::string answer;

				std::cout << std::endl;
				std::cout << "Enter Contact Information" << std::endl;
				std::cout << std::endl;

				std::cin.ignore();

				std::cout << "Enter First name :";
				getline(std::cin, answer);
				new_contact.firstname = answer;
				std::cout << std::endl;

				std::cout << "Enter Name :";
				getline(std::cin, answer);
				new_contact.name = answer;
				std::cout << std::endl;

				std::cout << "Enter Age :";
				getline(std::cin, answer);
				new_contact.age = std::stoi(answer, 0, 10);
				std::cout << std::endl;

				new_contact.address = Address::addAddress();

				std::cout << "Enter Email Address :";
				getline(std::cin, answer);
				new_contact.email = answer;
				std::cout << std::endl;

				std::cout << "Enter Phone Number :";
				getline(std::cin, answer);
				new_contact.phone = answer;
				std::cout << std::endl;

				contact_list.push_back(new_contact);
			}

			//SHOW
			static void showContacts(std::vector<Person> &contact_list){

				if(contact_list.size() < 1) {
					std::cout << "No Contact !" << std::endl;
				} 
				else{
					for (unsigned int i = 0 ; i < contact_list.size() ; i++){
						std::cout << contact_list[i].firstname << std::endl;
					}
				}
			}

			//SEARCH
			/******************************************************************
			void findContact(vector<AddressBook> &contact_list) {

			}	
			********************************************************************/

			//REMOVE
			static void removeContact(std::vector<Person> &contact_list){
				int index = 0;
				contact_list.erase(contact_list.begin()+(index-1));
				std::cout << "DELETE !" << std::endl;
			}

			//EDIT
			static void editContact(std::vector<Person> &contact_list){

				int index=0;
				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New First name :";
				getline(std::cin, answer);
				contact_list[index].firstname = answer;
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}

			//EXPORT

			

		
};

//PROGRAM
int main(){
	int loop = 1;

	//Menu Initialisation
	int menu_answer = 0;

	//Contact List
	std::vector<Person> contact_list;


	while (loop){
		Menu::welcomeMessage();
		Menu::displayMainMenu();
		menu_answer = Menu::actionMainMenu();

		if(menu_answer == 1)
			Person::showContacts(contact_list);

		if(menu_answer == 3)
			Person::addContact(contact_list);

		if(menu_answer == 4)
			Person::removeContact(contact_list);

		if(menu_answer == 5)
			Person::editContact(contact_list);

		if(menu_answer == 7)
			Menu::goodbyeMessage(&loop);
	}
	
	return 0;
}