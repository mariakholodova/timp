#  Практическая работа №3

Задания: Реализовать односвязный и двусвязный список + функционал

[Ссылка на методичку](https://vk.com/doc203062831_492886426?hash=d88f18fc9238864141&dl=7e741ece6f2c7e29d0 'Тык')
Оформили отчет по [markdown'у](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet 'Тык')
________________________________________________
# Ход работы

Была использована подсистема Ubuntu 18.04, которую мы использовали для выполнения [Практической работы №1](https://github.com/mariakholodova/timp/tree/pr1) и последующих
После запуска подсистемы мы создали файл и записали в него код для выполнения задания 
```sh
$ > 01_737-2_hma.c
$ nano 01_737-2_hma.c
```
И так же
```sh
$ > 02_737-2_hma.c
$ nano 02_737-2_hma.c
```
После этого выполняется команда компиляции "gcc <имя файла>", в результате чего создан исполняемый файл "a.out", который мы и запустили. 

Ниже представлена такая работа со вторым файлом
```sh
$  gcc 02_737-2_hma.c
$  ./a.out
```
После этого создаем все остальные необходимые файлы (скриншоты работы программы, README), прописываем в .gitignore файл a.out, прописываем commit
```sh
$ nano .gitignore
$ > README.md
$ nano README.md
$ git add .
$ git commit -m "Добавлено неполное readme "
$ git push 
```
___________________________
# Результат

Скрины работы:
- [Скриншот 1](https://github.com/mariakholodova/timp/blob/pr3/1.jpg 'Тык')
- [Скриншот 2](https://github.com/mariakholodova/timp/blob/pr3/2.jpg 'Тык')





