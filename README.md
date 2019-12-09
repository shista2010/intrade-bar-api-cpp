![logo](doc/logo/logo-320-160-v2.png)
# intrade-bar-api-cpp

C++ header-only api для работы с брокером [intrade.bar](https://intrade.bar/)

## Описание

*C++ header-only* библиотека для работы с брокером [https://intrade.bar/](https://intrade.bar/)

**На данный момент библиотека находится в разработке**

## Вспомогательные программы

### Загрузка исторических данных котировок

Программа *intrade-bar-downloader.exe* способна загружать исторические данные всех символов (валютные пары и золото), представленные у брокера [intrade.bar](https://intrade.bar/).

* Готовая сборка программы находится в папке *bin*. 
* Иструкция по использованию расположена здесь *bin/README.md*. 
* Недостающие *dll* файлы можно найти в *bin/dll.7z*.
* Исходный код программы для загрузки исторических данных находится здесь *code_blocks/intrade-bar-downloader*.

## Как начать использовать

Библиотека *intrade-bar-api-cpp* имеет следующие зависимости:

- *boost.asio*
- *openssl*
- *curl*
- *Simple-WebSocket-Server*
- *zstd*
- *zlib*
- *zlib*
- *gzip-hpp*
- *json*
- *banana-filesystem-cpp*
- *xtime_cpp*
- *xquotes_history*

Несмотря на то, что зависимостей достаточно много, установить все это не так сложно. Многие библиотеки являются *header-only*, в противном случае чаще всего достаточно лишь добавить *.cpp* файлы в проект.

### Инструкция установки по порядку 
- Если вы хотите использовать компилятор *mingw*, прочитайте инструкция по установке в файле *MINGW_INSTALL.md*.
- Инструкция по установке *boost.asio* представлена в файле *BOOST_INSTALL.md*.
- Библиотеку *curl* проще всего не собирать самостоятельно, а скачать готовую сборку. 



