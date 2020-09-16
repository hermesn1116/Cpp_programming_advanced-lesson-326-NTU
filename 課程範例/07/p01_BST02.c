#include<stdio.h>
#include<stdlib.h>

struct BTreeNode
{
    int data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;

void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
}
void print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
        printf("%d ", ptr->data);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}
void print_postorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);        
        printf("%d ", ptr->data);
    }
}

node *search_node(node *ptr, int value)
{
    node *temp;
    
    if(ptr != NULL)
    {
    	printf("%d ", ptr->data);
        if(ptr->data == value)
            return ptr;
        else
        {
            temp = search_node(ptr->left, value);
            if(temp != NULL)
                return temp;
            temp = search_node(ptr->right, value);
            if(temp != NULL)
                return temp;
        }
    }
    return NULL;
}


node *insert_node(node *root, int value)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
    {
        root = new_node; //return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(current->data > value)
                current = current->left;
            else
                current = current->right;
        }
        if(parent->data > value)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}


// ��Y�Ȥ����`�I
node *find_parent(node *ptr, int value, int *pos)
{
    node *parent;

    parent = ptr;    // �qptr�}�l��
    *pos = 0;
    while(ptr != NULL)    
    {
        if(ptr->data == value)    // ���ؼ�
            return parent;        // �^�Ǧ��`�I�����`�I
        else
        {
            parent = ptr;
            if(ptr->data > value)
            {
                *pos = -1;            // ptr�bparent���l��
                ptr = ptr->left;    // ������
            }
            else
            {
                *pos = 1;            // ptr�bparent�k�l��
                ptr = ptr->right;    // ���k��
            }
        }
    }
    return NULL;    // �䤣��
}

// �R���`�I
node *delete_node(node *root, int value)
{
    node *parent;
    node *ptr;
    node *next;
    int pos;

    parent = find_parent(root, value, &pos);    // �qroot�}�l,��value�����`�I
    if(parent != NULL)    // �����, �ǳƧR��
    {
        switch(pos)    // �P�_�ثe�`�I�A���`�I����Υk��
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
        if(ptr->left == NULL)        // ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
        {
            if(parent == ptr)    // �p�G�n�R���O�ڸ`�I
                root = root->right;
            else                // ��L
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
        else if(ptr->right == NULL)    // ���p2: �`�I�S���k�l��
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
                root = root->left;
            free(ptr);
        }
        else                        // ���p3: �`�I�����k�l��
        {
            parent = ptr;
            next = ptr->left;    // ����N�Inext, �qptr����}�l��
            if(next->right != NULL){			
	            while(next->right != NULL)    // �����l�`�I���k�l���̤j�ȷ���N�I
	            {
	                parent = next;        // parent��next�����`�I
	                next = next->right;
	            }
	            parent->right = next->left; // ¶�Lnext�`�I
	        }
	        else{
	        	ptr->left = next->left;
			}
			ptr->data = next->data;        // ���N!!
            free(next);    // �R��next (�`�N: ���O�R��ptr)
        }
    }
    return root;    // �^�Ǧ���
}

node *find_node(node *ptr, int value)
{
    while(ptr != NULL)
    {
        if(ptr->data == value)
            return ptr;
        else
        {
            if(ptr->data > value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return NULL;
}


int main()
{
    node *root=NULL, *ptr;
    int value;
    char op;
    
    while(1){
    	/*
    	puts("i insert");
    	puts("l list inorder");
    	puts("m list preorder");
    	puts("n list postorder");
    	puts("q quit");
    	*/
    	scanf(" %c",&op);
    	switch(op){
    		case 'i':
    			scanf("%d",&value);
    			root = insert_node(root, value);
    			break;
    		case 'l':
    			print_inorder(root);
    			puts("");
    			break;
    		case 'm':
    			print_preorder(root);
    			puts("");
    			break;
    		case 'n':
    			print_postorder(root);
    			puts("");
    			break;
    		case 'f':
    			scanf("%d",&value);
				ptr = find_node(root, value);
				if(ptr != NULL)
					printf("found: %d\n", ptr->data);
				else
					printf("not found\n");
				break;
			case 'd':
				scanf("%d",&value);
				ptr = find_node(root, value);
				if(ptr != NULL){
					root= delete_node(root, value);
					printf("delete %d ok\n", value);
				}
				else
					printf("cannot delete\n");

				break;
    		case 'q':
    			return 0;
    			break;
		}
		system("pause");
		system("cls");
	}
}
