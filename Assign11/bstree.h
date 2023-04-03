//*******************************************************************
// 
//  CSCI 241 Assignment 11
//
// Trevor Berggren  z1906236
// 4/15/2021
//
//*******************************************************************

#ifndef BSTREE_H
#define BSTREE_H
        
#include <iostream>
#include <queue>
using namespace std;
        
// Forward declaration of the bstree template class
template <class K, class V>
class bstree;
        
template <class K, class V>
struct node
{
    K key;
    V value;
    node<K, V>* left;
    node<K, V>* right;
    
    node(const K& key = K(), const V& value = V(), node<K, V>* left = nullptr, node<K, V>* right = nullptr)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

template <class K, class V>
class bstree
{

    private:
    node<K, V>* root = nullptr;
    size_t tree_size = 0;

    node<K, V>* clone(node<K, V>*) const;
    size_t height(node<K, V>*) const;
    void preorder(node<K, V>*)const;
    void inorder(node<K, V>*)const;
    void postorder(node<K, V>*)const;

    public:
    bstree() = default;
    ~bstree();
    bstree(const bstree<K, V>&);
    bstree<K, V>& operator=(const bstree<K, V>&);
    void clear();
    size_t size() const;
    size_t height() const;
    bool empty() const;
    const K& min() const;
    const K& max() const;
    bool insert(const K&, const V&);
    bool remove(const K&);
    const node<K, V>* find(const K&) const;
    void destroy(node<K, V>*);
    void preorder()const;
    void inorder()const;
    void postorder()const;
    void level_order()const;
};

//destructor
template <class K, class V>
bstree<K, V>::~bstree()
{
    clear();                            // clears the queue
}

// copy constructor
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x)
{
    tree_size = x.tree_size;            // copies the size
    root = clone(x.root);               // clones the root
}

/**
 * Copy assignment operator.
 *
 * @param x The mystack object on the right-hand side of the 
 *          assignment statement.
 *
 * @return The updated node on the left side of the 
 *         assignment statement.
 ********************************************************************/
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x)
{
    if(this != &x)
    {
        clear();                       // clears
        tree_size = x.tree_size;        // copies size and root
        root = clone(x.root);
    }
    return *this;

}

/**
 * Clone function
 *
 * @param p is a pointer to a tree node
 *
 * @return a cloned tree node
 ********************************************************************/
template <class K, class V>
node<K, V>* bstree<K, V>::clone(node<K, V>* p)const
{
    if(p != nullptr)
    {
         node<K, V>* new_node = new node<K, V>();   // allocates a new node
         new_node->key = p->key;                    // assigns
         new_node->value = p->value;

        new_node->left = clone(p->left);            // clones left and right to
        new_node->right = clone(p->right);          // the new node and returns

        return new_node;
    }
    else
    return nullptr;                                 // if null pointer

}

/**
 * destroy function
 *
 * @param p is a pointer to a tree node
 *
 ********************************************************************/
template <class K, class V>
void bstree<K, V>::destroy(node<K, V>* p)
{
    if(p != nullptr)
    {
        destroy(p->left);               // destorys the tree node forleft and right
        destroy(p->right);
        
        delete p;                       // deletes the pointer
    }
}

/**
 * Resets the stack to the empty state.
 ********************************************************************/
template <class K, class V>
void bstree<K, V>::clear()
{
    destroy(root);                      // destroys the root
    root = nullptr;                     // assigns null and 0
    tree_size = 0;

}

/**
 * Returns the stack size.
 *
 * @return The number of elements stored in the stack.
 ********************************************************************/
template <class K, class V>
size_t bstree<K, V>::size() const
{
    return tree_size;
}

/**
 * Returns the height.
 *
 * @return The height of the tree
 * Non-recursive public function
 ********************************************************************/
template <class K, class V>
size_t bstree<K, V>::height() const
{
    return height(root);            // calls the height function
}

/**
 * Returns the height.
 * 
 * @param p is a pointer to a tree node
 *
 * @return The height of the tree
 * recursive private function
 ********************************************************************/
template <class K, class V>
size_t bstree<K, V>::height(node<K, V>* p) const
{

    size_t left_height;
    size_t right_height;

    if(p == nullptr)
    {
        return 0;               // if p is null height is 0
    }

    else 
    {
        left_height = height(p->left);      // assigns
        right_height = height(p->right);

        if(left_height > right_height)
           { return left_height + 1;        // if left is bigger
           }
        else                                // if left is less than right
        return right_height + 1;
    }
}

/**
 * Tests whether the stack is empty.
 *
 * @return Returns true if the stack size is 0, false
 *         otherwise.
 ********************************************************************/ 
template <class K, class V>
bool bstree<K, V>::empty() const
{       
    if(tree_size == 0)              
    return true;

    else 
    return false;
}

/**
 * Finds the min node
 *
 * @return The min key found
 ********************************************************************/
template <class K, class V>
const K& bstree<K, V>::min() const
{
    node<K, V>* min = root;             // assigns node

    while(min->left != nullptr)         // checks that next left isnt null
    {
        min = min->left;                // goes to next left
    }
    return(min->key);                   // returns min
}

/**
 * Finds the max node
 *
 * @return The max key found
 ********************************************************************/
