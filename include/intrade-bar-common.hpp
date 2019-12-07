/*
* intrade-bar-api-cpp - C ++ API client for intrade.bar
*
* Copyright (c) 2019 Elektro Yar. Email: git.electroyar@gmail.com
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef INTRADE_BAR_COMMON_HPP_INCLUDED
#define INTRADE_BAR_COMMON_HPP_INCLUDED

//#include <stdio.h>
//#include <string.h>
#include <iostream>
#include <map>
#include <array>
#include <string>
#include <cstring>
#include <xtime.hpp>

namespace intrade_bar_common {

    const uint32_t CURRENCY_PAIRS = 26; /**< Количество торговых символов */
    const uint32_t MAX_DURATION = xtime::SECONDS_IN_MINUTE * 500;   /**<
        Максимальная продолжительность опциона */
    const uint32_t MAX_NUM_BET = 10;    /**< Максимальное количество одновременно открытых сделок */
    // минимальные и максимальные ставки
    const uint32_t MAX_BET_USD = 500;   /**< Максимальная ставка в долларах */
    const uint32_t MAX_BET_RUB = 25000; /**< Максимальная ставка в рублях */
    const uint32_t MIN_BET_USD = 1;     /**< Минимальная ставка в долларах */
    const uint32_t MIN_BET_RUB = 50;    /**< Минимальная ставка в рублях */

    const uint32_t MAX_BET_GC_USD = 250;
    const uint32_t MAX_BET_GC_RUB = 12500;
    const uint32_t MIN_BET_GC_USD = 10;
    const uint32_t MIN_BET_GC_RUB = 500;

    const uint32_t GC_INDEX = 25;       /**< Номер символа "Золото" */


    /// Варианты настроек для исторических данных котировок
    enum {
        FXCM_USE_HIST_QUOTES_BID = 0,           /**< Использовать только цену bid в исторических данных */
        FXCM_USE_HIST_QUOTES_ASK = 1,           /**< Использовать только цену ask в исторических данных */
        FXCM_USE_HIST_QUOTES_BID_ASK_DIV2 = 2,  /**< Использовать цену (bid + ask)/2 в исторических данных */
    };

    static const std::array<std::string, CURRENCY_PAIRS> currency_pairs = {
        "EURUSD","USDJPY","GBPUSD","USDCHF",
        "USDCAD","EURJPY","AUDUSD","NZDUSD",
        "EURGBP","EURCHF","AUDJPY","GBPJPY",
        "CHFJPY","EURCAD","AUDCAD","CADJPY",
        "NZDJPY","AUDNZD","GBPAUD","EURAUD",
        "GBPCHF","EURNZD","AUDCHF","GBPNZD",
        "GBPCAD","XAUUSD",
    };  /**< Массив имен символов (валютные пары и Золото) */

    static const std::array<std::string, CURRENCY_PAIRS>
        extended_name_currency_pairs = {
        "EUR/USD","USD/JPY","GBP/USD","USD/CHF",
        "USD/CAD","EUR/JPY","AUD/USD","NZD/USD",
        "EUR/GBP","EUR/CHF","AUD/JPY","GBP/JPY",
        "CHF/JPY","EUR/CAD","AUD/CAD","CAD/JPY",
        "NZD/JPY","AUD/NZD","GBP/AUD","EUR/AUD",
        "GBP/CHF","EUR/NZD","AUD/CHF","GBP/NZD",
        "GBP/CAD","XAU/USD",
    };  /**< Массив имен символов (валютные пары и Золото)
         * c расширенным именем (со знаком / между валютными парами)
         */

    static const std::map<std::string, int> currency_pairs_indx = {
        {"EURUSD",0},{"USDJPY",1},{"GBPUSD",2},{"USDCHF",3},
        {"USDCAD",4},{"EURJPY",5},{"AUDUSD",6},{"NZDUSD",7},
        {"EURGBP",8},{"EURCHF",9},{"AUDJPY",10},{"GBPJPY",11},
        {"CHFJPY",12},{"EURCAD",13},{"AUDCAD",14},{"CADJPY",15},
        {"NZDJPY",16},{"AUDNZD",17},{"GBPAUD",18},{"EURAUD",19},
        {"GBPCHF",20},{"EURNZD",21},{"AUDCHF",22},{"GBPNZD",23},
        {"GBPCAD",24},{"XAUUSD",25}
    };  /**< Пары ключ-значение для имен символов и их порядкового номера */

    /// Варнианты сделок
    enum {
        BUY = 1,    ///< Сделка на повышение курса
        CALL = 1,   ///< Сделка на повышение курса
        SELL = -1,  ///< Сделка на понижение
        PUT = -1,   ///< Сделка на понижение
    };

    /// Варианты состояния ошибок
    enum {
        OK = 0,                             ///< Ошибки нет
        CURL_CANNOT_BE_INIT = -1,           ///< CURL не может быть инициализирован
        AUTHORIZATION_ERROR = -2,           ///< Ошибка авторизации
        CONTENT_ENCODING_NOT_SUPPORT = -3,  ///< Тип кодирования контента не поддерживается
        DECOMPRESSOR_ERROR = -4,            ///< Ошибка декомпрессии
        JSON_PARSER_ERROR = -5,             ///< Ошибка парсера JSON
        NO_ANSWER = -6,                     ///< Нет ответа
        INVALID_ARGUMENT = -7,              ///< Неверный аргумент метода класса
        STRANGE_PROGRAM_BEHAVIOR = -8,      ///< Странное поведение программы (т.е. такого не должно быть, очевидно проблема в коде)
        BETTING_QUEUE_IS_FULL = -9,         ///< Очередь ставок переполнена
        ERROR_RESPONSE = -10,               ///< Сервер брокера вернул ошибку
        NO_DATA_IN_RESPONSE = -11,
        ALERT_RESPONSE = -12,               ///< Сервер брокера вернул предупреждение
        DATA_NOT_AVAILABLE = -13,           ///< Данные не доступны
        PARSER_ERROR = -14,                 ///< Ошибка парсера ответа от сервера
    };

    /// Параметры счета
    enum {
        USD = 0,    ///< Долларовый счет
        RUB = 1,    ///< Рублевый счет
        DEMO = 0,   ///< Демо счет
        REAL = 1,   ///< Реальный счет
    };

    /// Параметры обновления цены
    enum {
        UPDATE_EVERY_SECOND = 0,
        UPDATE_EVERY_END_MINUTE = 1,
        UPDATE_EVERY_START_MINUTE = 2,
    };

    /** \brief Получить аргумент командной строки
     */
    const char *get_argument(int argc, char **argv, const char *key) {
        for(int i = 1; i < argc; ++i) {
            if(argv[i][0] == '-' || argv[i][0] == '/') {
                uint32_t delim_offset = 0;
                if(strncmp(argv[i], "--", 2) == 0) delim_offset = 2;
                else if(std::strncmp(argv[i], "-", 1) == 0 ||
                        std::strncmp(argv[i], "/", 1) == 0) delim_offset = 1;

                if(stricmp(argv[i] + delim_offset, key) == 0 && argc > (i + 1))
                    return argv[i+1];
            }
        }
        return "";
    }

    void print_line(std::string message) {
        static uint32_t message_size = 0;
        if(message_size > 0) {
            for(size_t i = 0; i < message_size; ++i) {
                std::cout << " ";
            }
            std::cout << "\r";
        }
        std::cout.width(message.size() + 1);
        std::cout << message << "\r";
        message_size = message.size();
    }
};

#endif // INTRADE_BAR_COMMON_HPP_INCLUDED