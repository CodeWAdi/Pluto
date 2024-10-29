#include "defs.h"
#include <stdio.h>

  int Sq120To64[ BRD_SQ_NUM];
  int Sq64To120[64];

  U64 SetMask[64];
  U64 ClearMask[64];


  void InitBitMask(){
    int index = 0;

    for(index=0;index<64;index++){
      SetMask[index] = 0ULL;
      ClearMask[index] = 0ULL;
    }  

    for(index=0; index<64;index++) {
      SetMask[index] |= (1ULL << index);
      ClearMask[index] = ~SetMask[index];


    }

  }









    void InitSq120To64() {
        int index = 0;
        int file = FILE_A;
        int rank = RANK_1 ;
        int sq = A1;
        int sq64 = 00;

        // All the indexes are set to no. that cant be reached if everythhing works properly so in case if the function returns 65 or 120 we caan say theres an error in code'''

         for (index  = 0; index < BRD_SQ_NUM; ++index)
         {
           Sq120To64[index] = 65;
         }

         

         for (index = 0; index < 64; ++index)
         {
            Sq64To120[index] = 120;
         }
         

        for (rank  = RANK_1; rank <=RANK_8; ++rank){
            for(file=FILE_A; file<=FILE_H;  ++file){
                    sq =FR2SQ(file,rank);
                    Sq64To120[sq64]= sq;
                    Sq120To64[sq] =sq64;
                    sq64 ++;

            }
        } 
         

    }



void AllInit(){

    InitSq120To64();

} 