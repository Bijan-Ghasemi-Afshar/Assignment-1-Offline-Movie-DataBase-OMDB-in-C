/*****************************************************************************
 
File        : date.c
 
Date        : Tuesday 25th October 2016
 
Author      : Gavin Cawley
  
Description : Source file for a simple Abstract Data Type (ADT) representing
              a date.  The implementation is currently very basic and a full
              implementation would have many more interface functions.
 
History     : 20/10/2016 - v1.00
              25/10/2016 - v1.10 tidied up the code, comments etc.
  
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Film.h"


Film *film_new(char *title,int year,char *classification,char *genre, int length, float rating)
{   
    
   Film *film = (Film*)malloc(sizeof(Film));
         
   film->title   = strdup(title);
   film->year   = year;
   film->classification  = strdup(classification);
   film->genre  = strdup(genre);
   film->length = length;
   film->rating  = rating;
   
   return film;
}


void film_fprint(FILE *fd, const Film *film)
{
    fprintf(fd, "%s|%02d|%s|%s|%02d|%.1f",film->title, film->year,film->classification,film->genre, film->length, film->rating);
}

void film_free(Film *film)
{
    free(film);
}

void film_setTitle(Film *film, char *title)
{
    film->title = strdup(title);
}

void film_setYear(Film *film, int year)
{
    if (year < 0)
    {
        fprintf(stderr, "Error invalid year!\n");
        
        exit(EXIT_FAILURE);
    }
    
    film->year = year;
}

void film_setClassification(Film *film, char *classification)
{
    film->classification = strdup(classification);
}

void film_setGenre(Film *film, char *genre)
{
    film->genre = strdup(genre);
}

void film_setLength(Film *film, int length)
{
    if (length < 0)
    {
        fprintf(stderr, "Error invalid length!\n");
        
        exit(EXIT_FAILURE);
    }
    
    film->length = length;
}

void film_setRating(Film *film, float rating)
{
    if (rating < 0)
    {
        fprintf(stderr, "Error invalid rating!\n");
        
        exit(EXIT_FAILURE);
    }
    
    film->rating = rating;
}