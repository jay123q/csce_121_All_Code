/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "Tag.h"
#include <iostream>

using std::string;
using std::vector;
using std:: cout, std::endl;

Tag::Tag(string tagName) /* TODO(student): initialize */ 
{

  if(tagName.length()<2)
  {
    throw std::invalid_argument(" the length is less than 2");
  }
  if(tagName.at(0) == '\0')
  {
    throw std::invalid_argument(" null string ");
  }
  if(tagName.at(0)!='#')
  {
    throw std::invalid_argument("the leading statement is not a hashtag ");
  }
  char CharHere;
  char LowerCaseChar;
  int characterCounter = 0;
  for(int thisPosition = 1 ;  thisPosition < tagName.size() ; thisPosition++)
  {
    CharHere = tagName.at(thisPosition);
    LowerCaseChar = tolower(tagName.at(thisPosition));
    
    if((CharHere != LowerCaseChar))
    {
      throw std::invalid_argument(" The Character is not lower case line 41 ");
    }
    if (( CharHere >= 65 && CharHere <= 90))
    {
      throw std::invalid_argument(" The Character is bad");
    }
  }
  if(!(isalpha(tagName.at(1))))
  {
    throw std::invalid_argument("the leading statement is not a hashtag ");
  }
  

  // check if there is any uppercase letters

  for(int j = tagName.size();j<=0;j--)
  {
    if(islower(tagName.at(j)))
    {
      break;
    }
    if(tagName[j] == '!' ||tagName[j] == '?'||tagName[j] == '.' ||tagName[j] == ',')
   {
    throw std::invalid_argument(" puncuation " );  
    }
  }



  // TODO(student): implement constructor checks
  this->tagName = tagName;
}

string Tag::getTagName() 
{
  // TODO(student): implement getter
  
  return this->tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return this->tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts

  if(post == nullptr)
  {
    throw std::invalid_argument("tagName is a null ptr");
  }
  else
  {
    this->tagPosts.push_back(post);
  }
  
  

}
