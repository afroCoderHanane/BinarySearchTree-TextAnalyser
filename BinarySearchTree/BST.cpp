#include"BST.h"
#include<stack>


template <class T>
BSTree<T> :: BSTree ()
{
   root = NULL;
   phrases=0;
   characters =0;
   words=0;
   countnodes=0;
   specialnodes=0;
   phrasewords=0;
   longword=0;
   total=0;
   longsen =0;
   charindex = ' ';
}

template<class T>
void BSTree<T>::pushToTree()
{
  ifstream infile;
  string item;
  infile.open("Numbers1.txt", ios::in);

  
  while (!infile.eof())
  {
    
     infile>> item;
     words++;
     
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
    //algorithm to erase some char
    item.erase(remove(item.begin(), item.end(), '.'), item.end());
    item.erase(remove(item.begin(), item.end(), '?'), item.end());
    item.erase(remove(item.begin(), item.end(), '"'), item.end());
    item.erase(remove(item.begin(), item.end(), ')'), item.end());
    item.erase(remove(item.begin(), item.end(), '('), item.end());
    item.erase(remove(item.begin(), item.end(), '!'), item.end());
    item.erase(remove(item.begin(), item.end(), ','), item.end());
    item.erase(remove(item.begin(), item.end(), ';'), item.end());
       insertItem (item);
  }
infile.close();
}
template <class T>
BSTree<T> :: ~BSTree ()
{
   destroyTree (root);  
}
template <class T>
void BSTree<T> :: deleteAll ()
{
   destroyTree (root);  
}
template <class T>
void BSTree<T> :: destroyTree (node<T> * &p )
{
   if ( p != NULL )
   {
       destroyTree (p->left);
       destroyTree (p->right);
       delete p;
       p = NULL;

   }
}

template <class T>
BSTree<T> :: BSTree (const BSTree<T> & other)
{
   if ( other.root == NULL )
       root = NULL;
   else copyTree (root, other.root); 
}

template <class T>
void BSTree<T> :: operator= (const BSTree<T> & other)
{
   if ( this != &other )
   {
      destroyTree (root);
      copyTree (root, other.root);
   }
}

template <class T>
void BSTree<T> :: copyTree (node<T> *& nroot, node<T> *croot  )
{
    if ( croot == NULL )
        nroot = NULL;
    else 
    {
       nroot = new node<T>;
       nroot->info = croot->info;
       copyTree (nroot->left, croot->left);
       copyTree (nroot->right, croot->right);
    }
}


template <class T>
void BSTree<T> :: print ()
{
   printInorder (root); 
}
// function that print the output to a file with non recursive  inorder print
template <class T>
void BSTree<T> :: printInorder (node<T> *p )
{   
    int n= special();
    ofstream fout;
    fout.open("chapter.text");
    fout<<"STASTICAL SUMMARY "<<endl<<endl;
    fout<<"TOTAL NUMBER OF WORDS: "<<words<<endl;
    fout<<"TOTAL NUMBER OF UNIQUE WORDS: "<<numNode()<<endl;
    fout<<"TOTAL NUMBER OF UNIQUE WORDS GREATER THAN THREE LETTERS: "<<n
    <<endl;
    fout<<"AVERAGE SENTENCE LENGTH: "<<getAveSentence() <<endl;
    fout<<"AVERAGE WORD LENGTH: "<<getAveWord() <<endl;

    fout<<endl<<"STYLE WARNING"<<endl
    <<"WORLD USED TOO OFTEN"<<endl;
     node<T> *q =p;
     stack<node<T>*>tempS;
     while(q!=NULL || tempS.empty()==false)
     {
       while(q!=NULL)
         {
           tempS.push(q);
           q = q->left;

         }
         q = tempS.top();
     tempS.pop();
     if(q->occurence>((5*n)/100) && (q->info).length()>3)
        {fout<<q->info<<endl;}

      q= q->right;
     }
  fout<<endl<<"AVERAGE SENTENCE LENGTH TOO LONG-12 WORDS: "<< getLongSentences()  <<endl<<"AVERAGE WORDS LENGTH TOO LONG-12 WORDS: "<<getLongWord()<<endl << "INDICE OF UNIQUE WORDS"<<endl;

     
    char temp;
    stack<node<T> *> s; 
    node<T> *curr = p; 
    while (curr != NULL || s.empty() == false) 
    { 
        // Reach the left most Node of the curr Node 
        while (curr !=  NULL) 
        {      
            s.push(curr); //place pointer to a tree node on the stack before traversing the node's left subtree 
            curr = curr->left; 
        } 
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
      temp = toupper(curr->info[0]);
      if(charindex!=temp)
         {
           charindex = temp;
           fout<<endl<<endl;
           charindex=toupper(charindex);
           fout<<endl<<endl;
           fout<<endl<<charindex<<endl;
         }
         
        fout <<endl<<curr->info <<endl; 
        
  
        // we have visited the node and its left subtree.  Now, it's right subtree's turn 
        curr = curr->right; 
  
    } /* end of while */

  // delete curr;
}

