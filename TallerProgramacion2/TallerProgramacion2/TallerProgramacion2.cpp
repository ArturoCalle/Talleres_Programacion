// TallerProgramacion2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
class Node
{
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
            this->printList();
            ToLastHead->printList();
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

    bool ExistInList(int data)
    {
        Node* n = this;
        bool doesExist = false;
        while (n != nullptr)
        {
            if (n->data == data)
                return true;
            n = n->next;
        }
        return false;
    }
    int MaxValue()
    {
        Node* n = this;
        int max = 0;
        while (n != nullptr)
        {
            if (n->data > max)
                max = n->data;
            n = n->next;
        }
        return max;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    Node* node = new Node(0);
    Node* node2 = new Node(3);
    for (int i = 1; i < 4; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 9; i > 4; i--)
    {
        node->appendToTail(i);
    }
    for (int i = 6; i < 9; i++)
    {
        node2->appendToTail(i);
    }
    node->printList();
    node2->printList();

    std::cout << "______________" << std::endl;
    Node* node3 = Node::SumLists2(node, node2);
    node3->printList();
    std::cout << "______________" << std::endl;


}

