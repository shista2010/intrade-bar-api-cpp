# Описание программ

* build_brotli - сборка библиотеки brotli (не нужно)
* build_zstd - сборка библиотеки zstd
* example_api - пример API брокера
* example_historical_data - пример загрузки исторических данных
* example-websocket - пример получения потока котировок от брокера intrade.bar
* intrade-bar-downloader - программа для загрузки исторических данных

### intrade-bar-downloader

Данная программа скачивает исторические данные котировок брокера intrade.bar (FXCM)
Программа автоматически находит цену (bid+ask)/2 и записывает данные значения для всех цен бара (open, low, high, close).
Подробнее смотрите файл *intrade-bar-downloader/README*

### example-websocket

Данная программа демонстрирует получение котировок в режиме реального времени
