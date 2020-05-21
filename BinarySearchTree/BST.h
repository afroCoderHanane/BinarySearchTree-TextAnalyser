#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

template <class T>
struct node
{
   T info;
   node *left;
   node *right;
   int occurence;
};

template <class T>
class BSTree
{
   private:
      node<T> *root;
       vector<string> word;
       char charindex;
    vector<int>count;
    int index;
    int length;
      void printPreorder (node<T> *);
      void printPostorder (node<T> *);
      void printInorder (node<T> *);
      void destroyTree (node<T> * &);
      void copyTree (node<T> *&, node<T> *);
      int numNode(node<T>*);
      int special(node<T>*);
      void repeatO (node<T> *p);
   public:
      BSTree();
      ~BSTree();
      BSTree (const BSTree<T> &);
      void operator= (const BSTree<T> &);
      void insertItem (T);
      void deleteItem (T);
      void deleteItem (node<T> *&, T);
      void DeleteNode (node<T> *&); 
      T  getPredecessor ( node<T> * );
      bool searchItem (T);
      void printPreorder();
      void printPostorder();
      void printInorder();
      bool isEmpty(); 
      int numNode();
      int special();
      void repeat( );

};