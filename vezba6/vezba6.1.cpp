//INKI927 Ana Dajovska
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition
struct card {
   const char *face; // define pointer face
   const char *suit; // define pointer suit
}; // end struct card

typedef struct card Card; // new type name for struct card

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );

int main( void )
{
   Card deck[ CARDS ]; // define array of Cards

   // sto se pravi vo ovoj red ?
   // Vo nizata face se inicijalizira zaedno so site broevi na spilot karti, a nizata se koristi za popolnuvanje na poleto "face" kaj sekoja poedinecna karta.
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   // sto se pravi vo ovoj red ?
   // Vo nizata suit se inicijalizira zaedno so cetirite "suits" na spilot karti,nizata se koristi za popolnuvanje na poleto "suit" kaj sekoja poedinecna karta.
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   srand( time( NULL ) ); // sto e ovaa naredba ?
   // naredbata e vsusnost generator na random broj cija vrednost na argumentot pse prenesuva na nego, vo ovaj slucaj 'time(null)'

   fillDeck( deck, face, suit ); 
   shuffle( deck ); 
   deal( deck ); 
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] )
{
   size_t i; 

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   } // end for
} // end function fillDeck

// shuffle cards
void shuffle( Card * const wDeck )
{
   size_t i; // sto e ovaa promenliva ?
   // promenlivata 'i' se koristi kako brojac na jamki niz nekolku funkcii za povtoruvanje preku kartite vo spilot.
   size_t j; // sto e ovaa promenliva i vo koi vrednosti se dvizi ? vidi kod 
   // promenlivata 'j' se koristi kako brojac na jamka vo funkcijata 'shuffle()'. Vrednosta se dvizi od 0 do 51 koja e dodelena random so funkcijata 'rand()'.
   Card temp; // define temporary structure for swapping Cards

   // loop thr
   for ( i = 0; i < CARDS; ++i ) {
      j = rand() % CARDS; // 
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   } // end for
} // end function shuffle

// deal cards
void deal( const Card * const wDeck )
{
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s of %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4 ? "  " : "\n" );
   } // end for
} // end function deal 
