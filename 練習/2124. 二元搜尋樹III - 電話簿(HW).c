#include <stdio.h>
#include <stdlib.h> 

struct _binarytree
{
	char Nmae[128];
	char Phone[128];
	char Email[128];
	struct _binarytree *left;
	struct _binarytree *right;
}; typedef struct _binarytree binarytree;

binarytree *insert_binarytree(binarytree *root, binarytree value);
void print_inorder(binarytree *ptr);
void print_preorder(binarytree *ptr);
void print_postorder(binarytree *ptr);
binarytree *findData(binarytree *root, int target);
binarytree *find_parent(binarytree *ptr, int value, int *pos);
binarytree *delete_node(binarytree *root, int value);

int main(void)
{
	binarytree *root, *res, input;
	char opt;
	int val;
	
	root = NULL;
	
	do
	{
		scanf(" %c", &opt);
		switch(opt)
		{
			case 'i' :
				scanf("%d", &val);
				root = insert_binarytree(root, val);
				
				break;
			case 'l' :
				print_inorder(root);
				printf("\n");
				
				break;
			case 'm' :
				print_preorder(root);
				printf("\n");
				
				break;
			case 'n' :
				print_postorder(root);
				printf("\n");
				
				break;
			case 'd' :
				scanf("%d", &val);
				res = findData(root, val);
				if(res != NULL)
				{
					root = delete_node(root, val);
					printf("delete %d ok\n", val);
				}
				else
				{
					printf("cannot delete\n");
				}
				
				break;
			case 'f' :
				scanf("%d", &val);
				res = findData(root, val);
				if(res != NULL)
				{
					printf("found: %d\n", res->data);
				}
				else
				{
					printf("not found\n");
				}
				
				break;
		}
	} while(opt != 'q');	
	
	return 0;
}

binarytree *insert_binarytree(binarytree *root, int value)
{
	binarytree *new_node, *current, *parent;
	
	new_node = (binarytree*)malloc(sizeof(binarytree));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	
	if(root == NULL)
	{
		root = new_node;
	}
	else
	{
		current = root;
		while(current != NULL)
		{
			parent = current;
			if(current->data > value)
			{
				current = current->left;
			}				
			else
			{
				current = current->right;
			}				
		}
		if(parent->data > value)
		{
			parent->left = new_node;
		}			
		else
		{
			parent->right = new_node;
		}
	}
	
	return root;
}

void print_inorder(binarytree *ptr)
{
	if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
};

void print_preorder(binarytree *ptr)
{
	if(ptr != NULL)
    {
    	printf("%d ", ptr->data);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
};

void print_postorder(binarytree *ptr)
{
	if(ptr != NULL)
    {
        print_postorder(ptr->left);        
        print_postorder(ptr->right);
		printf("%d ", ptr->data);
    }
};

binarytree *findData(binarytree *root, int target)
{
	binarytree *tmp;
	
	tmp = root;
	while(tmp != NULL)
	{
		if(tmp->data == target)
		{
			return tmp;
		}
		else
		{
			if(tmp->data > target)
			{
				tmp = tmp->left;
			}
			else
			{
				tmp = tmp->right;
			}
		}
	}
	
	return NULL;
};

// ��Y�Ȥ����`�I
binarytree *find_parent(binarytree *ptr, int value, int *pos)
{
	binarytree *parent;

	parent = ptr;	// �qptr�}�l��
	*pos = 0;
	while(ptr != NULL)	
	{
		if(ptr->data == value)	// ���ؼ�
			return parent;		// �^�Ǧ��`�I�����`�I
		else
		{
			parent = ptr;
			if(ptr->data > value)
			{
				*pos = -1;			// ptr�bparent���l��
				ptr = ptr->left;	// ������
			}
			else
			{
				*pos = 1;			// ptr�bparent�k�l��
				ptr = ptr->right;	// ���k��
			}
		}
	}
	return NULL;	// �䤣��
};

// �R���`�I
binarytree *delete_node(binarytree *root, int value)
{
	binarytree *parent;
	binarytree *ptr;
	binarytree *next;
	int pos;

	parent = find_parent(root, value, &pos);	// �qroot�}�l,��value�����`�I
	if(parent != NULL)	// �����, �ǳƧR��
	{
		switch(pos)	// �P�_�ثe�`�I�A���`�I����Υk��
		{
			case -1:
				ptr = parent->left;
				break;
			case 1:
				ptr = parent->right;
				break;
			case 0:
				ptr = parent;
				break;
		}
		if(ptr->left == NULL)		// ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
		{
			if(parent == ptr)	// �p�G�n�R���O�ڸ`�I
				{
					root = root->right;
				}				
			else				// ��L
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
					parent->right = ptr->right;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
					parent->left = ptr->right;
				}
			}
			free(ptr);
		}
		else if(ptr->right == NULL)	// ���p2: �`�I�S���k�l��
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
					parent->right = ptr->left;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
					parent->left = ptr->left;
				}
			}
			else
			{
				root = root->left;
			}				
			free(ptr);
		}
		else					
		{
			parent = ptr;
			next = ptr->left;
			if(next->right != NULL)
			{
				while(next->right != NULL)
				{
					parent = next;		
					next = next->right;
				}				
				parent->right = next->left;
			} 
			else
			{
				ptr->left = next->left; 
			}
			ptr->data = next->data;
			free(next);	
		}
	}
	
	return root;
}
