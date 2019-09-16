// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Yanghaoyu (z5223796)
// on 19/4/2019
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    Pokemon         pokemon;
    int found;
    int current;
    struct pokenode *evoltion;
};

// Add any other structs you define here.


// Add prototypes for any extra functions you create here.

// Make a new pokenode and add pokemon to node
struct pokenode *new_pokenode(Pokemon pokemon) {
    struct pokenode *node = malloc(sizeof (struct pokenode));
    node->pokemon = pokemon;
    node->next = NULL;
    node->evoltion = NULL;
    return node;
}

// Add pokenode to the end of the Pokedex
void add_to_end(Pokedex pokedex, struct pokenode *node) {
    struct pokenode *curr = pokedex->head;
    if(curr == NULL){
        // pokedex is empty
        pokedex->head = node;
        node->current = 1;
        node->found = 0;
    }else{
        while(curr != NULL){
            if(pokemon_id(curr->pokemon) == pokemon_id(node->pokemon)){
                printf("ERROR: You have already a Pokemon in the Pokedex with the same pokemon_id\n");
                exit(1);
            }
            curr = curr ->next;
        }
        curr = pokedex->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
        node->current = 0;
        node->found = 0;
    }
        
} 


// print detail of pokemon
void print(Pokemon pokemon){
    int firsttype = pokemon_first_type(pokemon);
    int secondtype = pokemon_second_type(pokemon);
    printf("Id: %03d\n",pokemon_id(pokemon));
    printf("Name: %s\n",pokemon_name(pokemon));
    printf("Height: %.1fm\n",pokemon_height(pokemon));
    printf("Weight: %.1fkg\n",pokemon_weight(pokemon));
    printf("Type: %s ",pokemon_type_to_string(firsttype));
    if(secondtype != 0){
        printf("%s",pokemon_type_to_string(secondtype));
    }
    printf("\n");
}
// print samesize* for name
void replace(char *name){
    while(*name != '\0' ){
        printf("*");
        name++;
    }
    printf("\n");
}
// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    struct pokenode *node = new_pokenode(pokemon);
    add_to_end(pokedex,node);
}

void detail_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while(curr->current != 1){
        curr = curr->next;
    }
    if(curr->found == 1){
        print(curr->pokemon);
    }else{
        printf("Id: %03d\n",pokemon_id(curr->pokemon));
        printf("Name: ");
        replace(pokemon_name(curr->pokemon));
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    }
}

Pokemon get_current_pokemon(Pokedex pokedex) {
    if(pokedex->head == NULL){
        printf("ERROR: Your Pokedex is empty\n");
        exit(1);
    }else{
        struct pokenode *curr = pokedex->head;
        while(curr->current != 1){
            curr = curr->next;
        }
        return curr->pokemon;
    }
}

void find_current_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    if(curr != NULL){
        while(curr->current != 1){
            curr = curr ->next;
        }
        curr->found = 1;
    }
}

void print_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while(curr != NULL){
        if(curr->found == 1 && curr->current == 1) {
            //pokemon has been found
            printf("--> #%03d: %s\n",pokemon_id(curr->pokemon), pokemon_name(curr->pokemon));
        }else if(curr->found == 1 && curr->current == 0 ) {
            printf("    #%03d: %s\n",pokemon_id(curr->pokemon), pokemon_name(curr->pokemon));
        }else if(curr->found == 0 && curr->current == 1) {
            printf("--> #%03d: ",pokemon_id(curr->pokemon));
            replace(pokemon_name(curr->pokemon));
        }else if(curr->found == 0 && curr->current == 0){
            printf("    #%03d: ",pokemon_id(curr->pokemon));
            replace(pokemon_name(curr->pokemon));
        }
        curr = curr->next;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    if(curr != NULL){
        while(curr->current != 1){
            curr = curr->next;
        }
        if(curr->next != NULL){
            curr->current = 0;
            curr->next->current = 1;
        }
    }
}

void prev_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *prev;
    if(curr != NULL){
        while(curr->current != 1) {
            prev = curr;
            curr = curr->next;
        }
        if(curr != pokedex->head){
            curr->current = 0;
            prev->current = 1;
        }
    }
}

void change_current_pokemon(Pokedex pokedex, int id) {
    struct pokenode *curr = pokedex->head;
    int a=0;
    while(curr != NULL){
        if(pokemon_id(curr->pokemon) == id){
            a = 1;
        }
        curr= curr->next;
    }
    curr = pokedex->head;
    if(a==1){
        while(curr != NULL){
            curr->current = 0;
            if(pokemon_id(curr->pokemon) == id){
                curr->current = 1;
            }
            curr = curr->next;
        }
    }
}

void remove_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *prev;
    int countnumber = 0;
    if(curr != NULL){
        while(curr != NULL){
            countnumber++;
            curr = curr->next;
        }
        curr = pokedex->head;
        if(countnumber == 1){
            pokedex->head = NULL;
            destroy_pokemon(curr->pokemon);
            free(curr);
        }else{
            while(curr->current != 1){
                prev = curr;
                curr = curr->next;
            }
            if(curr == pokedex->head){
                pokedex->head = curr->next;
                curr->next->current = 1;
                destroy_pokemon(curr->pokemon);
                free(curr);
            }else if(curr->next == NULL){
                destroy_pokemon(curr->pokemon);
                free(curr);
                prev->current = 1;
                prev->next = NULL;
            }else if(curr->next != NULL){
                prev->next = curr->next;
                destroy_pokemon(curr->pokemon);
                free(curr);
                prev->next->current = 1;
            }
        }
    } 
}

