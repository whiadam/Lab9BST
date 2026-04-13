#include <iostream>
#include "TreeType.h"

using namespace std;

int main()
{
    TreeType tree;

    // empty tree test
    cout << "empty tree leaf count: " << tree.LeafCount() << endl;

    // add one node
    tree.PutItem('M');
    cout << "just root, leaf count: " << tree.LeafCount() << endl;

    // normal tree
    tree.PutItem('F');
    tree.PutItem('T');
    tree.PutItem('A');
    tree.PutItem('J');
    cout << "after adding M F T A J, leaf count: " << tree.LeafCount() << endl;

    // bigger tree
    tree.PutItem('R');
    tree.PutItem('W');
    cout << "after adding R W, leaf count: " << tree.LeafCount() << endl;

    // new tree to test all on one side
    TreeType tree2;
    tree2.PutItem('A');
    tree2.PutItem('B');
    tree2.PutItem('C');
    cout << "one sided tree leaf count: " << tree2.LeafCount() << endl;

    return 0;
}
