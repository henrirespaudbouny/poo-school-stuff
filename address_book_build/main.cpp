//COMPILE WITH : g++ -Wall main.cpp -std=c++11 -o address_book.exe

//LIBRARIES
#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>


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
		std::cout << "|   Thank you for using my Address Book program! See you soon!    |" << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
		return *loop;
	}

	static void displayMainMenu(){
		std::cout << "MAIN MENU" << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << "1) SHOW  	2) SEARCH" << std::endl;
		std::cout << "3) ADD  	4) SAVE FILE" << std::endl;
		std::cout << "5) EXIT"	<< std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
	}

	static int actionMainMenu(){
		int answer;
		std::cout << "Type the figure corresponding to the action you want to make :";
		std::cin >> answer; 
		return answer;
	}
	
	static int callToActionMenu(){
		std::string answer;		

		std::cout << "1) ADD  	2) EXIT" << std::endl;
		std::cout << "YOUR CHOICE :";
		getline(std::cin, answer);
		int int_answer = std::stoi(answer, 0, 10);
		
		return int_answer;
	}

	static int callToActionMenuWithContact(){
		std::string answer;		

		std::cout << "1) SHOW MORE 		2) ADD    	3) REMOVE   	4) SHOW CONTACT		5) EXIT" << std::endl;
		std::cout << "YOUR CHOICE :";
		getline(std::cin, answer);
		int int_answer = std::stoi(answer, 0, 10);
		
		return int_answer;
	}

	static int showMore(){
		std::string answer;		

		std::cout << "PLEASE CHOOSE CONTACT (corresponding figure)" << std::endl;
		std::cout << "YOUR CHOICE :";
		getline(std::cin, answer);
		int int_answer = std::stoi(answer, 0, 10);
		
		return int_answer;
	}

	static int actionMenuShowMore(){
		std::string answer;		

		std::cout << "1) EDIT 		2) REMOVE 		3) EXIT" << std::endl;
		std::cout << "YOUR CHOICE :";
		getline(std::cin, answer);
		int int_answer = std::stoi(answer, 0, 10);
		
		return int_answer;
	}

	static int menuEdit(){
		std::string answer;		

		std::cout << "WHAT DO YOU WANT TO EDIT ?" << std::endl << std::endl;
		std::cout << "1) FIRSTNAME 		2) NAME" << std::endl;
		std::cout << "3) AGE 			4) ADDRESS" << std::endl;
		std::cout << "5) MAIL 		6) PHONE" << std::endl;
		std::cout << "7) NOTHING" << std::endl;
		std::cout << "YOUR CHOICE :";
		getline(std::cin, answer);
		int int_answer = std::stoi(answer, 0, 10);
		
		return int_answer;
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
		void printStreetnumber(){std::cout << streetnumber;}
		void printStreetname(){std::cout << streetname;}
		void printZipcode(){std::cout << zipcode;}
		void printCity(){std::cout << city;}
		void printCountry(){std::cout << country;}

		std::string getAddress() const{
			std::string streetnb = std::to_string(streetnumber);
			return streetnb + " " + streetname + " " + zipcode + " " + city+ " " + country;
		}

			
		void printAddress(){
			printStreetnumber();
			std::cout << " ";
			printStreetname();
			std::cout << std::endl;
			printZipcode();
			std::cout << " ";
			printCity();
			std::cout << std::endl;
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
			void printFirstName(){std::cout << firstname;}
			void printName(){std::cout << 	   name;}
			void printAge(){std::cout << 	   age;}
			void printEmail(){std::cout << 	   email;}
			void printPhone(){std::cout << 	   phone;}

			
			static void printPerson(Person contact){
				contact.printFirstName();
				std::cout <<" ";
				contact.printName();
				std::cout << std::endl;
				contact.printAge();
				std::cout <<" years old" << std::endl;
				contact.address.Address::printAddress();
				std::cout << std::endl;
				contact.printEmail();
				std::cout << std::endl;
				contact.printPhone();
				std::cout << std::endl;
			};

			
			//ADD
			static void addContact(std::vector<Person> &contact_list){
				Person new_contact = Person("","",0,0,"","","","","","");
				std::string answer;
				
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
				
				std::cout << "============================ ADD CONTACT FORM =============================" << std::endl;
				std::cout << "Please enter Contact Information" << std::endl;
				std::cout << std::endl;

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

			
			//SEARCH
			static void findContactByFirstName(std::vector<Person> &contact_list){
				std::string search;
				unsigned int result = 0;

				std::cout << "===============================SEARCH===============================" << std::endl;

				std::cout << "Please Enter First name to search:";
				getline(std::cin, search);

				std::cout << std::endl;
				
				for (unsigned int i = 0 ; i < contact_list.size() ; i++){
					std::cout << "=================================================================" << std::endl;
					if(search == contact_list[i].firstname){
						result++;
						std::cout << result << "." << std::endl;
						printPerson(contact_list[i]);
					}
				}
				std::cout << "=====================================================================" << std::endl;
				if(!result)
					std::cout << "NO MATCH !" << std::endl;

			}	


			//REMOVE
			static void removeContact(std::vector<Person> &contact_list, int index){
				contact_list.erase(contact_list.begin()+(index-1));
				std::cout << "CONTACT DELETED !" << std::endl;
			}

			//EDIT
			static void editFirstName(std::vector<Person> &contact_list, int index){

				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New First name :";
				getline(std::cin, answer);
				contact_list[index-1].firstname = answer;
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}


			static void editName(std::vector<Person> &contact_list, int index){

				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New Name :";
				getline(std::cin, answer);

				contact_list[index-1].name = answer;
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}

			static void editAge(std::vector<Person> &contact_list, int index){

				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New Age :";
				getline(std::cin, answer);
				contact_list[index-1].age = std::stoi(answer, 0, 10);;
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}

			static void editAddress(std::vector<Person> &contact_list, int index){

				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New Address :";
				contact_list[index-1].address = Address::addAddress();
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}

			static void editEmail(std::vector<Person> &contact_list, int index){

				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New Email :";
				getline(std::cin, answer);

				contact_list[index-1].email = answer;
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}

			static void editPhone(std::vector<Person> &contact_list, int index){

				std::string answer;

				std::cin.ignore();

				std::cout << "Enter New Phone :";
				getline(std::cin, answer);

				contact_list[index-1].email = answer;
				std::cout << std::endl;

				std::cout << "EDIT !" << std::endl;
			}

			//SHOW
			static void showContacts(std::vector<Person> &contact_list){
				int menu_answer = 1;
				int index;
				int begin = 0;
				unsigned int max = 10;
				
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;

				std::cout << "===================LIST OF YOUR CONTACT(S)========================" << std::endl;

				if(contact_list.size() < 1) {
					std::cout << std::endl;
					std::cout << "No Contact(s) yet !" << std::endl;
					std::cout << std::endl;
					std::cout << "=================================================================" << std::endl;
					
						while(menu_answer){
							menu_answer = Menu::callToActionMenu();
							if( menu_answer == 1 ){
								Person::addContact(contact_list);
								std::cout << "=================================================================" << std::endl;
							}
							else if( menu_answer == 2 )
								return;
							else
								std::cout << "ERROR PLEASE CHOOSE AGAIN !" << std::endl;		
						}
				}
				else{
					while(menu_answer){

							if((contact_list.size()-max) > max)
								max = contact_list.size();

							for (unsigned int i = begin ; i < max ; i++){
								std::cout 	<< i+1 << "." << contact_list[i].firstname << " " << contact_list[i].name << std::endl;
							}

							std::cout << "=================================================================" << std::endl;
							menu_answer = Menu::callToActionMenuWithContact();
							if( menu_answer == 1 ){
								if(contact_list.size()>10){
									max +=10;
									begin +=10;
								}
								else{
									std::cout << "ERROR YOU DON'T HAVE MORE CONTACTS" << std::endl;
									Person::showContacts(contact_list);
								}	
							}
							else if( menu_answer == 2 ){
								Person::addContact(contact_list);
								std::cout << "=================================================================" << std::endl;
								menu_answer = Menu::callToActionMenu();
							}
							else if( menu_answer == 3 ){
								std::cout << "============================= DELETE =============================" << std::endl;
								menu_answer = Menu::showMore();
								index = menu_answer;
								Person::removeContact(contact_list, index);								
								menu_answer = Menu::callToActionMenu();

								std::cout << "=================================================================" << std::endl;
							}
							else if( menu_answer == 4 ){
								std::cout << "============================ CONTACT ============================" << std::endl;
								menu_answer = Menu::showMore();
								index = menu_answer;
								Person::printPerson(contact_list[index-1]);
								menu_answer = Menu::actionMenuShowMore();
								std::cout << "=================================================================" << std::endl;

									if( menu_answer == 1 ){
										std::cout << "============================= EDIT =============================" << std::endl;
										menu_answer = Menu::menuEdit();
											if( menu_answer == 1 )
												editFirstName(contact_list, index);
											else if( menu_answer == 2 )
												editName(contact_list, index);
											else if( menu_answer == 3 )
												editAge(contact_list, index);
											else if( menu_answer == 4 )
												editAddress(contact_list, index);
											else if( menu_answer == 5 )
												editEmail(contact_list, index);
											else if( menu_answer == 6 )
												editPhone(contact_list, index);
											else if( menu_answer == 7 )
												return;
											else
												std::cout << "ERROR PLEASE CHOOSE AGAIN !" << std::endl;
									}
									else if (menu_answer == 3){
										std::cout << "============================= DELETE =============================" << std::endl;
										menu_answer = Menu::showMore();
										index = menu_answer;
										Person::removeContact(contact_list, index);								
										menu_answer = Menu::callToActionMenu();
										std::cout << "=================================================================" << std::endl;
									}
									else if (menu_answer == 3)
										return;
									else
										std::cout << "ERROR PLEASE CHOOSE AGAIN !" << std::endl;
							}
							else if( menu_answer == 5 )
								return;
							else
								std::cout << "ERROR PLEASE CHOOSE AGAIN !" << std::endl;		
					}
				}
				
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}

			//EXPORT
			static void saveFile(const std::vector<Person> &contact_list) {

				std::string filename;
				std::ofstream outfile;

				std::string address;

				std::cout<<"Enter file name (.txt): ";

				getline(std::cin,filename);
				outfile.open(filename.c_str());


				if (!outfile.fail()){
					std::cout << "Saving Address Book to the disc " << std::endl;


					outfile << "===============CONTACT(S)=====================" << std::endl;
					for(unsigned int i = 0; i < contact_list.size(); i++){

							outfile << i+1 << "." << std::endl;
							outfile << contact_list[i].firstname << " " << contact_list[i].name << std::endl;
							outfile << contact_list[i].age << "years old" << std::endl;

							address = contact_list[i].address.Address::getAddress();
							outfile << address << std::endl;


							outfile << contact_list[i].email << std::endl;
							outfile << contact_list[i].phone << std::endl;

							outfile << "============================================" << std::endl;
						if (i < contact_list.size()-1) outfile << std::endl;
					}

				std::cout << std::endl << contact_list.size() << " Address Book written to the disc." << std::endl;
				outfile.close();
				} 
				else { 
					std::cout << "ERROR: problem with file" << std::endl;
				}
			}
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

		std::cin.ignore();

		if(menu_answer == 1)
			Person::showContacts(contact_list);

		if(menu_answer == 2){
			Person::findContactByFirstName(contact_list);
		}

		if(menu_answer == 3)
			Person::addContact(contact_list);

		if(menu_answer == 4)
			Person::saveFile(contact_list);

		if(menu_answer == 5)
			Menu::goodbyeMessage(&loop);
	}
	
	return 0;
}