void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *next;
    while(curr != NULL){
        next = curr->next;
        destroy_pokemon(curr->pokemon);
        free(curr);
        curr = next;
    }
    free(pokedex); 
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    struct pokenode *curr = pokedex->head;
    int min_id = pokemon_id(pokedex->head->pokemon);
    while(curr != NULL){
        if(pokemon_id(curr->pokemon)<min_id){
            min_id = pokemon_id(curr->pokemon);
        }
        curr = curr->next;
    }
    if((factor-1) >= min_id){
        int times=0;
        while(times < how_many){
            curr = pokedex->head;
            while(curr != NULL){
                srand(seed);
                if(pokemon_id(curr->pokemon) == rand()){
                    curr->found = 1;
                }
                curr = curr->next;
            }
            times++;
        }
    }else{
        printf("ERROR:there are no Pokemon in the Pokedex with pokemon_id  between 0 and '%d - 1'",factor);
        exit(1);
    }
}

int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int foundnumber=0;
    while(curr != NULL){
        if(curr->found == 1){
            foundnumber++;
        }
        curr = curr->next;
    }
    return foundnumber;
}

int count_total_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int totalnumber = 0;
    while(curr != NULL){
        totalnumber++;
        curr = curr->next;
    }
    return totalnumber;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    if(from_id == to_id){
        printf("ERROR: frome_id and to_id are same.\n");
        exit(1);
    }else{
        struct pokenode *curr = pokedex->head;
        int checkfrom = 0;
        int checkto = 0;
        while(curr != NULL){
            if(pokemon_id(curr->pokemon) == from_id){
                checkfrom = 1;
            }else if(pokemon_id(curr->pokemon) == to_id){
                checkto = 1;
            }
            curr = curr->next;
        }
        if(checkfrom == 1 && checkto == 1){
            struct pokenode *from = pokedex->head;
            while(pokemon_id(from->pokemon) != from_id){
                from = from->next;
            }
            struct pokenode *to = pokedex->head;
            while(pokemon_id(to->pokemon) != to_id){
                to = to->next;
            }
            struct pokenode *overwrithing = pokedex->head;
            while(overwrithing != NULL){
                if(overwrithing->evoltion == to){
                    overwrithing->evoltion = NULL;
                }
                overwrithing = overwrithing->next;
            }
            from->evoltion = NULL;
            from->evoltion = to;
        }else{
            printf("ERROR:The from_id or to_id pokemon does not exit.\n");
            exit(1);
        }
    }
}

void show_evolutions(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while(curr->current != 1){
        curr = curr->next;
    }
    struct pokenode *first = curr;
    struct pokenode *preevo = pokedex->head;
    int firstcheck = 0;
    int a;
    // Find first evolutions.
    int x = 0;
    while(firstcheck == 0){
        a = 0;
        preevo = pokedex->head;
        while(preevo != NULL){
            if(preevo->evoltion == first){
                first = preevo;
                a = 1;
                x = 1;
            }
            preevo = preevo->next;
        }
        if(a == 0){
            firstcheck = 1;
        }
    }
    if(first->evoltion != NULL || x == 1){
        while(first != NULL){
            if(first->found == 0){
                printf("#%03d ???? [????] ", pokemon_id(first->pokemon));
            }else if (first->found == 1){
                printf("#%03d %s ", pokemon_id(first->pokemon), pokemon_name(first->pokemon));
                // type 1 2 check
                int firsttype = pokemon_first_type(first->pokemon);
                int secondtype = pokemon_second_type(first->pokemon);
                if(secondtype != 0 ){
                    printf("[%s, %s] ",pokemon_type_to_string(firsttype),pokemon_type_to_string(secondtype));
                }else{
                    printf("[%s] ",pokemon_type_to_string(firsttype));
                }
            }
            if(first->evoltion != NULL){
                printf("--> ");
            }
            first = first->evoltion;
        }
        printf("\n");
    }else if(first->evoltion == NULL){
        if(first->found == 0){
            printf("#%03d ???? [????] ", pokemon_id(first->pokemon));
        }else if(first->found == 1){
            printf("#%03d %s ", pokemon_id(first->pokemon), pokemon_name(first->pokemon));
            // type 1 2 check
            int firsttype = pokemon_first_type(first->pokemon);
            int secondtype = pokemon_second_type(first->pokemon);
            if(secondtype != 0 ){
                printf("[%s, %s] ",pokemon_type_to_string(firsttype),pokemon_type_to_string(secondtype));
            }else{
                printf("[%s] ",pokemon_type_to_string(firsttype));
            }
        }
        printf("\n");
    }
}

int get_next_evolution(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    if(pokedex->head == NULL){
        printf("ERROR: The Pokedex is empty\n");
        exit(1);
    }else{
        while(curr->current != 1){
            curr = curr->next;
        }
        if(curr->evoltion != NULL){
            int id = pokemon_id(curr->evoltion->pokemon);
            return id;
        }else{
            return DOES_NOT_EVOLVE;
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    fprintf(stderr, "exiting because you have not implemented the get_pokemon_of_type function in pokedex.c\n");
    exit(1);
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_found_pokemon function in pokedex.c\n");
    exit(1);
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    fprintf(stderr, "exiting because you have not implemented the search_pokemon function in pokedex.c\n");
    exit(1);
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

/*while(comparetext < counttext){
            int comparename = 0;
            int goon = 0;
            while(comparename < countname){
                if(text[comparetext] == name[comparename]){
                    goon = 1;
                }
                if(goon == 1){
                    int Fcount = 0;
                    while(text[comparetext + Fcount] == name[comparename + Fcount] && comparetext + Fcount < counttext && comparename + Fcount < countname){
                        if(text[comparetext + Fcount +1] == '0'){
                            choose = 1;
                            break;
                            break;
                            break;
                        }
                        Fcount++;
                    }
                }
                comparename++;
            }
            comparetext++;
        }*/