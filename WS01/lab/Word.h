/*****************************************************************************
                           WORKSHOP 1 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-09-14
*****************************************************************************/

#ifndef SDDS_WORD_H // replace with relevant names
#define SDDS_WORD_H

namespace sdds {

   const int MAX_WORD_LEN = 21;

   struct Word {
      char letters[MAX_WORD_LEN];
      int count;
   };

   int searchWords(const Word words[], int num, const char word[]);
   int readWord(char* word, FILE* fptr, int maxLen);
   void addWord(Word words[], int* index, const char newWord[]);
   void title(const char* value, int len);
   void endList();
   void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
   void print(const Word* w, int gotoNextLine, int len);
   int findMaxLen(const Word words[], int noOfWords);
   void listWords(const Word words[], int noOfWords, const char* theTitle);
   void swap(Word* p1, Word* p2);
   void sort(Word words[], int cnt, int sortType);
   int totalCount(const Word* words, int num);
   void wordStats(const char* filename);
   void programTitle();

}
#endif