// Question 2:  How many nodes does the shortest linked list have? The longest linked list?
// Ans 2: ->A shortest linked list have 1 node and longest one can have infinity nodes with respect to your memory

// Question 3:  The linked list in Figure 3.1l was created in Section 3.2 with three assignments.
// Create this list with only one assignment.
// Ans 3: tail = (tail->next = new Node(10,tail,nullptr))
// this will only work if Node class have a constructor with 1st parameter as it's value, 2nd parameter as it's previous address and 3rd parameter as its next address(nulltpr)

// Question 4:  Merge two ordered singly linked lists of integers into one ordered list
//  Ans 4:
//  void merge(Linkedlist *List1, Linkedlist  *List2, Linkedlist *List3)
//  {
//    Node *head1 = List1->head;
//    Node *head2 = List2->head;
//    Node *temp1 = head1;
//    Node *temp2 = head2;
//    while(temp1 != nullptr && temp2 != nullptr)
//    {
//      if(temp1->data < temp2->data)
//      {
//        List3->insertAtTail(temp1->data);
//        temp1 = temp1->next;
//      }
//      else if(temp2->data < temp1->data)
//      {
//        List3->insertAtTail(temp2->data);
//        temp2 = temp2->next;
//      }
//      else if(temp1->data == temp2->data)
//      {
//        List3->insertAtTail(temp1->data);
//        temp1 = temp1->next;
//        List3->insertAtTail(temp2->data);
//        temp2 = temp2->next;
//      }
//      else if(temp1 == nullptr)
//      {
//        while(temp2 != nullptr)
//        {
//           List3->insertAtTail(temp2->data);
//           temp2 = temp2->next;
//        }
//      }
//      else if(temp2 == nullptr)
//      {
//        while(temp1 != nullptr)
//        {
//           List3->insertAtTail(temp1->data);
//           temp1 = temp1->next;
//        }
//      }
//    }
//   List3->Display();
//  }

// Question 5:  Delete an ith node from a linked list. Be sure that such a node exists.
//  Ans 5: Applying for singly linked list
//  void DeleteNode(index)
//  {
//    if(index < 0)
//    {
//      cout << "Invalid index" << endl;
//    }
//    else if(index == 0)
//    {
//      Node *temp = head;
//      head = head->next;
//      delete[] temp;
//    }
//    else
//    {
//      int currIndex = 0;
//      bool flag = true;
//      Node *temp = head;
//      Node *previous = nullptr;
//      while(temp != nullptr)
//      {
//        if(currIndex == index)
//        {
//          flag = false;
//          break;
//        }
//        previous = temp;
//        temp = temp->next;
//      }
//      if(flag)
//      {
//        cout << "Invalid index" << endl;
//      }
//      else
//      {
//        previous->next = temp->next;
//        delete[] temp;
//      }
//    }
//  }

// Question 6:  Delete from list L1
//   nodes whose positions are to be found in an ordered list L2. For instance, if L1=(A B C D E) and L2=(2 4 8),
//   then the second and the fourth nodes are to be deleted from list L1(the eighth node does not exist),
//   and after deletion, L1= (A C E)
//  Ans 6:
//  void DeleteNodeS(Linkedlist *List1, Linkedlist *List2)
//  {
//      Node *temp2 = List2->head;
//      while(temp2 != nullptr)
//      {
//          List1->deleteNode(temp2->data);
//          temp2 = temp2-> next;
//      }
//  }

// Question 7:  Delete from list L1 nodes occupying positions indicated in ordered lists L2
// and L3. For instance, if L1=(A B C D E), L2=(2 4 8), and L3=(2 5), then after deletion, L1=(A C).
// Ans 7:
// void deletingNodesInMergingOrder(List1, List2, List3)
// {
//     Node *head1 = List1.head;
//     Node *head2 = List2.head;
//     Node *temp1 = head1;
//     Node *temp2 = head2;
//     if(temp1->data == temp1->next->data)
//     {
//       List3.deleteNode(temp1->data);
//       temp1 = temp1->next->next;
//     }
//     else if(temp2->data == temp2->next->data)
//     {
//       List3.deleteNode(temp2->data);
//       temp2 = temp2->next->next;
//     }
//     else if(temp1->data < temp2->data)
//     {
//       List3.deleteNode(temp1->data);
//       temp1 = temp1->next;
//     }
//     else if(temp2->data < temp1->data)
//     {
//       List3.deleteNode(temp2->data);
//       temp2 = temp2->next;
//     }
//     else if(temp1->data == temp2->data)
//     {
//       List3.insertAtTail(temp1->data);
//       temp1 = temp1->next;
//       temp2 = temp2->next;
//     }
//     else if(temp1 == nullptr)
//     {
//       while(temp2 != nullptr);
//       List3.insertAtTail(temp2->data);
//       temp2 = temp2->next;
//     }
//     else if(temp2 == nullptr)
//     {
//       while(temp1 != nullptr);
//       List3.insertAtTail(temp1->data);
//       temp1 = temp1->next;
//     }
// }

// void deletingNodesInMergingOrder(List1, List2, List3)
// {
//     Linkedlist *merged;
//     merge(&List2, &List3, &merged);
//     DeleteNodeS(&List1, &merged);
// }

// Question 8: Delete from an ordered list L nodes occupying positions indicated in list L itself.
// For instance, if L = (1 3 5 7 8), then after deletion, L = (3 7).
// Ans 8:
// void selfDeleting(List1)
// {
//     Node *head1 = List1;
//     Node *temp = head1;
//     while(temp != nullptr)
//     {
//         if(temp->data == temp->next->data)
//         {
//             List1.deleteNode(temp->data);
//             temp = temp->next->next;
//         }
//         else
//         {
//             List1.deleteNode(temp->data);
//             temp = temp->next;
//         }
//     }
// }

// Question 9:  A linked list does not have to be implemented with pointers. Suggest other implementations of linked lists.

// Question 10:  Write a member function to check whether two singly linked lists have the same contents.

// void check(Linkedlist List1, Linkedlist List2)
// {
//     Node *temp1 = List1.head;
//     Node *temp2 = List2.head;
//     bool flag = true;
//     while (temp1 && temp2)
//     {
//         if (temp1->data != temp2->data)
//         {
//             flag = false;
//             break;
//         }
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }
//     if (flag)
//     {
//         cout << "Lists have same content" << endl;
//     }
//     else
//     {
//         cout << "Lists don't have same content" << endl;
//     }
// }

//Question 12: Insert a new node into a singly linked list (a) before and (b) after a node pointed to 
// by p in this list (possibly the first or the last). Do not use a loop in either operation.

// void insertingAtIndex(int index, int data)
// {
//     Node *newNode = new Node(data);
//     Node *temp = head;
//     currIndex = 0;
//     void traversing()
//     {
//         if(currIndex == index)
//         {
//             newNode->next = temp->next;
//             temp->next = newNode;
//             return;
//         }
//         else
//         {
//             temp = temp->next;
//         }
//         if(temp == nullptr)
//          {
//           return;
//          }
//         traversing();
//     }
// }

//Question 13:  Attach a singly linked list to the end of another singly linked list.
// void (Linkedlist List1, Linkedlist List2)
// {
//     Node *temp1 = List1.head;
//     Node *temp2 = List2.head;
//     while(temp1)
//     {
//         temp1 = temp1->next;
//     }
//     temp1->next = temp2;
// }

//Question 14: Put numbers in a singly linked list in ascending order. Use this operation to find the median in the list of numbers.