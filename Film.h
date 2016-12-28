/*****************************************************************************
 
File        : Film.h
 
Date        : Wednesday 26th October 2016
 
Author      : Bijan G.A
  
Description : Header file for a simple Abstract Data Type (ADT) representing
              a film.  The implementation is currently very basic and a full
              implementation would have many more interface functions.
 
History     : 26/10/2016 - v1.00
  
*****************************************************************************/

#ifndef FILM_H
#define FILM_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct FilmStruct
{    
    
    char *title;
    
    int year;
  
    char *classification;
    
    char *genre;
    
    int length;
  
    float rating;        
}
Film;

/*****************************************************************************

Function    : film_new

Parameters  : char *title - day of month [1 - days in month]  
              int year - month (enumeration type) [JAN, FEB, ..., DEC]
              char *classification - year (positive)
              char *genre - year (positive)
              int length - year (positive)
              float rating - year (positive)
 
Returns     : Film * - pointer to dynamically allocated Film structure.

Description : Dynamically allocate the memory for a Film structure and 
              initialise to the film given by the arguments.
  
*****************************************************************************/

Film *film_new(char *title,int year,char *classification,char *genre, int length, float rating);

/*****************************************************************************

Function    : film_fprint

Parameters  : FILE       *fd   - descriptor of the output stream
              const Film *film - pointer to film structure (n.b. const)
 
Returns     : none

Description : Print a minimal textual representation of a Film structure.
  
*****************************************************************************/

void film_fprint(FILE *fd, const Film *film);

/*****************************************************************************

Function    : film_free

Parameters  : Film *film - pointer to dynamically allocated Film structure.
 
Returns     : void

Description : Free dynamically allocated memory used for a Film structure.
  
*****************************************************************************/

void film_free(Film *film);

/*****************************************************************************

Function    : film_getTitle

Parameters  : const Film *film - pointer to a Film structure (n.b. const)
 
Returns     : char* - title of a film

Description : Accessor method returning the title of a film for a Film
              struct.  Use this in preference to directly accessing the struct
              to maintain encapsulation (allowing the implementation of the
              struct to be changed without affecting the client code (define
              inline to avoid computational overhead).
  
*****************************************************************************/

static inline char* film_getTitle(const Film *film)
{
    return film->title;
}

/*****************************************************************************

Function    : film_getYear

Parameters  : const Film *film - pointer to a Film structure (n.b. const)
 
Returns     : int - release year of a film

Description : Accessor method returning the release year of a filmm for a Film
              struct.  Use this in preference to directly accessing the struct
              to maintain encapsulation (allowing the implementation of the
              struct to be changed without affecting the client code (define
              inline to avoid computational overhead).
  
*****************************************************************************/

static inline int film_getYear(const Film *film)
{
    return film->year;
}

/*****************************************************************************

Function    : film_getClassification

Parameters  : const Film *film - pointer to a Film structure (n.b. const)
 
Returns     : char* - Classification of a film

Description : Accessor method returning the Classification of a film for a Film
              struct.  Use this in preference to directly accessing the struct
              to maintain encapsulation (allowing the implementation of the
              struct to be changed without affecting the client code (define
              inline to avoid computational overhead).
  
*****************************************************************************/

static inline char* film_getClassification(const Film *film)
{
    return film->classification;
}

/*****************************************************************************

Function    : film_getGenre

Parameters  : const Film *film - pointer to a Film structure (n.b. const)
 
Returns     : char* - Genre of a film

Description : Accessor method returning the Genre of a film for a Film
              struct.  Use this in preference to directly accessing the struct
              to maintain encapsulation (allowing the implementation of the
              struct to be changed without affecting the client code (define
              inline to avoid computational overhead).
  
*****************************************************************************/

static inline char* film_getGenre(const Film *film)
{
    return film->genre;
}

/*****************************************************************************

Function    : film_getLength

Parameters  : const Film *film - pointer to a Film structure (n.b. const)
 
Returns     : int - the Length of a film

Description : Accessor method returning the Length of a film for a Film
              struct.  Use this in preference to directly accessing the struct
              to maintain encapsulation (allowing the implementation of the
              struct to be changed without affecting the client code (define
              inline to avoid computational overhead).
  
*****************************************************************************/

static inline int film_getLength(const Film *film)
{
    return film->length;
}

/*****************************************************************************

Function    : film_getRating

Parameters  : const Film *film - pointer to a Film structure (n.b. const)
 
Returns     : float - the Rating of a film

Description : Accessor method returning the Rating of a film for a Film
              struct.  Use this in preference to directly accessing the struct
              to maintain encapsulation (allowing the implementation of the
              struct to be changed without affecting the client code (define
              inline to avoid computational overhead).
  
*****************************************************************************/

static inline float film_getRating(const Film *film)
{
    return film->rating;
}

/*****************************************************************************

Function    : film_setTitle

Parameters  : const Film *film - pointer to a Film structure 
              char  *title  - the title of a film 

Returns     : void

Description : Mutator/setter function used to alter the title of the film of a
              Film structure.
  
*****************************************************************************/

void film_setTitle(Film *film, char *title);

/*****************************************************************************

Function    : film_setYear

Parameters  : Film *film - pointer to a Film structure 
              int  year  - the release year of a film 

Returns     : void

Description : Mutator/setter function used to alter the release year of the 
              film of a Film structure.
  
*****************************************************************************/

void film_setYear(Film *film, int year);

/*****************************************************************************

Function    : film_setClassification

Parameters  : Film *film - pointer to a Film structure 
              char  *classification  - the classification of a film 

Returns     : void

Description : Mutator/setter function used to alter the classification of a 
              film of a Film structure.
  
*****************************************************************************/

void film_setClassification(Film *film, char *classification);

/*****************************************************************************

Function    : film_setGenre

Parameters  : Film *film - pointer to a Film structure 
              char  *genre  - the genre of a film 

Returns     : void

Description : Mutator/setter function used to alter the genre of a 
              film of a Film structure.
  
*****************************************************************************/

void film_setGenre(Film *film, char *genre);

/*****************************************************************************

Function    : film_setLength

Parameters  : Film *film - pointer to a Film structure 
              int  length  - the length of a film 

Returns     : void

Description : Mutator/setter function used to alter the length of a 
              film of a Film structure.
  
*****************************************************************************/

void film_setLength(Film *film, int length);

/*****************************************************************************

Function    : film_setRating

Parameters  : Film *film - pointer to a Film structure 
              float  rating  - the rating of a film 

Returns     : void

Description : Mutator/setter function used to alter the rating of a 
              film of a Film structure.
  
*****************************************************************************/

void film_setRating(Film *film, float rating);
   
#ifdef __cplusplus
}
#endif

#endif /* FILM_H */

