# Ответы на вопросы к экзамену по Компьютерным системам

### 1. Architektúra počítačov PC 

[21 страница](http://matlab.fei.tuke.sk/psvr/subory/literatura/snorek.pdf)

Архитэктура персональных компьютеров (PC) основана на фон-неймановской модели, которая определяет основные компоненты компьютера:

- **Процессор (CPU)** - это центральная вычислительная единица, которая выполняет инструкции программы.
- **Память** - это место, где хранятся инструкции программы и данные.
- **Вводно-выводные устройства (I/O)** - это устройства, которые позволяют компьютеру взаимодействовать с внешним миром.

В компьютерах PC процессор обычно выполнен в виде микропроцессора, который представляет собой интегральную схему, содержащую миллионы транзисторов. Микропроцессор состоит из двух основных частей: арифметико-логического устройства (ALU) и регистра команд (PC). ALU выполняет арифметические и логические операции, а PC хранит адрес следующей инструкции, которую должен выполнить процессор.

Память компьютера делится на два основных типа: **оперативную память (RAM)** и **постоянную память (ROM)**. RAM используется для хранения данных, которые должны быть доступны процессору во время выполнения программы. ROM используется для хранения данных, которые необходимы для запуска компьютера, таких как BIOS.

Вводно-выводные устройства (I/O) позволяют компьютеру взаимодействовать с внешним миром. К ним относятся клавиатура, мышь, монитор, принтер, сканер и другие устройства.

Помимо основных компонентов, в компьютерах PC также могут присутствовать следующие устройства:

- **Кэш-память** - это быстродействующая память, которая используется для хранения часто используемых данных.
- **Шина** - это набор линий связи, по которым данные и инструкции передаются между компонентами компьютера.
- **Системная плата** - это основная печатная плата компьютера, на которой расположены все основные компоненты.
Рассмотрим более подробно основные компоненты архитектуры PC.

#### Процессор

Процессор является сердцем компьютера. Он выполняет инструкции программы, которые определяют, что компьютер должен делать.

Процессоры обычно классифицируются по следующим параметрам:

- **Архитектура** - это набор правил, определяющих, как процессор выполняет инструкции.
- **Частота** - это количество циклов, выполняемых процессором в секунду.
- **Разрядность** - это количество бит, которые процессор может обрабатывать одновременно.

В современных компьютерах PC используются процессоры с архитектурой x86, частотой до нескольких гигагерц и разрядностью 64 бита.

#### Память

Память используется для хранения программ и данных.

Память компьютера делится на два основных типа: оперативную память (RAM) и постоянную память (ROM).

**Оперативная память (RAM)** - это память, в которой хранятся данные, необходимые для выполнения программы. RAM является энергозависимой памятью, что означает, что данные в ней стираются при выключении питания.

**Постоянная память (ROM)** - это память, в которой хранятся данные, которые необходимы для запуска компьютера. ROM является энергонезависимой памятью, что означает, что данные в ней сохраняются при выключении питания.

#### Вводно-выводные устройства (I/O)

Вводно-выводные устройства (I/O) позволяют компьютеру взаимодействовать с внешним миром.

К вводно-выводным устройствам относятся:

- **Клавиатура** - устройство ввода текста.
- **Мышь** - устройство ввода команд.
- **Монитор** - устройство вывода изображения.
- **Принтер** - устройство вывода текста и изображений.
- **Сканер** - устройство ввода изображений.

#### Кэш-память

Кэш-память - это быстродействующая память, которая используется для хранения часто используемых данных. Кэш-память расположена между процессором и оперативной памятью.

#### Шина

Шина - это набор линий связи, по которым данные и инструкции передаются между компонентами компьютера. Шина может быть внутренней или внешней.

#### Системная плата

Системная плата - это основная печатная плата компьютера, на которой расположены все основные компоненты.

### 2. Pamäťový podsystém počítačov PC

[119 страница](http://matlab.fei.tuke.sk/psvr/subory/literatura/snorek.pdf)

Памятьовый подсистем компьютера PC представляет собой совокупность компонентов, обеспечивающих хранение программ и данных. Основными компонентами памяти являются:

- **Регистры процессора** - это небольшие быстродействующие ячейки памяти, в которых хранятся данные, необходимые для выполнения текущих операций процессором.
- **Кэш-память** - это высокоскоростная память, расположенная между процессором и оперативной памятью. Кэш-память используется для хранения часто используемых данных, чтобы ускорить доступ к ним процессором.
- **Оперативная память (RAM)** - это основная память компьютера, в которой хранятся программы и данные, необходимые для его работы. RAM является энергозависимой памятью, что означает, что данные в ней стираются при выключении питания.
- **Постоянная память (ROM)** - это память, в которой хранятся данные, которые необходимы для запуска компьютера. ROM является энергонезависимой памятью, что означает, что данные в ней сохраняются при выключении питания.
- 
Памятьовый подсистем компьютера PC можно разделить на два основных уровня:

- **Первый уровень** - это регистры процессора и кэш-память. Эти уровни памяти являются самыми быстрыми, но имеют небольшую емкость.
- **Второй уровень** - это оперативная память. Этот уровень памяти является более медленным, чем первый, но имеет большую емкость.
- 
Памятьовый подсистем компьютера PC является важной частью системы, обеспечивающей ее быстродействие и эффективность.

#### Дополнительные сведения

Памятьовый подсистем компьютера PC можно также классифицировать по следующим параметрам:

- **Способ доступа к данным** - память может быть доступной случайным образом или последовательно.
- **Способ хранения данных** - память может быть магнитной, оптической или полупроводниковой.
- **Энергонезависимость** - память может быть энергозависимой или энергонезависимой.

В современных компьютерах PC используется память, доступная случайным образом, полупроводниковая, энергонезависимая.

### 3. Vstupno/výstupný podsystém počitačov PC

[8 страница](http://matlab.fei.tuke.sk/psvr/subory/literatura/snorek.pdf)

Входно-выходной подсистем компьютера PC представляет собой совокупность компонентов, обеспечивающих взаимодействие компьютера с внешним миром. Основными компонентами В/У подсистемы являются:

- **Вводно-выводные устройства (I/O)** - это устройства, которые позволяют компьютеру получать данные из внешнего мира и передавать данные во внешний мир.
- **Порты I/O** - это физические разъемы, к которым подключаются вводно-выводные устройства.
- **Драйверы I/O** - это программы, которые обеспечивают взаимодействие между компьютером и вводно-выводными устройствами.
- 
Входно-выходные устройства (I/O) можно классифицировать по следующим типам:

- **Устройства ввода** - это устройства, которые позволяют компьютеру получать данные из внешнего мира. К устройствам ввода относятся клавиатура, мышь, сканер, микрофон, веб-камера и другие устройства.
- **Устройства вывода** - это устройства, которые позволяют компьютеру передавать данные во внешний мир. К устройствам вывода относятся монитор, принтер, аудиосистема, сетевая карта и другие устройства.

Входно-выходной подсистем компьютера PC является важной частью системы, обеспечивающей ее взаимодействие с внешним миром.

#### Дополнительные сведения

Входно-выходной подсистем компьютера PC можно также классифицировать по следующим параметрам:

- **Способ передачи данных** - данные могут передаваться последовательно или параллельно.
- **Способ подключения** - устройства I/O могут подключаться к компьютеру напрямую или через адаптер.
- **Тип интерфейса** - устройства I/O могут использовать различные интерфейсы, такие как USB, PCI, Ethernet и другие.

В современных компьютерах PC используются вводно-выводные устройства, которые подключаются к компьютеру через шину PCI или шину USB.

### 4. Zbernice počítačov PC

[8 страница](http://matlab.fei.tuke.sk/psvr/subory/literatura/snorek.pdf)

#### Шины компьютеров PC

Шина компьютера PC представляет собой набор линий связи, по которым данные и инструкции передаются между компонентами компьютера. Шины могут быть внутренними или внешними.

#### Внутренние шины

Внутренние шины используются для подключения компонентов, расположенных на материнской плате. Основными внутренними шинами являются:

- **Шина данных** - используется для передачи данных между компонентами компьютера.
- **Шина адреса** - используется для передачи адреса памяти или устройства, с которым необходимо выполнить операцию.
- **Шина управления** - используется для передачи команд управления компонентами компьютера.
- 
#### Внешние шины

Внешние шины используются для подключения внешних устройств к компьютеру. Основными внешними шинами являются:

- **Шина PCI** - используется для подключения периферийных устройств, таких как видеокарты, сетевые карты и звуковые карты.
- **Шина USB** - используется для подключения различных устройств, таких как клавиатуры, мыши, принтеры и флэш-накопители.
- **Шина SATA** - используется для подключения жестких дисков и твердотельных накопителей.

Шины компьютеров PC играют важную роль в передаче данных и инструкций между компонентами компьютера. Они обеспечивают эффективное взаимодействие между различными компонентами компьютера, что позволяет ему работать быстро и эффективно.

#### Дополнительные сведения

Шины компьютеров PC можно классифицировать по следующим параметрам:

- **Тип передачи данных** - данные могут передаваться последовательно или параллельно.
- **Ширина шины** - определяет количество бит, которые могут передаваться по шине за один такт.
- **Частота шины** - определяет количество тактов в секунду, которые генерирует шина.

В современных компьютерах PC используются шины, которые передают данные параллельно, имеют широкую ширину шины и высокую частоту шины.

### 5. Prerušovací systém počítačov PC

#### Прерывающий систем компьютеров PC

Прерывающий систем компьютеров PC представляет собой совокупность компонентов, обеспечивающих взаимодействие между процессором и периферийными устройствами.

**Прерывание** - это событие, которое вызывает остановку текущего выполнения программы и переход к выполнению специального программного обеспечения, называемого обработчиком прерывания.

Прерывания могут быть вызваны следующими событиями:

- **Внешние события** - такие как нажатие клавиши на клавиатуре или перемещение мыши.
- **Внутренние события** - такие как завершение выполнения инструкции или истечение таймера.
- 
Прерывающий систем компьютеров PC состоит из следующих компонентов:

- **Процессор** - выполняет инструкции программы и реагирует на прерывания.
- **Радиатор прерываний** - принимает запросы на прерывание от периферийных устройств и передает их процессору.
- **Обработчик прерывания** - выполняет программное обеспечение, которое обрабатывает прерывание.

Прерывающий систем компьютеров PC играет важную роль в обеспечении эффективной работы компьютера. Он позволяет процессору обрабатывать запросы от периферийных устройств без прерывания выполнения текущей программы.

#### Дополнительные сведения

Прерывающий систем компьютеров PC можно классифицировать по следующим параметрам:

- **Тип прерывания** - прерывания могут быть маскируемыми или немаскируемыми. Маскируемые прерывания могут быть отключены процессором, а немаскируемые прерывания не могут быть отключены.
- **Приоритет прерывания** - прерывания имеют различные приоритеты. Приоритет определяет, какое прерывание будет обработано первым.

В современных компьютерах PC используются прерывания, которые являются маскируемыми и имеют приоритеты.

#### Пример работы прерывающего систем компьютеров PC:

Пользователь нажимает клавишу на клавиатуре. Клавиатура отправляет сигнал прерывания на радиатор прерываний. Радиатор прерываний принимает сигнал прерывания и передает его процессору. Процессор прерывает выполнение текущей программы и переходит к выполнению обработчика прерывания. Обработчик прерывания проверяет, какая клавиша была нажата, и выполняет соответствующую команду. После завершения обработки прерывания процессор возвращается к выполнению текущей программы.

### 6. Podsystém priameho prístupu do pamäti
