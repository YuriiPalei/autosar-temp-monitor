### Software Requirements Specification (SRS)

#### 1. Вступ

##### Мета документа

Цей документ описує функціональні та нефункціональні вимоги до системи TemperatureMonitor, призначеної для моніторингу температури з інтеграцією компонентів AUTOSAR Adaptive і AUTOSAR Classic.

##### Призначення програмного забезпечення

Програма призначена для виявлення перегріву, ведення логів температури та активації охолодження при перевищенні допустимого значення.

##### Область застосування

Система може застосовуватись у вбудованих автомобільних системах, зокрема в ECU (Electronic Control Unit), які використовують AUTOSAR-платформу.

#### 2. Огляд системи

##### Опис системи загалом

TemperatureMonitor зчитує температуру, аналізує її, реагує на перегрів (через AUTOSAR Classic), веде логування та генерує повідомлення (через AUTOSAR Adaptive).

##### Основні компоненти:
- TemperatureMonitor
- AutosarClassic (охолодження)
- AutosarAdaptive (логування, події)

#### 3. Вимоги до продукту

##### 3.1 Функціональні вимоги
- Система зчитує температуру з датчика.
- Визначає стан перегріву (температура > порогу).
- У разі перегріву:
- Активує охолодження через AutosarClassic.
- Публікує подію перегріву через AutosarAdaptive.
- Завжди логує температуру.
- Можливість виклику update(temp) для передачі нових значень температури.

##### Use Case:
![UseCase](https://www.plantuml.com/plantuml/png/XOyz2i9048NxdEALfiW5jWY1nKwmC3d0uewRmVq9audWxLtHHb1il_bvtnjMTQ9RYetPsmcd-wgK3BeUksdnJWaZfON4wIRKDjyWkkUsdUbynV56CfDJs98zAvVSDhz7hyjHE0IIoala7DuEBGpu0gr1w14viVxzT2ZXKtUWx6kt1m00)

##### Послідовність дій:
1.	ECU викликає update(temp)
2.	TemperatureMonitor:
- Зберігає температуру
- Логує її через Adaptive
- Якщо температура > порогу:
  - Викликає охолодження через Classic
  - Публікує подію перегріву через Adaptive

##### 3.2 Нефункціональні вимоги

##### Надійність
- Допустима втрата логів температури — <0.1%
- Система автоматично перезапускається у разі збою

##### Продуктивність
- Обробка кожного нового значення — ≤10 мс
- Сумісність з Autosar Adaptive/Classic — обов’язкова

##### Безпека
- Система не зберігає особистих даних 
- Обробка винятків при недопустимих температурах

##### Сумісність
- Сумісна з AUTOSAR Adaptive Platform v22-11
- Сумісна з AUTOSAR Classic Platform v4.3

#### 4. Вимоги до інтерфейсу

##### API
- void update(double temperature)
- bool isOverheating()
- double getCurrentTemperature()

#### 5. Вимоги до тестування
- Модульні тести з імітацією вхідних даних
- Тест на перегрів (температура > порогу)
- Тест стабільності роботи з великою кількістю даних

#### 6. Вимоги до документації
- Короткий README з описом компонентів
- src.md з документацією по архітектурі
- Інструкція по запуску

#### 7. Інші розділи
- Ліцензія: MIT
- Випуск: версія 1.0.0, червень 2025

### Software Design Document (SSD)

#### Архітектура

##### 3-рівнева модель:
- Презентація: main.cpp
- Бізнес-логіка: TemperatureMonitor
- Інтеграція/інфраструктура: AutosarAdaptive, AutosarClassic

#### Компоненти
- TemperatureMonitor: основна логіка обробки температури
- AutosarClassic: викликає систему охолодження
- AutosarAdaptive: логування та сповіщення

#### Потоки даних

##### Сценарій: Update Temperature

![UseCase](https://www.plantuml.com/plantuml/png/ROunQWD134NxEOLAkyW5KXYRnML8aUG0ogvO2xGpW-RFGcuV5IwoOHeX-Fyz_hM17Nspn3EAqttwIfKTEclb3FgKhOepkijRoHgLGtphA8rzCcvDvr5qMxX2TqafrFHo6HZfbNfT6792PESqQ0JtpnUGbVLFzGcpWH0VNSXqKoIYiUyuFNHmNLVngHJJl7xyjD2SpcD-kAVsRzFsUD_57yAuxvBnN2LvITSuVRDV)

#### Сховище даних
- Тип: вбудоване логування через AUTOSAR Adaptive
- Формат: неформалізовані події (event-based)

