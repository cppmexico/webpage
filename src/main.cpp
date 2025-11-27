#include <iostream>
#include "webkit.hpp"

using namespace std;

int main() {
  Tag html("html");
  html.addAttr("lang", "es");

  // ************ HEAD *************************************
  auto head = html.addChild(new Tag("head"));

  head->addChild(new Tag("meta"))
    ->addAttr("charset", "utf-8");

  // Title
  head->addChild(new Tag("title", "C++ Mexico"));

  head->addChild(new Tag("meta"))
    ->addAttr("name", "viewport")
    ->addAttr("content", "width=device-width, initial-scale=1");

  // Load CSS
  head->addChild(new Tag("style", loadCss("css/style.css")));

  // Meta tags for preview
  head->addChild(new Tag("meta"))
    ->addAttr("property", "og:url")
    ->addAttr("content", "https://cpp.com.mx");

  head->addChild(new Tag("meta"))
    ->addAttr("property", "og:title")
    ->addAttr("content", "C++ Mexico");

  head->addChild(new Tag("meta"))
    ->addAttr("property", "og:description")
    ->addAttr("content", "Comunidad de C++ Mexico");

  head->addChild(new Tag("meta"))
    ->addAttr("property", "og:image")
    ->addAttr("content", "https://cpp.com.mx/images/logo.png");

  // ************ BODY *************************************
  auto body = html.addChild(new Tag("body"));

  // Header (C++ Mexico)
  auto header = body
    ->addChild(new Tag("header"));

  header
    ->addChild(new Tag("strong", "C++ Mexico"));

  auto mainTag = body
    ->addChild(new Tag("main"));

  auto hero = mainTag
    ->addChild(new Tag("section"));

  hero->addAttr("class", "hero");

  // Logo
  hero
    ->addChild(new Tag("img"))
      ->addAttr("src", "https://cpp.com.mx/images/logo.png")
      ->addAttr("alt", "C++ Mexico logo");

  // Description
  hero
    ->addChild(new Tag("p", "Comunidad de C++ Mexico"));

  // Social media
  hero
    ->addChild(new Tag("p", R"(<a href="https://twitter.com/cpp_mx">Twitter</a> / <a href="https://discord.gg/t53X2e8Mrz">Discord</a> / <a href="https://github.com/cppmexico">GitHub</a> / <a href="https://www.twitch.tv/cppmexico">Twitch</a>)"))
      ->addAttr("class", "links");

  // Print generated html to stdout
  cout << "<!DOCTYPE html>" << endl;
  html.show();
}

