#include "webkit.hpp"

int main() {
  Tag html("html");

  // ************ HEAD *************************************
  auto head = html.addChild(new Tag("head"));

  // Title
  head->addChild(new Tag("title", "C++ Mexico"));

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
  Tag body("body");
  html.addChild(&body);

  // Body style
  body
    .addAttr("style", R"(
      line-height: 1.4;
      font-size: 10pt;
      font-family: Lucida\ Console, monaco, monospace;
      margin: 1em auto;
      max-width: 1000px;
    )");

  // Header (C++ Mexico)
  body
    .addChild(new Tag("header"))
      ->addAttr("style", R"(
        padding-top: 10px;
        text-align: center;
      )")
      ->addChild(new Tag("strong", "C++ Mexico"))
        ->addAttr("style", R"(
          font-size: 26pt;
          font-weight: normal;
          color: black;
        )");

  auto center = body
    .addChild(new Tag("main"))
      ->addChild(new Tag("div"))
        ->addAttr("class", "p")
        ->addChild(new Tag("center"));

  // Logo
  center
    ->addChild(new Tag("img"))
      ->addAttr("src", "https://cpp.com.mx/images/logo.png");

  // Description
  center
    ->addChild(new Tag("p", "Comunidad de C++ Mexico"));

  // Social media
  center
    ->addChild(new Tag("p", R"(<a href="https://twitter.com/cpp_mx">Twitter</a> / <a href="https://discord.gg/t53X2e8Mrz">Discord</a> / <a href="https://github.com/cppmexico">Github</a> / <a href="https://www.twitch.tv/cppmexico">Twitch</a>)"));

  // Print generated html to stdout
  html.show();
}
