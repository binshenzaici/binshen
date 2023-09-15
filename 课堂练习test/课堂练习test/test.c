#define  _CRT_SECURE_NO_WARNINGS 1
/*问题描述： 假设你正在准备去购物，并需要一个购物清单。你希望使用线性表的链式表示
来管理这个购物清单。
实例：购物清单的链式表示
我们将使用 C 语言来演示购物清单的链式表示。首先定义一个链表节点结构来表示每个购
物清单项：*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ShoppingItem {
	char name[50]; // 商品名称
	int quantity; // 商品数量
	struct ShoppingItem* next; // 指向下一个节点的指针
};

//然后，我们创建一个链表头指针，表示购物清单的起始点：
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
//1. 添加商品到购物清单：
void addItem(char itemName[], int itemQuantity) 
{
	//此处填写若干语句；
	struct ShoppingItem* head;
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	//struct ShoppingItem* shoppingList = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	strcpy(newItem->name, itemName);
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	if (shoppingList == NULL)
		shoppingList = newItem;
	else
	{
		head = shoppingList;
		while (head ->next!= NULL)
		{
			head = head->next;
		}
		head->next = newItem;
	}
}
//2. 从购物清单中移除商品：
void removeItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* previous = NULL;
	while (current != NULL) 
	{
		if (strcmp(current->name, itemName) == 0) 
		{
			if (previous != NULL) 
			{
				previous->next = current->next;
			}
			else 
			{
				shoppingList = current->next;
			}
			free(current);
			break;
		}
		//此处填写两行；
		previous = current;
		current = current->next;
		
	}
}
//3. 查看购物清单：
void displayList() 
{
	struct ShoppingItem* current = shoppingList;
	printf("购物清单:\n");
	while (current != NULL) {
		printf("%s - 数量：%d\n", current->name, current->quantity);
		
		//此处填写一句；
		current = current->next;
	}
}
//4. 修改购物清单中商品的数量：
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			//此处填写一句
			current->quantity = newItemQuantity;
				break;
		}
		current = current->next;
	}
}
//5. 清空购物清单：
void clearList() {
	while (shoppingList != NULL) {
		//此处填写两句。
		struct ShoppingItem* temp;
		temp = shoppingList, shoppingList = shoppingList->next;
			free(temp);
	}
}
//6. 计算购物清单中商品的总数量：
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		//此处填写两句；
		total++;
		current = current->next;
	}
	return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	printf("查找商品 \"%s\" ：\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		//此处填写一句。
		current = current->next;
	}
	printf("未找到商品 \"%s\"。\n", itemName);
}
//8. 排序购物清单：
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL) {
		nextItem = current->next;
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				// 交换商品信息
				//此处填写 3 句；
				strcpy(tempName, current->name);
				strcpy(current->name, nextItem->name);
				strcpy(nextItem->name, tempName);
					tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
		}
		current = current->next;
	}
}
//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	// 遍历到第一个购物清单的末尾
	//补充循环语句；
	while (current->next != NULL)
	{
		current = current->next;
	}

	// 将第二个购物清单连接到第一个清单的末尾
	current->next = *list2;
	*list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}
//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) 
		{
			if (prev == NULL) 
			{
				// 如果要删除的是第一个节点
				struct ShoppingItem* temp = shoppingList;
				
				//填写一句；
				shoppingList = shoppingList->next;
					free(temp);
				if (!deleteAll) break;
			}
			else 
			{
				// 如果要删除的不是第一个节点
				//填写一句；
				prev->next = current->next;
					free(current);
				current = prev->next;
				if (!deleteAll) break;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}
int main()
{
	//addItem("苹果", 12);
	//addItem("香蕉", 14);
	//addItem("葡萄", 45);
	/*displayList();//1.添加商品到购物清单，3.查看购物清单

	removeItem("香蕉");
	displayList();//2.从购物清单中移除商品

	updateQuantity("苹果", 20);
	displayList(); //4. 修改购物清单中商品的数量：

	clearList();
	displayList(); //5. 清空购物清单：

	addItem("苹果", 12);
	addItem("香蕉", 14);
	addItem("葡萄", 45);
	int total = totalQuantity();
	printf("%d\n",total); //6. 计算购物清单中商品的总数量：

	findItem("苹果"); //7. 查找购物清单中的商品：
	findItem("柠檬");*/

	//displayList();
	//sortList();
	//displayList();//8. 排序购物清单：

	/*struct ShoppingItem** list1;
	struct ShoppingItem** list2;
	list1 = shoppingList;
	list2 = shoppingList;
	mergeLists(&list1,&list2);
	displayList();*/

	addItem("苹果", 12);
	addItem("香蕉", 14);
	addItem("香蕉", 14);
	addItem("香蕉", 14);
	addItem("葡萄", 20);
	addItem("香蕉", 14);
	displayList();
	deleteItem("香蕉", 0);
	//10.删除第一个
/*      购物清单:
	苹果 - 数量：12
		香蕉 - 数量：14
		香蕉 - 数量：14
		香蕉 - 数量：14
		葡萄 - 数量：20
		香蕉 - 数量：14
		购物清单 :
	苹果 - 数量：12
		香蕉 - 数量：14
		香蕉 - 数量：14
		葡萄 - 数量：20
		香蕉 - 数量：14*/
	displayList();
	deleteItem("香蕉", 1);
	displayList();
	return 0;
}