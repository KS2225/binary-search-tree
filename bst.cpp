#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class treenode
{
    char word[100],meaning[100];
    treenode *left;
    treenode *right;
    friend class tree;
    friend class Queue;
};

class tree
{
    public:
    treenode *root;
    friend class Queue;
    tree();
    void create();
    void displayBFS();
    void levelOrder();
    void levelOrder(treenode *);
    void insertNode();
    void inorder_r();
    void inorder_r(treenode *);
    void insertNode(treenode *);
    void mirrorR();
    void mirrorR(treenode *);
    char* search_nr();
    void copyR(tree *);
    treenode* copyR(treenode *);
    void deleteBst();
};

tree:: tree()
{
    root=NULL;
}

class Queue
{
  treenode *q[20];
  int front,rear;
public:
  Queue() {
    front=rear=-1;
  }


  void insertQueue(treenode *temp) {
    if(!isFull()) q[++rear] = temp;
  }

  treenode* deleteQueue() {
    return q[++front];
  }

  int isEmpty() {
    if(front==rear) return 1;
    else return 0;
  }

  int isFull() {
    if(rear == 19) return 1;
    else return 0;
  }

  treenode* returnFront() {
    return q[front];
  }  
};


void tree:: create()
{
    int choice;
    //allocate memory and accept the data for root node;

    treenode *temp,*curr;
    
    root = new treenode();
    cout<<"\nCreating Root Node..."<<endl;
    cout<<"\nEnter root word: ";
    cin>>root->word;
    cout<<"\nEnter root meaning: ";
    cin>>root->meaning;
    root->left=NULL;
    root->right=NULL;
do
{
    temp=root;
    int flag=0;
//allocate memory and accept the data for curr node;
    curr= new treenode();
    cout<<"\nEnter word to insert: ";
    cin>>curr->word;
    cout<<"\nEnter meaning: ";
    cin>>curr->meaning;
    curr->left=curr->right=NULL;
while(flag==0)
    {
       
        if(strcmp(curr->word, temp->word)<0)
            {
            
                if(temp->left==NULL)
                    {
                        
                        temp->left=curr;
                        flag=1;
                    }
                else
                    {
                        
                        temp=temp->left;
                    }
                    
            } 
        else 
            {
                
                if(temp->right==NULL)
                    {
                        
                        temp->right=curr;
                        flag=1;
                    }
                else
                    {
                         
                            temp=temp->right;
                    }
            } 
    }
//Accept choice for adding more nodes;
cout<<"Enter More Nodes?(1/0): ";
cin>>choice;
}while(choice==1); 
} 



void tree:: displayBFS()
{
    Queue q;
    treenode *temp;
    temp = new treenode();
    temp = root;

    q.insertQueue(temp);
    while(!q.isEmpty()) 
    {
     temp = q.deleteQueue();
    cout<<"\nWORD: "<<temp->word<<"\nMEANING: "<<temp->meaning<<"\n";

        if(temp->left !=NULL) 
        {
          q.insertQueue(temp->left);
        }

        if(temp->right !=NULL) 
        {
          q.insertQueue(temp->right);
        }
    }
    cout<<"\n";
}


void tree::levelOrder()
{
    levelOrder(root);
}


void tree:: levelOrder(treenode *root)
{
    if (root == NULL) return;
    int c=0;
    Queue q;
    treenode *curr;
    curr=new treenode();
    q.insertQueue(root);
    q.insertQueue(NULL);
    cout<<"level 0: ";
    while (!q.isEmpty())
    {
        curr = q.returnFront();
        q.deleteQueue();
        if (curr == NULL)
        {
           q.insertQueue(NULL);
           cout <<"\n";
           c++;
           cout<<"level "<<c<<": ";
        }
          
        else {
            
            if(curr->left!=NULL)
                q.insertQueue(curr->left);
            if(curr->right!=NULL)
                q.insertQueue(curr->right);
            cout<<curr->word <<" ";
        }
    }
}
 
void tree::inorder_r()
{
	inorder_r(root);
}

void tree::inorder_r(treenode *temp)
{
	if (temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->word<<" ";
		inorder_r(temp->right);
	}
}
  
void tree:: insertNode()
{
    treenode *newNode;
    newNode = new treenode();
    cout<<"\n Enter new word to insert: ";
    cin>>newNode->word;
    cout<<"\nEnter meaning: ";
    cin>>newNode->meaning;
    insertNode(newNode);
}

void tree:: insertNode(treenode* newNode) 
{
    treenode *temp = root;
    int flag=0;
    while(flag==0) 
    {
      if(strcmp(temp->word,newNode->word) < 0) 
      {
        if(temp->right == NULL) 
        {
          temp->right = newNode;
          flag=1;
        }
        temp = temp->right;
      } 
      else 
      {
        if(temp->left == NULL) 
        {
          temp->left = newNode;
          flag=1;
        }
        temp=temp->left;
      }
    }
}



void tree::mirrorR() 
{
    mirrorR(root);
    levelOrder();
 }

