#include"BST.h"
template <class T>
BSTree<T> :: BSTree ()
{
   root = NULL;

  charindex = ' ';
}

template <class T>
BSTree<T> :: ~BSTree ()
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
void BSTree<T> :: printPreorder ()
{
   printPreorder (root);
  
}

template <class T>
void BSTree<T> :: printPreorder (node<T> *p )
{
   if ( p != NULL )
   {
      cout<<"  "<< p->info;
      printPreorder (p->left);
      printPreorder (p->right);
   }

}

template <class T>
void BSTree<T> :: printPostorder ()
{
   printPostorder (root);
  
}

template <class T>
void BSTree<T> :: printPostorder (node<T> *p )
{
   if ( p != NULL )
   {
      
      printPostorder (p->left);
      printPostorder (p->right);
      cout<<"  "<< p->info;
   }

}

template <class T>
void BSTree<T> :: printInorder ()
{
   printInorder (root);
  
}

template <class T>
void BSTree<T> :: printInorder (node<T> *p )
{   char temp;
   if ( p != NULL )
   {
      printInorder (p->left);
      temp = p->info[0];
      if(charindex!=temp)
         {
           charindex = temp;
           cout<<endl<<endl;
           putchar(toupper(charindex));
           cout<<endl<<endl;
         }
         //cout<<p->occurence<<endl;
      cout<< p->info<< endl;
      printInorder (p->right);
      
   }
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

template <class T>
void BSTree<T> :: deleteItem (T item )
{
   deleteItem (root, item);
}

template <class T>
void BSTree<T> :: deleteItem (node<T> *& p, T item)
{
   if ( p == NULL )
      cout<<"ITEM NOT THERE OR TREE EMPTY";
   else if ( item < p->info )
      deleteItem (p->left, item);
   else if ( item > p->info )
      deleteItem (p->right, item);
   else
      DeleteNode (p); 
  
}

template <class T>
void BSTree<T> :: DeleteNode (node<T> *&p)
{
   node<T> *q = p;

   if ( p->left == NULL )
   {
     p = p->right;
     delete q;
   }
   else if ( p->right == NULL )
   {
     p = p->left;
     delete q;
   }
   else 
   {
      T data = getPredecessor (p->left); 
      p->info = data;
      deleteItem (p->left, data);
   }
}

template <class T>
T  BSTree<T> :: getPredecessor ( node<T> *p )
{
     while ( p->right != NULL )
        p = p->right;
     return p->info;
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
  int res=0;
  if(p->left&&p->right)
  res++;

  res+=(numNode(p->left)+numNode(p->right));
  return res;

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
  if(p==NULL)
  return 0;
  int res=0;
  if(p->left&&p->right&&(p->info).length()>3)
  res++;

  res+=(numNode(p->left)+numNode(p->right));
  return res;

}
template<class T>
int BSTree<T>:: special()
{
  int n = numNode(root);
  return n;
}
template <class T>
void BSTree<T> :: repeat ()
{
   repeatO (root);
  
}

template <class T>
void BSTree<T> :: repeatO (node<T> *p )
{   int n= special();
   if ( p != NULL )
   {
      repeatO (p->left);
       if(p->occurence>((5*n)/100) && (p->info).length()>3)
          cout<<p->info<<endl;
      repeatO (p->right);
      
   }
}