Система мониторинга парковочных мест
====================================
(Вычислительный хаб)
--------------------

АННОТАЦИЯ
---------

Дипломный проект посвящен разработке системы мониторинга парковочных
мест. При выполнении дипломного проекта, было проведено исследование IoT
технологий в сфере транспортной инфраструктуры. В рамках исследования
был проведен анализ существующих систем. На основании этого был
спроектирован недорогой относительно конкурентов аппаратно-программный
прототип системы мониторинга парковочных мест. Основное назначение
системы заключается в определении наличия свободных парковочных мест и
отображении этих данных пользователям. Данная система позволит
пользователям (водителям) в режиме реального времени получать актуальную
информацию о состоянии парковочных мест.

ABSTRACT
--------

The diploma project is devoted to the development of a monitoring system
for parking places. When carrying out the diploma project, was conducted
research IoT technologies in the field of transport infrastructure. As
part of the research, existing systems were analyzed. Based on this, the
hardware-software prototype of a monitoring system for parking places
was designed inexpensive with respect to competitors. The main purpose
of the system is to determine the availability of parking spaces and
display data for users. This system allows users (drivers) to receive
up-to-date information about status of parking places in real time.

РЕФЕРАТ
-------

Разработан проект «Система мониторинга парковочных мест». Основное
назначение системы заключается в определении наличия свободных
парковочных мест и отображении этих данных пользователям. Данная система
позволит пользователям (водителям) в режиме реального времени получать
актуальную информацию о состоянии парковочных мест. Данная система
состоит из: «МК-подсистемы регистрации свободных парковочных мест»,
вычислительного хаба и сервера.

«МК-подсистема регистрации свободных парковочных мест» фиксирует наличие
свободных парковочных мест. К микроконтроллеру подключаются сенсоры,
каждый из которых следит за своим парковочным местом. Через радиомодуль
RFM95W информация о состоянии парковочных мест (свободно / занято)
передается в вычислительный хаб, для последующей обработки. Реализована
функция оплаты парковочного места, с отображением на дисплее и
подтверждением оплаты с клавиатуры.

Основное назначение вычислительного хаба, состоит в осуществлении
взаимодействия сервера, датчиков «МК-подсистема регистрации свободных
парковочных мест» и других компонентов системы.

Сервер осуществляет сбор данных с датчиков «МК-подсистема регистрации
свободных парковочных», управление всеми компонентами системы и вывод
данных пользователям об актуальном состоянии парковочных мест

Материалы по дипломному проекту представлены в виде графической части,
приложения с отлаженным программным кодом и расчетно-пояснительной
записки.

ОПРЕДЕЛЕНИЯ, ОБОЗНАЧЕНИЯ И СОКРАЩЕНИЯ
-------------------------------------

- БС - беспроводная сеть
- БД - база данных
- МК - микроконтроллер
- МКПМ - модуль контроля парковочного места
- МКПРСПМ - МК-подсистема регистрации свободных парковочных мест
- ОС - операционная система
- ПМ - парковочное место
- ПО - программное обеспечение
- СМПМ - система мониторинга парковочных мест
- СУБД - система управления базами данных
- ТС - транспортное средство
- IoT - internet of things
- LoRa - Long Range, метод модуляции в беспроводных сетях
- MQTT - message queue telemetry transport


СОДЕРЖАНИЕ
----------

