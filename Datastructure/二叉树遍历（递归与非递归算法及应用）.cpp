#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
} *TreeNode;
void creatbitree(TreeNode &root)//建立二叉树
{
	int data;
	cin>>data;
	if(data==0)
	{	
		root=NULL;
	}
	else 
	{
		TreeNode q=new Node;
		q->data=data;
		q->lchild=NULL;
		q->rchild=NULL;
		root=q;
		creatbitree(root->lchild);
		creatbitree(root->rchild);//递归方法建立二叉树
	}
}

void preorder(TreeNode root)//先序遍历
{
	if(root)
	{
		cout<<root->data<<" ";//先输出根结点的值
		preorder(root->lchild);//遍历左子树
		preorder(root->rchild);//遍历右子树
	}
} 
void midorder(TreeNode root)//中序遍历
{
	if(root)
	{
		midorder(root->lchild);//先遍历左子树
		cout<<root->data<<" ";//再遍历结点
		midorder(root->rchild);//最后遍历右子树
	}
}
void postorder(TreeNode root)//后序遍历
{
	if(root)
	{
		postorder(root->lchild);//先遍历左子树
		postorder(root->rchild);//再遍历右子树
		cout<<root->data<<" ";//最后遍历结点
	}	
} 
//以下为非递归算法
void nrpreorder(TreeNode root)
{
	stack<TreeNode> assiststack;//建立辅助栈
	TreeNode p=new Node;//
	if(!root)
	{
		return;//空树
	}
	else
	{
		p=root; 
	}
	do
	{
		while(p)
		{
			cout<<p->data<<" ";
			if(p->rchild)
			{
				assiststack.push(p->rchild);//右结点入栈
			}
			p=p->lchild;
		}
		if(!assiststack.empty())//判断栈是否为空
		{
			p=assiststack.top();//取栈首结点
			assiststack.pop();//弹栈
		}
	}while((!assiststack.empty())||(p!=NULL));
} 
void nrmidorder(TreeNode root)//非递归中序遍历
{
	stack<TreeNode> assiststack;//辅助栈
	TreeNode p=new Node;
	if(!root)
	{
		return;
	}
	else
	{
		p=root;
	}
	do
	{
		while(p)
		{
			assiststack.push(p);
			p=p->lchild;
		}
		if(!assiststack.empty())
		{
			p=assiststack.top();
			cout<<p->data<<" ";
			assiststack.pop();
			p=p->rchild;
		}
	}while((!assiststack.empty())||(p!=NULL));
}
void nrpostorder(TreeNode root)//非递归后序遍历
{
	stack<TreeNode> assiststack1;//建立辅助栈1
	stack<int> assiststack2;//建立辅助栈2，用于判断二次进栈
	TreeNode p=new Node;
	int k;//
	if(!root)
	{
		return;
	}
	else
	{
		p=root;
	}
	do
	{
//		if(t<0)
//		t=-t;
		while(p)
		{	
			assiststack1.push(p);
			assiststack2.push(::abs(p->data)); 
			p=p->lchild;
		}
		while((!assiststack1.empty())&&(p==NULL))
		{
			p=assiststack1.top();
			k=assiststack2.top();
			assiststack1.pop();
			assiststack2.pop();
			if(k>0)
			{
				assiststack1.push(p);
				assiststack2.push(-(p->data));
				p=p->rchild;		
			}
			else //已经进行了两次进栈，可以直接输出
			{
				cout<<p->data<<" ";
				p=NULL;
			}	
		} 
	}while((!assiststack1.empty())||(p!=NULL));
}
void leafnum(TreeNode root,int &num)//判断叶子结点的个数
{
    if (root!=NULL)
    {
        if (root->lchild==NULL&&root->rchild==NULL)
            num++;
        leafnum(root->lchild,num);
        leafnum(root->rchild,num);
    }
}
void depth_of_tree(TreeNode root,int k,int &h)
{
    if (root!=NULL)
    {
        k++;
        if (k>h)
            h=k;
        depth_of_tree(root->lchild,k,h);
        depth_of_tree(root->rchild,k,h);
    }
}
int main()
{
	TreeNode root=new Node;
	creatbitree(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	midorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl<<"以下为非递归算法部分"<<endl;
	nrpreorder(root);
	cout<<endl;
	nrmidorder(root);
	cout<<endl;
	nrpostorder(root);
	cout<<endl;
	int num=0;
	cout<<"统计叶子结点个数"<<endl;
	leafnum(root,num);
	cout<<num<<endl;
	cout<<"求二叉树的深度"<<endl;
    int k=0;
    int h=0;
    depth_of_tree(root,k,h);
    cout<<h;
	return 0;
} 
//1 2 3 0 0 4 5 0 0 6 7 0 0 0 8 9 0 0 10 11 12 0 0 13 0 0 14 0 0