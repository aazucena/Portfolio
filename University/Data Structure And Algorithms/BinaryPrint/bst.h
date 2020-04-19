/**
 * Assignment 3
 * Made by Aldrin Azucena
 * University Of Lethbridge
 * Data Structures and Algorithms - CPSC3620
 * SID: 01220471
 * Created on February 24th, 2020
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
      root = NULL;
   }
   
   //Destructor for Binary Tree
   virtual ~BST(){
      removeTree(root);
   }
   
   //external function that inserts value to BST
   void insert(int data);
   
   //external function that displays BST
   void display(int data);
   
  private:
   Node* root;
   
   //internal function that displays elements
   void printElements(Node* head, int min);
   
   //inserts function that inserts value to BST
   Node* insert(Node* head, int data);
   
   //utility for creating nodes
   Node* addNode(int val);
   
   //remove BST for memory deallocation
   Node* removeTree(Node *n);
   
};

#endif // BST_H_INCLUDED
