//with help from Austin
struct list_element{
	struct list_element *next;
	struct list_element *prev;
	int data;
};

void list_add(struct list_element *head, struct list_element* ele);
void list_remove(struct list_element* head, int data);
