/* 
 * File:   main.c
 * Author: Bijan G.A 
 * Created on 26 October 2016, 17:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#include "moviedatabase.h"

int main(int argc, char** argv) {

    
    // The address of the file containing films
    char *address = "C:\\Users\\Bijan\\Desktop\\Programming\\films.txt";
    
    // Making a list that is to store films from a file
    List* list = list_new();
    
    // Loading the movie database from the file containing films 
    LoadFilmsFromFileToList(address, list);
    
    // TASK 1
    // Sorting the list of films in a chronological order of release year
    list_sort_chronological(list);
    
    // TASK 2
    // Displaying the third longest Film-Noir
    printf("The third longest Film-Noir film: ");
    third_longest_film_noir(list);
    printf("\n\n");
    
    // TASK 3
    //Displaying the tenth highest rated Sci-Fi film
    printf("The tenth highest rated Sci-Fi ﬁlm: ");
    tenth_highest_rated_sci_fi(list);
    printf("\n\n");
    
    // TASK 4
    // Displaying the highest rated ﬁlm.
    printf("The highest rated film: ");
    list_sort_highest_rated(list);
    printf("\n\n");
    
    // TASK 5
    // Displaying the ﬁlm with the shortest title.
    printf("The film with the shortest title: ");
    shortest_title(list);
    printf("\n\n");
    
    // TASK 6
    // Displaying the number of ﬁlms left in the database after deleting all R rated ﬁlms.
    printf("The number of films that are not R rated is: ");
    char* rate = "R";
    remove_rated_films(list, rate);
    printf("%d\n", list_length(list));
    printf("\n\n");
    
            
    return (EXIT_SUCCESS);
}

