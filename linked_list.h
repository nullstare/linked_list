typedef struct linked_list linked_list;

struct linked_list {
    char *data;
    int index; /* position of the element in the list, normally not used with Linked Lists, just for exercise */
    struct linked_list *next;
};

/*Function will create a new list item and add that to end of list
    check if pointer is NULL
    find end of list
    will create a new element (malloc)
    add s to data item of new element
    make link from last element to new element (next)
    add NULL to new elements next
    write new index (last+1) to new elements index
 *ll is pointing to head/last element of the list
    return: -1 as error (no space left), index position in success */
int add_to_list( struct linked_list *ll, char *s );

/*List all elements in a list
  return: number of elements in list*/
int display_list(linked_list *ll);

/*Displays the required element (pointed by parameter linked_list *ll) in a list
  Return: -1 element not found , 0 ok */
int display_item(linked_list *ll);

/*Search for a data *s from a list
  Return: NULL if not found, pointer to */
linked_list * search_from_list(linked_list *ll, char *s);

/*Delete item from a list and free space
  Rest of list items index will be counted again
  Return value: -1 on error, length of remaining list*/
int delete_from_list(linked_list *ll, int index);

/*remove all items from the list and will free allocated memory
  return value items deleted from the list*/
int empty_list(linked_list *ll);

/*Sort list in rising order based on the data*/
int sort_list(linked_list *ll);
