//
// Created by bohdan on 3/18/17.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "deleter.h"
#include <type_traits>
#include <vector>
#include <algorithm>
#include <boost/filesystem.hpp>
using namespace std;

int deleter(vector<string> args, bool is_help, bool is_R, bool is_f)
{
    if(is_help) {
        cout << "Usage: rm [OPTION]... [FILE]..." << endl << "Remove (unlink) the FILE(s)." << endl;
        cout << "    " << "-h, --help                  show help to the function"<< endl;
        cout << "    " << "-f                          deletes files silently"<< endl;
        cout << "    " << "-R                          deletes directories"<< endl;
    }
    char confirm;
    if(is_f) {
        confirm = 'y';
    } else {
        cout << "Confirm your choice (y/[n]): ";
        cin >> confirm;
    }
    if(is_R && confirm == 'y') {
        cout << "Hi!";
        for (size_t i = 0; i < args.size(); i++) {
            boost::filesystem::remove_all(args[i]);
        }

        return 1;
    }
    if (confirm == 'y') {
        if(remove( args[0].c_str() ) != 0 )

            perror( "Error deleting file" );
        else
            puts( "File successfully deleted" );
    } else {
        return 0;
    }
    return 0;
}