void tree:: mirrorR(treenode *root) 
{
    if(root != NULL) 
    {
      treenode* temp;
      temp=new treenode();
      temp = root->left;
      root->left = root->right;
      root->right = temp;
      if(root->left!=NULL)
        mirrorR(root->left);
      if(root->right!=NULL)
        mirrorR(root->right);
    } 
    else 
    {
      return;
    }
}


 void tree:: copyR(tree *t) 
 {
    root=copyR(t->root);
 }

treenode* tree:: copyR(treenode* root) 
{
    treenode *temp = NULL;
    if(root != NULL) 
    {
      temp = new treenode();
      temp->left = temp->right = NULL;
      strcpy(temp->word,root->word);
      strcpy(temp->meaning,root->meaning);
      temp->left = copyR(root->left);
      temp->right = copyR(root->right);
    }
    return temp;
 }


char* tree::search_nr() 
{
    int flag=0;
    char str1[100];
    treenode *temp=root;
    cout<<"Enter string: ";
    cin>>str1;
    while(flag==0) 
    {
        if(temp!=NULL)
        {
            if(strcmp(str1,temp->word)==0)
            {
                flag=1; 
                break; 
            }
            else if(strcmp(str1,temp->word)<0)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        else
        {
            break;
        }
    } 
    if(flag==1)
    {
        cout<<"\n'"<<temp->word<<"' found!";
        
    }
    else
    {
        cout<<"\n'"<<temp->word<<"' not found!";
    }
} 



void tree :: deleteBst()
{
   
    string del_word;
    cout<<"Please enter the word which you want to delete :";
    cin>>del_word;
    treenode *temp;
    treenode *curr;
    treenode *parent;
    treenode *s;
    treenode *t1;
    treenode *t2;

    temp = root;

    while(temp!=NULL){

        if(del_word == temp->word){

            curr = temp;
            break;

        }else if(del_word < temp->word){

            parent =temp;
            temp = temp->left;

        }else{

            parent = temp;
            temp = temp->right;
        }
    }


    if(curr==root){             // if the delete meaning is a root node
        if(curr->left == NULL){

            curr = curr->right;

        }else if(curr->right == NULL){

            curr = curr->left;

        }else if(curr->left != NULL && curr->right != NULL){
            root = curr->right;
            temp = curr->left;
            s = curr->right;

            while(s->left!=NULL){

                s = s->left;

            }
            s->left = temp;
        }

    }
    else if(curr!=root)
    {

        if(curr->left!=NULL && curr->right!=NULL){
            s = temp->left;
            t1= temp-> right;

            while(t1->left!= NULL){

                t1=t1->left;
            }

            t1->left = s;
            t2= temp->right;

            if(temp == parent->left){

                parent->left = t2;

            }else{

                parent->right = t2;

            }

        }else if(curr->left== NULL && curr->right !=NULL){      // When left child is NULL and Right child is not Null

            if(curr == parent->right){

                parent->right = curr->right;
            }else{
                parent->left = curr->right;

            }
        }else if (curr->left!=NULL && curr->right == NULL){     // when left child is not NULL and right child is null

            if(curr== parent->right){

                parent->right = curr->left;

            }else{

                parent->left = curr->left;
            }

        }else if(curr->left==NULL && curr->right == NULL){                  // when both are NULL
            if( curr == parent->left){

                parent->left =NULL;

            }else{

                parent->right =NULL;

            }
        }
        else //deletion of a node having two child
        {
            s=curr->right;
            temp=curr->left;
            while(s->left!=NULL)
            {
                s=s->left;
            }
                s->left=temp;
            if(parent->left==curr){
                parent->left=curr->right;
            }
            else
            {
                    parent->right=curr->right;
            }
        }
    curr->left=NULL;
    curr->right=NULL;
    delete curr;
    }
    
}





int main()
{
    tree *bt,*bt2;
    int o;
    while(1)
    {
    cout<<"\n***"<<endl;
    cout<<"                                      MENU";
    cout<<"\n**"<<endl;
    cout<<"1.Create BST\n2.Display BST\n3.Insert\n4.Search\n5.Delete \n6.Mirror \n7.Copy\n8.Exit\n-> ";
     cin>>o;
    switch(o)
        {
            case 1:
            {
                bt=new tree();
                bt->create();
                break;
            }
            case 2:
            {
                cout<<"\nBFS(word,meaning): ";
                bt->displayBFS();
                cout<<"\nLevel-wise display:\n";
                bt->levelOrder();
                break;
            }
            case 3:
            {
                bt->insertNode();
                break;
            }
            case 4:
            {
                bt->search_nr();
                break;
            }
            case 5:
            {
                bt->deleteBst();
                bt->displayBFS();
                bt->levelOrder();
                break;
            }
            case 6:
            {
                bt->mirrorR();
                break;
            }
            case 7:
            {
                cout<<"\nCreating new tree bt2...";
                bt2= new tree();
                cout<<"\nCopying existing tree (bt) to new tree(bt2)...";
                bt2->copyR(bt);
                bt2->displayBFS();
                bt2->levelOrder();
                break;
            }
            case 8:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"\nInvalid Choice!Try Again!!"<<endl;
                break;
            }
        }
    }
}
