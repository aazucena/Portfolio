/**
 * Assignment 4
 * Made by Aldrin Azucena
 * University Of Lethbridge
 * Data Structures and Algorithms - CPSC3620
 * SID: 01220471
 * Created on March 16th, 2020
 */
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

//node data structure for BST
struct Node {
   int data;
   struct Node* left;
   struct Node* right;
};

class BST {
  public:
   //Constructor for Binary Tree
   BST() {
      root = nullptr;
   }

   //Destructor for Binary Tree
   virtual ~BST(){
      removeTree(root);
   }

   //external function that inserts value to BST
   void insert(int data);

   //external function that displays BST
   void display();
   
   //external function that compares two BSTs
   bool similar(BST end);

  private:
   Node* root;

   //internal function that compares two binary trees
   bool isSimilar(Node *head, Node *goal);
	
   //internal function that displays elements
   void printElements(Node* head);

   //inserts function that inserts value to BST
   Node* insert(Node* head, int data);

   //utility for creating nodes
   Node* addNode(int val);

   //remove BST for memory deallocation
   Node* removeTree(Node *n);

};

#endif // BST_H_INCLUDED
