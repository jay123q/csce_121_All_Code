/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Post.h"

using std::string;
using std::vector;
using std::cout,std::endl;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return this->postId;
}

string Post::getPostUser() {
  return this->userName;
}

string Post::getPostText() {
  return this->postText;
}

vector<string> Post::findTags() 
{
  string ThisWord;
  string SaveMe;
  vector <string> CleanedTags;
  std::stringstream ss(postText);
  ss>>ThisWord;
  if(ss.fail())
  {
    throw std::invalid_argument("String Stream failed in first input line 47");
  }
  while(!(ss.fail()))
  {
    if(ThisWord.at(0)=='#')
    {

      for(int character =0;character<ThisWord.size();character++)
      {
        char CharacterHere = tolower(ThisWord.at(character)); // 35 is hashtag
        if( ( CharacterHere >= 97 && CharacterHere <= 122) || CharacterHere == 45 || CharacterHere == 35)
        {
            SaveMe += CharacterHere;
        }
      }
      CleanedTags.push_back(SaveMe);
      // declare saveMe to be empty
      SaveMe = "";
    }
    ss>>ThisWord;

  }

  // TODO(student): extracts candidate tags based on occurrences of # in the post
  // first I want to ONLY things with #
  this->postText = postText;
 return CleanedTags;
}

