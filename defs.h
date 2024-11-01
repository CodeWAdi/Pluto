#ifndef DEFS_H
 #define DEFS_H
 #include "stdio.h"
 #include "stdlib.h"

 #define DEBUG
 #ifndef DEBUG
 #define ASSERT(n)
 #else
 #define ASSERT(n) \
do { \
    if (!(n)) { \
        printf("\n""\n");\
        printf("Assertion failed: %s\n", #n); \
        printf("ON: %s\n", __DATE__); \
        printf("AT: %s\n", __TIME__); \
        printf("IN: %s\n", __FILE__); \
        printf("LINE: %d\n", __LINE__); \
        exit(1); \
    } \
} while (0) 

#endif


 typedef unsigned long long U64;

 #define NAME "UCH 1.0"
 #define BRD_SQ_NUM 120
 #define MAXGAMEMOVES 3000 

#define RAND_64 ( \
    (U64) rand() +\
    (U64) rand()  << 15 + \
    (U64) rand() << 30 + \
    (U64) rand() << 45 + \
    ((U64) rand() & 0xf) << 60 )




 enum{ EMPTY ,wP ,wN ,wB ,wR ,wQ ,wK ,bP ,bN ,bB ,bR,bQ ,bK}; //pieces config

 enum{ FILE_A,FILE_B,FILE_C,FILE_D,FILE_E,FILE_F,FILE_G,FILE_H,FILE_NONE }; //FILES CONFIG
 
 enum{ RANK_1,RANK_2,RANK_3,RANK_4,RANK_5,RANK_6,RANK_7,RANK_8,RANK_NONE }; //rank config
 enum{WHITE ,BLACK ,BOTH};
 enum{
    A1=21,B1,C1,D1,E1,F1,G1,H1,
    A2=31,B2,C2,D2,E2,F2,G2,H2,
    A3=41,B3,C3,D3,E3,F3,G3,H3,
    A4=51,B4,C4,D4,E4,F4,G4,H4,
    A5=61,B5,C5,D5,E5,F5,G5,H5,
    A6=71,B6,C6,D6,E6,F6,G6,H6,
    A7=81,B7,C7,D7,E7,F7,G7,H7,
    A8=91,B8,C8,D8,E8,F8,G8,H8, NO_SQ
 };

 enum {FALSE, TRUE } ;

 enum{WKCA=1 , WQCA=2, BKCA =4 ,BQCA = 8}; // 0 0 0 0 represent whic side both player can castle

 typedef struct {
   int move;
   int castlePerm;
   int enPas;
   int fiftyMove;
   U64 posKey;
 } S_UNDO ; 
 




 typedef struct {
   int pieces[BRD_SQ_NUM]; // arr of 120 for board representation
   U64 pawns[3]; // for pawns on white , black or both colour

   int KingSq[2];

   int side; 
   int enPas;
   int fiftyMove;
   int castlePerm ; // for castling permission
   int ply;
   int hisPly;

   U64 posKey ; // a unique position key for each position
   
   int pceNum[13]; // pieces on the board based on their points

   int bigPce[3];
   int majPce[3];
   int minPce[3];

    
   S_UNDO history[MAXGAMEMOVES];


   //piece list
   int pList[13][10];

  

 } S_BOARD ;

  // MACROS

  #define FR2SQ(f,r) ( (21+(f)) + ((r)*10) )
  #define SQ64(index120) Sq120To64[index120]
  #define CNT(b) CountBits(b)
  #define POP(b) PopBit(b)
  #define CLRBIT(bb,sq) ((bb) &=ClearMask[(sq)])
  #define SETBIT(bb,sq) ((bb) |=SetMask[(sq)])
 
  //GLOBAL

  extern int Sq120To64[ BRD_SQ_NUM];
  extern int Sq64To120[ 64];
  extern U64 SetMask[64];
  extern U64 ClearMask[64];
  extern U64 PieceKeys[14] [120];
  extern U64 SideKey;
  extern U64 CastleKeys[16];


  //Functions

  extern void AllInit();

  //bitboards.c
  extern void PrintBitBoard(U64 bb);
  extern int PopBit(U64 *bb);
  extern int CountBits(U64 b);
  extern U64 GeneratePosKey(const S_BOARD *pos);

#endif