#include <iostream>
#include <string>
#include "List.h"
#include "secureList.h"


using namespace std;




int main(void){
	
	List* testList = new List();

	cout<<"List Class test"<<endl;
	cout<<"Add some text to List Object" << endl;

	testList->add("Hello, My name is..");
	testList->add("Oh, Nice to meet you!");
	testList->add("Make some nosie~");
	testList->add("How about that?");

	cout << "======printAll======" << endl;

	testList->printAll();
	cout << "====save to file=====" << endl;
	testList->saveFile("logfile.txt");

	cout << "==SecureList Class test ===" <<endl;
	List* myList = new SecureList();
	cout << "==load previous file and add some more=="<<endl;
	myList->loadFile("logfile.txt");

	myList->add("Compare to normal List");
	myList->add("This List encrypt the text");
	myList->add("How about that?");

	cout << "=====printAll======" << endl;
	myList->printAll();
	cout << "=====printDecryptAll=====" << endl;
	((SecureList*)myList)->printDecryptAll();
	cout << "=====Thank you======"<<endl;


	return 0;
}
