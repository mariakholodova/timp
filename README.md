#  Практическая работа №2

Задания: 
    - 4: Вывести разность введенных n чисел
    - 17: Вывести азность сумм чётных и нечётных квадратов n чисел

[Ссылка на файл с заданиями](http://timp.keva.su/TiMP_labs/practice_2.pdf 'Тык')
Оформили отчет по [markdown'у](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet 'Тык')
________________________________________________
# Ход работы

Была использована подсистема Ubuntu 18.04, которую мы использовали для выполнения [Практической работы №1](https://github.com/mariakholodova/timp/tree/pr1)
После запуска подсистемы мы создали файл и записали в него код для выполнения задания 
```sh
$ > 04_rasnost.c
$ nano 04_rasnost.c
```
И так же
```sh
$ > 17_kvadrati.c
$ > nano 17_kvadrati.c
```
После этого выполняется команда компиляции "gcc <имя файла>", в результате чего будет создан исполняемый файл "a.out", который мы и запустим. Ниже представлена работа со вторым файлом
```sh
$ > 17_kvadrati.c
$ > ./a.out
```
> Примечание:
> Если gcc не установлено, то следует прописать указанные ниже команды
```sh
$ sudo apt update
$ sudo apt install gcc
```
После этого создаем все остальные необходимые файлы (скриншоты работы программы, README), прописываем в .gitignore файл a.out, прописываем commit
```sh
$ nano .gitignore
$ > README.md
$ nano README.md
$ git add .
$ git commit -m "Исправлены ошибки, добавлен 17 вариант"
$ git push 
```
___________________________
# Результат
Для проверки первой программы вводили такие значения 
| Входные данные n (Первая строчка) | Входные данные (Вторая строчка) |Выходные данные |
| ------ | ------ | ------|
| 5 | 1 2 3 4 5 | -15 |

Для проверки второй программы вводили такие значения 
| Входные данные n (Первая строчка) | Входные данные (Вторая строчка) |Выходные данные |
| ------ | ------ | ------|
| 5 | 3 4 5 6 7 | -31 | 

Скрин работы:
- [Скриншот 1](https://github.com/mariakholodova/timp/blob/pr2/pr2.PNG 'Тык')





