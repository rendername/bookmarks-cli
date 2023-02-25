# bookmarks cli

bookmarks cli is a command line program built in rust. it is used
to manage local bookarks outside of any specific browser. the idea
is to be able to manage your bookmarks quickly and efficiently in
a terminal environment without having to deal with that pesky browser.

## specs

* language(s): rust
* persistent storage: local filesystem

## commands

|command name|CRUD operation|
|----------- |--------------|
|add         | create       |
|list        | read         |
|show        | read         |
|edit        | update       |
|delete      | delete       |

## extras

we will manage bookmarks in a text file that is one line per bookmark,
however we will provide a nicely styled local html file that we can pull up
in our browser built from our bookmark list. this will enable us to navigate
bookmarks better than the built in bookmark manager...if we are successful.
