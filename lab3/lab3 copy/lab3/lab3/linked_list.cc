// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    std::cout << curr->key;
    if (curr->next != NULL) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int> to_vector(Node* head) {
  std::vector<int> result;
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    result.push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){
  // ******** WRITE YOUR CODE HERE ********
  Node* tempDeleteNode = head->next;
  Node* firstNodeD = head;
  int deleteSize = size(head);
  if (deleteSize == 1) {
    head = NULL;
    delete head; //delete head since only thing in list or leave it NULL
  }
  else {
    while (tempDeleteNode->next != NULL) {
      firstNodeD = tempDeleteNode;
      tempDeleteNode = tempDeleteNode->next;
    }
    firstNodeD->next = NULL;
    delete tempDeleteNode;
  }
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */ 
void remove(Node*& head, int oldKey) {
  // ******** WRITE YOUR CODE HERE ********
  Node* tempRemoveNode = head;
  Node* tempRemovePrevious = NULL;
  if (tempRemoveNode != NULL) {
    int removeSize = size(head);
    for (int i = 0; i<removeSize;i++) {
      if (tempRemoveNode->key == oldKey) {
        if (tempRemoveNode == head) { //deal with the case in which head has the key
          if (removeSize != 1)
            head = head->next;
          else head = NULL;
          //break; // break out of the for loop since it was found
        }
        else { // every other case
          tempRemovePrevious->next = tempRemoveNode->next; // remove node w/ key from linked list
          //break; // break out of for loop;
          delete tempRemoveNode;
        }
      }
      tempRemovePrevious = tempRemoveNode; // node just checked is new previous
      tempRemoveNode = tempRemoveNode->next; // move to next node
    }
  }
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){
  // ******** WRITE YOUR CODE HERE ********
  Node* tempInsertNode = head;
  if (tempInsertNode != NULL) { //if the list isnt empty
    int insertSize = size(head);
    for (int j = 0; j<insertSize;j++) {
      if (tempInsertNode->key == oldKey) {
        insert(tempInsertNode->next, newKey); // does all the work of rearranging
        break;
      }
      else 
        tempInsertNode = tempInsertNode->next;// keep looping
    }
  }
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  if (!list1 && !list2) {
    //std::cout << "Both lists are NULL" << std::endl;
    return NULL;
  }
  if (list1 == NULL){ // base case #1 - list2 is only list left
    //std::cout << "Returning list2 " << std::endl;
    Node* list2first = new Node();
    list2first->key = list2->key;
    //std::cout << "The first key is " << list2first->key << std::endl;
    list2first->next = interleave(NULL, list2->next);
    return list2first;
  }
  if (list2 == NULL){// base case #2 - list1 is the only list left
    //std::cout << "Returning list1" << std::endl;
    Node* list1first = new Node();
    list1first->key = list1->key;
    //std::cout << "The first key is " << list1first->key << std::endl;
    list1first->next = interleave(list1->next, NULL);
    return list1first;
  }
  Node* first = new Node();
  first->key = list1->key;
  //std::cout << "The first key is " << first->key << std::endl;
  Node* second = new Node();
  second->key = list2->key;
  //std::cout << "The second key is " << second->key << std::endl;
  Node* third = list1->next;
  //std::cout << "The third key is " << third->key << std::endl;
  Node* fourth = list2->next;
  //std::cout << "The fourth key is " << fourth->key << std::endl;
  first->next = second;
  //std::cout << "Made second first->next"<< std::endl;
  second->next = interleave(third, fourth);
  return first;
}
