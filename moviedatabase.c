#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#include "moviedatabase.h"


/*****************************************************************************

Function    : makeFilmConstruct

Parameters  : char *address - pointer to dynamically allocated char.
 
Returns     : void

Description : Read date from the file(address) given and makes film structs.
  
*****************************************************************************/
void LoadFilmsFromFileToList(char *address, List* list){
    
    FILE *ptr_file;
    char buf[1000];
    const char c[2] = ",";
    const char q[2] = "\"";
    char *token;
    
    ptr_file =fopen(address,"r");    
    
    while (fgets(buf,1000, ptr_file)!= NULL)
    {

        //For triggering the while loop 
        token = "s";
         
        //Temporary variables to make a film struct
        int counter = 1;
        char *title;
        int year;
        char *classification;
        char *genre;
        int length;
        float rating;
        while( token != NULL ) 
        {
            switch(counter) {
                
                case 1:   
                   token = strtok(buf, q);                    
                   title = token;
                   token = strtok(NULL, c);
                   break; 

                case 2:                                       
                    year = atoi (token);
                    token = strtok(NULL, q);
                    break; 
                   
                case 3:                    
                   classification = token;
                   token = strtok(NULL, q);
                   token = strtok(NULL, q);                          
                   break; 
                   
                case 4:                    
                   genre = token;
                   token = strtok(NULL, c);
                   break;
                   
                case 5:                    
                   length = atoi (token);
                   token = strtok(NULL, c);
                   break;    
                   
                case 6:                    
                   rating = atof (token);
                   token = strtok(NULL, c);
                   break;      
                   
                default : 
                    break;
             }            
            counter ++;
        }
            Film *film = film_new(title,year,classification,genre,length,rating);
            list_add(list, film);      
    }  
    fclose(ptr_file);
}

List* list_new()
{
   List* list = (List*)malloc(sizeof(List));
    
   if (list == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate memory in list_new()\n");
      
      exit(EXIT_FAILURE);
   }
   
   list->first = NULL;
   list->last  = NULL;
   
   return list; 
}

void list_add(List* list, Film* film)
{
   Node* node = (Node*)malloc(sizeof(Node));
   
   if (node == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate memory in list_add()\n");
      
      exit(EXIT_FAILURE);
   }
   
   node->film.title = film->title;
   node->film.year = film->year;
   node->film.classification = film->classification;
   node->film.genre = film->genre;
   node->film.length = film->length;
   node->film.rating = film->rating;   
   node->next  = NULL;       
   
   if (list->last == NULL)
   {
      list->first = list->last = node;
   }
   else
   {
      list->last = list->last->next = node;  
   }
}

void list_fprint(List* list, FILE* fd)
{
   printf("list = ");
   fprintf(fd, "(");
    
   Node* node;
   for (node = list->first; node != NULL; node = node->next)
   {
       fprintf(fd,"%s, %d, %s, %s, %d, %.1f | ", node->film.title,
               node->film.year, node->film.classification, node->film.genre, 
               node->film.length, node->film.rating);
   }
   if(node!= NULL){
       fprintf(fd, "%s, %d, %s, %s, %d, %.1f | ", node->film.title,
               node->film.year, node->film.classification, node->film.genre,
               node->film.length, node->film.rating);
   }
   
   fprintf(fd, ")\n\n");
   free(node);
}

List* extract_new_list_of_genre(List* list, char *extract_genre){
    
    // Making a list that is to contain film-noir films
    List* new_list = list_new();
    
    // Extracting a list of specified genre of films from the original list    
    for (Node* node=list->first; node->next!=NULL; node=node->next)
    {         
       char *genre = node->film.genre;

       if (strstr(genre, extract_genre) != 0)
       {           
           Film *film = &node->film;
           list_add(new_list, film);               
       } 
    }
    return new_list;
}

void list_sort_chronological(List *list)
{
   if (list->first != list->last)   // list contains two or more items
   {
      int sorted;
      
      do
      {
         sorted = 1; 
         
         for (Node* node=list->first; node->next!=NULL; node=node->next)
         {
            if (node->film.year > node->next->film.year)
            {
               Film film = node->film;
               node->film = node->next->film;
               node->next->film = film;
               sorted= 0;
            }
         }
      }
      while (!sorted);
   }      
   list_fprint(list, stdout);   
}

