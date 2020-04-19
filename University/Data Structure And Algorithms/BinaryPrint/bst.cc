/**
 * Assignment 3
 * Made by Aldrin Azucena
 * University Of Lethbridge
 * Data Structures and Algorithms - CPSC3620
 * SID: 01220471
 * Created on February 24th, 2020
 */
#include <iostream>
#include <bits/stdc++.h>
#include "bst.h"

Node* BST::addNode(int val) {
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

Node* BST::insert(Node* head, int data) {
   if(head == NULL)
      head = addNode(data);

   else if (data < head->data)
      head->left = insert(head->left, data);

   else if (data > head->data)
      head->right = insert(head->right, data);

   return head;
}

Node* BST::removeTree(Node* n){
   if(n){
      removeTree(n->left);
      removeTree(n->right);
      delete node;
   }
}

void BST::printElements(Node* head, int min) {
   if(head == NULL)
      return;

   printElements(head->left, min);

   if(head->data > min)
      std::cout << head->data << " ";

   printElements(head->right, min);
}

void BST::insert(int data) {
   root = insert(root, data);
}

void BST::display(int data) {
   printElements(root, data);
}

int main() {
   BST b;
   int n, min, input = 0;
   char cmd;

   std::cout << "Welcome to the Binary Search Tree program where it will print the binary tree values based on the minimum value from the user.\n" << std::endl;

   do{
      std::cout << "Program Menu:\n"
		<< "Start [S]\n"
		<< "Help [H]\n"
		<< "Exit [E]\n" << std::endl;
      std::cout << "Your command: ";
      std::cin >> cmd;
      std::cin.ignore();
      if(cmd == 'S'||cmd == 's'){
	    std::cout << "How many values will be in your Binary Search Tree? " << std::endl;
	    std::cin >> n;
	    if(n <= 0){
	       std::cout << "You are literally want to type nothing lol..." << std::endl;
	    }
	    else{
	       std::cout << "Type your values: " << std::endl;
	       for (int i = 0; i < n; i++){
		  std::cin >> input;
		  b.insert(input);
	       }
	       std::cout << "Enter your minimum value: " << std::endl;
	       std::cin >> min;

	       std::cout << "The BST values that are minimum number of " << min << " :" << std::endl;

	       b.display(min);
	       
	       std::cout << std::endl;
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
