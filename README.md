# C++ Patterns

Исходники к серии из 23 видео уроков с канала [Builder Line](https://www.youtube.com/channel/UC-1Y9UDgr-vlNyEP8u5H2jA)

Написано в VSCode на Ubuntu.

## Зависимости

Их естественно нет. Надо лишь поставить на VSCode плагины:

- C/C++ IntelliSense
- C/C++ Extension Pack

Не помешают и эти:

- Better C++ Syntax
- C/C++ Themes
- Auto-Collapse Explorer

## Мелочи

- Makefile подходит под проект любой сложности с инкрементальной сборкой.
- Объектные файлы складываются в папку obj, где создаются подпапки, соответствующие путям к \*.cpp файлам относительно корня.
- По Ctrl+Shift+B можно выбрать цель - build или debug, с clean или без него.
- С помощью colorize.sh фильтруется и подсвечивается вывод make в терминал.
- В settings.json включен автоформат и колоризация скобок.
