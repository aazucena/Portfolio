/**
 * Assignment 4
 * Made by Aldrin Azucena
 * University Of Lethbridge
 * Data Structures and Algorithms - CPSC3620
 * SID: 01220471
 * Created on March 16th, 2020
 */
#include <iostream>
#include <bits/stdc++.h>
#include "bst.h"

Node* BST::addNode(int val) {
   struct Node* temp = new Node;
   temp->data = val;
   temp->left = nullptr;
   temp->right = nullptr;
   return temp;
}

Node* BST::insert(Node* head, int data) {
   if(head == nullptr)
      head = addNode(data);

   else if (data < head->data)
      head->left = insert(head->left, data);

   else if (data > head->data)
      head->right = insert(head->right, data);

   return head;
}

Node* BST::removeTree(Node* n){
   if(n != nullptr){
	  removeTree(n->left);
	  removeTree(n->right);
	  delete n;
   }
   n = nullptr;
}

bool BST::isSimilar(Node* head, Node* goal){
	if(head == nullptr && goal == nullptr)
		return true;
	
	if(head == nullptr && goal != nullptr)
		return false;
	
	if(head != nullptr && goal == nullptr)
		return false;
	
	if(head->data == goal->data 
	&& isSimilar(head->left, goal->left) 
	&& isSimilar(head->right, goal->right)){
		return true;
	} else {
		return false;
	}
}

void BST::printElements(Node* head) {
   if(head == nullptr)
      return;

   printElements(head->left);

   std::cout << head->data << " ";

   printElements(head->right);
}

void BST::insert(int data) {
   root = insert(root, data);
}

void BST::display() {
   printElements(root);
}

bool BST::similar(BST end) {
   return isSimilar(root, end.root);
}

int main() {
   BST b1;
   BST b2;
   int n, input1, input2 = 0;
   char cmd;

   std::cout << "Welcome to the Binary Search Tree program where it will compare the two binary trees made by user if they are similar.\n" << std::endl;

   do{
      std::cout << "Program Menu:\n"
		<< "Start [S]\n"
		<< "Help [H]\n"
		<< "Exit [E]\n" << std::endl;
      std::cout << "Your command: ";
      std::cin >> cmd;
      std::cin.ignore();
      if(cmd == 'S'||cmd == 's'){
	    std::cout << "How many values will be in your two Binary Search Trees? " << std::endl;
	    std::cin >> n;
	    if(n <= 0){
	       std::cout << "You are literally want to type nothing lol..." << std::endl;
	    }
	    else{
	       std::cout << "Type your values for Binary Tree #1: " << std::endl;
	       for (int i = 0; i < n; i++){
              std::cin >> input1;
              b1.insert(input1);
	       }
	       std::cout << std::endl;
	       std::cout << "Type your values for Binary Tree #2: " << std::endl;
	       for (int i = 0; i < n; i++){
              std::cin >> input2;
              b2.insert(input2);
	       }
			std::cout << std::endl;
		   if(b1.similar(b2)){
			   std::cout << "Both of your binary trees are similar..." << std::endl;
		   } else {
			   std::cout << "Both of your binary trees are different..." << std::endl;
		   }
		   b1.~BST();
		   b2.~BST();
	    }
      }
      else if(cmd == 'H'|| cmd == 'h'){
	    std::cout << "TL;DR:" << std::endl;
	    std::cout << "The Binary Search Tree Program is designed to search at  every node from all elements to the left of the node have a smaller key, and all elements to the right of a node have a large key. The program allows the user to enter data (integer) from standard input and construct a binary search tree, then input a minimum number that prints all elements bigger than  your input.\n" << std::endl;
      }
      else if(cmd == 'E'||cmd == 'e'){
	 std::cout << "Thanks for using my useful program. Have a very nice day..." << std::endl;
	 break;
      }
      else{
	    std::cout << "Why did you type '"
		      << cmd
		      << "'!!! Try again please..."
		      << std::endl;
      }
   }while(true);
   return 0;
}
