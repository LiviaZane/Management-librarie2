//
// Tema PA 02.07.2021 - Zane Livia, CR1.3B
//

#ifndef CODE_LISTS_H
#define CODE_LISTS_H



typedef struct author_node {
    long id_author;
    char author_name[20];
    char author_given_name[20];
    struct author_node *next;
} author_node;

typedef struct book_node {
    char book_title[100];
    long authors[10];
    struct book_node *next;
} book_node;


void add_book (struct book_node **head_book, long authors[], char *new_book_title);
void add_author (struct author_node **head_author, long new_id_author, char *new_author_name, char *new_author_given_name);
void search_book_authors(struct book_node *head_book, struct author_node *head_author, char *title);
void search_author_books(struct book_node *head_book, struct author_node *head_author, char *author_name, char *author_given_name);

long find_book (struct book_node *head_book, char *title);
long find_author (struct author_node *head_author, char *searched_author_name, char *searched_author_given_name);
void list_library (struct book_node *current_book);
void list_authors(struct author_node *current_author);
void save_library_books (struct book_node *current_book);
void save_library_authors (struct author_node *current_author);
void read_file_books (struct book_node **head_book);
void read_file_authors (struct author_node **head_author);
long list_books_lenght (struct book_node *current_list);
long list_authors_lenght (struct author_node *current_list);
void search_book_authors_nodisplay(struct book_node *head_book, struct author_node *head_author, char *title);
void search_author_books_nodisplay(struct book_node *head_book, struct author_node *head_author, char *author_name, char *author_given_name);

char *random_string(int size);

#endif //CODE_LISTS_H
