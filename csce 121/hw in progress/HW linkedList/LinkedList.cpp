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

     // will I need to deal with a improper comparison?
    // CopyME->data.id;

    // head = nullptr;
    // Node * SourceHead = CopyME.getHead();
    // // this is 
    // // this used to be NULL
    // if(SourceHead==nullptr)
    // {
    //     insert(SourceHead->data.id,SourceHead->data.fov,SourceHead->data.volume,SourceHead->data.center_x,SourceHead->data.center_y,SourceHead->data.min_x,SourceHead->data.max_x,SourceHead->data.min_y,SourceHead->data.max_y);
    //     SourceHead=SourceHead->next;
    // }
    //  while(SourceHead != nullptr)
    //  {

    //     // now insert the new at this position
    //     insert(SourceHead->data.id,SourceHead->data.fov,SourceHead->data.volume,SourceHead->data.center_x,SourceHead->data.center_y,SourceHead->data.min_x,SourceHead->data.max_x,SourceHead->data.min_y,SourceHead->data.max_y);
    //     // declare temp to be the next movement 
    //     SourceHead  = SourceHead->next;
    //  }
    // // Implement this function
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
    Node * walkThrough = this->head;    /*
   if (this->items->item==itemToDelete) {
      List *deleteme = this->items;
      this->items = this->items->next;
      // points to second one
      delete deleteme;
   }
    */
   if(ThisNode == nullptr || walkThrough == nullptr)
   {
       return;
   }
   if(walkThrough->data.id == ThisNode->data.id)
   {
       // point from the pervios one to the one you are trying to remove
 //      Node * deleteme = this->head;
       this->head = this->head->next;
   //    delete deleteme;

       return;
   }


/*
   List *prev = this->items;
   while (prev->next !=nullptr && prev->next->item != itemToDelete) {
     prev = prev->next;
     // prev = (*prev).next;

   }
   if (prev->next==nullptr) {
        return;
   }
*/

    while(walkThrough != nullptr && walkThrough->next->data.id != ThisNode->data.id)
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
        return;
    }
    /*
   List *deleteme = prev->next;
   prev->next = prev->next->next;
   delete deleteme;
    */
    Node * deleteme = walkThrough->next;
    walkThrough->next = walkThrough->next->next;
    delete deleteme;
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
}

Node* LinkedList::getHead() const 
{
    // Implement this function it will be used to help grade other functions
    return head;
}
/*
void print(): use this function to print out the content in the linked list.
o The first line should be “id, fov,
volume,center_x,center_y,min_x,max_x,min_y,max_y” without any
whitespaces.
o Output format is the same as the format in the input file. id, fov,
volume,center_x,center_y,min_x,max_x,min_y,max_y. Items are separated
with a comma without any whitespaces.
*/
string LinkedList::print() const 
{
//     LinkedList ll;
// ll.insert("2173497634120378088337806635102894778",12,1510.77,292.707,2897.58,284.488,300.926,2889.52,2905.64);
// ll.insert("79348300038704795909383410217324322859",0,1702.84,174.383,4374.47,165.894,182.872,4364.2,4384.74);
// ll.insert("223019657424923101059124670196117441553",12,302.44,387.688,2849.25,385.36,390.015,2842.76,2855.74);
// ll.insert("112315799428971059837534848038041808853",11,1454.6,353.811,2742.56,345.754,361.868,2733.31,2751.8);

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
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.center_x);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.center_y);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.min_x);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.max_x);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.min_y);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        PrintMe +=Storage+',';

        Storage = std::to_string(walkThroughNodes->data.max_y);
        Storage.erase ( Storage.find_last_not_of('0') + 1, std::string::npos );
        PrintMe +=Storage;

        // PrintMe += walkThroughNodes->data.volume+',';
        // PrintMe += walkThroughNodes->data.center_x+',';
        // PrintMe += walkThroughNodes->data.center_y+',';
        // PrintMe += walkThroughNodes->data.min_x+',';
        // PrintMe += walkThroughNodes->data.max_x+',';
        // PrintMe += walkThroughNodes->data.min_y+',';
        // PrintMe += walkThroughNodes->data.max_y;
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
    int CBT = countN(fov);
    if(CBT < N)
    {
        string Nstring = std::to_string(N);
        string FovString = std::to_string(fov);
        return "Less than "+ Nstring +" cells in fov "+FovString;
    }

    double variancex= variance(fov);
    double Delta = sqrt(variancex);

    Node * walkThrough = head;
    // here fov is first pos the cannvas post is a little wierd and outdates it has 
    //int k, int j, int N
    double LowerBound = average(fov)-k*(Delta);
    double UpperBound = average(fov)+k*(Delta);
    int CountCells = 0;
    while(walkThrough!=nullptr)
    {
        double Volume = walkThrough->data.volume;
        if((LowerBound <= Volume) && (Volume <= UpperBound))
        {
 //           cout << " This is running! " << std::endl;
            CountCells++;
             remove(walkThrough->data.id,walkThrough->data.fov,walkThrough->data.volume,walkThrough->data.center_x,walkThrough->data.center_y,walkThrough->data.min_x,walkThrough->data.max_x,walkThrough->data.min_y,walkThrough->data.max_y);
            // Node * deleteme = walkThrough->next;
             walkThrough->next = walkThrough->next->next;
          //  delete deleteme;

        }
        walkThrough=walkThrough->next;
    }
    return std::to_string(CountCells) + " cells are removed.";

    // remove every node that is k sqrt(variance from the average)

    // YOU NEED TO MAKE A PERVIOUS POINTER TO THEN DELETE THE ONE THAT HAS A OUTLIER
    // THEN UPDATE HEAD/TAIL


    // Implement this function
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
        before = copyThis;
        walkThrough=walkThrough->next;
    }
    return firstOne;
}

// tester function
//   void LinkedList::removeDeleteThis(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
//   {
//       LinkedList ll;
//       ll.remove("102664563492900048462363937849459428087",12,825.112,416.767,6086.12,412.441,421.092,6076.72,6095.53);

//   }
