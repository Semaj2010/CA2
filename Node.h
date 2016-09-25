#pragma once
#include <string>

using namespace std;

/*Node Class*/
class Node {
 private:
	 Node *prevNode;
	 Node *nextNode;
	 string str;
 public:
	 void setString(string str){
		this->str = str;
	 }
	 void setNextNode(Node* nextNode){
		this->nextNode = nextNode;
	 }
	 void setPrevNode(Node* prevNode){
		 this->prevNode = prevNode;
	 }
	 string getString(){
		 return this->str;
	 }
	 Node* getNextNode(){
		return this->nextNode;
	 }
	 Node* getPrevNode(){
		 return this->prevNode;
	 }
};
