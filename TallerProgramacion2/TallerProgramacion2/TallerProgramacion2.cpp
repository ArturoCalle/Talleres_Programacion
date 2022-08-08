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

    void appendToTail(int d)
    {
        Node* end = new Node(d);
        Node* n = this;
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
    for (int i = -1; i < 7; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 5; i < 7; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 8; i < 10; i++)
    {
        node->appendToTail(i);
    }
    for (int i = 3; i < 5; i++)
    {
        node->appendToTail(i);
    }
    node->printList();

    node->RemoveDuplicatesMemory();
    node->printList();


}

