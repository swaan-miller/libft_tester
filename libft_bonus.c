#include  "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void    f(void *str)
{
	char    *str1;
	int     i;

	str1 = (char*)str;
	i = 0;

	while(str1[i] != '\0')
	{
		if(str1[i] >= 'A' && str1[i] <= 'Z')
		{
			str1[i] = str1[i] + 32;
		}
		i++;
	}
}

void    *g(void *str)
{
	char    *str1;
	int     i;

	str1 = (char*)str;
	i = 0;

	while(str1[i] != '\0')
	{
		if(str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] = str1[i] - 32;
		}
		i++;
	}
	return(str);
}

int		main(void)
{
 	printf("\n\n\033[1;38;5;213m		         HERE WE GO!\033[0m\n");   


		/***************************************/
	/****************** ft_lstnew ******************/
		/***************************************/

/*  t_list    *ft_lstnew(char const *s, unsigned int start, size_t len)
	
	allocates with malloc and returns a new element. The variable content
	is initialized with the value of the parameter content. The variable
	next is initialized to null
*/
	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;40m		     ft_lstnew TESTER\033[0m\n\n");  

	t_list  *head;
	t_list  *new;

	char    newcontent[] = "NEW LST PLEASE!";

	new = ft_lstnew(newcontent);
	head = new;

	if((strncmp(new->content, newcontent, sizeof(newcontent)) == 0) && new->next == NULL)
		printf("\033[1;38;5;40mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");
	free(new);

		/***************************************/
	/****************** ft_lstadd_front ******************/
		/***************************************/

/*  void    ft_lstadd_front(t_list **lst, t_list *new)
	
	adds the element new at the beginning of the list
*/
	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;41m		   ft_lstadd_front TESTER\033[0m\n\n");  
 
	t_list  *head1;
	t_list  *first1;
	t_list  *new1;
	char    firstcontent[] = "FIRST ELEMENT";
	char    newcontent1[] = "NEW ELEMENT";

	first1 = ft_lstnew(firstcontent);
	head1 = first1;

	new1 = ft_lstnew(newcontent1);

	ft_lstadd_front(&head1, new1); 

   if(strncmp(head1->content, newcontent1, sizeof(newcontent1)) == 0)
		printf("\033[1;38;5;41mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");



		/***************************************/
	/****************** ft_lstsize ******************/
		/***************************************/

/*  int    ft_lstsize(t_list *lst)
	
	counts the number of elements in a list
*/

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;42m		     ft_lstsize TESTER\033[0m\n\n");  

	t_list  *one;
	t_list  *two;
	t_list  *three;
	t_list  *four;
	char    firstcont[] = "ELEMENT1";
	char    secondcont[] = "ELEMENT2";
	char    thirdcont[] = "ELEMENT3";
	char    fourthcont[] = "ELEMENT4";

	int     lstsize;

	one = ft_lstnew(firstcont);
	two = ft_lstnew(secondcont);
	three = ft_lstnew(thirdcont);
	four = ft_lstnew(fourthcont);

	head = one;
	one->next = two;
	two->next = three;
	three->next = four;

	lstsize = ft_lstsize(head);

	if(lstsize == 4)
		printf("\033[1;38;5;42mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");       


		/***************************************/
	/****************** ft_lstlast ******************/
		/***************************************/

/*  t_list    *ft_lstlast(t_list *lst)
	
	counts the number of elements in a list
*/

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;43m		     ft_lstlast TESTER\033[0m\n\n");  

	t_list  *last;
	last = ft_lstlast(head);

	if(strncmp(last->content, fourthcont, sizeof(fourthcont)) == 0)
 		printf("\033[1;38;5;43mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");      


		/***************************************/
	/****************** ft_lstadd_back ******************/
		/***************************************/

/*  void    ft_lstadd_back(t_list **lst, t_list *new)
	
	adds the element new at the end of the list
*/

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;44m		   ft_lstadd_back TESTER\033[0m\n\n");  

	t_list  *newback;
	t_list  *last_elem;
	char    lastcont[] = "LAST ELEMENT!";

	newback = ft_lstnew(lastcont);
	ft_lstadd_back(&head, newback);
	last_elem = ft_lstlast(head);

	if(strncmp(last_elem->content, lastcont, sizeof(lastcont)) == 0)
	 		printf("\033[1;38;5;44mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");    


		/***************************************/
	/****************** ft_lstdelone ******************/
		/***************************************/

/*  void    ft_lstdelone(t_list *lst, void (*del)(void*));
	
	takes as a parameter an element and frees the memory of the
	element's content using the function del given as a parameter 
	and then frees the element. The memory of next must not be freed.

 */

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;123m		    ft_lstdelone TESTER\033[0m\n\n");  

	t_list  *headdel;
	t_list  *firstdel;
	t_list  *seconddel;
	t_list  *thirddel;

	char    firstdelcontstr[] = "FIRST DEL ELEMENT";
	char    seconddelcontstr[] = "SECOND DEL ELEMENT";
	char    thirddelcontstr[] = "THIRD DEL CONTENT";
	char    empty[] = "";

	firstdel = ft_lstnew(firstdelcontstr);
	seconddel = ft_lstnew(seconddelcontstr);
	thirddel = ft_lstnew(thirddelcontstr);

	firstdel->content = strdup(firstdelcontstr);
	seconddel->content = strdup(seconddelcontstr);
	thirddel->content = strdup(thirddelcontstr);

	headdel = firstdel;
	firstdel->next = seconddel;
	seconddel->next = thirddel;

/*
	while(headdel != NULL)
	{
		printf("%s\n", headdel->content);
		printf("%p\n", headdel->next);
		headdel = headdel->next;
	}
*/

	ft_lstdelone(seconddel, &free);
	headdel = firstdel;

/*
	printf("\n");
	while(headdel != NULL)
	{
		printf("%s\n", headdel->content);
		printf("%p\n", headdel->next);
		headdel = headdel->next;
	}   
*/
	if(seconddel->next == thirddel && strncmp(seconddel->content, empty, 4) == 0)
		printf("\033[1;38;5;123mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");   


		/***************************************/
	/****************** ft_lstclear ******************/
		/***************************************/

/*  void    ft_lstclear(t_list **lst, void (*del)(void*));
	
	deletes and frees the given element and every successor
	of that element, using the function del and free. The 
	pointer to list must be set to NULL

 */

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;117m		    ft_lstclear TESTER\033[0m\n\n");  

	t_list  *headclear;
	t_list  *firstclear;
	t_list  *secondclear;
	t_list  *thirdclear;

	char    firstclearcontstr[] = "FIRST DEL ELEMENT";
	char    secondclearcontstr[] = "SECOND DEL ELEMENT";
	char    thirdclearcontstr[] = "THIRD DEL CONTENT";

	firstclear = ft_lstnew(firstclearcontstr);
	secondclear = ft_lstnew(secondclearcontstr);
	thirdclear = ft_lstnew(thirdclearcontstr);

	firstclear->content = strdup(firstclearcontstr);
	secondclear->content = strdup(secondclearcontstr);
	thirdclear->content = strdup(thirdclearcontstr);

	headclear = firstclear;
	firstclear->next = secondclear;
	secondclear->next = thirdclear;
	
	ft_lstclear(&headclear, &free);

	if(headclear == NULL)
	   printf("\033[1;38;5;117mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");       

		/***************************************/
	/****************** ft_lstiter ******************/
		/***************************************/

/*  void    ft_lstiter(t_list *lst, void (*f)(void *));
	
	iterates the list 'lst' and applies the function f
	to the content of each element

 */

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;153m		     ft_lstiter TESTER\033[0m\n\n");  

	char    lstiterone[] = "element1";
	char    lstitertwo[] = "element2";
	char    lstiterthree[] = "element3";
	char    lstiterfour[] = "element4";
	char    lstiterlast[] = "last element!";

	ft_lstiter(head, f);

	if((strncmp(firstcont, lstiterone, sizeof(lstiterone)) == 0) && (strncmp(secondcont, lstitertwo, sizeof(lstitertwo)) == 0) &&
	(strncmp(thirdcont, lstiterthree, sizeof(lstiterthree)) == 0) && (strncmp(fourthcont, lstiterfour, sizeof(lstiterfour)) == 0) &&
	(strncmp(lastcont, lstiterlast, sizeof(lstiterlast)) == 0))
		printf("\033[1;38;5;153mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");  


		/***************************************/
	/****************** ft_lstmap ******************/
		/***************************************/

/*  t_list    *ft_lstmap(t_list *lst, void (*g)(void *), void (*del)(void *));
	
	iterates the list 'lst' and applies the function f
	to the content of each element. Creates a new list resulting  in the 
	successive applications of the  function f. The del function is used 
	to  delete the  content of an element if needed.

 */

	printf("\n----------------------------------------------------------\n");
	printf("\n\033[1;38;5;39m		     ft_lstmap TESTER\033[0m\n\n");  

	t_list	*lstmapnew;
	char    lstmapone[] = "ELEMENT1";
	char    lstmaptwo[] = "ELEMENT2";
	char    lstmapthree[] = "ELEMENT3";
	char    lstmapfour[] = "ELEMENT4";
	char    lstmaplast[] = "LAST ELEMENT!";

/*	while(head != NULL)
	{
		printf("%s\n", head->content);
		head = head->next;
	} 
*/
	head = one;
	lstmapnew = ft_lstmap(head, g, &free);
/*	
	while(lstmapnew != NULL)
	{
		printf("%s\n", lstmapnew->content);
		lstmapnew = lstmapnew->next;
	} 
*/
	if((strncmp(firstcont, lstmapone, sizeof(lstiterone)) == 0) && (strncmp(secondcont, lstmaptwo, sizeof(lstitertwo)) == 0) &&
	(strncmp(thirdcont, lstmapthree, sizeof(lstiterthree)) == 0) && (strncmp(fourthcont, lstmapfour, sizeof(lstiterfour)) == 0) &&
	(strncmp(lastcont, lstmaplast, sizeof(lstiterlast)) == 0))
		printf("\033[1;38;5;39mOK - \033[0m");
	else
		printf("\033[1;38;5;196mKO - \033[0m");
	printf("basic\n");  

	printf("\n----------------------------------------------------------\n");
 	printf("\n\033[1;38;5;213m		   END OF BONUS SECTION\n\n		          WOOHOO!\033[0m\n\n");   


}
