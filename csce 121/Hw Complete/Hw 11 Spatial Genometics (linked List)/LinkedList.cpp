#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::string;
using std::ostream;
using std::endl;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	  // Implement this function
      //   Node * next = nullptr;

}

LinkedList::~LinkedList() {
	  // Implement this function
      this->clear();

}

LinkedList::LinkedList(const LinkedList& CopyME) : head(nullptr), tail(nullptr)
 {
      this->head = CopyME.copy();
     if(head == nullptr)
     {
         tail = nullptr;
     }
     else
     {
         Node * walkThrough = head;
         while(walkThrough !=  nullptr)
         {
            this->tail = walkThrough;
            walkThrough=walkThrough->next;

         }
     }

}

LinkedList& LinkedList::operator=(const LinkedList& source) 
{
    //  this->data = LinkedList(source);
    // // implement copy
    // Node * sourceHead = source.head;
    // while (walkThrough != nullptr)
    // {
    //     walkThrough = sourceHead;
    //     sourceHead = sourceHead->next;
    //     walkThrough = walkThrough->next;
    // }
    // return *this;
    this->clear();
    this->head=source.copy();
     if(head == nullptr)
     {
         tail = nullptr;
     }
     else
     {
         Node * walkThrough = head;
         while(walkThrough !=  nullptr)
         {
            this->tail = walkThrough;
            walkThrough=walkThrough->next;

         }
     }
//    this->tail=source.copy();
    // while(walkThrough!=nullptr)
    // {
    //     walkThrough=source.copy();
    //     walkThrough=walkThrough->next;
    // }
    return *this;

}

void LinkedList::insert(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    // Implement this function

            
    Node * newNode = new Node( id,  fov,  volume,  center_x,  center_y,  min_x,  max_x,  min_y,  max_y);
    // now I want to run to the end
    if(head == nullptr || tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
    Node * walkThrough = head;
    bool Found = false; // this is for the tail be we cannot check if the tail is the last thing
    bool RunLoop = true;
    if((newNode->data)<(head->data))
    { // head check
        Node * temp = head;
        head = newNode;
        head->next=temp;

        RunLoop = false;
        temp= nullptr;
    }        
    Node * previous;
    while(walkThrough != nullptr && RunLoop)
    {

        // if(walkThrough == nullptr)
        // {
        //     break;
        // }
        // do we need a new middle value?
        if((newNode->data)<(walkThrough->data)) // because celldata already contains walkthrough
            {// if the newNode  has a greater fov than the CURRENT point, it should go infront of the current
            previous->next= newNode; 
            previous->next->next = walkThrough;
            Found=true;
            break;
            // then say that the next new node is walk through next next
            }

        previous = walkThrough;
        walkThrough=walkThrough->next;



    }
    
        
    
    if(!(Found)&&(RunLoop))
    { // tail
            tail->next = newNode;
            tail = tail->next;
            // I think this was  causting a infinte loop because it constantly readded another next
    }
    walkThrough = nullptr;
    }
    newNode = nullptr;
    

}

void LinkedList::remove(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
    {// Implement this function
    //while not nullptr run through  
    //id==data.id

    Node * ThisNode = new Node(id,fov,volume,center_x,center_y,min_x,max_x,min_y,max_y);
    Node * walkThrough = this->head;    
    /*
   if (this->items->item==itemToDelete) {
      List *deleteme = this->items;
      this->items = this->items->next;
      // points to second one
      delete deleteme;
   }
    */


   if(ThisNode == nullptr || walkThrough == nullptr)
   {
       delete ThisNode;
       return;
   }
   if(walkThrough->data == ThisNode->data)
   {
       // point from the pervios one to the one you are trying to remove
 //      Node * deleteme = this->head;
       this->head = this->head->next;
   //    delete deleteme;
        delete ThisNode;
        return;
   }

    while(walkThrough != nullptr && !(walkThrough->next->data == ThisNode->data))
    {
        walkThrough = walkThrough->next;
        // if(walkThrough->data.id == id)
        // { //  if the data is found

        //     delete walkThrough;


        // }
    }
    if(walkThrough->next==nullptr)
    {
        //breaK;
        this->tail = walkThrough;
        delete ThisNode;
        return;
    }
    /*
   List *deleteme = prev->next;
   prev->next = prev->next->next;
   delete deleteme;
    */
    Node * deleteme = walkThrough->next;
    walkThrough->next = walkThrough->next->next;
    // if(walkThrough->next==nullptr)
    // {
    //     this->tail=walkThrough;
    // }
    delete deleteme;
    delete ThisNode;
    }
/*
   List *l = this->items;
   while (l!=nullptr) {
     List *temp=l->next;
     delete l;
     l=temp;
   }
   this->items = nullptr;
*/
void LinkedList::clear() 
{	
    Node * walkThroughNodes = this->head; 
    while(walkThroughNodes != nullptr)
    {
        Node * temp = walkThroughNodes->next;
        delete walkThroughNodes;
        walkThroughNodes = temp;
    }
    walkThroughNodes = nullptr;
    // Implement this function
    this->head = nullptr;
    this->tail  = nullptr;
}

Node* LinkedList::getHead() const 
{
    // Implement this function it will be used to help grade other functions
    return head;
}

string LinkedList::print() const 
{

    Node * walkThroughNodes = head; 
    string PrintMe = "fov,volume,center_x,center_y,min_x,max_x,min_y,max_y";
    PrintMe += '\n';
    string Storage;
    // Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
    while(walkThroughNodes != nullptr)
    {   
        Storage = walkThroughNodes->data.id;
        PrintMe += Storage+',';

        Storage = std::to_string(walkThroughNodes->data.fov);
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.volume);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.center_x);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.center_y);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.min_x);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.max_x);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.min_y);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.max_y);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        if(Storage[Storage.size()-1]=='.')
        {
            Storage.erase(Storage.size()-1);
        }
        PrintMe +=Storage;
        PrintMe += '\n';
        walkThroughNodes = walkThroughNodes->next;
        // how do I open the box and then extract the data I want

    }
    walkThroughNodes = nullptr;
    return PrintMe;
   	// Implement this function
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

