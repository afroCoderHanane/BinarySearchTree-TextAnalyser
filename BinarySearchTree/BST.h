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
   int occurence;//saving occurrences
};

template <class T>
class BSTree
{
   private:
      node<T> *root;
      char charindex;// saving the first index of letter
      int countnodes;//store the number of nodes in the tree
      int specialnodes;//stores the number of countnodes in the tree which are greater than 3char 
      int phrases;
      int characters ;
      int words; //number of words total
      int phrasewords;//store the numbers of words in a phrase
      int longword; // number of longwords
      int total;  //container to calculate average
      vector<int>avewords; //receptacle of phrasewords per sentence
      vector<int>avechar; //receptacle of char per word
      int longsen;//numbers of long sentence 
      

    protected:  
      void printInorder (node<T> *);
      void destroyTree (node<T> * &);
      void copyTree (node<T> *&, node<T> *);
      int numNode(node<T>*); //number of node 
      int special(node<T>*); //function that take public special root 
      int getLongSentences();
      int getLongWord();
      int getAveSentence();
      int getAveWord();
      int getNumWord();
   public:
      BSTree();
      ~BSTree();
      BSTree (const BSTree<T> &);
      void operator= (const BSTree<T> &);
      void pushToTree();
      void insertItem (T);
      bool searchItem (T);
      void print();
      void deleteAll();
      bool isEmpty(); 
      int numNode();
      int special();//return the number of unique data above three char

};