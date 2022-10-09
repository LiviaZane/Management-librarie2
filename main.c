#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"


int main() {

    struct book_node *head_book = NULL;                 // Bild an empty head node for single list of books
    struct author_node *head_author = NULL;             // Bild an empty head node for single list of author

    long authors[] = {1,2,3,4,5,0,0,0,0,0};   //Authors array for a book
    long find;                         //used to verify if a book or author are in the lists (0 for messing)
    char *ptr1, *ptr2;      // transform string (title, name and given name) to pointer to be parsed to a function
    int choice;                       // input the choice of running (program or test)

    printf("ACE-UCV    -    Tema laborator PA 2021    -    Zane Livia, CR1.3B\n\n");
    printf("Se doreste rularea programului sau a testului? \n 1. Rulare program librarie\n 2. Rulare test random\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            // Load single linked lists book and author from files
            read_file_authors (&head_author);
            read_file_books (&head_book);
            // List the linked lists
            printf("\n====================================\n\n");
            printf("Listele de autori si carti incarcate din fisiere\n\n");
            printf("Lista de autori (id):\n\n");
            list_authors(head_author);
            printf("====================================\n\n");
            printf("Lista de carti:\n\n");
            list_library (head_book);
            printf("====================================\n\n");

            // Add new author nodes to the single list of authors
            printf("Adaugam noi autori\n\n");
            ptr1 = "Vasile Ion";
            ptr2 = "Gheorghe Marin";
            find = find_author (head_author, ptr1, ptr2);
            if (find == 0){
                add_author (&head_author, 4, ptr1, ptr2);
                printf("     Autorul - %s %s - a fost adaugat\n", ptr1, ptr2);
            } else {
                printf ("     Autorul - %s %s - exista si are id=%ld\n", ptr1, ptr2, find);
            }
            // Existent author
            ptr1 = "Zane";
            ptr2 = "Livia";
            find = find_author (head_author, ptr1, ptr2);
            if (find == 0){
                add_author (&head_author, 6, ptr1, ptr2);
                printf("     Autorul - %s %s - a fost adaugat\n", ptr1, ptr2);
            } else {
                printf ("     Autorul - %s %s - exista si are id=%ld\n", ptr1, ptr2, find);
            }
            // New author
            ptr1 = "Vraca";
            ptr2 = "George Ion";
            find = find_author (head_author, ptr1, ptr2);
            if (find == 0){
                add_author (&head_author, 5, ptr1, ptr2);
                printf("     Autorul - %s %s - a fost adaugat\n", ptr1, ptr2);
            } else {
                printf ("     Autorul - %s %s - exista si are id=%ld\n", ptr1, ptr2, find);
            }
            printf("====================================\n\n");

            // Add a new book node with 5 authors to the single list of books
            printf("Adaugam carti noi \n\n");
            ptr1 = "Carte noua, cu 5 autori";
            find = find_book (head_book, ptr1);
            if (find == 0){
                add_book (&head_book, authors, ptr1);
                printf("     Cartea - %s - a fost adaugata\n", ptr1);
            } else {
                printf ("     Cartea - %s - existenta, nu a fost adaugata\n", ptr1);
            }
            // Add again the same book to avoid double record of the same book
            ptr1 = "Carte noua, cu 5 autori";
            find = find_book (head_book, ptr1);
            if (find == 0){
                add_book (&head_book, authors, ptr1);
                printf("     Cartea - %s - a fost adaugata\n", ptr1);
            } else {
                printf ("     Cartea - %s - existenta, nu a fost adaugata\n", ptr1);
            }
            printf("====================================\n\n");

            // list again the lists of books and authors from library
            printf("Lista de autori (id):\n\n");
            list_authors(head_author);
            printf("====================================\n\n");
            printf("Lista de carti:\n\n");
            list_library (head_book);
            printf("====================================\n\n");

            // List of books co-authored by a given author
            printf("Afisare carti ale unui autor dat \n\n");
            ptr1 = "Zane";
            ptr2 = "Livia";
            find = find_author (head_author, ptr1, ptr2);
            if (find != 0){
                printf("Cartile autorului %s %s:\n", ptr1, ptr2);
                search_author_books(head_book, head_author, ptr1, ptr2);
            } else {
                printf ("\nAutorul %s %s nu este in lista de autori!\n\n", ptr1, ptr2);
            }
            // Inexistent author
            ptr1 = "Zane";
            ptr2 = "Liviuta";
            find = find_author (head_author, ptr1, ptr2);
            if (find != 0){
                printf("Cartile autorului %s %s:\n", ptr1, ptr2);
                search_author_books(head_book, head_author, ptr1, ptr2);
            } else {
                printf ("\nAutorul %s %s nu este in lista de autori!\n\n", ptr1, ptr2);
            }
            // Another author from list
            ptr1 = "Rebreanu";
            ptr2 = "Liviu";
            find = find_author (head_author, ptr1, ptr2);
            if (find != 0){
                printf("Cartile autorului %s %s:\n", ptr1, ptr2);
                search_author_books(head_book, head_author, ptr1, ptr2);
            } else {
                printf ("\nAutorul %s %s nu este in lista de autori!\n\n", ptr1, ptr2);
            }
            printf("\n====================================\n\n");


            // List of authors that co-authored a given book
            printf("Afisare autori pentru o carte data \n");
            ptr1 = "Carte noua, cu 5 autori";
            find = find_book (head_book, ptr1);
            if (find == 1){
                search_book_authors(head_book, head_author, ptr1);
            } else {
                printf ("\nCartea - %s - nu este in biblioteca!\n", ptr1);
            }
            // Inexistent book
            ptr1 = "Carte noua, cu 15 autori";
            find = find_book (head_book, ptr1);
            if (find == 1){
                search_book_authors(head_book, head_author, ptr1);
            } else {
                printf ("\nCartea - %s - nu este in biblioteca!\n", ptr1);
            }
            // Another book from list
            ptr1 = "Homework P.A. ver. 1";
            find = find_book (head_book, ptr1);
            if (find == 1){
                search_book_authors(head_book, head_author, ptr1);
            } else {
                printf ("\nCartea - %s - nu este in biblioteca!\n", ptr1);
            }
            printf("\n============== SFARSIT =============\n\n");
            free(head_book);
            free(head_author);
            break;


        case 2:
            printf("\n======================================================================================\n\n");
            printf("  lungime lista autori: %ld, inainte de populare\n", list_authors_lenght(head_author));
            printf("  lungime lista carti: %ld, inainte de populare\n", list_books_lenght(head_book));

            char *rand_book_title;              //book title randomized
            char *rand_author_name;               // author name randomized
            char *rand_author_given_name;          // author given name randomized
            time_t t;                  // variable for returning the time measured in seconds
            clock_t start;                   // to measure start time of the algorithm
            clock_t end;                // to measure end time of the algorithm
            double time_alghoritm;            // to calculate in seconds the time of the algorithm

            srand((unsigned) time(&t));    //seeds the random number generator used by rand function


            //push in single linked list 10.000 authors
            start = clock();               // time of algorithm starting
            for (long i = 1; i <= 10000; i++){
                rand_author_name = random_string(10);        // random strig generation function
                rand_author_given_name = random_string(10);  // 10 it's the superior limit of the random string
                find = find_author (head_author, rand_author_name, rand_author_given_name);
                if (find == 0){                                  // author doesn't exist in the list
                    add_author(&head_author, i, rand_author_name, rand_author_given_name);
                } else {
                    printf ("     Autorul exista si are id=%ld\n", find);
                }
            }

            //push in single linked list 10.000 books
            for (int i = 10;  i <= 10009; i++){        // loop starf from 10 because j, esed for assign id_author, takes 10 values bellow i
                rand_book_title = random_string(40);  // 40 it's the superior limit (size) of the random string
                for (int j = 0; j < 10; j++){
                    authors[j] = i - j;
                }
                find = find_book (head_book, rand_book_title);
                if (find == 0){
                    add_book (&head_book, authors, rand_book_title);
                } else {
                    printf ("     Carte  existenta\n");
                }
            }
            end = clock();
            time_alghoritm = (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nTimpul (CPU time) de executie a algoritmului de adaugare 10.000 autori si 10.000 carti (fiecare cu 10 autori) : %f sec.\n", time_alghoritm);
            printf("\n======================================================================================\n\n");


            // Lenght the lists after fill in with 10.000 records
            printf("\n  lungime lista autori: %ld, dupa populare\n", list_authors_lenght(head_author));
            printf("  lungime lista carti: %ld, dupa populare\n", list_books_lenght(head_book));
            printf("\n======================================================================================\n\n");


            // Test for the list of authors that co-authored a given book (test for 10.000 books with 10 authors each)
            printf("Dureaza aproximativ 25 de secunde.........\n");
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

            start = clock();           // start the test
            while (iterator_book != NULL){
                search_book_authors_nodisplay(head_book, head_author, iterator_book->book_title);
                iterator_book = iterator_book->next;
            }
            end = clock();        // end the test
            time_alghoritm = (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nTimpul (CPU time) de executie a algoritmului de cautare a autorilor unei carti date (10.000 carti date): %f sec.\n", time_alghoritm);
            printf("\n=======================================================================================\n\n");


            // Test for the list of books that co-authored by given author (test for 10.000 authors)
            iterator_book = head_book;
            iterator_author = head_author;
            start = clock();       // start the test
            while (iterator_author != NULL){
                search_author_books_nodisplay(head_book, head_author, iterator_author->author_name, iterator_author->author_given_name);
                iterator_author = iterator_author->next;
            }
            end = clock();       // end the test
            time_alghoritm = (double)(end - start)/CLOCKS_PER_SEC;
            printf("\nTimpul (CPU time) de executie a algoritmului de cautare a cartilor unui autor dat (10.000 autori dati): %f sec.\n", time_alghoritm);
            printf("\n=======================================================================================\n\n");


            //List authors for a given book and books authored by a given author
            printf("\n\n     AFISARE AUTORI PENTRU O CARTE DATA, DIN SETUL DE TEST\n");
            iterator_book = head_book;
            for (int i=1; i<100; i++){   // chouse to show the 100-th book from the books list
                iterator_book = iterator_book->next;
            }
            ptr1 = iterator_book->book_title;
            find = find_book (head_book, ptr1);
            if (find == 1){
                search_book_authors(head_book, head_author, ptr1);
            } else {
                printf ("\nCartea - %s - nu este in biblioteca!\n", ptr1);
            }


            //List books of a given author
            printf("\n\n     AFISARE CARTI ALE UNUI AUTOR DAT, DIN SETUL DE TEST\n\n");
            iterator_author = head_author;
            for (int i=1; i<100; i++){   // chouse to show the 100-th author from the authors list
                iterator_author = iterator_author->next;
            }
            ptr1 = iterator_author->author_name;
            ptr2 = iterator_author->author_given_name;
            find = find_author (head_author, ptr1, ptr2);
            if (find != 0){
                printf("Cartile autorului %s %s:\n", ptr1, ptr2);
                search_author_books(head_book, head_author, ptr1, ptr2);
            } else {
                printf ("\nAutorul %s %s nu este in lista de autori!\n\n", ptr1, ptr2);
            }
            free(head_book);
            free(head_author);
            printf("\n====================== SFARSIT TEST ======================\n\n");
            break;


        default:
            printf("\nAti tastat gresit....se inchide programul!\n\n");
    }

    return 0;
}
