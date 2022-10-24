#ifndef PROBLEM1_H
#define PROBLEM1_H
#include <string>
#include <iostream>
#include <stdexcept>

struct Waitlist
{
    std::string*array = new std::string[1]{};
    size_t capacity = 1;
    size_t size = 0;
};
void add_to_waitlist(Waitlist&, const std::string&);

std::string remove_from_waitlist(Waitlist&);

Waitlist split(Waitlist&);

#endif
