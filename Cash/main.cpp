#include "cash.h"

using namespace ClientServerSQL;

int main(){
    Cash c;

    c.Insert(100, "pppp");
    c.Insert(105, "hhhh");
    c.Insert(206, "llll");
    c.Insert(30, "jjjj");
    c.Insert(40, "sssss");
    c.Insert(50, "qqqq");
    c.Insert(60, "wwww");
    c.Insert(70, "eee");
    c.Insert(80, "rrr");
    c.Insert(90, "ttttt");

    c.Print();
    cout << endl << endl;
    c.Insert(11, "yyy");
    c.Insert(12, "uuu");

    c.Print();

    /*unordered_map<int, string> um;
    um.emplace(make_pair<int, string>(100, "pppp"));
    um.emplace(make_pair<int, string>(105, "hhhh"));
    um.emplace(make_pair<int, string>(206, "llll"));
    um.emplace(make_pair<int, string>(20, "kkkk"));
    um.emplace(make_pair<int, string>(30, "jjjj"));
    um.emplace(make_pair<int, string>(90, "oooo"));
    um.emplace(make_pair<int, string>(70, "wwww"));
    um.emplace(make_pair<int, string>(104, "ssss"));
    um.emplace(make_pair<int, string>(300, "vvvv"));
    um.emplace(make_pair<int, string>(40, "ssss"));

    for (auto& p : um) {
            cout << p.first << " " << p.second << endl;
    }
    cout << endl << endl;
    um.erase(um.begin());
    um.erase(um.begin());
    um.erase(um.begin());

    for (auto& p : um) {
            cout << p.first << " " << p.second << endl;
    }*/

}
