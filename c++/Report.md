## Binary Search Tree

The purpose of this project is the implementation of a templated binary search tree using modern C++14.
The performance of the container has been compared against the one of other built-in containers in the Standard Template Library. 


## General Structure


The `bst` class is templated on the types of the key, value and comparison operator. It has two private members: a unique pointer to an object of type _node **root** and a comparison operator **op**.

The `_node` struct is templated on the type of the pair stored in the node. Since the default visibility of a struct is public, all the members and methods are public for the tree to use. It has four members: a unique pointer to the **left** child, a unique pointer to the **right** child, a raw pointer to the **parent** and the key-value **pair** stored. This struct is implemented outside the bst class, since it does not need the template on the comparison operator. 

Then we provided our container with a class `_iterator`, in order to sequentially access the elements, without exposing its underlying representation. In particular it implements a forward iterator. This class is templated on the type of the node and the type of the pair stored in the node, in order to define both *iterator* and *const_iterator*. This class is implemented outside the bst class, being templated on different types. It has one private member: a raw pointer to a node, named **current**.



Three classes are implemented:

* `bst<k_t, v_t, OP>`: a templated Binary Search Tree; `k_t` is the key type - `v_t` is the value type - OP corresponds to std::less<k_t>, an object which implements a templated comparison operation among the keys. The class features two standard members: `root` (a `std::unique_ptr` pointing to the root node of the tree) and an OP object.

* `_node<N>`: a templated struct whose members are `node`, in form of pair_type (std::pair<const k_t, v_t>) and three pointers: `left` and `right` (pointing to left and right child nodes respectively), and `parent` (raw ptr pointing to the parent node).
The class _node is kept outside the class bst as it can easily be reused by multiple trees without the need to be a nested class.

* `iterator<N, O>`: a templated class whose only private member is `current`, a raw pointer to the current node of type `N`. The second template argument `O` is the pair_type. This class is used to allow the tree traversal and make it esier to jump from one node the another going "forward" from left to right. As in _node, the class is implemented outside the class `bst`.

## Constructors & Member Functions

















#### my_find
```
//private
std::pair<node *, const bool> my_find(const k_t& x) const;

```
my_find is an accessory private function whose main goal is to ease the the work done by `find` and `insert`. It returns a pair of an ptr to node and a boolean: if the key specified as input is present in the tree, then the ptr to the found node is returned and the boolean variable is set to true; instead, if the key is not found, then a ptr to the parent node is returned together with a false statement.


#### insert
```
//private
template <typename O> 
std::pair<iterator,bool>  _insert(O&&x);

//public
std::pair<iterator, bool> insert(const pair_type& x){ return _insert(x);}
std::pair<iterator, bool> insert(pair_type&& x){ return _insert(std::move(x));} 

```
`insert` allows the user to insert a new node in the tree, by giving the pair (key+value) as the input. In order to make the code more clear, both the versions for `insert` invoked `_insert`, a private function in which `forward<O>` is called to allow for the usage of lvalue or rvalue reference according to the needs of the function. `insert` exploits `my_find` to look for the key and insert it, whether it is not already in the tree: in this case it returns a pair of an iterator to the ndoe and a bool evaluated to true. In the case in which the key was already present, then an iterator to the node of the retrieved key is returned together with a the boolean value set to false.

#### find
```
//public
iterator find(const k_t& x);
const_iterator find(const k_t& x) const;

```
`find` searches for the key in the tree: if it is already present, then an iterator to the proper node is returned; otherwise, an iterator to the `end()` is returned.


#### Subscripting operator []
```
//public
v_t& operator[](k_t&& x);
v_t& operator[](const k_t& x);

```

the `subscripting operator []` is an overloading operator which, given a key in input (in form of rvalue reference or const lvalue), returns a reference to the associated value if the key was already present in the tree; otherwise, the key is inserted and the associated value is a default one (obtained writing v_t v {}). 


#### emplace
```
//public
template< class... Types >
std::pair<iterator,bool> emplace(Types&&... args)
  
```

`emplace` calls `insert` by giving in input a `forward<O>` construct, which allows flexibility in calling the proper version of the `_insert` function. Therefore it behaves like `insert` itself: the only difference is that it uses a variadic template, requesting in input two args (key and value). It returns a pair of an iterator to the added node if the key was not present before, together with a true statement; instead, if the key was already present, then an iterator to the already present node is returned, and the boolean value is false.





















