/*****************************************************************************

File        : moviedatabase.h

Description : Header file for a simple C implementation of a singly linked
              list of films.

Author      : Bijan G.A

******************************************************************************/
#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H



#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct _Node
    {
        Film film;

        struct _Node* next;
    }
    Node;

    typedef struct _List
    {
        Node* first;

        Node* last;
    } 
    List;

    void LoadFilmsFromFileToList(char *address, List* list);
    
    typedef Node* Iterator;

    static inline Iterator list_begin(const List *list)
    {
       return list->first;
    }

    static inline Iterator list_end(const List *list)
    {
       return NULL;
    }

    static inline Iterator iterator_next(const Iterator i)
    {
       return i->next;
    }

    static inline char iterator_value_title(const Iterator i)
    {
        return i->film.title;
    }

    static inline Iterator iterator_set_title(Iterator i, char title)
    {
        i->film.title = title;
    }

    /*****************************************************************************

    Procedure   : list_new

    Parameters  : none

    Returns     : List* - pointer to newly created list

    Description : Allocate memory for a new linked list of films and
                  initialise it.  Generates an error message and the program
                  terminates if insufficient memory is available.

     *****************************************************************************/

    List* list_new();

    /*****************************************************************************

    Procedure   : list_add

    Parameters  : List* list - pointer to list to which a film is added
                  Film* film - pointer to a film to be added to the list

    Returns     : none

    Description : Appends a film to the tail of the list. Generates an 
                  error message and the program terminates if insufficient memory 
                  is available.

     *****************************************************************************/

    void list_add(List* list, Film* film);
    
    /*****************************************************************************

    Procedure   : list_length

    Parameters  : List* list - pointer to a lined list structure.

    Returns     : int - number of elements comprising the list.

    Description : Determines the number of films currently stored in a
                  linked list structure.

     *****************************************************************************/

    int list_length(List* list);

    /*****************************************************************************

    Procedure   : list_clear

    Parameters  : List* list - pointer to a linked list structure

    Returns     : none

    Description : Delete all elements from a linked list structure.

     *****************************************************************************/

    void list_clear(List *list);

    /*****************************************************************************

    Procedure   : list_fprint

    Parameters  : List* list - pointer to a linked list structure.
                  FILE* fd   - pointer to a file stream descriptor structure.

    Returns     : none

    Description : Prints a linked list of films including their relevant date
                  to the specified output
                  stream (typically stdout), as a set of comma separated data
                  enclosed in parentheses.

     *****************************************************************************/

    void list_fprint(List* list, FILE* fd);

    
    /*****************************************************************************

    Procedure   : list_sort_chronological

    Parameters  : List* list - pointer to a linked list structure.

    Returns     : none

    Description : Sorts the elements of a linked list structure into ascending
                  order of release year, using the bubble sort algorithm, and 
                  displaying it.

     *****************************************************************************/

    void list_sort_chronological(List* list);
    
    /*****************************************************************************

    Procedure   : extract_new_list_of_genre

    Parameters  : List* list - pointer to a linked list structure.
                  char* extract_genre - pointer to a genre name.

    Returns     : List* - Returns a list which includes films with a specific
                          genre

    Description : Extract the films with specific genres and creates a list of 
                  them.

     *****************************************************************************/

    List* extract_new_list_of_genre(List* list, char* extract_genre);
    
    /*****************************************************************************

    Procedure   : third_longest_film_noir

    Parameters  : List* list - pointer to a linked list structure.

    Returns     : none

    Description : Sorts a list of film-noir films in a decreasing order of
                  duration, and displays the third longest film-noir film

     *****************************************************************************/

    void third_longest_film_noir(List* list);
    
    /*****************************************************************************

    Procedure   : tenth_highest_rated_sci_fi

    Parameters  : List* list - pointer to a linked list structure.

    Returns     : none

    Description : Sorts the elements of a linked list of Sci-Fi films in a 
                  decreasing order of rating, and displays the tenth highest
                  rated Sci-Fi film.

     *****************************************************************************/

    void tenth_highest_rated_sci_fi(List* list);

    /*****************************************************************************

    Procedure   : list_sort_highest_rated

    Parameters  : List* list - pointer to a linked list structure.

    Returns     : none

    Description : Sorts the elements of a linked list structure into ascending
                  order of rating, and displays the highest rated film.

     *****************************************************************************/

    void list_sort_highest_rated(List* list);
    
    /*****************************************************************************

    Procedure   : shortest_title

    Parameters  : List* list - pointer to a linked list structure.

    Returns     : none

    Description : Searches through the films of a linked list and finds the 
                  film with the shortest title.

     *****************************************************************************/

    void shortest_title(List* list);
    
    /*****************************************************************************

    Procedure   : remove_rated_films

    Parameters  : List* list - pointer to a linked list structure.

    Returns     : none

    Description : Goes through a linked list of films and removes the r rated 
                  films and displays the length of the linked list after that.

     *****************************************************************************/

    void remove_rated_films(List* list, char* rate);
            
    

#ifdef __cplusplus
}
#endif

#endif /* MOVIEDATABASE_H */