template <class T>
void BSTree<T> :: insertItem (T item )
{
   node<T> *temp = new node<T>;
   temp->info = item;
   temp->occurence=1;
   temp->left = NULL;
   temp->right = NULL;

   if ( root == NULL )
   {
      root = temp;
      
   }
   else    
       {
          node<T> *p = root;
          node<T> *s;

          while ( p != NULL )
          {
             s = p;
             if ( p->info == item )
             {
               p->occurence++;
               return;
             }   
             else if ( p->info > item )
               p = p->left;
             else 
               p = p->right;

          }

          if ( s->info > item )
             s->left = temp;
          else 
             s->right = temp;   
       }
   

}

template <class T>
bool BSTree<T> :: isEmpty ()
{
  return root == NULL;
}
template<class T>
int BSTree<T>:: numNode(node<T>*p)
{
  if(p==NULL)
		return 0;
	if(p->left!=NULL)
	{
		countnodes=countnodes+1;
		countnodes=numNode(p->left);
	}
	if(p->right!=NULL)
	{
		countnodes=countnodes+1;
		countnodes=numNode(p->right);
	}
	return countnodes;

}
template<class T>
int BSTree<T>:: numNode()
{
  int n = numNode(root);
  
  return n;
}

template<class T>
int BSTree<T>:: special(node<T>*p)
{
  string temp;
  if(p==NULL)
		return 0;
  else if(p!=NULL)
    {
      
      special(p->left);
      temp = p->info;
      if(temp.length()>3)
       specialnodes++;
      special(p->right);
    }
	return specialnodes;

}

template<class T>
int BSTree<T>:: special()
{
  int n = special(root);
  return n;
}

//get Sentences
template<class T>
int BSTree<T>::getLongSentences()
{
  for(auto i=0;i<avewords.size();i++)
  {
    if (avewords[i]>10)
       longsen++;
  }
  return longsen;
}
template<class T>
int BSTree<T>::getLongWord()
{
  for(auto i=0;i<avechar.size();i++)
  {
    if (avewords[i]>8)
       longword++;
  }
  return longword;
}
template <class T>
int BSTree<T>:: getNumWord()
{
  return words;
}
template<class T>
int BSTree<T>:: getAveSentence()
{
  for(auto i=0;i<avewords.size();i++)
  {
    total+= avewords[i];
  }
  return total/phrases;
}
template<class T>
int BSTree<T>:: getAveWord()
{
  return characters/words;
}

template <class T>
bool BSTree<T> :: searchItem (T item )
{
   if ( root == NULL )
      return false;
   else 
   {
      node<T> *p = root;
      bool found = false;

      while ( p != NULL && !found )
      {
         if ( p->info == item )
            found = true;
         else if ( p->info < item )
            p = p->right;
         else 
            p = p->left;      

      }

     return found;
   }    
}