// given a fov number, count the cells observed in that fov
int LinkedList::countN(int fov)
{
	/* Do not modify this function */
    int count = 0;
    Node* cur = head;
    while (cur!=nullptr)
    {
        if (cur->data.fov == fov)
            count++;
        cur = cur->next;
    }
    return count;
}

/* given a fov number, compute the average volume of all the cells observed in
 * that fov
 */
double LinkedList::average(int fov)
{

    // Implement this function
    Node * walkThrough = head;
    double counter = 0;
    double total = 0;

    while(walkThrough!=nullptr)
    {
        if(walkThrough->data.fov == fov)
        {
            counter++;

            total += walkThrough->data.volume;
        }
        walkThrough=walkThrough->next;
    }
    return total/counter;
}

/* given a fov number, compute the variance volume of all the cells observed in
 * that fov
 */
double LinkedList::variance(int fov)
{
	/* Do not modify this function */
    double sum = 0;
    double avg = average(fov);
    int count = countN(fov);

    if (count == 0)
        return -1;

    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume - avg) * (cur->data.volume - avg);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, remove outliers
 */
string LinkedList::outliers(int fov, int k, int N)
{
    int o_o = countN(fov);
    if(o_o < N)
    {
        string Nstring = std::to_string(N);
        string FovString = std::to_string(fov);
        return "Less than "+ Nstring +" cells in fov "+FovString;
    }

    //double variancex= variance(fov);

    Node * walkThrough = head;
    // here fov is first pos the cannvas post is a little wierd and outdates it has 
    //int k, int j, int N

    double avg = average(fov);
    double Delta = sqrt(variance(fov));
    double LowerBound = avg-k*(Delta);
    // cout << "lb: " << LowerBound << endl;
    double UpperBound = avg+k*(Delta);
    // cout << "ub: " << UpperBound << endl;
    int CountCells = 0;
    while(walkThrough!=nullptr)
    {

        int x = fov;
        if(fov == walkThrough->data.fov)
        {// if in the right fov


        double Volume = walkThrough->data.volume;
           
            if((Volume < LowerBound) || (UpperBound < Volume))
            {
                // 709.265
                //515.718
                CountCells++;
    //           cout << " This is running! " << std::endl;
                Node * NextNode = walkThrough->next;
                remove(walkThrough->data.id,walkThrough->data.fov,walkThrough->data.volume,walkThrough->data.center_x,walkThrough->data.center_y,walkThrough->data.min_x,walkThrough->data.max_x,walkThrough->data.min_y,walkThrough->data.max_y);
                // Node * deleteme = walkThrough->next;
            //    walkThrough->next = walkThrough->next->next;
                walkThrough = NextNode;
            //  delete deleteme;

            }
            else{
                walkThrough=walkThrough->next;

            }
        }
        else
        {
        walkThrough=walkThrough->next;
        }
    }

    return std::to_string(CountCells) + " cells are removed.";

}

Node * LinkedList::copy() const
{
    Node * walkThrough = this->head;
    Node * before, *firstOne;
    if(walkThrough == nullptr)
    {
        // if this is empty return null
        return nullptr;
    }
    // handle first one
    before = new Node;
    // so I make a new class or like a new box that contains a node and say the first node is new Node
    firstOne = before;
    before->data = walkThrough->data;
    before->next=nullptr;
    walkThrough=walkThrough->next;
    // do the rest
    while (walkThrough != nullptr)
    {
        Node * copyThis = new Node;
        copyThis->data = walkThrough->data;
        copyThis->next=nullptr;
        before->next = copyThis;

    //    copyThis = tail;
    // you need to declare tail to be copyThis;
        
        before = copyThis;
        walkThrough=walkThrough->next;
    }


    return firstOne;
}
