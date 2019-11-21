#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int add_to_list( struct linked_list *ll, char *s ) {
    while ( ll->next != NULL ) {
        ll = ll->next;
    }

    struct linked_list *node = NULL;
    node = (struct linked_list*)malloc( sizeof( linked_list ) );

    if ( node == NULL ) {
        return -1;
    }

    node->next = NULL;
    node->index = ll->index + 1;
    node->data = s;

    ll->next = node;

    return node->index;
}

int display_list( struct linked_list *ll ) {
    int i = 0;
    while ( ll->next != NULL ) {
        ll = ll->next;
        i++;
        printf( "%s\n", ll->data );
    }

    return i;
}

int display_item(linked_list *ll) {
    if ( ll->data == NULL ) {
        return -1;
    }
    else {
        printf( "%s\n", ll->data );
        return 0;
    }
}

linked_list * search_from_list(linked_list *ll, char *s) {
    while ( ll->next != NULL ) {
        ll = ll->next;

        if ( strcmp( ll->data, s ) == 0 ) {
            return ll;
        }
    }

    return NULL;
}

int delete_from_list(linked_list *ll, int index) {
    int i = 0;

    struct linked_list *last = NULL;

    while ( ll != NULL ) {
        last = ll;
        last->index = i;
        i++;

        if ( ll->index == index && ll->next != NULL ) {
            last->next = ll->next;
            free( ll );
        }
        else {
            ll = ll->next;
        }
    }
    return i;
}

int empty_list(linked_list *ll) {
    int i = 0;
    
    struct linked_list *last = NULL;

    while ( ll->next != NULL ) {
        last = ll;
        free( last );
        ll = ll->next;
        i++;
    }
    return i;
}
