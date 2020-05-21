#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include"BinarySearchTree/BST.h"
#include"BinarySearchTree/BST.cpp"
using namespace std;

int main() 
{
  BSTree<string> T1;
  string item;
  int phrases=0;
  int characters =0;
  int words=0;
  int phrasewords=0;
  int longword=0;
  int total=0;
  vector<int>avewords;
  vector<int>avechar;
  int longsen =0;
  
  fstream infile;

  infile.open("Numbers.txt");

  
  while (!infile.eof())
  {
     words++;
     infile>> item;
     avechar.push_back(item.length());
     characters += item.length();
     phrasewords++;
     transform(item.begin(), item.end(), item.begin(), ::tolower); 
    for(int i =0; i<item.length(); i++)
    {
       if(item[i]=='.'||item[i]=='?'||item[i]=='!')
       {
         phrases++;
         avewords.push_back(phrasewords);
         phrasewords=0;
       }
    }
    item.erase(remove(item.begin(), item.end(), '.'), item.end());
    item.erase(remove(item.begin(), item.end(), '?'), item.end());
    item.erase(remove(item.begin(), item.end(), '!'), item.end());
    item.erase(remove(item.begin(), item.end(), ','), item.end());
    item.erase(remove(item.begin(), item.end(), ';'), item.end());

       T1.insertItem (item);
  }

  
  for(auto i=0;i<avewords.size();i++)
  {
    if (avewords[i]>10)
       longsen++;
  }
  cout<<"sentence Too long: "<<longsen<<endl;
  
  for(auto i=0;i<avechar.size();i++)
  {
    if (avewords[i]>8)
       longword++;
  }
  cout<<"word Too long: "<<longword<<endl;
  cout<<endl;
  T1.printInorder();
  int n=T1.numNode();
  cout<<endl<<"world used Too often"<<endl;
  T1.repeat();
  cout<<endl<<"Number of phrases: "<<phrases <<" Number of words "<<words<<endl;
   

  for(auto i=0;i<avewords.size();i++)
  {
    total+= avewords[i];
  }
cout<<"average  sentence length: "<< total/phrases<<endl;
cout<<"Average Word Length: "<<characters/words<<endl;
cout<<"Unique words "<<n<<endl;

  return 0;

}
