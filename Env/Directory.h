//
// Created by d1md1m on 26.03.17.
//

#ifndef LAB_2_SHELL_DIRECTORY_H
#define LAB_2_SHELL_DIRECTORY_H

#include <boost/filesystem/path.hpp>
#include <iostream>
#include <string>

#include "User.h"

namespace fs = boost::filesystem;

class Directory{

public:
    const fs::path &getActualPath() const;

    void setActualPath(const fs::path &actual_path); ;

    bool doesPathWasChanged() const ;;

    void setPathWasChanged(const bool path_was_changed); ;

    Directory();

    int refreshPath();

    //by default shows info about this object, but can do for any
    bool containsHisHome( const User *this_user) const;

private:
    fs::path actual_path_;

    bool path_was_changed_;

};



#endif //LAB_2_SHELL_DIRECTORY_H
