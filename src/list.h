#ifndef __LIST_H
#define __LIST_H

struct listElement{
	struct listElement *next;
	struct listElement *prev;
};

void listAdd(struct list_element **head, struct listElement* newElement);
void listRemove(struct listElement *b);
#endif
