#include "binboom.h"

int main(){
    // init the file names
    vector<string> files = { "input/input-file-1.txt", "input/input-file-2.txt"};

    // read from input files
    for(int i=0; i<files.size(); i++){
        cout << "File " << files[i] << endl;
        BinaireBoom<string> tree(files[i]);

        cout << "Preorder:  ";
        tree.schrijf(cout, "preorder");
        cout << endl;

        cout << "Inorder:   ";
        tree.schrijf(cout, "inorder");
        cout << endl;

        cout << "Postorder: ";
        tree.schrijf(cout, "postorder");
        cout << endl;

        cout << endl;
    }

    return 0;
}