#include "BST.hpp"

#include <chrono>
#include <string>


using namespace std::chrono;


int main(){


/*

    using k_type = const int;     // set type of key
    using v_type = std::string;   // set type of value
    
    bst<k_type,v_type> tree{};
    std::string s = "ciao";
    std::pair<k_type,v_type> x{3,s};
    std::pair<k_type,v_type> k{4,"monte"};
    std::pair<k_type,v_type> z{5,s};
    std::pair<k_type,v_type> b{18349,s};
    std::pair<k_type,v_type> v{4,s};  // same key==4 not added by insert !
    tree.insert(k);
  
    srand(1);
    auto start = high_resolution_clock::now();
    for (int i=0; i<100000; i++) {
        const int j = rand() % 100000 + 1;
        std::pair<k_type,v_type> bb{j,s};
        tree.insert(bb);
    }
   
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    // end measure

    
    //std::cout << "**************************** tree[" << key << "] = " << tree[key] << std::endl;
    



*/


















    using k_type = const int;	    // set type of key
    using v_type = std::string;   // set type of value
    
    bst<k_type,v_type> tree{};
    std::string s = "ciao";
    std::pair<k_type,v_type> x{100,s};
    std::pair<k_type,v_type> k{8,"monte"};
    std::pair<k_type,v_type> z{9,s};
    std::pair<k_type,v_type> b{10,s};
    std::pair<k_type,v_type> v{12,s};
    std::pair<k_type,v_type> f{11,s};
    
    tree.insert(x);
    tree.insert(k);    
    tree.insert(z);
    tree.insert(b);
    tree.insert(v);
    tree.insert(f);
    std::cout << tree;
    tree.print_structure();
    tree.balance();
    tree.print_structure();
    
    
    
    /*
    for (int i=0; i<100; i++) {
    		std::pair<k_type,v_type> bb{i,s};
    		tree.insert(bb);
    }
    */
    k_type key = 989;
    // measure time of finding a key
    auto start = high_resolution_clock::now();
    for (int i=0; i<100; i++) {
        const int j = rand() % 100 + 1;
        std::pair<k_type,v_type> bb{j,s};
        tree.insert(bb);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>((stop - start)/1000);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    // end measure
    tree.print_structure();
    tree.balance();
    tree.print_structure();
    tree.find(123);
    
    std::cout << "**************************** tree[" << key << "] = " << tree[key] << std::endl;
    
    bst<k_type,v_type> t{};   // custom ctor
    bst<k_type,v_type> p{tree};  // copy ctor - deepcopy
    //std::cout << p;	  // print copied tree

  
}