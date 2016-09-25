#pragma once
#include <iostream>
#include "Node.h"
#include <fstream>
#include <string>

using namespace std;


class List{
	protected:
		Node * header;
		Node * tailer;
		int listsize;
	public:
		List(){
			initList();
		}
		/*add before tailer*/
		virtual void add(string str){
			Node* newNode = new Node();
			newNode->setString(str);

			newNode->setPrevNode(tailer->getPrevNode());
			newNode->setNextNode(tailer);
			tailer->getPrevNode()->setNextNode(newNode);
			tailer->setPrevNode(newNode);
			this->listsize ++;
		}
		/*remove by index*/
		void remove(int idx){
			int i = 0;
			Node* currentNode=header;
			for(i=0;i<listsize;i++){
				currentNode = currentNode->getNextNode();	
			}
		}
		virtual void printAll(){
			Node *temp = header->getNextNode();
			while (temp != tailer){
				cout << temp->getString() << endl;
				temp = temp->getNextNode();
			}

		}
		void saveFile(string filename){
			ofstream ofs;
			Node* currentNode;
			ofs.open(filename.c_str(), ios::out);
			if(!ofs){
				cout << "Unable to open file" << endl;
				return;
			}
			currentNode = header->getNextNode();
			while(currentNode != tailer){
				ofs << currentNode->getString() << endl; 
				currentNode = currentNode->getNextNode(); 	
			}
			ofs.close();
		}
		void loadFile(string filename){
			ifstream ifs;
			string tempString;
			ifs.open(filename.c_str());
			if(!ifs){
				cout << "Unable to open file" << endl;
				return;
			}
			while(getline(ifs,tempString)){
				this->add(tempString);
				cout << tempString << endl;
			}
			ifs.close();

		}
		void initList(){
			header = new Node();
			tailer = new Node();
			(*header).setNextNode(tailer);
			tailer->setPrevNode(header);
			this->listsize = 0;
		}
};