void third_longest_film_noir(List* list){
    
    char* extract_genre = "Film-Noir";
    
    List* film_noir_list = extract_new_list_of_genre(list, extract_genre);
    
    // Sorting the list of film-noir films in a decreasing order of duration
    for (Node* node=list->first; node->next!=NULL; node=node->next)
    {
      int sorted;
      do
      {
         sorted = 1; 
         
         for (Node* node=film_noir_list->first; node->next!=NULL; node=node->next)
         {
            if (node->film.length < node->next->film.length)
            {
               Film film = node->film;
               node->film = node->next->film;
               node->next->film = film;
               sorted= 0;
            }
         }
      }
      while (!sorted);
    }
    
    // Displaying the third longest Film-Noir Film
    int counter = 1;
    Node* node;
    for(node = film_noir_list->first; counter != 3; node = node->next){
        counter++;
    }
    Film *thirdLongestFilm = &node->film;
    film_fprint(stdout, thirdLongestFilm);
}

void tenth_highest_rated_sci_fi(List* list){
    
    char* extract_genre = "Sci-Fi";
    
    List* sci_fi_list = extract_new_list_of_genre(list, extract_genre);
    
    // Sorting the list of Sci-Fi films in a decreasing order of rating
    for (Node* node=list->first; node->next!=NULL; node=node->next)
    {
      int sorted;
      
      do
      {
         sorted = 1; 
         
         for (Node* node=sci_fi_list->first; node->next!=NULL; node=node->next)
         {
            if (node->film.rating < node->next->film.rating)
            {
               Film film = node->film;
               node->film = node->next->film;
               node->next->film = film;
               sorted= 0;
            }
         }
      }
      while (!sorted);
    }
    
    // Displaying the tenth longest Sci-Fi Film
    int counter = 1;
    Node* node;
    for(node = sci_fi_list->first; counter != 10; node = node->next){
        counter++;
    }
    Film *thirdLongestFilm = &node->film;
    film_fprint(stdout, thirdLongestFilm);
    free(node);
}

void list_sort_highest_rated(List* list){
    if (list->first != list->last)   // list contains two or more items
   {
      int sorted;
      do
      {
         sorted = 1; 
                  
         for (Node* node=list->first; node->next!=NULL; node=node->next)
         {
            if (node->film.rating > node->next->film.rating)
            {
               Film film = node->film;
               node->film = node->next->film;
               node->next->film = film;
               sorted= 0;
            }
         }
      }
      while (!sorted);
   }
    Film *highestRated = &list->last->film;
    film_fprint(stdout, highestRated);
}

void shortest_title(List* list){
    if (list->first != list->last)   // list contains two or more items
    {
        int shortest_film_title_legnth = 1000000;
        Film shortest_film_title;
        
        // Finding the film with the shortest title
        for (Node* node=list->first; node->next!=NULL; node=node->next)
        {            
           if (strlen(node->film.title) < shortest_film_title_legnth)
           {
               shortest_film_title_legnth = strlen(node->film.title);
                shortest_film_title = node->film;
           }
        }
        Film *film = &shortest_film_title;
        film_fprint(stdout, film);
    }
}

void remove_rated_films(List* list, char* rate)
{                    
    for (Node* node=list->first; node->next!=NULL; node=node->next)
    {       
        if(strcmp(node->film.classification, rate) == 0)
        {   
            // Finding the previous film of an R rated film in the database
            Node* prev = list->first;
            while(prev->next != NULL && prev->next != node){
                prev = prev->next;
            }
                      
            prev->next = node->next;
            free(node);                        
        } 
    }        
}

void list_clear(List *list)
{
   while (list->first != NULL)
   {
      Node* node = list->first;
      
      list->first = node->next;
      
      free(node);    
     
   }
   
   list->last = NULL;
}

int list_length(List* list){
    int length = 0;
    
   for (Node* node = list->first; node != NULL; node = node->next)
   {
       length++;
   }
    
   return length;
}