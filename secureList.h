#pragma once
#include <iostream>
#include "List.h"
#include <string>

using namespace std;


class SecureList :public List{
	private:
		string s_key="abcd";
	protected:
	public:
		SecureList(){

		}
		/*encrypt string and add to list*/
		void add(string str){

			List::add(encrypt(str));

		}
		void printAll(){
			cout<< "==This is encrypted text==" << endl;
			List::printAll();
			cout<<"==========================="<<endl;
		}
		void printDecryptAll(){
			Node *temp = header->getNextNode();
			while (temp != tailer){
				cout << this->decrypt(temp->getString()) << endl;
				temp = temp->getNextNode();
			}	
		}
		/*encrypt the string*/
		string encrypt(string str){
			string result = ""; 
			
			for(int i=0; i<str.length();i++){
				result += str.at(i);
				result += s_key.at(i % 4);

			}
			return result;
		}
		/*decrypt the string */
		string decrypt(string str){
			string result = "";

			for(int i=0; i<str.length();i+=2){
				result += str.at(i);

			}
			return result;

		}


};
