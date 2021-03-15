#include "list.h"
#include "rprintf.h"
#include "serial.h"
# define NULL (void)0

void bss_to_zero();

extern int __bss_start;
extern int __bss_end;
extern struct ppage* free_list;
int global;

/*struct list_element b = {NULL,NULL, 1};
struct list_element a = {NULL,NULL, 5};
struct list_element c = {NULL,NULL, 2};
struct list_element *head = &a;
struct list_element* list = &a;*/
 
void kernel_main(){
	bss_to_zero();
	//mmu
	mmu_on();
	//hw 7
	init_pfa_list();
	struct ppage* test = free_list;
	test = test->next; //where error is, doesnt like pointing to next
	esp_printf(putc, "Physical location:  %x \n", test->physical_addr);
	test = test->next;
        esp_printf(putc, "Physical location:  %x \n", test->physical_addr);
	test = test->next;
        esp_printf(putc, "Physical location:  %x \n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf(putc, "Physical pages:  %x \n", test->physical_addr);
	//hw 5
	//esp_printf(putc, "Mem location for kernel main:  %x \n", kernel_main);

	//blinky hw 4
	//led_init();
	while (1){

	}
}

void bss_to_zero(){
	(&__bss_start)[0] = 0x0c;
	int x=0;
	while ((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0;
		x++;
	}
}
