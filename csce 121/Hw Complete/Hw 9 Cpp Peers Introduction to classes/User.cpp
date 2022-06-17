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
#include "User.h"
#include <iostream>

using std::string;
using std::vector;
using std::cout, std:: endl;

User::User(string userName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  // check if this is bad

    
  if (userName == " "|| userName == "\0" )
  {
  
    throw std::invalid_argument("you entered a invalid username " );
  }

  for(int thisLetter = 0; thisLetter < userName.size();thisLetter++)
  {
      char isLetter = userName.at(thisLetter);
      if(isLetter < 97 || isLetter > 122)
      {
        throw std::invalid_argument(" You have a invalid userame ");
      }
    
  }
  
  this->userName = userName;

}

string User::getUserName() {
  // TODO(student): implement getter
  
  return this->userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return this->userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts

  if (post == nullptr)
  {
    throw std::invalid_argument("you entered a invalid username ");
  }
  else
  {
   
    // this is a user, check the user.h and
    this->getUserPosts().push_back(post);
  }

}
