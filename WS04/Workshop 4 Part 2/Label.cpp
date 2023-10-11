/*****************************************************************************
                           WORKSHOP 4 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-10
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Label.h"

const char* DEFAULT_FRAME{ "+-+|+-+|" };

namespace sdds {


   // Creates an empty label and defaults the frame to "+-+|+-+|"
   // The frame is dictated by a series of 8 characters in a Cstring.
   // These characters indicate how the frame is to be drawn:
   Label::Label()
   {
      m_content = nullptr;
      m_frameArg = new char[strlen(DEFAULT_FRAME) + 1];
      strcpy(m_frameArg, DEFAULT_FRAME);
   }

   // Creates an empty label and sets the frame to the frameArg argument.
   // If the frameArg is nullptr, the default frame will be used instead.
   Label::Label(const char* frameArg)
   {
      m_content = nullptr;

      if (frameArg == nullptr) {
         m_frameArg = new char[strlen(DEFAULT_FRAME) + 1];
         strcpy(m_frameArg, DEFAULT_FRAME);
      }
      else
      {
         m_frameArg = new char[strlen(frameArg) + 1];
         strcpy(m_frameArg, frameArg);
      }
   }

   // Creates a Label with the frame set to frameArg
   // and the content of the Label set to the corresponding argument.
   // Note that you must keep the content dynamically
   // even though it should never be more than 70 characters.
   Label::Label(const char* frameArg, const char* content)
   {
      if (frameArg == nullptr) {
         m_frameArg = new char[strlen(DEFAULT_FRAME) + 1];
         strcpy(m_frameArg, DEFAULT_FRAME);
      }
      else
      {
         m_frameArg = new char[strlen(frameArg) + 1];
         strcpy(m_frameArg, frameArg);
      }

      if (content == nullptr) {
         m_content = nullptr;
      }
      else
      {
         m_content = new char[strlen(content) + 1];
         strcpy(m_content, content);
      }

   }

   // Makes sure there is no memory leak when the label goes out of scope.
   Label::~Label()
   {
      delete[] m_content;
      delete[] m_frameArg;
   }

   // Reads the content of the label from the console up to 70 characters
   // and stores it in the Label as shown below and then returns the cin.
   std::istream& Label::readLabel()
   {
      char temp[MAX_CHAR_SIZE + 1];
      std::cin.getline(temp, MAX_CHAR_SIZE);

      if (m_content != nullptr) {
         delete[] m_content;
      }
      m_content = new char[strlen(temp) + 1];
      strcpy(m_content, temp);
      
      // TODO: insert return statement here
      return std::cin;
   }

   // Prints the label by drawing the frame around the content as shown below.
   // Note that no newline is printed after the last line and cout is returned at the end.
   // +-------------------+
   // |                   |
   // | My Label Content! |
   // |                   |
   // +-------------------+
   // 01234567
   // +-+|+-+|
   std::ostream& Label::printLabel() const
   {
      if (m_content == nullptr || m_frameArg == nullptr)
      {
         return std::cout;
      }

      int contentLength = strlen(m_content); // length of the m_content assigned to contentLength
      int frameWidth = contentLength + 2;  // adding padding from both sides of the content

      // TOP (FIRST) LINE
      std::cout << m_frameArg[0]; // top left corner
      for (int i{ 0 }; i < frameWidth; ++i) {
         std::cout << m_frameArg[1]; // the '+' char will repeat appropriately
      }
      std::cout << m_frameArg[2] << std::endl; // top right corner

      // SECOND LINE
      std::cout << m_frameArg[3];
      for (int i{ 0 }; i < frameWidth; ++i) {
         std::cout << " ";
      }
      std::cout << m_frameArg[7] << std::endl;

      // CONTENT LINE
      std::cout << m_frameArg[3] << " " << m_content << " " << m_frameArg[7] << std::endl;

      // FOURTH LINE
      std::cout << m_frameArg[3];
      for (int i{ 0 }; i < frameWidth; ++i) {
         std::cout << " ";
      }
      std::cout << m_frameArg[7] << std::endl;

      // BOTTOM LINE
      std::cout << m_frameArg[2]; 
      for (int i{ 0 }; i < frameWidth; ++i) {
         std::cout << m_frameArg[1]; // the '+' char will repeat appropriately
      }
      std::cout << m_frameArg[4];

      return std::cout;
   }

   // Sets the content of the Label (up to 70 characters) dynamically 
   // and then returns the reference of the current object.
   Label& Label::text(const char* content)
   {
      if (m_content != nullptr) {
         delete[] m_content;
      }
      m_content = new char[strlen(content) + 1];
      strcpy(m_content, content);
      return *this;
   }

}
