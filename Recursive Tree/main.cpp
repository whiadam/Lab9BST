#include <iostream>
#include "TreeType.h"

using namespace std;

int main()
{
    TreeType tree;

    cout << "Test 1: Empty tree" << endl;
    cout << "LeafCount = " << tree.LeafCount() << endl;
    cout << endl;

    cout << "Test 2: Single node (root only)" << endl;
    tree.PutItem('M');
    cout << "LeafCount = " << tree.LeafCount() << endl;
    cout << endl;

    cout << "Test 3: Tree with multiple nodes" << endl;
    tree.PutItem('F');
    tree.PutItem('T');
    tree.PutItem('A');
    tree.PutItem('J');
    tree.PutItem('R');
    tree.PutItem('W');
    cout << "Inserted: M F T A J R W" << endl;
    cout << "LeafCount = " << tree.LeafCount() << endl;
    cout << endl;

    cout << "Test 4: Linear chain (all right children)" << endl;
    TreeType chain;
    chain.PutItem('A');
    chain.PutItem('B');
    chain.PutItem('C');
    chain.PutItem('D');
    cout << "Inserted: A B C D (right-skewed)" << endl;
    cout << "LeafCount = " << chain.LeafCount() << endl;
    cout << endl;

    cout << "Test 5: Full binary tree (7 nodes, 4 leaves)" << endl;
    TreeType full;
    full.PutItem('D');
    full.PutItem('B');
    full.PutItem('F');
    full.PutItem('A');
    full.PutItem('C');
    full.PutItem('E');
    full.PutItem('G');
    cout << "Inserted: D B F A C E G" << endl;
    cout << "LeafCount = " << full.LeafCount() << endl;
    cout << endl;

    cout << "Test 6: Two nodes only" << endl;
    TreeType two;
    two.PutItem('B');
    two.PutItem('A');
    cout << "Inserted: B A" << endl;
    cout << "LeafCount = " << two.LeafCount() << endl;

    return 0;
}
