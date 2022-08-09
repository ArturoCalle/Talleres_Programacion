// TallerProgramacion2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <map>
class NodeDouble
{
public:
    NodeDouble* next = nullptr;
    NodeDouble* previous = nullptr;
    int data;
public:
    NodeDouble(int d)
    {
        data = d;
    }
    NodeDouble* deleteMe(NodeDouble* node)
    {
        NodeDouble* aux = node;
        if (node->previous == nullptr)
        {
            node=node->next;
            node->previous = nullptr;
            return node;
            
        }
        else if(node->next == nullptr)
        {
            node = node->previous;
            node->next = nullptr;
            return this;
            
        }
        else
        {
            node->next->previous = node->previous;
            node->previous->next = node->next;
            return this;
        }

        

    }
    NodeDouble* Find(int data)
    {
        NodeDouble* n = this;
        while (n != nullptr)
        {
            if (n->data == data)
            {
                return n;
            }
            n = n->next;
        }
        return nullptr;
    }
    NodeDouble* Push_Front(int data)
    {
        NodeDouble* NewNode = new NodeDouble(data);
        NodeDouble* n = this;

        if (n != nullptr)
        {
            NewNode->next = n;
            n->previous = NewNode;
        }
        else
        {
            n = NewNode;
        }
        return NewNode;
    }
    void printList()
    {
        NodeDouble* n = this;
        while (n != nullptr)
        {
            std::cout << n->data << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }
    NodeDouble* GetTail()
    {
        NodeDouble* n = this;
        if (n == nullptr)
            return n;
        while (n->next != nullptr)
        {
            n = n->next;
        }
        return n;
    }
    int Size()
    {
        NodeDouble* n = this;
        int size = 0;
        while (n != nullptr)
        {
            size++;
            n = n->next;
        }
        return size;
    }
};
class LRUCache
{
    NodeDouble* head;
    NodeDouble* tail;
    int CacheSize;
    int CurrentSize;
    std::map<int, const char*> Map;

public:
    LRUCache(int Size)
    {
        CacheSize = Size;
        CurrentSize = 0;
        head = nullptr;
        tail = nullptr;
    }
    void Store(int x, const char* data)
    {
        if (head == nullptr)
        {
            //sets the first element
            CurrentSize++;
            head = head->Push_Front(x);
            tail = head;

            //add to map
            Map[x] = data;
        }
        else if (CurrentSize < CacheSize)
        {
            //adds element to the double linked list
            CurrentSize++;
            head = head->Push_Front(x);
            
            //add to map
            Map[x] = data;
        }
        else
        {
            //add new to list
            head = head->Push_Front(x);
            tail = head->GetTail();
            //remove least used from map
            Map.erase(tail->data);
            Map[x] = data;

            //deletes the least used
            NodeDouble* aux = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete aux;   
        }

    }
    const char* Refer(int x)
    {
        NodeDouble* n = head->Find(x);
        if (n != nullptr)
        {
            //moves node from any position to head, as its the most recently used
            head = head->deleteMe(n);
            head = head->Push_Front(n->data);
            

            //returns data assosiated to the searched value
            const char* data = Map[n->data];
            return data;

        }
        return NULL;

    }
    void Display()
    {
        NodeDouble* n = head;
        while (n != nullptr)
        {
            std::cout << n->data << ": ";
            const char* value = Map[n->data];
            while(*value != NULL)
            {
                std::cout << *value;
                value++;
            }
            std::cout << std::endl;
            n = n->next;
        }
    }

};
class Node
{
public:
    Node* next = nullptr;
    int data;
public:
    Node(int d)
    {
        data = d;
    }
    void printList()
    {
        Node* n = this;
        while (n != nullptr)
        {
            std::cout << n->data << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }

    int Size()
    {
        Node* n = this;
        int counter = 0;
        while (n != nullptr)
        {
            counter++;
            n = n->next;
        }
        return counter;
    }

    Node* Clear()
    {
        if (this == nullptr)
            return nullptr;
        Node* n = this;
        while (n != nullptr)
        {
            Node* aux = n;
            n = n->next;
            delete aux;
        }
        return nullptr;
    }
    
    void appendToTail(int d)
    {
        Node* n = this;
        Node* end = new Node(d);
        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->next = end;
    }

    Node* deleteNode(Node* head, int d)
    {
        if (head == nullptr)
            return nullptr;
        Node* n = head;
        if (n->data == d)
        {
            delete n;
            return head->next; /* moved head */
        }
        while (n->next != nullptr)
        {
            if (n->next->data == d)
            {
                Node* aux = n->next->next;
                delete n->next;
                n->next = aux;
                return head; /* head didn't change */
            }
            n = n->next;
        }
        return head;
    }

    int extractElementAt(Node* head, int offset)
    {
        if (head == nullptr)
            return NULL;
        Node* n = head;
        int Value;
        if (offset == 0)
        {
            Value = head->data;
            head = head->next; /* moved head */
            delete n;
            return Value;

        }
        int counter = 0;
        while ((counter < offset-1)&&(n->next != nullptr))
        {
            counter++;
            n = n->next;
        }
        if (n->next == nullptr)
        {
            return NULL;
        }
        Value = n->next->data;
        Node* aux = n->next;
        n->next = n->next->next;
        delete aux;
        return Value;

    }

    void RemoveDuplicatesFast()
    {
        Node* n = this;
        if (n == nullptr)
            return;

        std::map<int, int> Values;
        Values.insert(std::pair<int, int>(n->data, n->data));
        Node* previus = n;
        n = n->next;
        while (n != nullptr)
        {
            std::pair<std::map<int, int>::iterator, bool> duplicate;
            duplicate = Values.insert(std::pair<int, int>(n->data, n->data));
            if (duplicate.second == false)
            {
                previus->next = n->next;
                delete n;
                n = previus->next;
            }
            else
            {
                previus = n;
                n = n->next;

            }
        }

    }

    void RemoveDuplicatesMemory()
    {
        Node* n = this;
        if (n == nullptr)
            return;
        int counter = 1;
        while (n->next != nullptr)
        {
            bool isDuplicate = false;
            Node* checkDupes = this;
            for(int i = 0;i < counter;i++)
            {
                if (n->next->data == checkDupes->data)
                {                    
                    isDuplicate = true;
                    break;
                }
                checkDupes = checkDupes->next;
            }
            if (isDuplicate)
            {
                Node* aux = n->next;
                n->next = n->next->next;
                delete aux;
            }
            else
            {
                counter++;
                n = n->next;
            }
            

        }
    }

    Node* Kth_ToLast(int Kth)
    {
        int size = this->Size();
        size = size - Kth -1 ;

        if (size < 0)
            return this;
        Node* n = this;
        while (n != nullptr)
        {
            if (size == 0)
                return n;
            size--;
            n = n->next;

        }
        return n;

    }

    void Partition(int PartitionInt)
    {
        int size = this->Size();
        Node* n = this;
        Node* ToLast = nullptr;
        Node* ToLastHead = nullptr;
        if (n == nullptr)
            return;
        if (n->data >= PartitionInt)
        {
            ToLastHead = n;
            ToLast = ToLastHead;
            Node* head = this;
            head = n->next;
        }
        while(n->next!=nullptr)
        {
            if (n->next->data >= PartitionInt)
            {
                if (ToLastHead == nullptr)
                {
                    ToLastHead = n->next;  
                    ToLast = ToLastHead;
                    
                }
                else
                {
                    ToLast->next = n->next;
                    ToLast = ToLast->next;
                }
                n->next = n->next->next;

            }
            else
            {
                n = n->next;
            }
        }
        if (ToLastHead != nullptr)
        {
            n->next = ToLastHead;
        }

    }

    static Node* SumLists(Node* L1Head, Node* L2Head)
    {
        int aux = 0;
        Node* Sum = nullptr;
        Node* L1 = L1Head;
        Node* L2 = L2Head;
        while ((L1 != nullptr) && (L2 != nullptr))
        {
            aux = L1->data + L2->data+aux;
            if (Sum == nullptr)
            {
                Sum = new Node(aux % 10);
            }
            else
            {
                Sum->appendToTail(aux % 10);
            }
            aux = aux / 10; 
            L1 = L1->next;
            L2 = L2->next; 
        }
        while (L1 != nullptr)
        {
            aux = L1->data+ aux;
            if (Sum == nullptr)
            {
                Sum = new Node(aux % 10);
            }
            else
            {
                Sum->appendToTail(aux % 10);
            }
            aux = aux / 10;
            L1 = L1->next;
        }
        while (L2 != nullptr)
        {
            aux = L2->data + aux;
            if (Sum == nullptr)
            {
                Sum = new Node(aux % 10);
            }
            else
            {
                Sum->appendToTail(aux % 10);
            }
            aux = aux / 10;
            L2 = L2->next;
        }
        return Sum;
    }

    static Node* SumLists2(Node * L1Head, Node * L2Head)
    {
        //Calculate the size of each number
        int SizeNum1 = 0;
        int SizeNum2 = 0;
        Node* L1 = L1Head;
        Node* L2 = L2Head;
        while (L1 != nullptr)
        {
            SizeNum1++;
            L1 = L1->next;
        }
        while (L2 != nullptr)
        {
            SizeNum2++;
            L2 = L2->next;
        }

        
        //save the difference between sizes
        int SizeDiff = SizeNum1 - SizeNum2;
        while (SizeDiff != 0)
        {
            if (SizeDiff > 0)
            {
                Node* n = new Node(0);
               n->next = L2Head;
               L2Head = n;
               SizeDiff--;
                
            }
            else if (SizeDiff < 0)
            {
               Node* n = new Node(0);
               n->next = L1Head;
               L1Head = n;
               SizeDiff++;
            }
        }
  
        int aux = 0;
        Node* Sum = nullptr;
        Node* SumIterator = nullptr;
        L1 = L1Head;
        L2 = L2Head;
        //insertion of th number addition
        while ((L1!= nullptr) && (L2 != nullptr))
        {
            aux = (L1->data + L2->data)/10 + aux;
            if (aux == 10 && SumIterator != nullptr)
            {
                aux = 0;
                SumIterator->data++;
            }
            if (Sum == nullptr)
            {
                Sum = new Node(aux);
                SumIterator = Sum;
            }
            else
            {
                Sum->appendToTail(aux);
                SumIterator = SumIterator->next;
            }
            aux = (L1->data + L2->data)%10;
            L1 = L1->next;
            L2 = L2->next;
            
        }
        Sum->appendToTail(aux);
        if (Sum->data == 0)
        {
            Node* n = Sum;
            Sum = Sum->next;
            delete n;
        }
        return Sum;
    }
    
    bool Palindrome()
    {
        int size = this->Size();
        int half = size / 2;
        int* copy = new int[half];
        Node* n = this;
        if (n != nullptr)
        {
            for(int i = 0; i < half ;i++)
            {
                copy[i] = n->data;
                n = n->next;
            }
        }
        if (size % 2 == 1)
        {
            n = n->next;
        }
        while (n != nullptr)
        {
            if (n->data != copy[half-1])
            {

                return false;
            }
            half--;
            n = n->next;
        }
    }
};
int main()
{
    /*Insertion of a list ___________________________________________________________________________________________________________________________________________
    */
    Node* node = new Node(0);
    for (int i = 1; i < 6; i++)
    {
        node->appendToTail(i);
    }
    std::cout << "list: " << std::endl;
    node->printList();
    std::cout << std::endl;

    /*Element Extraction ____________________________________________________________________________________________________________________________________________
    */
    std::cout << "Element Extraction (3): " << std::endl;
    int element = node->extractElementAt(node, 3);
    std::cout << "Element: " << element << std::endl;
    std::cout << "list: " << std::endl;
    node->printList();
    std::cout << std::endl;

    /*Duplicate Removal _______________________________________________________________________________________________________________________________________________
    */
    std::cout << "Duplicate Removal Fast: " << std::endl;
    for (int i = 5; i < 9; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 2; i < 6; i++)
    {
        node->appendToTail(i);
    }
    std::cout << "list: " << std::endl;
    node->printList();
    node->RemoveDuplicatesFast();
    std::cout << "elements removed list: " << std::endl;
    node->printList();
    std::cout << std::endl;

    /*Duplicate Removal Memory rather than performance _______________________________________________________________________________________________________________
    */
    std::cout << "Duplicate Removal Memory: " << std::endl;
    for (int i = 5; i < 9; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 2; i < 6; i++)
    {
        node->appendToTail(i);
    }
    std::cout << "list: " << std::endl;
    node->printList();
    node->RemoveDuplicatesMemory();
    std::cout << "Duplicate removed list: " << std::endl;
    node->printList();
    std::cout << std::endl;

    /*Return the Kth element to last _____________________________________________________________________________________________________________________________________
    */
    std::cout << "Kth element to last (4): " << std::endl;
    std::cout << "list: " << std::endl;
    node->printList();
    Node* kth = node->Kth_ToLast(4);
    std::cout << "kth element: " << kth->data << std::endl;
    std::cout << std::endl;

    /*List Partition  _____________________________________________________________________________________________________________________________________
    */
    std::cout << "List partition X = 4: " << std::endl;
    for (int i = 5; i < 9; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 0; i < 5; i++)
    {
        node->appendToTail(i);
    }
    std::cout << "list: " << std::endl;
    node->printList();
    node->Partition(4);
    std::cout << "partition list: " << std::endl;
    node->printList();
    std::cout << std::endl;

    /*Sum Lists  _____________________________________________________________________________________________________________________________________
    */
    node->Clear();
    std::cout << "List Sum: " << std::endl;
    node = new Node(3);
    for (int i = 1; i < 4; i++)
    {
        node->appendToTail(i);
    }
    Node* node2 = new Node(4);
    for (int i = 9; i > 2; i--)
    {
        node2->appendToTail(i);
    }
    std::cout << "list1: " << std::endl;
    node->printList();
    std::cout << "list2: " << std::endl;
    node2->printList();
    Node* Sum = Node::SumLists(node, node2);
    std::cout << "Sum: " << std::endl;
    Sum->printList();
    std::cout << std::endl;

    /*Sum Lists  _____________________________________________________________________________________________________________________________________
    */
    node->Clear();
    node2->Clear();
    Sum->Clear();

    std::cout << "List Sum2: " << std::endl;
    node = new Node(3);
    for (int i = 8; i > 2; i--)
    {
        node->appendToTail(i);
    }
    node2 = new Node(4);
    for (int i = 9; i > 2; i--)
    {
        node2->appendToTail(i);
    }
    std::cout << "list1: " << std::endl;
    node->printList();
    std::cout << "list2: " << std::endl;
    node2->printList();
    Sum = Node::SumLists2(node, node2);
    std::cout << "Sum: " << std::endl;
    Sum->printList();
    std::cout << std::endl;

    /*Sum Lists  _____________________________________________________________________________________________________________________________________
    */
    node->Clear();
    node2->Clear();
    Sum->Clear();

    std::cout << "Palindrome: " << std::endl;
    node = new Node(0);
    for (int i = 1; i < 4; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 4; i >= 0; i--)
    {
        node->appendToTail(i);
    }
    std::cout << "list: " << std::endl;
    node->printList();
    if (node->Palindrome())
    {
        std::cout << "is Palindrome: " << std::endl;
    }
    else
    {
        std::cout << "is not Palindrome " << std::endl;
    }
    std::cout << std::endl;
    

    node->Clear();
    node = new Node(0);
    for (int i = 1; i < 2; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 3; i >= 1; i--)
    {
        node->appendToTail(i);
    }
    std::cout << "list: " << std::endl;
    node->printList();
    if (node->Palindrome())
    {
        std::cout << "is Palindrome: " << std::endl;
    }
    else
    {
        std::cout << "is not Palindrome " << std::endl;
    }
    std::cout << std::endl;


    /*Demo Cache
    */
    LRUCache* cache = new LRUCache(3);

    std::string word =  "Pedro" + NULL;
    cache->Store(1, word.c_str());
    std::string word2 =  "Pablo" + NULL;
    cache->Store(2, word2.c_str());
    std::string word3 =  "Juan" + NULL;
    cache->Store(3, word3.c_str());
    cache->Display();
    std::cout << std::endl;

    std::string word4 = cache->Refer(1);
    cache->Display();
    std::cout << std::endl;

    std::string word5 = "Julian" + NULL;
    cache->Store(4, word5.c_str());
    cache->Display();
    std::cout << std::endl;



}

