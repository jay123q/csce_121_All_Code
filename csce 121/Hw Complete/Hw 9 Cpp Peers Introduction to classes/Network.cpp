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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"


using std::string;
using std::vector;
using namespace std;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream File;
  string SortMe;
  string UserName;
  string PostName;
  string postText;
  int PostId;



  File.open(fileName);
  if(File.fail())
  {
    throw std::invalid_argument(" bAd file ");
  }

// try
// {
  while(!File.fail())
  {
    File>>SortMe;
    if(File.fail())
     {
       // end of loop
     break;

    }
     if(SortMe == "User")
      {
      File >> UserName;
      if(File.fail())
      {
      throw std::runtime_error("Cannot 58 USERNAME Open File Network line 30");
      }
      try
      {
      addUser(UserName);
      }
      catch(...)
      {
        throw std::runtime_error("line 66 error in user add");
      }
      }
      else if(SortMe == "Post")
      {
        File >> PostId;
        if(File.fail())
        {
         throw std::runtime_error("Cannot Open 67 Post ID File Network line 30");
         }
         File>>UserName;
        if(File.fail())
        {
         throw std::runtime_error("Cannot Open File 72 PostName Network line 30");
         }
        try
        {
         std::getline(File,postText);
         addPost(PostId,UserName,postText);
        }
        catch(...)
        {
          throw std::runtime_error(" line 92 error in add post");
        }
      }
      else
      {
        throw std::runtime_error(" Some 83 else random error in file here");
      }

    
  



  }
//}
// catch(...)
// {
//   throw std::runtime_error(" Caught One heres another line 70");
// }



}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  string NewUserName = userName;
  string toLowerUserName = "";
  // first comvert to lower
  if(userName[0] == '\0' )
  {
    throw std::invalid_argument(" name is a null ptr ");
  }
  
  // lower
  for(int charhere=0; charhere < userName.size(); charhere++)
  {
    toLowerUserName += tolower(NewUserName.at(charhere));
  }

  for(int thisName = 0; thisName<users.size(); thisName++)
  {
    if(toLowerUserName == users.at(thisName)->getUserName())
    {
      throw std::invalid_argument(" This Name already exists before");
    }
  }
/*
  if(users.size() == 0)
  {
    throw std::invalid_argument("abcdefghijklmnop");
  }
  */
  User * newUser = new User(NewUserName);
  users.push_back(newUser);
  cout << "Added User " << userName << endl;
  toLowerUserName = ""; // declare it to be empty
}

void Network::addPost(unsigned int postId, string userName, string postText) 
{
  // TODO(student): create post and add it to network

  // look through posts and usernames for matches if match error
  bool NewtagExists = false;
  for(int thisPost = 0;thisPost < posts.size();thisPost++)
  {
    if(posts.at(thisPost)->getPostId() == postId)
    {
      throw std::invalid_argument(" This post id already exists ");
    }
  }
  // checking usernames
  // bool CanPost = true; 
  // for(int thisUser = 0;thisUser<users.size();thisUser++)
  // {
  //   if(users.at(thisUser)->getUserName() == userName)
  //   {
  //     CanPost = false;
  //     throw std::invalid_argument(" This user already exists ");
  //   }
  // }  
  // now if it doesnt already exist
  // create a new post
  Post * newPost= new Post(postId,userName,postText);



  // addition of post information to corresponding user
  bool found = false;
  for( int thisIndex = 0 ; thisIndex < users.size(); thisIndex++)
  {
    
    if(userName == users.at(thisIndex)->getUserName())
    {
      users.at(thisIndex)->addUserPost(newPost);
      found = true;
    }
  
  }
  if(!found) {
    throw std::invalid_argument(" user not found ");
  }
  // for loop and avector for tags
  // walk thoorugh and repeat 123 above for if we find a new tag
  // vector <string> ExistingTags;

  vector<string> ExistingTags = newPost->findTags();
  int SaveTagIndex =0;


  for(int j = 0;j<ExistingTags.size();j++)
  {
   try
   {
   string CheckTag = ExistingTags.at(j);

   
   for(int tagIndex = 0 ; tagIndex<tags.size() ; tagIndex++)
  {
    NewtagExists = false;
    // ExistingTags.at(tagIndex)->findTags(postText);
    if(tags.at(tagIndex)->getTagName() == CheckTag )
    { //  if the tag is found in postText
      NewtagExists = true;
      tags.at(tagIndex)->addTagPost(newPost);
    }
    
   }
   // check before second for loop
    if(!NewtagExists)
    {
    Tag * newTag = new Tag(ExistingTags.at(j));
    tags.push_back(newTag);
    tags.back()->addTagPost(newPost);
    }
   }
   
   catch(...) 
   {
     continue;
   }
  }
  

  posts.push_back(newPost);
  cout << "Added Post "<<postId<< " by " << userName << endl;
  

}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user

  if(userName == " ")
  {
    throw std::invalid_argument(" Username is empty ");
  }
  bool found = false;
  int SaveMe = -1;

  // User * getUserPosts();
  for( int thisIndex = 0 ; thisIndex < users.size(); thisIndex++)
  {
    
    if(userName == users.at(thisIndex)->getUserName())
    {
      found = true;
      SaveMe = thisIndex; //  this is useless?
      return users.at(thisIndex)->getUserPosts();    
    }
  
  }
  if(!found) 
  {
    throw std::invalid_argument(" user not found 267 ");
  }

 return users.at(SaveMe)->getUserPosts();   
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag

  if(tagName == " ")
  {
    throw std::invalid_argument(" tag not found 281 ");
  }
  bool found =false;
  int saveIndex=-1;

  // look for tag name
  for(int i = 0; i<tags.size();i++)
  {
    if(tagName == tags.at(i)->getTagName())
    {
      saveIndex=i;
      
      found = true;
      return tags.at(i)->getTagPosts();
    }
  }
  if(!found)
  {
    throw std::invalid_argument(" not found 296 ");
  }


  return tags.at(saveIndex)->getTagPosts();
}

vector<string> Network::getMostPopularHashtag() 
{
  // TODO(student): return the tag occurring in most posts

  int HighestTagged;
  // store thhe higest tag
  vector <string> TagLength; 
  int maxValue = 0;
  if(tags.size() == 0)
  { // return empty vector
    return this->getMostPopularHashtag();
  }
  
// look through tag, calling length of the get tag vector calling tag
// the
  for (int ThisIndex =0 ;ThisIndex < tags.size(); ThisIndex++)
  {
    if(maxValue < tags.at(ThisIndex)->getTagPosts().size())
    {
      maxValue = tags.at(ThisIndex)->getTagPosts().size();
    }
  }

  // now reiterate through and call if the CURRENT value is the max
  for(int i =0;i<tags.size();i++)
  {
    if(maxValue == tags.at(i)->getTagPosts().size())
    {// add the tag  name if the current tag is the proper longest tag
      TagLength.push_back(tags.at(i)->getTagName());
    }
  }
  return TagLength;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
