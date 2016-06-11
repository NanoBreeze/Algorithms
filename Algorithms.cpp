/*
 * =========== BINARY SEARCH TREE ==========
 * Traversals: preorder, inorder, postorder, level order | CHECK
 * Insert, delete (needs work)
 * Find max, min, specific number
 *
 */
 
#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
  Node(int d) { data = d; }
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
};

void preorderTraversal(Node* root) 
{
   if (root)
   {
      cout << root->data << "," ; //process data
      preorderTraversal(root->left);
      preorderTraversal(root->right);
   }
}

void inorderTraversal(Node* root)
{
   
   if (root)
   {
      inorderTraversal(root->left);
      cout << root->data << ","; //process data
      inorderTraversal(root->right);
   }
}


void postorderTraversal(Node* root)
{
   
   if (root)
   {
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      cout << root->data << "," ; //process data
   }
}


void levelorderTraversal(Node* root)
{
   int a = 43;
   
   queue<Node*> q;
   q.push(root);

   while (!q.empty())
   {
      root = q.front();
      q.pop();
      cout << root-> data << "," ; //process data
      if (root->left) { q.push(root->left); }
      if (root->right) { q.push(root->right); }
   
   }
}

Node* insert(Node* root, int data)
{
   if (root)
   {
      if (root->data > data)
      {
         root->left = insert(root->left, data);
	 return root;
      }
      if (root-> data < data)
      {
	  root->right = insert(root->right, data);
	  return root;
      }
   }
   return new Node(data);

}

Node* findMax(Node* root)
{
	
	if (root->right)
	{
		findMax(root->right);
	}
	else
	{
		return root;
	}
}

Node* findMin(Node* root)
{
	
	if (root->left)
	{
		findMax(root->left);
	}
	else
	{
		return root;
	}
}

Node* findData(Node* root, int data)
{
	if (root)
	{
		if (data > root->data)
		{
			return findData(root->right, data);
		}

		if (data < root->data)
		{
			return findData(root->left, data);
		}
		
		if (data == root->data)
		{
			return root;
		}
	}

	return nullptr;
}

//===================================================== NOT TESTED, NOT FINISHED YET!!!!! =======================================
Node* deleteNode(Node* root, int data)
{
	if (root)
	{
	 	if (root->data > data)
      	{
       		root->left = deleteNode(root->left, data);
	 		return root;
      	}
      	if (root-> data < data)
      	{
	  		root->right = deleteNode(root->right, data);
	  		return root;
      	}
		if (root->data == data)
		{
			//if no children, simply delete this node
			if ((root->left == nullptr) && (root->right == nullptr))
			{
                cout << "No children" << endl;
                delete(root);
				return nullptr;
			}

			//if one child only, that child shall replace this current node
			if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->left == nullptr))
			{
                cout << "One child\n" << endl;
				Node* child = (root->left == nullptr) ? root->right : root->left;
                delete(root);
				return child;
			}

			//if two children ...replace this node with a predecessor or sucessor and delete that 
            if ((root->left != nullptr && root->right != nullptr))
            {
                cout << "Two children" << endl;
                Node* predecessor = findMax(root->left);
                int temp = root->data;
                root->data = predecessor->data;
                predecessor->data = temp;
                root->left = deleteNode(root->left, temp);
                return root;
            }        
		}
	}
	else
	{
		cout << "The node is not found in this tree";
		return nullptr;
	}

}	

int main(){
Node* root = new Node(100);
insert(root, 83);
insert(root, 123);
insert(root, 133);
insert(root, 153);
insert(root, 1223);
insert(root, 183);
insert(root, 113);
insert(root, 129);
insert(root, 1393);
insert(root, 150);

cout << "INORDER TRAVERSAL: ";
inorderTraversal(root);

cout << endl << "PREORDER TRAVERSAL: ";
preorderTraversal(root);

cout << endl << "POSTORDER TRAVERSAL: ";
postorderTraversal(root);

cout << endl << "LEVELORDER TRAVERSA: ";
levelorderTraversal(root);

cout << endl << "FINDING MAX:  ";
Node* max = findMax(root);
cout << max->data;
//delete(max);

cout << endl << "FINDING MIN:   ";
Node* min = findMin(root);
cout << min->data;
//delete(min);

cout << endl << "FINDING NODE WITH DATA 153:  ";
Node* node1 = findData(root, 153);
if (node1 != nullptr) { cout << node1->data; } 
else { cout << "NODE NOT FOUND!"; }
//delete(node1);

cout << endl << "DELETING ROOT, WHICH HAS TWO CHILDREN";
deleteNode(root, 100);


return 0;
}