[ВВЕДЕНИЕ](#ВВЕДЕНИЕ)

[Анализ требований к СМПМ](#Анализ-требований-к-СМПМ)

[Разработка диаграммы вариантов использований](#Разработка-диаграммы-вариантов-использований)

[Описание и структура СМПМ](#Описание-и-структура-СМПМ)

[Описание функциональной схемы СМПМ](#Описание-функциональной-схемы-СМПМ)

[Разработка вычислительного хаба](#Разработка-вычислительного-хаба)

[Анализ требований](Анализ-требований)

[Подключение радиомодуля RFM95](#Подключение-радиомодуля-rfm95)

[Описание диаграммы классов](#Описание-диаграммы-классов)

[Описание файла настроек](#Описание-файла-настроек)

[Тестирование СМПМ](#Тестирование-СМПМ)

[ЗАКЛЮЧЕНИЕ](#ЗАКЛЮЧЕНИЕ)

[Приложение В. Тестирование](/docs/Приложение%20В.%20Тестирование%20СMПМ.pdf)


ВВЕДЕНИЕ
--------

Дипломный проект «Система мониторинга парковочных мест» выполняется на
основании учебного плана кафедры ИУ6 с исходными данными, заданными в
техническом задании. Целью работы является проектирование системы
мониторинга парковочных мест.

Формирование специализированных зон для стоянки автотранспорта началось
почти одновременно с появлением первых автомобилей. Число машин
стремительно растет и для решения возникнувшей проблемы ограниченности
парковочных мест начали внедрять современные технологии.

Основным направлением развития являются «умные» датчики парковки. Такие
датчики встраиваются в дорожное полотно на места парковок и отслеживают
свободно ли машиноместо над ними, отдавая данные в общую систему.
Используя сеть таких датчиков, формируется карта парковок, состояния
которых рассылается пользователям на улицах с помощью специальных табло
или мобильного приложения.

Такая система позволяет решить следующие задачи:
-   сокращение очередей и времени поиска свободного места на парковке;
-   организация оптимального движения транспортных средств и пешеходов
    на парковке;
-   визуальное оповещение о количестве свободных мест в реальном времени
    с помощью информационных табло или на веб-портале;
-   оптимизация работы парковочного пространства.

В ходе данной работы была спроектирована «Система мониторинга
парковочных мест». Основное назначение системы заключается в определении
наличия свободных парковочных мест и отображении этих данных
пользователям. Данная система позволит пользователям (водителям) в
режиме реального времени получать актуальную информацию о состоянии
парковочных мест. Данная система состоит из: «МК-подсистемы регистрации
свободных парковочных мест», вычислительного хаба и сервера.



Анализ требований к СМПМ
========================

Разработка диаграммы вариантов использований
--------------------------------------------

Основное назначение СМПМ заключается в определении наличия свободных
парковочных мест и отображении этих данных пользователям. Данная система
позволяет пользователям (водителям) в режиме реального времени получать
актуальную информацию о состоянии парковочных мест.

Для уточнения требований к функционированию системы необходимо
определить варианты её использования при помощи диаграммы вариантов
использования. Система взаимодействует с двумя видами действующих лиц:
пользователь (водитель) и владелец стоянки. Соответствующие диаграммы
для этих лиц показаны на рисунках 5 и 6.

![Диаграмма вариантов использований для пользователя](/docs/Diagram_of_usage_options_for_the_user.svg)

Рисунок 5 - Диаграмма вариантов использований для пользователя

![Диаграмма вариантов использований для владельца стоянки](/docs/Diagram_of_usage_options_for_the_owner.svg)

Рисунок 6 - Диаграмма вариантов использований для владельца стоянки

Описание и структура СМПМ
-------------------------

На рисунке 7 представлена структурная схема системы мониторинга
парковочных мест. Система мониторинга парковочных мест состоит из
следующих блоков:
-   МК-подсистема регистрирования свободных парковочных мест (МКПРСПМ),
-   вычислительный хаб,
-   сервер.

Датчики МКПРСПМ служат для фиксации наличия свободных парковочных мест и
оплаты. МКПРСПМ формирует пакеты с информацией о свободных парковочных
местах и передаёт их на вычислительный хаб по беспроводной сети LoRaWAN.

Вычислительный хаб, представленный в виде микрокомпьютера Raspberry Pi,
необходим для осуществления взаимодействия сервера, МКПРСПМ и других
компонентов системы. Хаб выполняет приём пакетов, переданных с МКПРСПМ,
формирует пакеты MQTT и передает их на сервер по сети интернет. Обратно
от сервера хаб получает команды управления МКПРСПМ, которые также
передаются по сети LoRaWAN, на МК-подсистемы.

Пользователь с мобильного устройства на платформе Android с
установленным приложением сможет посмотреть карту с указанием
местоположений свободных парковочных мест. Мобильное приложение получает
данные о парковочных местах с помощью API-сервисов, предоставляемых
сервером.

![Структурная схема системы мониторинга парковочных мест](/docs/Structural_scheme.svg)

Рисунок 7 - Структурная схема системы мониторинга парковочных мест

Веб-клиент, предоставляет карту со свободными парковочными местами.
Также для владельцев стоянок, предоставляется возможность для управления
за парковочными местами: изменение тарифного плана, настройка параметров
МКПСРСПМ.

Описание функциональной схемы СМПМ
----------------------------------

На рисунке Рисунок 8 показана функциональная схема СМПМ. Система
работает следующим образом. В МКПРСПМ сигнал о состоянии парковочного
места приходит от сенсора присутствия автомобиля, после чего МК
ATMEGA328 формирует пакеты и отправляет их через радиомодуль RFM95 по
сети LoRaWAN на вычислительный хаб. Также по сети LoRaWAN МКРСППМ может
принять команды для изменения настроечных параметров.

Вычислительный хаб служит для осуществления взаимодействия сервера,
МКПРСПМ и других компонентов системы. Хаб через радиомодуль RFM95
принимает пакеты, переданные с МКПРСПМ, формирует MQTT пакеты и передает
их на сервер и на другие компоненты системы. Данные внутри MQTT пакетов
передаются в формате JSON. Обратно от сервера хаб получает команды
управления МКПРСПМ, которые также передаются по сети LoRaWAN, на
МК-подсистемы. ПО для вычислительного хаба написано с использованием
фреймворка Qt. На вычислительном хабе может быть установлено серверное
ПО, тем самым хаб сформирует локальную сеть, внутри которой сможет
работать как сервер. MQTT - это легкий протокол для передачи данных,
который идеально подходит для взаимодействия большого количества IoT
устройств. Таким образом, к вычислительному хабу возможно подключить
множество других устройств (например, табло индикации количества
свободных парковочных мест), позволяющие взаимодействовать по протоколу
MQTT.

![Функциональная схема СМПМ](/docs/Functional_diagram.svg)

Рисунок 8 - Функциональная схема СМПМ

Сервер взаимодействует с вычислительным хабом по протоколу MQTT. Для
этого на сервере установлен MQTT брокер Mosquitto. Приложение на
фреймворке Ruby on Rails принимает данные о состоянии ПМ через MQTT
брокер и сохраняет в БД PostgreSQL. Также сервер может управлять
датчиками МКПРСПМ, отправляя команды по протоколу MQTT на вычислительный
хаб. Сервер Nginx является Frontend сервером, он осуществляет раздачу
статики и проксирование запросов на веб-сервер Puma, который уже
взаимодействует с веб-приложением на Ruby on Rails. Веб-приложение для
кэширования использует сервис кэширования Memcached. Для работы Action
Cable, который осуществляет взаимодействие с веб-клиентами по WebSocket,
необходима «key - value» хранилище данных Redis. Чтобы веб-клиент в
режиме реального времени получал данные о состоянии парковочных мест,
данные о парковочных местах в формате JSON периодически отправляются по
протоколу WebSocket.



Разработка вычислительного хаба
===============================

Анализ требований
-----------------

Согласно анализу технического задания, консольное приложение
вычислительного хаба должен реализовывать следующий функционал:
-   прием пакетов данных, полученные от датчиков МКПРСПМ по сети LoRaWAN
    или через последовательный порт UART и формирование MQTT-пакетов в
    формате JSON и передача их на сервер и на другие устройства СМПМ;
-   приём MQTT пакетов данных в формате JSON, полученные от сервера и
    передача их на МКПРСПМ;
-   конфигурационный файл для настройки параметров ПО вычислительного хаба.

Для реализации ПО вычислительного хаба использовались библиотеки
фреймворка Qt, а также библиотека RadioHead для работы с радиомодулем
RFM95. Основное преимущество использования Qt фреймворка -- является то,
что он является кроссплатформенным, т.е. разработанное ПО можно будет
запускать на различных устройствах и ОС. Таким образом данное ПО можно
будет установить не только на микрокомпьютере Raspberry Pi, но и на
обычном ПК для тестирования или для непосредственного использования
данной системы. Также в Qt имеются такие удобные библиотеки как:

-   `QMqttClient` - интерфейс для взаимодействия с MQTT брокером
    (появилась только в Qt 5.10);
-   `QSerialPort` - интерфейс для взаимодействия с последовательными портами;
-   `QSettings` - класс для реализации постоянных платформонезависимых настроек приложения.

Подключение радиомодуля RFM95
-----------------------------

Радиомодуль RFM95 (п.п. 3.5.1.2. Радиочастотный приёмопередатчика
RFM95W) используется для связи вычислительного хаба с датчиками МКПРСПМ
по сети LoRaWAN. Если вычислительный хаб представлен в виде
микрокомпьютера Raspberry Pi 3 Model B, то в таблице Таблица 18
приведено подключение радиомодуля к данному микрокомпьютеру:

Таблица 18 - Подключение модуля RFM95W к Raspberry Pi 3 Model B

  Контакт RFM95W   |  Контакт Raspberry Pi 3 Model B |   Роль
  ---------------- | ------------------------------- | ------------------------------------------------------------------------------------------
  1, 8, 10 - GND   | 20 - GND                        | Земля
  2 - MISO         | 21 - SPI0 MISO                  | Приём данных от модуля на Raspberry
  3 - MOSI         | 19 - SPI0 MOSI                  | Передача данных от Raspberry на модуль
  4 - SCK          | 23 - SPI0 SCLK                  | Синхронизация передачи данных
  5 - NSS          | 24 - SPI0 CE0                   | Выбор подчиненного устройства
  9 - ANT          | -                               | Вывод на антенну
  13 - 3,3V        | 17 - 3,3V                       | Питание +3,3В
  14 - DIO0        | 22 - GPIO25                     | Возникновение прерывание на Raspberry при успешном приёме / передачи пакета по сети LoRa

Ниже на рисунке 24 показан внешний вид подключение модуля LoRa BEE на базе
радиочастотного приёмопередатчика RFM95W к микрокомпьютеру Raspberry Pi 3 Model B:

![Внешний вид подключения модуля LoRa BEE к Raspberry Pi 3 Model B](/docs/media/image26.png)

Рисунок 24 - Внешний вид подключения модуля LoRa BEE к Raspberry Pi 3 Model B

Описание диаграммы классов
--------------------------

При проектировании ПО для вычислительного хаба использовался
объектно-ориентированный подход, т.к. при таком подходе ускоряется время
разработки и программный продукт легко изменять и добавлять новый
функционал. На рисунке Е.15 показана разработанная диаграмма классов.

![Диаграмма классов](/docs/Приложение%20Е.15.%20Диаграмма%20классов%20вычислительного%20хаба.svg)

`Worker` является главным классом, отвечающий за инициализацию, а
также периодическим опросом драйвера (класс `Driver`) в методе
`run()` для приёма данных с радиомодуля LoRa или с последовательного
порта. С помощью `QTimer` с заданной периодичностью вызывается метод `run()`.

Абстрактный класс `Driver` является базовым классом для
`LoRaConnection` и `SerialConnection` и является интерфейсом для
взаимодействия с датчиками МКПРСПМ. Потомки данного класса реализовывают
подключение и приём-передачу данных с МКПРСПМ, определяя методы
`send()`, `available()` и `recv()`. Таким образом, реализуется
паттерн «Стратегия», тем самым внутри `Worker` в зависимости от
настроек выбирается способ подключения с датчиками МКПРСПМ: радиомодуль
LoRa или последовательный порт UART. Принимая пакет, драйвер определяет
тип сообщения и отправляет его на соответствующий обработчик.

Класс `Server` реализует интерфейс взаимодействия с сервером по
протоколу MQTT. При инициализации он подключается к MQTT брокеру сервера
и подписывается на соответствующие темы. Приняв сообщение от сервера,
экземпляр класса по подписке определяет соответствующий обработчик.

Абстрактный класс `AbstractReceiveMessageHandler` является
обработчиком входящих сообщений от датчиков МКПРСПМ и сервера. Данный
класс реализует потомок `ReceiveMessageHandler`.

Описание файла настроек
-----------------------

При первом запуске приложения генерируется файл настроек
`settings.ino`, в котором можно поменять способ подключения к датчикам
МКПРСПМ (LoRa или UART), перечислить список идентификаторов датчиков,
настроить подключение к серверам и т.д. Ниже (Листинг 1) приводится
пример настроечного файла `settings.ino` с комментариями, в которых
описан каждый параметр:

Листинг 1 - Файл `settings.ino`
```
[General]
# Способ подключения к датчикам МКПРСПМ (lora, serial)
driver=lora
# Частота радиомодуля при подключении по lora
frequency=868
# Timeout при отправки данных по lora
lora_timeout=1000
# Последовательный порт при подключении serial
serial_port=ttyUSB0
# Baud rate для последовотельного порта
baud_rate=9600

# Список идентификаторов датчиков МКПРСПМ
sensors=1, 2
# Список серверов и папраметров подключения к ним
# host - хост MQTT брокер сервера
# mqtt_port - порт MQTT брокер сервера
# mqtt_username - логин от MQTT брокер сервера
# mqtt_password - пароль от MQTT брокер сервера
# login - логин владельца парковки
# password - пароль владельца парковки
servers="[\
	{\
		\"host\":\"0.0.0.0\",\
		\"mqtt_port\":1883,\
		\"mqtt_username\":\"\",\
		\"mqtt_password\":\"\",\
		\"login\":\"user1@mail.ru\",\
		\"password\":\"pwd123456\"\
	}, {\
		\"host\":\"m23.cloudmqtt.com\",\
		\"mqtt_port\":16325,\
		\"mqtt_username\":\"mqtt_username\",\
		\"mqtt_password\":\"Pwd123456\",\
		\"login\":\"user1@gmail.com\",\
		\"password\":\"123456\"\
	}\
]"
# Частота опроса датчиков
idle_period=300
```

Обратите внимание, что параметр `servers` описывается в виде массива,
таким образом, можно подключить несколько MQTT брокер серверов, и от
каждого из них хаб будет принимать команды и отправлять каждому данные
от датчиков МКПРСПМ.



Тестирование СМПМ
=================

Для проверки требований, предъявленных в техническом задании, в
разработанной системе мониторинга парковочных мест были протестированы
все компоненты системы, а также было проведено комплексное тестирование
системы (Приложение В). Для тестирования МКПРСПМ был собран отладочный
макет, внешний вид которого изображен на рисунке 30.

![](/docs/media/image32.png)

Рисунок 30 - Внешний вид отладочного макета

Также для проверки и анализа данных работоспособности при большой
нагрузки было проведено нагрузочное тестирование. Так, например, RPS для
выдачи парковочных мест (п.п. 5.4) при заполненной БД (13582 записи)
составила 846 запросов в секунду (более подробнее см. в Приложение В).

Для обеспечения качества в ходе дальнейшей разработки для веб-приложения
были написаны 60 автоматизированных теста, покрывающие весь функционал.
Из них 14 модульных теста, 6 интеграционных теста и 40 функциональных
тестов контроллеров.

Результатом проведенного тестирования было установлено, что были
выполнены все предъявляемые требования к разработанному прототипу
системы мониторинга парковочных мест.


ЗАКЛЮЧЕНИЕ
----------

В результате выполнения выпускной квалификационной работы бакалавра был
спроектирован и реализован аппаратно-программный прототип «Системы
мониторинга парковочных мест». Такая система для водителей будет в
режиме реального времени предоставлять актуальные данные о состоянии
парковочных мест. Данная система состоит из МК-подсистемы регистрации
свободных парковочных мест, вычислительного хаба и центрального сервера.

Программное обеспечение для компонентов системы написано преимущественно
в объектном стиле, который обеспечивает интеграцию и удобство для
дальнейшей разработки командой разработчиков.

В ходе выполнения работы было проведено исследование IoTтехнологий в
транспортной инфраструктуре, а также анализ существующих систем.
Разработанная система экономически более выгодна относительно
конкурентных систем.

Все компоненты системы были отлажены и протестированы. Для
разработанного серверного ПО были написаны автоматизированные тесты для
обеспечения качества в ходе дальнейшей разработки. Также был проведен
анализ безопасности системы. Таким образом, разработанная система
соответствует всем требованиям, заявленных в техническом задании.