template <class K, class V>
const K& bstree<K, V>::max() const
{
    node<K, V>* max = root;            // assigns node

    while(max->right != nullptr)
    {                               // checks if right is null
        max = max->right;           // goes to next right and returns
    }
    return(max->key);
}

/**
 * Inserts a key and value
 * 
 * @param key value
 *
 * @return True if able to insert false if not
 ********************************************************************/
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value)
{
    node<K, V>* p;                  // declare new nodes
    node<K, V>* parent;
    node<K, V>* new_node;

    p = root;                       // assigns
    parent = nullptr;

    while(p != nullptr && key != p->key)
    {
        parent = p;

        if(key < p->key)
        p = p->left;                // checks if bigger or smaller
        else                        // assigns
        p = p->right;
    }

    if(p != nullptr)
    return false;

    new_node = new node<K, V>(key, value);

    if(parent == nullptr)
    {
        root = new_node;
    }

    else
    {
        if(new_node->key < parent->key)     // checks if bigger or smaller
        parent->left = new_node;
        else                                // assigns
        parent->right = new_node;

    }
    tree_size = tree_size + 1;              // increment
    return true;

}

/**
 * Removes a key
 * 
 * @param key
 *
 * @return True if removed false if not
 ********************************************************************/
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
    node<K, V>* p;                         // declare
    node<K, V>* parent;
    node<K, V>* replace;
    node<K, V>* replace_parent;

    p = root;                               // assigns
    parent = nullptr;

    while(p != nullptr && key != p->key)
    {
        parent = p;

        if(key < p->key)                    // if bigger or smaller and assigns
        p = p->left;
        else
        p = p->right;
    }

    if(p == nullptr)
    return false;

    if(p->left == nullptr)
    replace = p->right;                 // checks for null
    else if(p->right == nullptr)
    replace = p->left;

    else
    {
        replace_parent = p;
        replace = p->left;

        while(replace->right != nullptr)
        {                               // checks for null and assigns
            replace_parent = replace;
            replace = replace->right;
        }

        if(replace_parent != p)         // checks for equal then assigns
        {
            replace_parent->right = replace->left;
            replace->left = p->left;
        }
        replace->right = p->right;
    }

    if(parent == nullptr)
    root = replace;
    else
    {
        if(p->key < parent->key)        // check for biggger or smaller
        parent->left = replace;
        else
        parent->right = replace;
    }

    delete p;                          // delete pointer and decreases
    tree_size = tree_size - 1;
    return true;

}

/**
 * Finds a key
 * 
 * @param key
 *
 * @return The node it was found
 ********************************************************************/
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const
{
    node<K, V>* p;
                                    // declares and assigns
    p = root;

    while(p != nullptr && key != p->key)
    {
        if(key < p->key)            // if bigger or smaller
        p = p->left;
        else
        p = p->right;
    }
    return p;
}

// Non-recursive public function
template <class K, class V>
void bstree<K, V>::preorder() const
{
    preorder(root);             // calls preorder
}

/**
 * Prints preorder
 * 
 * @param p is a pointer to a tree node
 *
 * recursive private function
 ********************************************************************/
template <class K, class V>
void bstree<K, V>::preorder(node<K, V>* p) const
{
    if(p != nullptr)                // checks for null
    {
        cout << p->key <<": " << p->value << ' ' << endl;
        preorder(p->left);          // prints before going left and right
        preorder(p->right);
    }
}

// Non-recursive public function
template <class K, class V>
void bstree<K, V>::inorder() const
{
    inorder(root);                      // calls inorder
}

/**
 * Prints inorder
 * 
 * @param p is a pointer to a tree node
 *
 * recursive private function
 ********************************************************************/
template <class K, class V>
void bstree<K, V>::inorder(node<K, V>* p) const
{
    if(p != nullptr)                // checks for null
    {
        inorder(p->left);           // prints inorder of going left and right
        cout << p->key <<": " << p->value << ' ' << endl;
        inorder(p->right);
    }
}

// Non-recursive public function
template <class K, class V>
void bstree<K, V>::postorder() const
{
    postorder(root);                // calls postorder function
}

/**
 * Prints postorder
 * 
 * @param p is a pointer to a tree node
 *
 * recursive private function
 ********************************************************************/
template <class K, class V>
void bstree<K, V>::postorder(node<K, V>* p) const
{
    if(p != nullptr)
    {
        postorder(p->left);         // prints after going left and right
        postorder(p->right);
        cout << p->key <<": " << p->value << ' ' << endl;
    }
}

/**
 * Prints level order
 *
 * recursive private function
 ********************************************************************/
template <class K, class V>
void bstree<K, V>::level_order() const
{
    node<K, V>* p;
    std::queue<node<K, V>*> q;      // queue node

    if(root == nullptr)
    return;

    q.push(root);                   // pushes root

    while(!q.empty())               // while queue is not empty
    {
        p = q.front();              // front of the queue
        q.pop();                    // pops and prints
       cout << p->key <<": " << p->value << ' ' << endl;

        if(p->left != nullptr)
        q.push(p->left);            // push left if not null

        if(p->right != nullptr)
        q.push(p->right);           // push right if not null
    }
}

#endif