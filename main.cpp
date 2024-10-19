#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include "asteroids.h"
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
using namespace std;

int main() {
    vector<asteroids> asteroid;
    BinarySearchTree<int> bst1;
    SplayTree<int> test;
    int depth = 0;
    // Makes sure data was read in from asteroid dataset
    if (getDataFromFile(asteroid)) {
        cout << "Read in data. Size of Vector: " << asteroid.size() << endl;
    }




    // Initializing the three types of trees
    BinarySearchTree<int> bintree;
    AVLTree<int> avltree;
    SplayTree<int> splaytree;
    // Loops through numbers 1 to 100 and adds them to each tree
    for (int i = 1; i <= 100; ++i) {
        bintree.add(i);
        avltree.add(i);
        splaytree.add(i);
    }
    // Makes new file in data folder
    ofstream outFile1;
    outFile1.open("../data/output_asteroids.csv");
    for (int i = 1; i <= 100; ++i) {
        int bstDepth = 0, avltreeDepth = 0, splaytreeDepth = 0;
        // Finds depth of each number
        bintree.find(i, bstDepth);
        avltree.find(i, avltreeDepth);
        splaytree.find(i, splaytreeDepth);
        // Adds depth of each number 1 through 100 in the new file
        outFile1 << bstDepth << "," << avltreeDepth << "," << splaytreeDepth << endl;
    }
    outFile1.close();
    // Finds whats at value 0 and what is supposed to be at value 0
    bool findZero = bintree.find(0, depth);
    cout << "Find value 0: " << findZero << ", Depth: " << depth << endl;
    depth = 0;
    // Finds whats at value 101 and what is supposed to be at value 101
    bool findOneHundredOne = bintree.find(101, depth);
    cout << "Find value 101: " << findOneHundredOne << ", Depth: " << depth << endl;
    depth = 0;
    // Finds whats at value 102 and what is supposed to be at value 102
    bool findOneHundredTwo = bintree.find(102, depth);
    cout << "Find value 102: " << findOneHundredTwo << ", Depth: " << depth << endl;




    // Initializes new trees and vector ranNums
    BinarySearchTree<int> bintree2;
    AVLTree<int> avltree2;
    SplayTree<int> splaytree2;
    vector<int> ranNums;
    // Adds 1 through 100 into vector ranNums
    for (int i = 1; i <= 100; ++i) {
        ranNums.push_back(i);
    }
    // Shuffles the ranNums vector
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(ranNums.begin(), ranNums.end(),default_random_engine(seed));
    // Adds the randomized numbers into each tree
    for (int num = 0; num < 100; ++num) {
        bintree2.add(ranNums[num]);
        avltree2.add(ranNums[num]);
        splaytree2.add(ranNums[num]);
    }
    // Opens new file in data folder
    ofstream outFile2;
    outFile2.open("../data/shuffled_output.csv");
    for (int i = 1; i <= 100; ++i) {
        int depthBST = 0, depthAVL = 0, depthSplay = 0;
        // Find the integer in each tree and track the depth
        bintree.find(i, depthBST);
        avltree.find(i, depthAVL);
        splaytree.find(i, depthSplay);
        // Record the number and the depths to the CSV file
        outFile2 << depthBST << "," << depthAVL << "," << depthSplay << endl;
    }




    // Initializes new trees
    BinarySearchTree<asteroids> astBinary;
    AVLTree<asteroids> astAVL;
    SplayTree<asteroids> astSplay;
    // Adds asteroids into the trees
    for (int i = 0; i < asteroid.size(); i++) {
        astBinary.add(asteroid[i]);
        astAVL.add(asteroid[i]);
        astSplay.add(asteroid[i]);
    }
    // Checks to make sure that the size of the tree and the size of the data set are the same
    if (astBinary.getSize() != asteroid.size() ||
        astAVL.getSize() != asteroid.size() ||
        astSplay.getSize() != asteroid.size()) {
        cout << "Size mismatch!" << endl;
        return 1;
    }
    else {
        cout << "OK" << endl;
    }
    // Opens new file in data folder
    ofstream outFileNew;
    outFileNew.open("../data/asteroid_outputNew.csv");
    outFileNew << "ID,BST_Depth,AVL_Depth,Splay_Depth" << endl;
    int count = 0;
    // Finds asteroid at index i and its depth
    for(int i = 0; i < asteroid.size(); i++) {
        int depthBST = 0, depthAVL = 0, depthSplay = 0;
        bool BST = astBinary.find(asteroid[i], depthBST);
        bool AVL = astAVL.find(asteroid[i], depthAVL);
        bool Splay = astSplay.find(asteroid[i], depthSplay);
        // Makes sure something is being added to depth
        if (BST && AVL && Splay) {
            // Adds depth to file
            outFileNew << "Row "<< i << "," << depthBST<< "," << depthAVL << "," << depthSplay << endl;
        }
        else {
            cout << "BST or AVL or Splay" << endl;
        }
    }
    outFileNew.close();




    // Creates new splay tree
    SplayTree<asteroids> splayTreeLast;
    // Adds all asteroids into the tree
    for (int i = 0; i < asteroid.size(); i++) {
        splayTreeLast.add(asteroid[i]);
    }
    // Opens new file in data folder
    ofstream outFileSplay;
    outFileSplay.open("../data/asteroid_Splay.csv");
    // Finds 5 different depths for same object
    for (int i = 0; i < asteroid.size(); ++i) {
        int depth = 0;
        for (int j = 0; j < 5; ++j) {
            splayTreeLast.find(asteroid[i], depth);
            if (depth) {
                outFileSplay << depth << endl;
            }
            else {
                cout << "failed for asteroid " << asteroid[i] << endl;
            }
        }
    }
    // -----------------------------------
    //      THIS DOES THE SAME THING
    // -----------------------------------
    //
    // for (int i = 0; i < asteroid.size(); i++) {
    //     int splayDepth1 = 0, splayDepth2 = 0, splayDepth3 = 0, splayDepth4 = 0, splayDepth5 = 0;
    //     splayTreeLast.find(asteroid[i], splayDepth1);
    //     splayTreeLast.find(asteroid[i], splayDepth2);
    //     splayTreeLast.find(asteroid[i], splayDepth3);
    //     splayTreeLast.find(asteroid[i], splayDepth4);
    //     splayTreeLast.find(asteroid[i], splayDepth5);
    //     // Confirms that there is something being added to depth
    //     if (splayDepth1 && splayDepth2 && splayDepth3 && splayDepth4 && splayDepth5) {
    //         // Adds depths to new file
    //         outFileSplay << "Row " << i << "," << splayDepth1 << "," << splayDepth2 << "," << splayDepth3 << "," << splayDepth4 << "," << splayDepth5 << endl;
    //     }
    //     else {
    //         cout << "Splay didnt work" << endl;
    //     }
    //}
    outFileSplay.close();
    return 0;
}