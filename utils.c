#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"




//Push a new book node at the begining books list
void add_book (struct book_node **head_book, long authors[], char *new_book_title) {
    struct book_node *new_book = malloc (sizeof (*new_book));
    if (new_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    strcpy (new_book->book_title, new_book_title);
    for (int i = 0; i < 10; i++){
        new_book->authors[i] = authors[i];
    }
    new_book->next = *head_book;
    *head_book = new_book;
}

// Push a new author node at the begining author list
void add_author (struct author_node **head_author, long new_id_author, char *new_author_name, char *new_author_given_name) {
    struct author_node *new_author = malloc (sizeof (*new_author));
    if (new_author == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    strcpy(new_author->author_name, new_author_name);
    strcpy(new_author->author_given_name, new_author_given_name);
    new_author->id_author = new_id_author;
    new_author->next = *head_author;
    *head_author = new_author;
}


// List of authors that co-authored a given book
void search_book_authors(struct book_node *head_book, struct author_node *head_author, char *title){

    struct book_node *iterator_book = malloc (sizeof (*iterator_book));
    if (iterator_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_book = head_book;
    struct author_node *iterator_author = malloc (sizeof (*iterator_author));
    if (iterator_author == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_author = head_author;

    while (iterator_book != NULL) {
        if(strcmp(iterator_book->book_title, title) == 0){
            printf("\nCartea -  %s - are autori:\n", iterator_book->book_title);
            for(int i=0; i<10; i++){
                if(iterator_book->authors[i] != 0){
                    while (iterator_author != NULL) {
                        if(iterator_author->id_author == iterator_book->authors[i]){
                            printf("    - %s %s (id %ld)\n", iterator_author->author_name,
                              iterator_author->author_given_name, iterator_author->id_author);
                        }
                        iterator_author = iterator_author->next;
                    }
                }
                iterator_author = head_author;
            }
        break;
        }
        iterator_book = iterator_book->next;
    }
    free(iterator_book);
    free(iterator_author);
}


// List of books co-authored by a given author
void search_author_books(struct book_node *head_book, struct author_node *head_author, char *author_name, char *author_given_name){

    struct book_node *iterator_book = malloc (sizeof (*iterator_book));
    if (iterator_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_book = head_book;
    struct author_node *iterator_author = malloc (sizeof (*iterator_author));
    if (iterator_author == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_author = head_author;

    while (iterator_author != NULL) {
        if(strcmp(iterator_author->author_name, author_name) == 0){
            if(strcmp(iterator_author->author_name, author_name) == 0){
                while (iterator_book != NULL) {
                    for(int i=0; i<10; i++){
                        if(iterator_author->id_author == iterator_book->authors[i]){
                            printf("    - %s \n", iterator_book->book_title);
                        }
                    }
                    iterator_book = iterator_book->next;
                }
            }
        break;
        }
        iterator_author = iterator_author->next;
    }
    free(iterator_book);
    free(iterator_author);
}


// Find a book and return 1 if it's founded or 0 if it's not founded
long find_book (struct book_node *head_book, char *title){
    struct book_node *current_book = malloc (sizeof (*current_book));  // current_book as iterator node for book's list
    if (current_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    current_book = head_book;
    while (current_book != NULL){
        if (strcmp(current_book->book_title, title) == 0)
            return 1;
        current_book = current_book->next;
    }

    return 0;
}

// Find an author (name and given name) and return ID_AUTHOR if it's founded or 0 if it's not founded
long find_author (struct author_node *head_author, char *searched_author_name, char *searched_author_given_name){
    while (head_author != NULL){
        if (strcmp(head_author->author_name, searched_author_name) == 0){
            if (strcmp(head_author->author_given_name, searched_author_given_name) == 0){
                return head_author->id_author;
            }
        }
        head_author = head_author->next;
    }
    return 0;
}

//List all books with authors (id authors)
void list_library (struct book_node *current_book) {
     while (current_book != NULL) {
        printf ("Cartea - %s - are autori: ", current_book->book_title);
        for (int i = 0; i < 10; i++){
            if (current_book->authors[i]>0){
                printf ("%ld ", current_book->authors[i]);
            }
        }
        printf("\n");
        current_book = current_book->next;
    }
}

//List all authors
void list_authors(struct author_node *current_author){
     while (current_author != NULL) {
        printf ("     %s %s (id %ld)\n", current_author->author_name, current_author->author_given_name, current_author->id_author);
        current_author = current_author->next;
    }
}

//Save the library books to file "file_books.txt"
void save_library_books (struct book_node *current_book) {
    FILE *file_books;            //pointer to the file where some examples of books are
    file_books = fopen("data/file_books.txt", "w+");
    if (file_books == NULL) {
        printf("Error open file_books.txt!");
        exit(0);
    }

    while (current_book != NULL) {
        fprintf (file_books, "%s\n", current_book->book_title);
        fprintf (file_books, "%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n", current_book->authors[0],
                 current_book->authors[1], current_book->authors[2], current_book->authors[3], current_book->authors[4],
                 current_book->authors[5], current_book->authors[6], current_book->authors[7], current_book->authors[8],
                 current_book->authors[9]);
        current_book = current_book->next;
    }
    fclose(file_books);
}

//Save the library authors to file "file_authors.txt"
void save_library_authors (struct author_node *current_author) {
    FILE *file_authors;           //pointer to the file where some examples of authors are
    file_authors = fopen("data/file_authors.txt", "w+");
    if (file_authors == NULL) {
        printf("Error open file_authors.txt!");
        exit(0);
    }
    while (current_author != NULL) {
        fprintf (file_authors, "%ld\n", current_author->id_author);
        fprintf (file_authors, "%20s\n", current_author->author_name);
        fprintf (file_authors, "%20s\n", current_author->author_given_name);
        current_author = current_author->next;
    }
    fclose(file_authors);
}

//Load the library books from file "file_books.txt"
void read_file_books (struct book_node **head_book) {
    long authors[10];  // to read array (10 elements) of ID authors for each book
    char title[100];      // ro read the title of the book
    FILE *file_books;        //pointer to the file where some examples of books are
    file_books = fopen("data/file_books.txt", "r+");
    if (file_books == NULL) {
        printf("Error open file_books.txt!");
        exit(0);
    }
char c;   // do nothing, just to pass over the special characters from end of line (\t,\n)
    while (1){
        fscanf (file_books, "%[^\t\n]s", title);
        for (int i = 0; i < 10; i++){
            fscanf (file_books, "%ld", &authors[i]);
        }
        fscanf (file_books, "%c\n", &c);

        struct book_node *new_book = malloc (sizeof (*new_book));    //node for a book read from file
        if (new_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
        strcpy (new_book->book_title, title);
        for (int i = 0; i < 10; i++){
            new_book->authors[i] = authors[i];
        }
        new_book->next = *head_book;
        *head_book = new_book;

        if (feof(file_books))
            break;
    }
    fclose(file_books);
}

//Load the library authors from file "file_authors.txt"
void read_file_authors (struct author_node **head_author) {
    long id_author;      //store ID of each author read from file
    char author_name[20];         //store name of each author read from file
    char author_given_name[20];     //store given name of each author read from file
    FILE *file_authors;
    file_authors = fopen("data/file_authors.txt", "r+");
    if (file_authors == NULL) {
        printf("Error open file_authors.txt!");
        exit(0);
    }

    while (1){
        fscanf (file_authors, "%ld", &id_author);
        fscanf (file_authors, "%s\n", author_name);
        fscanf (file_authors, "%s\n", author_given_name);

        struct author_node *new_author = malloc (sizeof (*new_author));
        if (new_author == NULL) {
            printf("Memory not allocated!\n");
            exit(0);
        }
        new_author->id_author = id_author;
        strcpy (new_author->author_name, author_name);
        strcpy (new_author->author_given_name, author_given_name);
        new_author->next = *head_author;
        *head_author = new_author;
        if (feof(file_authors))
            break;
    }
    fclose(file_authors);
}


long list_books_lenght (struct book_node *current_list){

    long lenght=0;
    while (current_list != NULL){
        lenght++;
        current_list = current_list->next;
    }

return lenght;
}

long list_authors_lenght (struct author_node *current_list){

    long lenght=0;
    while (current_list != NULL){
        lenght++;
        current_list = current_list->next;
    }

return lenght;
}

// List of authors that co-authored a given book
void search_book_authors_nodisplay(struct book_node *head_book, struct author_node *head_author, char *title){

    struct book_node *iterator_book = malloc (sizeof (*iterator_book));
    if (iterator_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_book = head_book;
    struct author_node *iterator_author = malloc (sizeof (*iterator_author));
    if (iterator_author == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_author = head_author;
    while (iterator_book != NULL) {
        if(strcmp(iterator_book->book_title, title) == 0){
            ;   // do nothing
//            printf("\nCartea -  %s - are autori:\n", iterator_book->book_title);
            for(int i=0; i<10; i++){
                if(iterator_book->authors[i] != 0){
                    while (iterator_author != NULL) {
                        if(iterator_author->id_author == iterator_book->authors[i]){
                            ; //do nothing
//                            printf("    - %s %s (id %ld)\n", iterator_author->author_name,
//                              iterator_author->author_given_name, iterator_author->id_author);
                        }
                        iterator_author = iterator_author->next;
                    }
                }
                iterator_author = head_author;
            }
        break;
        }
        iterator_book = iterator_book->next;
    }
    free(iterator_book);
    free(iterator_author);
}

void search_author_books_nodisplay(struct book_node *head_book, struct author_node *head_author, char *author_name, char *author_given_name){
    struct book_node *iterator_book = malloc (sizeof (*iterator_book));
    if (iterator_book == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_book = head_book;
    struct author_node *iterator_author = malloc (sizeof (*iterator_author));
    if (iterator_author == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    iterator_author = head_author;
    while (iterator_author != NULL) {
        if(strcmp(iterator_author->author_name, author_name) == 0){
            if(strcmp(iterator_author->author_name, author_name) == 0){
                while (iterator_book != NULL) {
                    for(int i=0; i<10; i++){
                        if(iterator_author->id_author == iterator_book->authors[i]){
                            ; //do nothing
//                            printf("    - %s \n", iterator_book->book_title);
                        }
                    }
                    iterator_book = iterator_book->next;
                }
            }
        break;
        }
        iterator_author = iterator_author->next;
    }
    free(iterator_book);
    free(iterator_author);
}


char *random_string(int size){
    #define ASCII_START 32
    #define ASCII_END 126
    int i;

    char *rand_string = malloc(size);

    for(i = 0; i < size-1; i++) {
        rand_string[i] = (char) (rand()%(ASCII_END-ASCII_START))+ASCII_START;
    }
  //  rand_string[i] = '\0';

    return rand_string;
}
