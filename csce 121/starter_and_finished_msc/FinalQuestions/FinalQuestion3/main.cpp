void insert(char afterLetter, LinkedList& insertList)
{
    Node* walkthroughFirst = head;
    Node* walkthroughSecond = insertList.head;
    bool WeAreAfterTheLetter=false;
    bool RunOnce = true;
    char transfer;
    if(walkthroughSecond == nullptr)
    { //  there is nothing to copy
        return;
    }
    while(walkthroughFirst != nullptr)
    {
        if((afterLetter == walkthroughFirst->letter)&&RunOnce)
        {
            WeAreAfterTheLetter=true;
            RunOnce = false;
            // now we want to go one after i
            Node * saveMyPlace = walkthroughFirst;
            while(walkthroughSecond != nullptr)
            {
                walkthroughFirst->next->Node(walkthroughSecond->letter);
                walkthroughFirst = walkthroughFirst->next;
                walkthroughSecond = walkthroughSecond->next;
                // I will clear the second at the end
            }
            // now I have added the items I needed
            // now call saveMyPlace
            walkthroughFirst = saveMyPlace;
            // this will allow walkthroguh to point back to i
        }
        walkthroughFirst = walkthroughFirst->next;
    }
    // if te  letter does not exist add to the end
    if(!WeAreAfterTheLetter)
    {
        Node * oneStepFromEnd = walkthroughfirst->prev;
        Node* walkthroughSecond = insertList.head;
        while(walkthroughSecond != nullptr)
        {
            oneStepFromEnd->next->Node(walkthroughSecond->letter);
            walkthroughSecond = walkthroughSecond->next;
            oneStepFromEnd=oneStepFromEnd->next;
        } 
        // after we have added all the letters
        oneStepFromEnd->next=nullptr;

    }
    // now I need to clear the copied list

    Node * walkthroughSecond = insertList.head;
    while(walkthroughSecond!=nullptr)
    {
        Node * temp = walkthroughSecond->next;
        delete walkthroughSecond;
        walkthroughSecond = temp;
    }
    insertList.head = nullptr;
}
