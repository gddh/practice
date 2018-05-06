#include "traversals.h"

void	order_test(void)
{
    t_node *root = NULL;
    root = insert(root, 25);
    insert(root, 15);
    insert(root, 50);
    insert(root, 10);
    insert(root, 4);
    insert(root, 12);
    insert(root, 22);
	insert(root, 18);
	insert(root, 24);
	insert(root, 35);
	insert(root, 31);
	insert(root, 44);
	insert(root, 70);
	insert(root, 66);
	insert(root, 90);
  
	printf("inorder: ");
    inorder(root);
	printf("\n");
	printf("preorder: ");
    preorder(root);
	printf("\n");
	printf("postorder: ");
    postorder(root);
	printf("\n");
}

void	deletion_test(void)
{
    t_node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

}

int		main()
{
    t_node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

	printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
	deletion_test();
	return 0;
}
