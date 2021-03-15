#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Tag {
  private:
    string name;
    string content;
    map<string, string> attributes;
    vector<Tag*> children;

  public:
    Tag(string s) {
      name = s;
    }

    Tag(string s, string c) {
      name = s;
      content = c;
    }

    void show() {
      cout << "<" << name;
      for(auto& p: attributes)
        cout << " " << p.first << "=\"" << p.second << "\"";
      cout << ">" << content;
      for(Tag*& t: children)
        t->show();
      cout << "</" << name << ">";
    }

    Tag* addChild(Tag* t) {
      children.push_back(t);
      return t;
    }

    vector<Tag*> getChildsByName(string s) {
      vector<Tag*> result;
      for(Tag*& t: children)
        if(t->getName() == s)
          result.push_back(t);
      return result;
    }

    vector<Tag*> getDescendantsByName(string s) {
      vector<Tag*> result;
      for(Tag*& t: children) {
        if(t->getName() == s)
          result.push_back(t);
        auto result2 = t->getDescendantsByName(s);
        result.insert(end(result), begin(result2), end(result2));
      }
      return result;
    }

    Tag* addAttr(string s, string c) {
      attributes.insert(make_pair(s, c));
      return this;
    }

    string getName() {
      return name;
    }
};

string loadCss(string filename) {
  ifstream cssfile(filename);
  stringstream strStream;
  strStream << cssfile.rdbuf();
  cssfile.close();
  return strStream.str();
}
